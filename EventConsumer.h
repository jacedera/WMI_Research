// CEventConsumer.h: Definition of the CEventConsumer class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CEventConsumer_H__74163953_94EA_4C6E_AD48_BAE847581B61__INCLUDED_)
#define AFX_CEventConsumer_H__74163953_94EA_4C6E_AD48_BAE847581B61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

#include <string>

/////////////////////////////////////////////////////////////////////////////
// typedef's
typedef std::basic_string<TCHAR> tstring;

/////////////////////////////////////////////////////////////////////////////
// CEventConsumer
// "An event consumer provider must define its own class for its logical consumers"
class CEventConsumer : 
	public CComObjectRoot,
	public CComCoClass<CEventConsumer, &CLSID_EventConsumer>,
	public IWbemProviderInit,
	public IWbemEventConsumerProvider
{
public:
	CEventConsumer() {}

	BEGIN_COM_MAP(CEventConsumer)
		COM_INTERFACE_ENTRY(IWbemProviderInit)
		COM_INTERFACE_ENTRY(IWbemEventConsumerProvider)
	END_COM_MAP()

	DECLARE_NOT_AGGREGATABLE(CEventConsumer) 

	DECLARE_REGISTRY_RESOURCEID(IDR_EventConsumer)

protected:
	CComPtr<IWbemServices> m_spLocalServices;


// "It must support the IWbemProviderInit and IWbemEventConsumerProvider interfaces"
// means that any methods that the two interfaces need must be declared and defined
// similar to implementing interfaces in Java. 

// IWbemProviderInit
public:
	STDMETHOD(Initialize)(LPWSTR wszUser, LONG lFlags,
		LPWSTR wszNamespace, LPWSTR wszLocale,
        IWbemServices *pNamespace, IWbemContext *pCtx,
		IWbemProviderInitSink *pInitSink);


// IWbemEventConsumerProvider
public:
	STDMETHOD(FindConsumer)(IWbemClassObject* pLogicalConsumer,
		IWbemUnboundObjectSink** ppConsumer);

};

#endif // !defined(AFX_CEventConsumer_H__74163953_94EA_4C6E_AD48_BAE847581B61__INCLUDED_)
