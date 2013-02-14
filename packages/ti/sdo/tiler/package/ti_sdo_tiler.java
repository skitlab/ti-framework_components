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

public class ti_sdo_tiler
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
        pkgP = (Proto.Obj)om.bind("ti.sdo.tiler.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sdo.tiler", new Value.Obj("ti.sdo.tiler", pkgP));
    }

    void Settings$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.tiler.Settings.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.tiler.Settings", new Value.Obj("ti.sdo.tiler.Settings", po));
        pkgV.bind("Settings", vo);
        // decls 
        om.bind("ti.sdo.tiler.Settings.TilerLib", new Proto.Enm("ti.sdo.tiler.Settings.TilerLib"));
        om.bind("ti.sdo.tiler.Settings.OperSys", new Proto.Enm("ti.sdo.tiler.Settings.OperSys"));
    }

    void Settings$$CONSTS()
    {
        // module Settings
        om.bind("ti.sdo.tiler.Settings.TilerLib_Stub", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.tiler.Settings.TilerLib", "ti.sdo.tiler"), "ti.sdo.tiler.Settings.TilerLib_Stub", 0));
        om.bind("ti.sdo.tiler.Settings.TilerLib_Skel", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.tiler.Settings.TilerLib", "ti.sdo.tiler"), "ti.sdo.tiler.Settings.TilerLib_Skel", 1));
        om.bind("ti.sdo.tiler.Settings.TilerLib_Direct", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.tiler.Settings.TilerLib", "ti.sdo.tiler"), "ti.sdo.tiler.Settings.TilerLib_Direct", 2));
        om.bind("ti.sdo.tiler.Settings.OperSys_Linux", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.tiler.Settings.OperSys", "ti.sdo.tiler"), "ti.sdo.tiler.Settings.OperSys_Linux", 0));
        om.bind("ti.sdo.tiler.Settings.OperSys_WinCE", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.tiler.Settings.OperSys", "ti.sdo.tiler"), "ti.sdo.tiler.Settings.OperSys_WinCE", 1));
        om.bind("ti.sdo.tiler.Settings.OperSys_RTOS", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.tiler.Settings.OperSys", "ti.sdo.tiler"), "ti.sdo.tiler.Settings.OperSys_RTOS", 2));
    }

    void Settings$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void Settings$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Settings$$SIZES()
    {
    }

    void Settings$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/tiler/Settings.xs");
        om.bind("ti.sdo.tiler.Settings$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.tiler.Settings.Module", "ti.sdo.tiler");
        po.init("ti.sdo.tiler.Settings.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("heapId", Proto.Elm.newCNum("(xdc_UInt16)"), $$UNDEF, "wh");
        po.addFld("tilerDaemonName", $$T_Str, null, "wh");
        po.addFld("tilerLib", (Proto)om.findStrict("ti.sdo.tiler.Settings.TilerLib", "ti.sdo.tiler"), $$UNDEF, "wh");
        po.addFld("tilerManagerOS", (Proto)om.findStrict("ti.sdo.tiler.Settings.OperSys", "ti.sdo.tiler"), $$UNDEF, "wh");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.tiler.Settings$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.tiler.Settings$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.tiler.Settings$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
    }

    void Settings$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sdo.tiler.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sdo.tiler"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/tiler/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.sdo.tiler"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.sdo.tiler"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.sdo.tiler"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.sdo.tiler"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.sdo.tiler"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.sdo.tiler"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.sdo.tiler", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sdo.tiler");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sdo.tiler.");
        pkgV.bind("$vers", Global.newArray("1, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sdo.tiler'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/debug/tiler_stub.aem3',\n");
            sb.append("'lib/release/tiler_stub.aem3',\n");
            sb.append("'lib/debug/tiler_stub.ae674',\n");
            sb.append("'lib/release/tiler_stub.ae674',\n");
            sb.append("'lib/debug/tiler_skel.av5T',\n");
            sb.append("'lib/release/tiler_skel.av5T',\n");
            sb.append("'lib/debug/tiler_linux.av5T',\n");
            sb.append("'lib/release/tiler_linux.av5T',\n");
            sb.append("'lib/debug/tiler_rtos.aem3',\n");
            sb.append("'lib/release/tiler_rtos.aem3',\n");
            sb.append("'lib/debug/tiler_rtos.ae674',\n");
            sb.append("'lib/release/tiler_rtos.ae674',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/debug/tiler_stub.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/tiler_stub.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/debug/tiler_stub.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/tiler_stub.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/debug/tiler_skel.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/release/tiler_skel.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/debug/tiler_linux.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/release/tiler_linux.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/debug/tiler_rtos.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/tiler_rtos.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/debug/tiler_rtos.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/tiler_rtos.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Settings$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.tiler.Settings", "ti.sdo.tiler");
        po = (Proto.Obj)om.findStrict("ti.sdo.tiler.Settings.Module", "ti.sdo.tiler");
        vo.init2(po, "ti.sdo.tiler.Settings", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.tiler.Settings$$capsule", "ti.sdo.tiler"));
        vo.bind("$package", om.findStrict("ti.sdo.tiler", "ti.sdo.tiler"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("TilerLib", om.findStrict("ti.sdo.tiler.Settings.TilerLib", "ti.sdo.tiler"));
        vo.bind("OperSys", om.findStrict("ti.sdo.tiler.Settings.OperSys", "ti.sdo.tiler"));
        vo.bind("TilerLib_Stub", om.findStrict("ti.sdo.tiler.Settings.TilerLib_Stub", "ti.sdo.tiler"));
        vo.bind("TilerLib_Skel", om.findStrict("ti.sdo.tiler.Settings.TilerLib_Skel", "ti.sdo.tiler"));
        vo.bind("TilerLib_Direct", om.findStrict("ti.sdo.tiler.Settings.TilerLib_Direct", "ti.sdo.tiler"));
        vo.bind("OperSys_Linux", om.findStrict("ti.sdo.tiler.Settings.OperSys_Linux", "ti.sdo.tiler"));
        vo.bind("OperSys_WinCE", om.findStrict("ti.sdo.tiler.Settings.OperSys_WinCE", "ti.sdo.tiler"));
        vo.bind("OperSys_RTOS", om.findStrict("ti.sdo.tiler.Settings.OperSys_RTOS", "ti.sdo.tiler"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.tiler")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.tiler.Settings$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.setElem("", "./Settings.xdt");
        atmap.seal("length");
        vo.bind("TEMPLATE$", "./Settings.xdt");
        pkgV.bind("Settings", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Settings");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.tiler.Settings", "ti.sdo.tiler"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sdo.tiler.Settings")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sdo.tiler")).add(pkgV);
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
        Settings$$CONSTS();
        Settings$$CREATES();
        Settings$$FUNCTIONS();
        Settings$$SIZES();
        Settings$$TYPES();
        if (isROV) {
            Settings$$ROV();
        }//isROV
        $$SINGLETONS();
        Settings$$SINGLETONS();
        $$INITIALIZATION();
    }
}
