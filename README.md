# c0gnito-mitigation
Two methods of mitigating c0gnitos authentication security implementations

# How it works?
The first method is a dummy dll that exports the same primitives as the production module for c0gnito.cc; the issue with this method of emulating their authentication is
it can easily be avoided by integrity checking the c0gnito module when loading it which can be an issue for us. Another issue is some people ship their product with the module 
contained within their image preventing one from just swapping the modules. The solution to would have been pointer swapping the imports to the process but that can screwed over by
protection such as VMP. So by simply locating the export address to the authentication primitive we can simply place a jmp instruction to own function (detour hooking) and do what 
ever we want.

![](https://github.com/j7cb1/c0gnito-mitigation/blob/main/readme/Capture.PNG)

