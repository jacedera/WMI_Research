// EventConsumer.cpp : Implementation of CWMIEventConsumerProvApp and DLL registration.

#include "stdafx.h"
#include "WMIEventConsumerProv.h"
#include "EventConsumer.h"
#include "EventConsumerSink.h"
#pragma comment (lib, "wbemuuid.lib")
/////////////////////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//
STDMETHODIMP CEventConsumer::Initialize(LPWSTR wszUser, LONG lFlags, 
	LPWSTR wszNamespace, LPWSTR wszLocale, IWbemServices *pNamespace, 
	IWbemContext *pCtx, IWbemProviderInitSink *pInitSink)
{
	ObjectLock lock(this);

	// Cache a copy of the WBEM interface
	m_spLocalServices = pNamespace;

	HRESULT hrStatus = WBEM_S_INITIALIZED;

	try
	{
		//
		// TODO: Add your initialization code here
		//
	}
	catch(...)
	{
		hrStatus = WBEM_E_FAILED;
	}

	// Let WMI know your initialized
	pInitSink->SetStatus(hrStatus, 0);

	return WBEM_S_NO_ERROR;
}

STDMETHODIMP CEventConsumer::FindConsumer(IWbemClassObject* pLogicalConsumer,
		IWbemUnboundObjectSink** ppConsumer)
{
	ObjectLock lock(this);
	HRESULT hr = WBEM_E_NOT_FOUND;

	*ppConsumer = 0;		// Init out-param

	// Get the class of the event consumer
	CComVariant varClass;
	hr = pLogicalConsumer->Get(CComBSTR("__CLASS"), 0, &varClass, 0, 0);

	// Check that we can support this event consumer
	if (_wcsicmp(V_BSTR(&varClass), L"Sample_WMIBookEventConsumer") == 0)
	{
		// Create permanent event comsumer 
		CComObject<CEventConsumerSink>* pEventSink = 0;
		hr = CComObject<CEventConsumerSink>::CreateInstance(&pEventSink);

		// Query forthe out-going interface
		hr =  pEventSink->QueryInterface(IID_IWbemUnboundObjectSink, 
			(LPVOID*)ppConsumer);
		
		Beep(1000, 250);
	}
	else 
		hr = WBEM_E_NOT_FOUND;

	return hr;
}
