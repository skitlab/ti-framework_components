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

public class ti_sdo_opencl
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
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.sdo.opencl.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sdo.opencl", new Value.Obj("ti.sdo.opencl", pkgP));
    }

    void OpenCL$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.opencl.OpenCL.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.opencl.OpenCL", new Value.Obj("ti.sdo.opencl.OpenCL", po));
        pkgV.bind("OpenCL", vo);
        // decls 
    }

    void ComputeDevice$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.opencl.ComputeDevice.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.opencl.ComputeDevice", new Value.Obj("ti.sdo.opencl.ComputeDevice", po));
        pkgV.bind("ComputeDevice", vo);
        // decls 
        om.bind("ti.sdo.opencl.ComputeDevice.ArgType", new Proto.Enm("ti.sdo.opencl.ComputeDevice.ArgType"));
        spo = (Proto.Obj)om.bind("ti.sdo.opencl.ComputeDevice$$FxnDesc", new Proto.Obj());
        om.bind("ti.sdo.opencl.ComputeDevice.FxnDesc", new Proto.Str(spo, true));
        spo = (Proto.Obj)om.bind("ti.sdo.opencl.ComputeDevice$$Unit", new Proto.Obj());
        om.bind("ti.sdo.opencl.ComputeDevice.Unit", new Proto.Str(spo, true));
    }

    void OpenCL$$CONSTS()
    {
        // module OpenCL
    }

    void ComputeDevice$$CONSTS()
    {
        // module ComputeDevice
        om.bind("ti.sdo.opencl.ComputeDevice.ArgType_Int", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType", "ti.sdo.opencl"), "ti.sdo.opencl.ComputeDevice.ArgType_Int", 0));
        om.bind("ti.sdo.opencl.ComputeDevice.ArgType_LocalPtr", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType", "ti.sdo.opencl"), "ti.sdo.opencl.ComputeDevice.ArgType_LocalPtr", 1));
        om.bind("ti.sdo.opencl.ComputeDevice.ArgType_GlobalPtr", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType", "ti.sdo.opencl"), "ti.sdo.opencl.ComputeDevice.ArgType_GlobalPtr", 2));
        om.bind("ti.sdo.opencl.ComputeDevice.ArgType_SrPtr", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType", "ti.sdo.opencl"), "ti.sdo.opencl.ComputeDevice.ArgType_SrPtr", 3));
    }

    void OpenCL$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void ComputeDevice$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void OpenCL$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void ComputeDevice$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void OpenCL$$SIZES()
    {
    }

    void ComputeDevice$$SIZES()
    {
    }

    void OpenCL$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        po = (Proto.Obj)om.findStrict("ti.sdo.opencl.OpenCL.Module", "ti.sdo.opencl");
        po.init("ti.sdo.opencl.OpenCL.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
    }

    void ComputeDevice$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/opencl/ComputeDevice.xs");
        om.bind("ti.sdo.opencl.ComputeDevice$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.opencl.ComputeDevice.Module", "ti.sdo.opencl");
        po.init("ti.sdo.opencl.ComputeDevice.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("units", new Proto.Arr((Proto)om.findStrict("ti.sdo.opencl.ComputeDevice.Unit", "ti.sdo.opencl"), false), $$DEFAULT, "wh");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.opencl.ComputeDevice$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.opencl.ComputeDevice$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.opencl.ComputeDevice$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        // struct ComputeDevice.FxnDesc
        po = (Proto.Obj)om.findStrict("ti.sdo.opencl.ComputeDevice$$FxnDesc", "ti.sdo.opencl");
        po.init("ti.sdo.opencl.ComputeDevice.FxnDesc", null);
                po.addFld("$hostonly", $$T_Num, 1, "r");
                po.addFld("name", $$T_Str, $$UNDEF, "w");
                po.addFld("addr", new Proto.Adr("xdc_Fxn", "Pf"), $$UNDEF, "w");
                po.addFld("numArgs", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF, "w");
                po.addFld("args", new Proto.Arr((Proto)om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType", "ti.sdo.opencl"), false), $$DEFAULT, "w");
        // struct ComputeDevice.Unit
        po = (Proto.Obj)om.findStrict("ti.sdo.opencl.ComputeDevice$$Unit", "ti.sdo.opencl");
        po.init("ti.sdo.opencl.ComputeDevice.Unit", null);
                po.addFld("$hostonly", $$T_Num, 1, "r");
                po.addFld("initFxn", $$T_Str, $$UNDEF, "w");
                po.addFld("exitFxn", $$T_Str, $$UNDEF, "w");
                po.addFld("fxnTab", new Proto.Arr((Proto)om.findStrict("ti.sdo.opencl.ComputeDevice.FxnDesc", "ti.sdo.opencl"), false), $$DEFAULT, "w");
    }

    void OpenCL$$ROV()
    {
    }

    void ComputeDevice$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sdo.opencl.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sdo.opencl"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/opencl/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.sdo.opencl"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.sdo.opencl"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.sdo.opencl"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.sdo.opencl"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.sdo.opencl"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.sdo.opencl"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.sdo.opencl", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sdo.opencl");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sdo.opencl.");
        pkgV.bind("$vers", Global.newArray("1, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sdo.opencl'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/debug/opencl_api.aem3',\n");
            sb.append("'lib/release/opencl_api.aem3',\n");
            sb.append("'lib/debug/opencl_api.ae674',\n");
            sb.append("'lib/release/opencl_api.ae674',\n");
            sb.append("'lib/debug/opencl_api_syslink.av5T',\n");
            sb.append("'lib/release/opencl_api_syslink.av5T',\n");
            sb.append("'lib/debug/opencl_runtime.aem3',\n");
            sb.append("'lib/release/opencl_runtime.aem3',\n");
            sb.append("'lib/debug/opencl_runtime.ae674',\n");
            sb.append("'lib/release/opencl_runtime.ae674',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/debug/opencl_api.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/opencl_api.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/debug/opencl_api.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/opencl_api.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/debug/opencl_api_syslink.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/release/opencl_api_syslink.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/debug/opencl_runtime.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/opencl_runtime.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/debug/opencl_runtime.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/opencl_runtime.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void OpenCL$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.opencl.OpenCL", "ti.sdo.opencl");
        po = (Proto.Obj)om.findStrict("ti.sdo.opencl.OpenCL.Module", "ti.sdo.opencl");
        vo.init2(po, "ti.sdo.opencl.OpenCL", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", $$UNDEF);
        vo.bind("$package", om.findStrict("ti.sdo.opencl", "ti.sdo.opencl"));
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
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.opencl")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.opencl.OpenCL$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("OpenCL", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("OpenCL");
    }

    void ComputeDevice$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.opencl.ComputeDevice", "ti.sdo.opencl");
        po = (Proto.Obj)om.findStrict("ti.sdo.opencl.ComputeDevice.Module", "ti.sdo.opencl");
        vo.init2(po, "ti.sdo.opencl.ComputeDevice", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.opencl.ComputeDevice$$capsule", "ti.sdo.opencl"));
        vo.bind("$package", om.findStrict("ti.sdo.opencl", "ti.sdo.opencl"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("ArgType", om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType", "ti.sdo.opencl"));
        vo.bind("FxnDesc", om.findStrict("ti.sdo.opencl.ComputeDevice.FxnDesc", "ti.sdo.opencl"));
        tdefs.add(om.findStrict("ti.sdo.opencl.ComputeDevice.FxnDesc", "ti.sdo.opencl"));
        vo.bind("Unit", om.findStrict("ti.sdo.opencl.ComputeDevice.Unit", "ti.sdo.opencl"));
        tdefs.add(om.findStrict("ti.sdo.opencl.ComputeDevice.Unit", "ti.sdo.opencl"));
        vo.bind("ArgType_Int", om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType_Int", "ti.sdo.opencl"));
        vo.bind("ArgType_LocalPtr", om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType_LocalPtr", "ti.sdo.opencl"));
        vo.bind("ArgType_GlobalPtr", om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType_GlobalPtr", "ti.sdo.opencl"));
        vo.bind("ArgType_SrPtr", om.findStrict("ti.sdo.opencl.ComputeDevice.ArgType_SrPtr", "ti.sdo.opencl"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.opencl")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.opencl.ComputeDevice$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.setElem("", "./ComputeDevice.xdt");
        atmap.seal("length");
        vo.bind("TEMPLATE$", "./ComputeDevice.xdt");
        pkgV.bind("ComputeDevice", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("ComputeDevice");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.opencl.OpenCL", "ti.sdo.opencl"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.opencl.ComputeDevice", "ti.sdo.opencl"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sdo.opencl.OpenCL")).bless();
        ((Value.Obj)om.getv("ti.sdo.opencl.ComputeDevice")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sdo.opencl")).add(pkgV);
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
        OpenCL$$OBJECTS();
        ComputeDevice$$OBJECTS();
        OpenCL$$CONSTS();
        ComputeDevice$$CONSTS();
        OpenCL$$CREATES();
        ComputeDevice$$CREATES();
        OpenCL$$FUNCTIONS();
        ComputeDevice$$FUNCTIONS();
        OpenCL$$SIZES();
        ComputeDevice$$SIZES();
        OpenCL$$TYPES();
        ComputeDevice$$TYPES();
        if (isROV) {
            OpenCL$$ROV();
            ComputeDevice$$ROV();
        }//isROV
        $$SINGLETONS();
        OpenCL$$SINGLETONS();
        ComputeDevice$$SINGLETONS();
        $$INITIALIZATION();
    }
}
