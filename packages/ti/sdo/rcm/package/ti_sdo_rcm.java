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

public class ti_sdo_rcm
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
        pkgP = (Proto.Obj)om.bind("ti.sdo.rcm.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sdo.rcm", new Value.Obj("ti.sdo.rcm", pkgP));
    }

    void RcmClient$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.rcm.RcmClient.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.rcm.RcmClient", new Value.Obj("ti.sdo.rcm.RcmClient", po));
        pkgV.bind("RcmClient", vo);
        // decls 
    }

    void RcmServer$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.rcm.RcmServer.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.rcm.RcmServer", new Value.Obj("ti.sdo.rcm.RcmServer", po));
        pkgV.bind("RcmServer", vo);
        // decls 
    }

    void Settings$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.rcm.Settings.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.rcm.Settings", new Value.Obj("ti.sdo.rcm.Settings", po));
        pkgV.bind("Settings", vo);
        // decls 
        om.bind("ti.sdo.rcm.Settings.IpcSupport", new Proto.Enm("ti.sdo.rcm.Settings.IpcSupport"));
    }

    void RcmClient$$CONSTS()
    {
        // module RcmClient
    }

    void RcmServer$$CONSTS()
    {
        // module RcmServer
    }

    void Settings$$CONSTS()
    {
        // module Settings
        om.bind("ti.sdo.rcm.Settings.IpcSupport_ti_sdo_ipc", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.rcm.Settings.IpcSupport", "ti.sdo.rcm"), "ti.sdo.rcm.Settings.IpcSupport_ti_sdo_ipc", 0));
        om.bind("ti.sdo.rcm.Settings.IpcSupport_ti_syslink_ipc", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.sdo.rcm.Settings.IpcSupport", "ti.sdo.rcm"), "ti.sdo.rcm.Settings.IpcSupport_ti_syslink_ipc", 1));
    }

    void RcmClient$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void RcmServer$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void Settings$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void RcmClient$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void RcmServer$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Settings$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void RcmClient$$SIZES()
    {
    }

    void RcmServer$$SIZES()
    {
    }

    void Settings$$SIZES()
    {
    }

    void RcmClient$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/rcm/RcmClient.xs");
        om.bind("ti.sdo.rcm.RcmClient$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.rcm.RcmClient.Module", "ti.sdo.rcm");
        po.init("ti.sdo.rcm.RcmClient.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.rcm.RcmClient$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.rcm.RcmClient$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.rcm.RcmClient$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
    }

    void RcmServer$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/rcm/RcmServer.xs");
        om.bind("ti.sdo.rcm.RcmServer$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.rcm.RcmServer.Module", "ti.sdo.rcm");
        po.init("ti.sdo.rcm.RcmServer.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.rcm.RcmServer$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.rcm.RcmServer$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.rcm.RcmServer$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
    }

    void Settings$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/rcm/Settings.xs");
        om.bind("ti.sdo.rcm.Settings$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.rcm.Settings.Module", "ti.sdo.rcm");
        po.init("ti.sdo.rcm.Settings.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("ipc", (Proto)om.findStrict("ti.sdo.rcm.Settings.IpcSupport", "ti.sdo.rcm"), $$UNDEF, "wh");
        po.addFld("loadStrings", $$T_Bool, true, "wh");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.rcm.Settings$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.rcm.Settings$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.rcm.Settings$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
    }

    void RcmClient$$ROV()
    {
    }

    void RcmServer$$ROV()
    {
    }

    void Settings$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sdo.rcm.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sdo.rcm"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/rcm/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.sdo.rcm"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.sdo.rcm"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.sdo.rcm"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.sdo.rcm"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.sdo.rcm"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.sdo.rcm"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.sdo.rcm", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sdo.rcm");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sdo.rcm.");
        pkgV.bind("$vers", Global.newArray("2, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sdo.rcm'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/debug/rcm.aem3',\n");
            sb.append("'lib/release/rcm.aem3',\n");
            sb.append("'lib/debug/rcm.ae674',\n");
            sb.append("'lib/release/rcm.ae674',\n");
            sb.append("'lib/debug/rcm_syslink.av5T',\n");
            sb.append("'lib/release/rcm_syslink.av5T',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/debug/rcm.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/rcm.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/debug/rcm.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/rcm.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/debug/rcm_syslink.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
            sb.append("['lib/release/rcm_syslink.av5T', {target: 'gnu.targets.arm.GCArmv5T', suffix: 'v5T'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void RcmClient$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.rcm.RcmClient", "ti.sdo.rcm");
        po = (Proto.Obj)om.findStrict("ti.sdo.rcm.RcmClient.Module", "ti.sdo.rcm");
        vo.init2(po, "ti.sdo.rcm.RcmClient", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.rcm.RcmClient$$capsule", "ti.sdo.rcm"));
        vo.bind("$package", om.findStrict("ti.sdo.rcm", "ti.sdo.rcm"));
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
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.rcm")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.rcm.RcmClient$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("RcmClient", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("RcmClient");
    }

    void RcmServer$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.rcm.RcmServer", "ti.sdo.rcm");
        po = (Proto.Obj)om.findStrict("ti.sdo.rcm.RcmServer.Module", "ti.sdo.rcm");
        vo.init2(po, "ti.sdo.rcm.RcmServer", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.rcm.RcmServer$$capsule", "ti.sdo.rcm"));
        vo.bind("$package", om.findStrict("ti.sdo.rcm", "ti.sdo.rcm"));
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
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.rcm")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.rcm.RcmServer$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("RcmServer", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("RcmServer");
    }

    void Settings$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sdo.rcm.Settings", "ti.sdo.rcm");
        po = (Proto.Obj)om.findStrict("ti.sdo.rcm.Settings.Module", "ti.sdo.rcm");
        vo.init2(po, "ti.sdo.rcm.Settings", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.rcm.Settings$$capsule", "ti.sdo.rcm"));
        vo.bind("$package", om.findStrict("ti.sdo.rcm", "ti.sdo.rcm"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("IpcSupport", om.findStrict("ti.sdo.rcm.Settings.IpcSupport", "ti.sdo.rcm"));
        vo.bind("IpcSupport_ti_sdo_ipc", om.findStrict("ti.sdo.rcm.Settings.IpcSupport_ti_sdo_ipc", "ti.sdo.rcm"));
        vo.bind("IpcSupport_ti_syslink_ipc", om.findStrict("ti.sdo.rcm.Settings.IpcSupport_ti_syslink_ipc", "ti.sdo.rcm"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.rcm")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.rcm.Settings$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("Settings", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Settings");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.rcm.RcmClient", "ti.sdo.rcm"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.rcm.RcmServer", "ti.sdo.rcm"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.rcm.Settings", "ti.sdo.rcm"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sdo.rcm.RcmClient")).bless();
        ((Value.Obj)om.getv("ti.sdo.rcm.RcmServer")).bless();
        ((Value.Obj)om.getv("ti.sdo.rcm.Settings")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sdo.rcm")).add(pkgV);
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
        RcmClient$$OBJECTS();
        RcmServer$$OBJECTS();
        Settings$$OBJECTS();
        RcmClient$$CONSTS();
        RcmServer$$CONSTS();
        Settings$$CONSTS();
        RcmClient$$CREATES();
        RcmServer$$CREATES();
        Settings$$CREATES();
        RcmClient$$FUNCTIONS();
        RcmServer$$FUNCTIONS();
        Settings$$FUNCTIONS();
        RcmClient$$SIZES();
        RcmServer$$SIZES();
        Settings$$SIZES();
        RcmClient$$TYPES();
        RcmServer$$TYPES();
        Settings$$TYPES();
        if (isROV) {
            RcmClient$$ROV();
            RcmServer$$ROV();
            Settings$$ROV();
        }//isROV
        $$SINGLETONS();
        RcmClient$$SINGLETONS();
        RcmServer$$SINGLETONS();
        Settings$$SINGLETONS();
        $$INITIALIZATION();
    }
}
