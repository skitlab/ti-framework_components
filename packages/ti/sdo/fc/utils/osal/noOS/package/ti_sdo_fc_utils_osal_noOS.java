/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y25
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_sdo_fc_utils_osal_noOS
{
    static final String VERS = "@(#) xdc-y25\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "xdc.runtime.knl");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sdo.fc.utils.osal.noOS", new Value.Obj("ti.sdo.fc.utils.osal.noOS", pkgP));
    }

    void Settings$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.Settings.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.Settings", new Value.Obj("ti.sdo.fc.utils.osal.noOS.Settings", po));
        pkgV.bind("Settings", vo);
        // decls 
    }

    void GateNull$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull", new Value.Obj("ti.sdo.fc.utils.osal.noOS.GateNull", po));
        pkgV.bind("GateNull", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$Object", new Proto.Obj());
        Object objP = om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$Params", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Params", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", new Proto.Str(po, false));
        om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Handle", insP);
        if (isROV) {
            om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        }//isROV
    }

    void GateMPNull$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull", new Value.Obj("ti.sdo.fc.utils.osal.noOS.GateMPNull", po));
        pkgV.bind("GateMPNull", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Object", new Proto.Obj());
        Object objP = om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Params", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Params", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", new Proto.Str(po, false));
        om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Handle", insP);
        if (isROV) {
            om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        }//isROV
    }

    void SemThreadNull$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull", new Value.Obj("ti.sdo.fc.utils.osal.noOS.SemThreadNull", po));
        pkgV.bind("SemThreadNull", vo);
        // decls 
        om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.PendStatus", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus", "ti.sdo.fc.utils.osal.noOS"));
        om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Mode", om.findStrict("xdc.runtime.knl.ISemaphore.Mode", "ti.sdo.fc.utils.osal.noOS"));
        spo = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Object", new Proto.Obj());
        Object objP = om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Params", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Params", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", new Proto.Str(po, false));
        om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Handle", insP);
        if (isROV) {
            om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        }//isROV
    }

    void SemProcessNull$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull", new Value.Obj("ti.sdo.fc.utils.osal.noOS.SemProcessNull", po));
        pkgV.bind("SemProcessNull", vo);
        // decls 
        om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.PendStatus", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus", "ti.sdo.fc.utils.osal.noOS"));
        om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Mode", om.findStrict("xdc.runtime.knl.ISemaphore.Mode", "ti.sdo.fc.utils.osal.noOS"));
        spo = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Object", new Proto.Obj());
        Object objP = om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Params", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Params", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Instance_State", new Proto.Obj());
        om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", new Proto.Str(po, false));
        om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Handle", insP);
        if (isROV) {
            om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        }//isROV
    }

    void Settings$$CONSTS()
    {
        // module Settings
    }

    void GateNull$$CONSTS()
    {
        // module GateNull
        om.bind("ti.sdo.fc.utils.osal.noOS.GateNull.query", new Extern("ti_sdo_fc_utils_osal_noOS_GateNull_query__E", "xdc_Bool(*)(xdc_Int)", true, false));
    }

    void GateMPNull$$CONSTS()
    {
        // module GateMPNull
        om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull.query", new Extern("ti_sdo_fc_utils_osal_noOS_GateMPNull_query__E", "xdc_Bool(*)(xdc_Int)", true, false));
    }

    void SemThreadNull$$CONSTS()
    {
        // module SemThreadNull
    }

    void SemProcessNull$$CONSTS()
    {
        // module SemProcessNull
    }

    void Settings$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void GateNull$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$GateNull$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.sdo.fc.utils.osal.noOS.GateNull.create() called before xdc.useModule('ti.sdo.fc.utils.osal.noOS.GateNull')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$create", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Module", "ti.sdo.fc.utils.osal.noOS"), om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance", "ti.sdo.fc.utils.osal.noOS"), 1, 0, false));
                        fxn.addArg(0, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$GateNull$$create = function( __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull'];\n");
                sb.append("var __inst = xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.sdo.fc.utils.osal.noOS']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, []);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$construct", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Module", "ti.sdo.fc.utils.osal.noOS"), null, 2, 0, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Object", "ti.sdo.fc.utils.osal.noOS"), null);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$GateNull$$construct = function( __obj, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void GateMPNull$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$GateMPNull$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.sdo.fc.utils.osal.noOS.GateMPNull.create() called before xdc.useModule('ti.sdo.fc.utils.osal.noOS.GateMPNull')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$create", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Module", "ti.sdo.fc.utils.osal.noOS"), om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance", "ti.sdo.fc.utils.osal.noOS"), 1, 0, false));
                        fxn.addArg(0, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$GateMPNull$$create = function( __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull'];\n");
                sb.append("var __inst = xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.sdo.fc.utils.osal.noOS']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, []);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$construct", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Module", "ti.sdo.fc.utils.osal.noOS"), null, 2, 0, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Object", "ti.sdo.fc.utils.osal.noOS"), null);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$GateMPNull$$construct = function( __obj, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void SemThreadNull$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$SemThreadNull$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.sdo.fc.utils.osal.noOS.SemThreadNull.create() called before xdc.useModule('ti.sdo.fc.utils.osal.noOS.SemThreadNull')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst.$args.count, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$create", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Module", "ti.sdo.fc.utils.osal.noOS"), om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance", "ti.sdo.fc.utils.osal.noOS"), 2, 1, false));
                        fxn.addArg(0, "count", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$SemThreadNull$$create = function( count, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull'];\n");
                sb.append("var __inst = xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.sdo.fc.utils.osal.noOS']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {count:count});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, [count]);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$construct", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Module", "ti.sdo.fc.utils.osal.noOS"), null, 3, 1, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Object", "ti.sdo.fc.utils.osal.noOS"), null);
                        fxn.addArg(1, "count", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(2, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$SemThreadNull$$construct = function( __obj, count, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {count:count});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void SemProcessNull$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$SemProcessNull$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.sdo.fc.utils.osal.noOS.SemProcessNull.create() called before xdc.useModule('ti.sdo.fc.utils.osal.noOS.SemProcessNull')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst.$args.count, inst.$args.key, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$create", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Module", "ti.sdo.fc.utils.osal.noOS"), om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance", "ti.sdo.fc.utils.osal.noOS"), 3, 2, false));
                        fxn.addArg(0, "count", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(1, "key", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(2, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$SemProcessNull$$create = function( count, key, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull'];\n");
                sb.append("var __inst = xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.sdo.fc.utils.osal.noOS']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {count:count, key:key});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, [count, key]);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$construct", new Proto.Fxn(om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Module", "ti.sdo.fc.utils.osal.noOS"), null, 4, 2, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Object", "ti.sdo.fc.utils.osal.noOS"), null);
                        fxn.addArg(1, "count", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(2, "key", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(3, "__params", (Proto)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Params", "ti.sdo.fc.utils.osal.noOS"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sdo$fc$utils$osal$noOS$SemProcessNull$$construct = function( __obj, count, key, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {count:count, key:key});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void Settings$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void GateNull$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void GateMPNull$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void SemThreadNull$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void SemProcessNull$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Settings$$SIZES()
    {
    }

    void GateNull$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", "ti.sdo.fc.utils.osal.noOS");
        sizes.clear();
        sizes.add(Global.newArray("__fxns", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void GateMPNull$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", "ti.sdo.fc.utils.osal.noOS");
        sizes.clear();
        sizes.add(Global.newArray("__fxns", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void SemThreadNull$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", "ti.sdo.fc.utils.osal.noOS");
        sizes.clear();
        sizes.add(Global.newArray("__fxns", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void SemProcessNull$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", "ti.sdo.fc.utils.osal.noOS");
        sizes.clear();
        sizes.add(Global.newArray("__fxns", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void Settings$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/fc/utils/osal/noOS/Settings.xs");
        om.bind("ti.sdo.fc.utils.osal.noOS.Settings$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.Settings.Module", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.Settings.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.Settings$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.Settings$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.Settings$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
    }

    void GateNull$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/fc/utils/osal/noOS/GateNull.xs");
        om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Module", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateNull.Module", om.findStrict("xdc.runtime.knl.IGateThreadSupport.Module", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("Q_BLOCKING", Proto.Elm.newCNum("(xdc_Int)"), 1L, "rh");
                po.addFld("Q_PREEMPTING", Proto.Elm.newCNum("(xdc_Int)"), 2L, "rh");
        if (isCFG) {
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$create", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$GateNull$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$construct", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$GateNull$$construct"));
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$static$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateNull$$instance$static$init", true);
        if (fxn != null) po.addFxn("instance$static$init", $$T_Met, fxn);
                fxn = Global.get(cap, "queryMeta");
                if (fxn != null) po.addFxn("queryMeta", (Proto.Fxn)om.findStrict("xdc.runtime.IGateProvider$$queryMeta", "ti.sdo.fc.utils.osal.noOS"), fxn);
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateNull.Instance", om.findStrict("xdc.runtime.knl.IGateThreadSupport.Instance", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("Q_BLOCKING", Proto.Elm.newCNum("(xdc_Int)"), 1L, "rh");
                po.addFld("Q_PREEMPTING", Proto.Elm.newCNum("(xdc_Int)"), 2L, "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Params", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateNull.Params", om.findStrict("xdc.runtime.knl.IGateThreadSupport$$Params", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("Q_BLOCKING", Proto.Elm.newCNum("(xdc_Int)"), 1L, "rh");
                po.addFld("Q_PREEMPTING", Proto.Elm.newCNum("(xdc_Int)"), 2L, "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Object", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        // struct GateNull.Instance_State
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", null);
        po.addFld("$hostonly", $$T_Num, 0, "r");
    }

    void GateMPNull$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/fc/utils/osal/noOS/GateMPNull.xs");
        om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Module", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateMPNull.Module", om.findStrict("xdc.runtime.knl.IGateProcessSupport.Module", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("Q_BLOCKING", Proto.Elm.newCNum("(xdc_Int)"), 1L, "rh");
                po.addFld("Q_PREEMPTING", Proto.Elm.newCNum("(xdc_Int)"), 2L, "rh");
                po.addFld("GETREFCOUNT_FAILED", Proto.Elm.newCNum("(xdc_Int)"), Global.eval("-1"), "rh");
        if (isCFG) {
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$create", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$GateMPNull$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$construct", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$GateMPNull$$construct"));
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$static$init");
        if (fxn != null) om.bind("ti.sdo.fc.utils.osal.noOS.GateMPNull$$instance$static$init", true);
        if (fxn != null) po.addFxn("instance$static$init", $$T_Met, fxn);
                fxn = Global.get(cap, "queryMeta");
                if (fxn != null) po.addFxn("queryMeta", (Proto.Fxn)om.findStrict("xdc.runtime.IGateProvider$$queryMeta", "ti.sdo.fc.utils.osal.noOS"), fxn);
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance", om.findStrict("xdc.runtime.knl.IGateProcessSupport.Instance", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("Q_BLOCKING", Proto.Elm.newCNum("(xdc_Int)"), 1L, "rh");
                po.addFld("Q_PREEMPTING", Proto.Elm.newCNum("(xdc_Int)"), 2L, "rh");
                po.addFld("GETREFCOUNT_FAILED", Proto.Elm.newCNum("(xdc_Int)"), Global.eval("-1"), "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Params", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateMPNull.Params", om.findStrict("xdc.runtime.knl.IGateProcessSupport$$Params", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("Q_BLOCKING", Proto.Elm.newCNum("(xdc_Int)"), 1L, "rh");
                po.addFld("Q_PREEMPTING", Proto.Elm.newCNum("(xdc_Int)"), 2L, "rh");
                po.addFld("GETREFCOUNT_FAILED", Proto.Elm.newCNum("(xdc_Int)"), Global.eval("-1"), "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Object", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateMPNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        // struct GateMPNull.Instance_State
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", null);
        po.addFld("$hostonly", $$T_Num, 0, "r");
    }

    void SemThreadNull$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Module", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Module", om.findStrict("xdc.runtime.knl.ISemThreadSupport.Module", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("FOREVER", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("~(0)"), "rh");
        if (isCFG) {
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$create", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$SemThreadNull$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$construct", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$SemThreadNull$$construct"));
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance", om.findStrict("xdc.runtime.knl.ISemThreadSupport.Instance", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("FOREVER", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("~(0)"), "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Params", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Params", om.findStrict("xdc.runtime.knl.ISemThreadSupport$$Params", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("FOREVER", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("~(0)"), "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Object", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        // struct SemThreadNull.Instance_State
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", null);
        po.addFld("$hostonly", $$T_Num, 0, "r");
    }

    void SemProcessNull$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Module", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Module", om.findStrict("xdc.runtime.knl.ISemProcessSupport.Module", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("FOREVER", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("~(0)"), "rh");
        if (isCFG) {
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$create", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$SemProcessNull$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$construct", "ti.sdo.fc.utils.osal.noOS"), Global.get("ti$sdo$fc$utils$osal$noOS$SemProcessNull$$construct"));
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance", om.findStrict("xdc.runtime.knl.ISemProcessSupport.Instance", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("FOREVER", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("~(0)"), "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Params", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Params", om.findStrict("xdc.runtime.knl.ISemProcessSupport$$Params", "ti.sdo.fc.utils.osal.noOS"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("FOREVER", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("~(0)"), "rh");
        if (isCFG) {
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sdo.fc.utils.osal.noOS"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Object", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        // struct SemProcessNull.Instance_State
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.init("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", null);
        po.addFld("$hostonly", $$T_Num, 0, "r");
    }

    void Settings$$ROV()
    {
    }

    void GateNull$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.addFld("__fxns", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
    }

    void GateMPNull$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.addFld("__fxns", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
    }

    void SemThreadNull$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.addFld("__fxns", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
    }

    void SemProcessNull$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
        po.addFld("__fxns", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull$$Instance_State", "ti.sdo.fc.utils.osal.noOS");
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sdo.fc.utils.osal.noOS.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sdo.fc.utils.osal.noOS"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/fc/utils/osal/noOS/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.sdo.fc.utils.osal.noOS"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.sdo.fc.utils.osal.noOS"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.sdo.fc.utils.osal.noOS"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.sdo.fc.utils.osal.noOS"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.sdo.fc.utils.osal.noOS"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.sdo.fc.utils.osal.noOS"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.sdo.fc.utils.osal.noOS", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sdo.fc.utils.osal.noOS");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sdo.fc.utils.osal.noOS.");
        pkgV.bind("$vers", Global.newArray("1, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sdo.fc.utils.osal.noOS'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/debug/noOS.aem3',\n");
            sb.append("'lib/release/noOS.aem3',\n");
            sb.append("'lib/debug/noOS.ae674',\n");
            sb.append("'lib/release/noOS.ae674',\n");
            sb.append("'lib/debug/noOS.av5T',\n");
            sb.append("'lib/release/noOS.av5T',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/debug/noOS.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/noOS.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/debug/noOS.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/noOS.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/debug/noOS.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/release/noOS.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Settings$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.Settings", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.Settings.Module", "ti.sdo.fc.utils.osal.noOS");
        vo.init2(po, "ti.sdo.fc.utils.osal.noOS.Settings", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.fc.utils.osal.noOS.Settings$$capsule", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$package", om.findStrict("ti.sdo.fc.utils.osal.noOS", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.fc.utils.osal.noOS")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.fc.utils.osal.noOS.Settings$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("Settings", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Settings");
    }

    void GateNull$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Module", "ti.sdo.fc.utils.osal.noOS");
        vo.init2(po, "ti.sdo.fc.utils.osal.noOS.GateNull", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull$$capsule", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Params", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Params", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Params", "ti.sdo.fc.utils.osal.noOS")).newInstance());
        vo.bind("Handle", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Handle", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$package", om.findStrict("ti.sdo.fc.utils.osal.noOS", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.add(om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime");
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.fc.utils.osal.noOS")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
            vo.bind("__initObject", Global.get("ti$sdo$fc$utils$osal$noOS$GateNull$$__initObject"));
        }//isCFG
        vo.bind("query", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.query", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$$fxntab", Global.newArray("ti_sdo_fc_utils_osal_noOS_GateNull_Handle__label__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Module__startupDone__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Object__create__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Object__delete__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Object__destruct__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Object__get__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Object__first__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Object__next__E", "ti_sdo_fc_utils_osal_noOS_GateNull_Params__init__E", "ti_sdo_fc_utils_osal_noOS_GateNull_query__E", "ti_sdo_fc_utils_osal_noOS_GateNull_enter__E", "ti_sdo_fc_utils_osal_noOS_GateNull_leave__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Object", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "query", "entry", "%d", "exit", "%d"));
        loggables.add(Global.newObject("name", "enter", "entry", "%p", "exit", "%p"));
        loggables.add(Global.newObject("name", "leave", "entry", "%p, %p", "exit", ""));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("GateNull", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("GateNull");
    }

    void GateMPNull$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Module", "ti.sdo.fc.utils.osal.noOS");
        vo.init2(po, "ti.sdo.fc.utils.osal.noOS.GateMPNull", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull$$capsule", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Params", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Params", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Params", "ti.sdo.fc.utils.osal.noOS")).newInstance());
        vo.bind("Handle", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Handle", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$package", om.findStrict("ti.sdo.fc.utils.osal.noOS", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.add(om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime");
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.fc.utils.osal.noOS")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
            vo.bind("__initObject", Global.get("ti$sdo$fc$utils$osal$noOS$GateMPNull$$__initObject"));
        }//isCFG
        vo.bind("query", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.query", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$$fxntab", Global.newArray("ti_sdo_fc_utils_osal_noOS_GateMPNull_Handle__label__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Module__startupDone__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Object__create__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Object__delete__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Object__destruct__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Object__get__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Object__first__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Object__next__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_Params__init__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_query__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_enter__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_leave__E", "ti_sdo_fc_utils_osal_noOS_GateMPNull_getReferenceCount__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Object", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "query", "entry", "%d", "exit", "%d"));
        loggables.add(Global.newObject("name", "enter", "entry", "%p", "exit", "%p"));
        loggables.add(Global.newObject("name", "leave", "entry", "%p, %p", "exit", ""));
        loggables.add(Global.newObject("name", "getReferenceCount", "entry", "%p, %p", "exit", "%d"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("GateMPNull", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("GateMPNull");
    }

    void SemThreadNull$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Module", "ti.sdo.fc.utils.osal.noOS");
        vo.init2(po, "ti.sdo.fc.utils.osal.noOS.SemThreadNull", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", $$UNDEF);
        vo.bind("Instance", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Params", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Params", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Params", "ti.sdo.fc.utils.osal.noOS")).newInstance());
        vo.bind("Handle", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Handle", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$package", om.findStrict("ti.sdo.fc.utils.osal.noOS", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("PendStatus", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Mode", om.findStrict("xdc.runtime.knl.ISemaphore.Mode", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.add(om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PendStatus_ERROR", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus_ERROR", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PendStatus_TIMEOUT", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus_TIMEOUT", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PendStatus_SUCCESS", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus_SUCCESS", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Mode_COUNTING", om.findStrict("xdc.runtime.knl.ISemaphore.Mode_COUNTING", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Mode_BINARY", om.findStrict("xdc.runtime.knl.ISemaphore.Mode_BINARY", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.fc.utils.osal.noOS")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
            vo.bind("__initObject", Global.get("ti$sdo$fc$utils$osal$noOS$SemThreadNull$$__initObject"));
        }//isCFG
        vo.bind("$$fxntab", Global.newArray("ti_sdo_fc_utils_osal_noOS_SemThreadNull_Handle__label__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Module__startupDone__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__create__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__delete__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__destruct__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__get__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__first__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Object__next__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_Params__init__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_pend__E", "ti_sdo_fc_utils_osal_noOS_SemThreadNull_post__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Object", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "pend", "entry", "%p, 0x%x, %p", "exit", "%d"));
        loggables.add(Global.newObject("name", "post", "entry", "%p, %p", "exit", "%d"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("SemThreadNull", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("SemThreadNull");
    }

    void SemProcessNull$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull", "ti.sdo.fc.utils.osal.noOS");
        po = (Proto.Obj)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Module", "ti.sdo.fc.utils.osal.noOS");
        vo.init2(po, "ti.sdo.fc.utils.osal.noOS.SemProcessNull", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", $$UNDEF);
        vo.bind("Instance", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Params", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Params", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Params", "ti.sdo.fc.utils.osal.noOS")).newInstance());
        vo.bind("Handle", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Handle", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$package", om.findStrict("ti.sdo.fc.utils.osal.noOS", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("PendStatus", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Mode", om.findStrict("xdc.runtime.knl.ISemaphore.Mode", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        tdefs.add(om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PendStatus_ERROR", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus_ERROR", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PendStatus_TIMEOUT", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus_TIMEOUT", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("PendStatus_SUCCESS", om.findStrict("xdc.runtime.knl.ISemaphore.PendStatus_SUCCESS", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Mode_COUNTING", om.findStrict("xdc.runtime.knl.ISemaphore.Mode_COUNTING", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Mode_BINARY", om.findStrict("xdc.runtime.knl.ISemaphore.Mode_BINARY", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime.knl");
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.fc.utils.osal.noOS")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
            vo.bind("__initObject", Global.get("ti$sdo$fc$utils$osal$noOS$SemProcessNull$$__initObject"));
        }//isCFG
        vo.bind("$$fxntab", Global.newArray("ti_sdo_fc_utils_osal_noOS_SemProcessNull_Handle__label__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Module__startupDone__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Object__create__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Object__delete__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Object__destruct__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Object__get__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Object__first__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Object__next__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_Params__init__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_pend__E", "ti_sdo_fc_utils_osal_noOS_SemProcessNull_post__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Object", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("Instance_State", om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull.Instance_State", "ti.sdo.fc.utils.osal.noOS"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "pend", "entry", "%p, 0x%x, %p", "exit", "%d"));
        loggables.add(Global.newObject("name", "post", "entry", "%p, %p", "exit", "%d"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("SemProcessNull", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("SemProcessNull");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
            Object srcP = ((XScriptO)om.findStrict("xdc.runtime.IInstance", "ti.sdo.fc.utils.osal.noOS")).findStrict("PARAMS", "ti.sdo.fc.utils.osal.noOS");
            Scriptable dstP;

            dstP = (Scriptable)((XScriptO)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull", "ti.sdo.fc.utils.osal.noOS")).findStrict("PARAMS", "ti.sdo.fc.utils.osal.noOS");
            Global.put(dstP, "instance", srcP);
            dstP = (Scriptable)((XScriptO)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull", "ti.sdo.fc.utils.osal.noOS")).findStrict("PARAMS", "ti.sdo.fc.utils.osal.noOS");
            Global.put(dstP, "instance", srcP);
            dstP = (Scriptable)((XScriptO)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull", "ti.sdo.fc.utils.osal.noOS")).findStrict("PARAMS", "ti.sdo.fc.utils.osal.noOS");
            Global.put(dstP, "instance", srcP);
            dstP = (Scriptable)((XScriptO)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull", "ti.sdo.fc.utils.osal.noOS")).findStrict("PARAMS", "ti.sdo.fc.utils.osal.noOS");
            Global.put(dstP, "instance", srcP);
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.fc.utils.osal.noOS.Settings", "ti.sdo.fc.utils.osal.noOS"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateNull", "ti.sdo.fc.utils.osal.noOS"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.fc.utils.osal.noOS.GateMPNull", "ti.sdo.fc.utils.osal.noOS"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemThreadNull", "ti.sdo.fc.utils.osal.noOS"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.fc.utils.osal.noOS.SemProcessNull", "ti.sdo.fc.utils.osal.noOS"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sdo.fc.utils.osal.noOS.Settings")).bless();
        ((Value.Obj)om.getv("ti.sdo.fc.utils.osal.noOS.GateNull")).bless();
        ((Value.Obj)om.getv("ti.sdo.fc.utils.osal.noOS.GateMPNull")).bless();
        ((Value.Obj)om.getv("ti.sdo.fc.utils.osal.noOS.SemThreadNull")).bless();
        ((Value.Obj)om.getv("ti.sdo.fc.utils.osal.noOS.SemProcessNull")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sdo.fc.utils.osal.noOS")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        Settings$$OBJECTS();
        GateNull$$OBJECTS();
        GateMPNull$$OBJECTS();
        SemThreadNull$$OBJECTS();
        SemProcessNull$$OBJECTS();
        Settings$$CONSTS();
        GateNull$$CONSTS();
        GateMPNull$$CONSTS();
        SemThreadNull$$CONSTS();
        SemProcessNull$$CONSTS();
        Settings$$CREATES();
        GateNull$$CREATES();
        GateMPNull$$CREATES();
        SemThreadNull$$CREATES();
        SemProcessNull$$CREATES();
        Settings$$FUNCTIONS();
        GateNull$$FUNCTIONS();
        GateMPNull$$FUNCTIONS();
        SemThreadNull$$FUNCTIONS();
        SemProcessNull$$FUNCTIONS();
        Settings$$SIZES();
        GateNull$$SIZES();
        GateMPNull$$SIZES();
        SemThreadNull$$SIZES();
        SemProcessNull$$SIZES();
        Settings$$TYPES();
        GateNull$$TYPES();
        GateMPNull$$TYPES();
        SemThreadNull$$TYPES();
        SemProcessNull$$TYPES();
        if (isROV) {
            Settings$$ROV();
            GateNull$$ROV();
            GateMPNull$$ROV();
            SemThreadNull$$ROV();
            SemProcessNull$$ROV();
        }//isROV
        $$SINGLETONS();
        Settings$$SINGLETONS();
        GateNull$$SINGLETONS();
        GateMPNull$$SINGLETONS();
        SemThreadNull$$SINGLETONS();
        SemProcessNull$$SINGLETONS();
        $$INITIALIZATION();
    }
}
