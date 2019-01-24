
WMIEventConsumerProvps.dll: dlldata.obj WMIEventConsumerProv_p.obj WMIEventConsumerProv_i.obj
	link /dll /out:WMIEventConsumerProvps.dll /def:WMIEventConsumerProvps.def /entry:DllMain dlldata.obj WMIEventConsumerProv_p.obj WMIEventConsumerProv_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del WMIEventConsumerProvps.dll
	@del WMIEventConsumerProvps.lib
	@del WMIEventConsumerProvps.exp
	@del dlldata.obj
	@del WMIEventConsumerProv_p.obj
	@del WMIEventConsumerProv_i.obj
