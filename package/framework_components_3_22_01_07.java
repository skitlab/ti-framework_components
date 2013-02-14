/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y21
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class framework_components_3_22_01_07
{
    static final String VERS = "@(#) xdc-y21\n";

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
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.global");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.dskt2");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.dman3");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.acpy3");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ecpy");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.utils");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.utils.api");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.utils.gtinfra");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.utils.osal");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.utils.osalsupport");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.utils.osal.noOS");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.memutils");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.examples");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.examples.buildutils");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.examples.dmaXfer");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.examples.dmaxferchecker");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.bufres");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.edma3chan");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.hdvicp");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.nullresource");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.sdma");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.shmbuf");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.tiledmemory");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.vicp");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.edma3");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.scpy");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.hdintc");
        Global.callFxn("loadPackage", xdcO, "khronos.opencl");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.opencl");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.opencl.platforms.c6472");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.opencl.examples");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.opencl.examples.autoviz");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.opencl.examples.hello");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.utils.trace");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.rcm");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.tiler");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.dskt2.examples");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.bufres");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.bufres_yield");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.dmaXferScratch");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.dummyEdma3");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.hdvicp");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.nullresource.test");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.plugin");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.scratchEdma3");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.sdma");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.shmbuf");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.vicp");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.rman.examples.hdvicp.hdvicp2");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.dman3.examples.fastcopy");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.examples.codecs.auddec1");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.examples.codecs.edmacodec1");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.examples.codecs.idma3codec1");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.examples.codecs.template");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.fc.ires.examples.codecs.universal_dma");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.rcm.examples.appcfg");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.rcm.examples.hello");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.rcm.examples.minidist.linux.osal");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.rcm.examples.minidist.linux.client");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.rcm.examples.minidist.linux.server");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.tiler.examples.remote");
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("framework_components_3_22_01_07.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("framework_components_3_22_01_07", new Value.Obj("framework_components_3_22_01_07", pkgP));
    }

    void $$SINGLETONS()
    {
        pkgP.init("framework_components_3_22_01_07.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "framework_components_3_22_01_07"));
        pkgP.bind("$capsule", $$UNDEF);
        pkgV.init2(pkgP, "framework_components_3_22_01_07", Value.DEFAULT, false);
        pkgV.bind("$name", "framework_components_3_22_01_07");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "framework_components_3_22_01_07.");
        pkgV.bind("$vers", Global.newArray("1, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        imports.add(Global.newArray("ti.sdo.fc.global", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.dskt2", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.dman3", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.acpy3", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ecpy", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.utils", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.utils.api", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.utils.gtinfra", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.utils.osal", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.utils.osalsupport", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.utils.osal.noOS", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.memutils", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.examples", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.examples.buildutils", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.examples.dmaXfer", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.examples.dmaxferchecker", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.bufres", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.edma3chan", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.hdvicp", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.nullresource", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.sdma", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.shmbuf", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.tiledmemory", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.vicp", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.edma3", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.scpy", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.hdintc", Global.newArray()));
        imports.add(Global.newArray("khronos.opencl", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.opencl", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.opencl.platforms.c6472", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.opencl.examples", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.opencl.examples.autoviz", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.opencl.examples.hello", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.utils.trace", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.rcm", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.tiler", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.dskt2.examples", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.bufres", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.bufres_yield", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.dmaXferScratch", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.dummyEdma3", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.hdvicp", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.nullresource.test", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.plugin", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.scratchEdma3", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.sdma", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.shmbuf", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.vicp", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.rman.examples.hdvicp.hdvicp2", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.dman3.examples.fastcopy", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.examples.codecs.auddec1", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.examples.codecs.edmacodec1", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.examples.codecs.idma3codec1", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.examples.codecs.template", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.fc.ires.examples.codecs.universal_dma", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.rcm.examples.appcfg", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.rcm.examples.hello", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.rcm.examples.minidist.linux.osal", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.rcm.examples.minidist.linux.client", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.rcm.examples.minidist.linux.server", Global.newArray()));
        imports.add(Global.newArray("ti.sdo.tiler.examples.remote", Global.newArray()));
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['framework_components_3_22_01_07'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("init", pkgV);
        ((Value.Arr)om.findStrict("$packages", "framework_components_3_22_01_07")).add(pkgV);
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
        if (isROV) {
        }//isROV
        $$SINGLETONS();
        $$INITIALIZATION();
    }
}
