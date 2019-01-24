#include "stdafx.h"
#include "WMIEventConsumerProv.h"
#include "EventConsumerSink.h"

/////////////////////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//
STDMETHODIMP CEventConsumerSink::IndicateToConsumer(
	IWbemClassObject* pLogicalConsumer, 
	long lNumObjects, 
	IWbemClassObject** apObjects)
{
	ObjectLock lock(this);
	HRESULT hr = WBEM_S_NO_ERROR;

	// Get the class of the event consumer
	CComVariant varClass;
	hr = pLogicalConsumer->Get(CComBSTR("__CLASS"), 0, &varClass, 0, 0);

	// Check that we can support this event consumer
	if (_wcsicmp(V_BSTR(&varClass), L"Sample_WMIBookEventConsumer") == 0)
	{
		// Get event consumer properties
		CComVariant varBeep;
		hr = pLogicalConsumer->Get(CComBSTR("EnableBeep"), 0, &varBeep, 0, 0);

		// WMI can que events and send them all together in one call
		for (int nIndex = 0; nIndex < lNumObjects; nIndex++)
		{
			// This is a simple event handler, just retrieves the class.
			CComVariant varEventType;
			hr = apObjects[nIndex]->Get(CComBSTR(_T("TargetInstance")), 0, 
				&varEventType, 0, 0);			

			// Get event object
			CComQIPtr<IWbemClassObject> spEvent = V_UNKNOWN(&varEventType);

			// Get the class of the event
			CComVariant varEventTypeClass;
			hr = spEvent->Get(CComBSTR(_T("__CLASS")), 0, 
					&varEventTypeClass, 0, 0);			

			// Make a beep sound if the consumer is configured as such
			if (V_BOOL(&varBeep))
				Beep(1500, 250);

			// Recieved event of type <VT_BSTR(&varTypeClass)> 
		}
	}
	else 
		hr = WBEM_E_NOT_FOUND;

	return hr;
}
