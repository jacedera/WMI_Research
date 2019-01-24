#if !defined(AFX_EventConsumerSink_H__74163953_94EA_4C6E_AD48_BAE847581B61__INCLUDED_)
#define AFX_EventConsumerSink_H__74163953_94EA_4C6E_AD48_BAE847581B61__INCLUDED_


class CEventConsumerSink :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IWbemUnboundObjectSink
{
public:
	CEventConsumerSink() { }

	BEGIN_COM_MAP(CEventConsumerSink)
		COM_INTERFACE_ENTRY(IWbemUnboundObjectSink)
	END_COM_MAP()

// IWbemUnboundObjectSink
public:
	STDMETHOD(IndicateToConsumer)(IWbemClassObject* pLogicalConsumer,
		long lNumObjects, IWbemClassObject** apObjects);

};

#endif // !defined(AFX_EventConsumerSink_H__74163953_94EA_4C6E_AD48_BAE847581B61__INCLUDED_)
