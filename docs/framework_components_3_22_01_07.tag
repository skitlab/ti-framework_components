<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>Framework Components API Reference</title>
    <filename>index</filename>
    <docanchor file="index">modules</docanchor>
  </compound>
  <compound kind="file">
    <name>acpy3.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/acpy3/</path>
    <filename>acpy3_8h</filename>
    <includes id="idma3_8h" name="idma3.h" local="no" imported="no">ti/xdais/idma3.h</includes>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_configure</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga7c968c0683e57ebaaa84f7428316b086</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_Params *params, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_fastConfigure16b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga9b4de2acd317d163d0a1183b0a91749a</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_ParamField16b fieldId, unsigned short value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_fastConfigure32b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga9c2c2ad10eda1f7f9b7c39e1ce6cb72e</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_ParamField32b fieldId, Uns value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_setFinal</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga8f4b393fa67f4344b49f8bf24a1b1e02</anchor>
      <arglist>(IDMA3_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_fastSetFinal</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga6bd96df00b973b8a22a736b913cbb53a</anchor>
      <arglist>(IDMA3_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_start</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gab4102200f00a9df3961a8374c0042bed</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_wait</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga499bc0643a52f5cfd0828c1ce21cd69b</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_waitLinked</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga1209333a83fe6a2b2c75d011dab09a25</anchor>
      <arglist>(IDMA3_Handle handle, unsigned short waitId)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>ACPY3_complete</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae22deca1f6878a359a619cff8654d9de</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>ACPY3_completeLinked</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga3a7afab3f58902acf651345505e6d0b5</anchor>
      <arglist>(IDMA3_Handle handle, unsigned short waitId)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_activate</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gaf9dc07965774895d79323a47b36cc442</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_deactivate</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2736d2e136e868577a71710571027de5</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_init</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gac79227aad8cb9f68ab67da77de81fd17</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_exit</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae7072f7010b53bdeab5ac76737b380af</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_GTNAME</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga9ac4b2a9bdc89338d486453e93aaf560</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_MODNAME</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga5e18ff4ee608d09809a0538c17fa94ed</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">ACPY3_Params</class>
    <member kind="typedef">
      <type>enum ACPY3_ParamField16b</type>
      <name>ACPY3_ParamField16b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae68edf9ac573c2b952a6d40e96103c01</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_ParamField32b</type>
      <name>ACPY3_ParamField32b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga6312b4a2db69af18b3f164836767abf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_TransferType</type>
      <name>ACPY3_TransferType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga730e4286738a2ed77e95b9f5338e719a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_Params</type>
      <name>ACPY3_Params</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae2796cd82f9251f4b6e4dede5b9602aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_ParamField16b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gaf9624d3d925ec0d15bd845967664e608</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTSIZE</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608af590c76a022dbe56043c8a0a577a88c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_NUMELEMENTS</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608ab95b07e80a06c8d2b0ccd191de1fb8aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTINDEX_SRC</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608aa3a4872acfc89e4da1820e0839b0fb87</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTINDEX_DST</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608aa1c08ec69ae102d758b8678c492038e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_FRAMEINDEX_SRC</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608acd1fe7c99a4596d8724a9cf359bf8f57</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_FRAMEINDEX_DST</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608aad2460b82b3834e625dcdb3e1e2c140c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_NUMFRAMES</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608a5593f2242b7d6741c9dcb4233909942d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_ParamField32b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga96f43d4bc010da2d1bb9dc08ea828de0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_SRCADDR</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0a807013269912df7c5dbc2361483d2e1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_DSTADDR</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0a927624fccb072b2ff847a10c4729fedf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTINDEXES</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0ace2eb39c83c77fa1ee38d5c87e045e83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_FRAMEINDEXES</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0a88347f099298128f5989f76636e64dc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_TransferType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gabe2d02fcbde983c823b138f20667cbfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_1D1D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfcaf9cef75ab1829399370006a48d16182e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_1D2D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfca7e3376fb0def5e38484dfb121e7b2fb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_2D1D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfca3ad50651b016c2c96f8fb6f724213623</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_2D2D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfcad8ac84d79831cfe53a4088a321989a85</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IDMA3_ProtocolObj</type>
      <name>ACPY3_PROTOCOL</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga7171d01619b7fc26dbb11eb9aaf1a3b2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>acpy3_instr.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/acpy3/</path>
    <filename>acpy3__instr_8h</filename>
    <includes id="idma3_8h" name="idma3.h" local="no" imported="no">ti/xdais/idma3.h</includes>
    <class kind="struct">ACPY3_INSTR_Hook</class>
    <class kind="struct">ACPY3_INSTR_Hooks</class>
    <class kind="struct">ACPY3_INSTR_ExtendedHooks</class>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_INSTR_NUMHOOKS</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga4cd29b57cda5002d541e9f51b341c4ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_INSTR_NUMEXTENDEDHOOKS</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga0ec901a1813d45e43123a03052a774de</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_INSTR_HookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_START_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6accd037f87563e0c241a9864c8e8e9590</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_START_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6a5588ac9c1ff6c4925392f50e6f731393</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAIT_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6a9fcc76fd464260e570c90525290ee14d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAIT_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6abe7aad80582e0e0b3178ed75c204993e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_INSTR_ExtendedHookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAITLINKED_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05af270a6b21f22cb41834a09e5fcaa7fa8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAITLINKED_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a8d848097c2f88c48856f0e12f36a09f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_ACTIVATE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05af08858cedaf5af244a28b03b0f585f16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_ACTIVATE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05acfc9d48e557e5020d68eac5a4a4defb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_DEACTIVATE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a833584c7662cb46bacf3bef67283456a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_DEACTIVATE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a200da6497c774857270e4fc39d0721f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a9a0a6b59022ef1516029bfc8078ca996</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a98691726530703faae4d97aeb3b02ab7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETELINKED_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a2851dab3b27da3b926a53f6d5d1353ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETELINKED_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a591a8e532256855c4357b126b93622b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_CONFIGURE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a64956372df6069db186f8f8c3c485203</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_CONFIGURE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a0c66a6b4d3985e55e069678e9ef91004</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE16_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a3508a134cbdae98e84000fe171b6ee16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE16_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a6fde3b32ff50ca89aacbead84e71d76f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE32_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05ad7471a5e44a30928433f106a44935aaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE32_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05ad0be66b12acfbd49dfb73e7a73b145be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFINAL_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a118bb352f15b4e8869e31857b990077c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFINAL_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a74aebc9d8fe0a6232acf0ad56ba5f612</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFASTFINAL_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05accd8c23a638c8a206536b9935792ef0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFASTFINAL_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05addb6061f2df956cfcb5109447a063aa3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_INIT_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05adab51be6f7d31b79e5b5c064241490a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_INIT_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05abbcc98db88ad1d057b5ee53e1ca90cf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_EXIT_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05ae1fdbc8fa67196f1b75f27e1af5904f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_EXIT_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05aa17392f0da11248926400167638da551</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_INSTR_HookType</type>
      <name>ACPY3_INSTR_HookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga59cfeeab682e4c6b55da00e0f5fce888</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_INSTR_ExtendedHookType</type>
      <name>ACPY3_INSTR_ExtendedHookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga66c6cd00c1b29bfade8bb8f9d5f76f45</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>ACPY3_INSTR_HookFxn</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gac637aa469ae9eeb2e0a81009a52a0e6f</anchor>
      <arglist>)(IDMA3_Handle handle, void *param)</arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_INSTR_Hook</type>
      <name>ACPY3_INSTR_Hook</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gafa887e1997a17daf1a52c7024905182c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_INSTR_Hooks</type>
      <name>ACPY3_INSTR_Hooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga71534cee41f006ae9ac546e882366ee4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_INSTR_ExtendedHooks</type>
      <name>ACPY3_INSTR_ExtendedHooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gadb5381ffc001bacd16929bcb347c7155</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_INSTR_registerHooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gaf7b7bfefbb4dc5c7bd20a73b5e0fbaeb</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_INSTR_Hooks *hooks, ACPY3_INSTR_ExtendedHooks *extended_hooks)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_INSTR_unregisterHooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga4fbf3aeced924bd7ef7e928742bc1aa9</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>disclaimer.dox</name>
    <path>/db/toolsrc/library/tools/vendors/opensource/doxygen/templates/1.7.2/</path>
    <filename>disclaimer_8dox</filename>
  </compound>
  <compound kind="file">
    <name>dman3.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/dman3/</path>
    <filename>dman3_8h</filename>
    <includes id="ialg_8h" name="ialg.h" local="no" imported="no">ti/xdais/ialg.h</includes>
    <includes id="idma3_8h" name="idma3.h" local="no" imported="no">ti/xdais/idma3.h</includes>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_grantDmaChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gae0e5031bc5e947da1bd5d12cca1c5e00</anchor>
      <arglist>(Int groupId, IALG_Handle algHandle[], IDMA3_Fxns *dmaFxns[], Int numAlgs)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DMAN3_exit</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gac26a2a6153c50b10dc3ae9106bfa8594</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_createChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gaee927c5ad460e5e5a122471ccb047db1</anchor>
      <arglist>(Int groupId, IDMA3_ChannelRec dmaTab[], Int numChans)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DMAN3_init</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gaf0a672c8ba5962dabc8b319978aafd3b</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_releaseDmaChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga664b5e2445c2ec3a0ed9e14f8cfc1d20</anchor>
      <arglist>(IALG_Handle algHandle[], IDMA3_Fxns *dmaFxns[], Int numAlgs)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_freeChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga2d14c4952c1194b913ac6e8bb7f0e9d5</anchor>
      <arglist>(IDMA3_Handle channelTab[], Int numChans)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga5588e76c77396c16216bf7475612c9ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gacc2eb308be5d04d2b2bf935505796611</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_MAXGROUPS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gab4a261c271c8d0f1e9843eada6b263e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_SOK</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga462d3887266b42b69cf21c65e87dc99d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EOUTOFMEMORY</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga70d091dae946805ff49ab47b903483a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EFAIL</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gae81e9235f9755ac2e6a6279401c8798d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EFREE</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga097f382f6603cc69c2d998c0ce6b9dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EOUTOFTCCS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gab04511fe9f738b3a189758163e75f1d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EOUTOFPARAMS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga45977d32b34b6e98e33b6510c9164dee</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_ETCCCONFIG</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga63c528d94fcf56d1af53b723dd353fb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EPARAMCONFIG</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gaadcb78abb90cd713d02bb0b85c021e35</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">DMAN3_Params</class>
    <member kind="typedef">
      <type>Bool(*</type>
      <name>DMAN3_ScratchAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gad828e3c20733776991f5d87aaaff7aad</anchor>
      <arglist>)(IALG_Handle alg, Int mutexId, IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>DMAN3_ScratchFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gacf1a15063787f2b589489be6234301fc</anchor>
      <arglist>)(Int mutexId, Void *addr, Uns size)</arglist>
    </member>
    <member kind="typedef">
      <type>struct DMAN3_Params</type>
      <name>DMAN3_Params</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga1ce61c1477d05515d0f27849b3b3f1d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>DMAN3_Params</type>
      <name>DMAN3_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gae3b96522afa89788ab1efdb5154c3e03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>ti_sdo_fc_dman3_DMAN3_numQdmaGroup</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga7a13bbecafc22773c55ca1b257bc75b7</anchor>
      <arglist>[20+1]</arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>ti_sdo_fc_dman3_DMAN3_useCustomDma</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga67d359a006317a42ef47ae82906ed304</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>doxygen.txt</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/</path>
    <filename>doxygen_8txt</filename>
  </compound>
  <compound kind="file">
    <name>packages/ti/sdo/rcm/doxygen.txt</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/rcm/</path>
    <filename>packages_2ti_2sdo_2rcm_2doxygen_8txt</filename>
  </compound>
  <compound kind="file">
    <name>dskt2.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/dskt2/</path>
    <filename>dskt2_8h</filename>
    <includes id="ialg_8h" name="ialg.h" local="no" imported="no">ti/xdais/ialg.h</includes>
    <includes id="ires_8h" name="ires.h" local="no" imported="no">ti/xdais/ires.h</includes>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_activateAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gaf946d426d6d9a95040d3967fa746cd7a</anchor>
      <arglist>(Int scratchMutexId, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DSKT2_controlAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga65d8c7ae9d40adcda0c92a9e51c6fd0b</anchor>
      <arglist>(IALG_Handle alg, IALG_Cmd cmd, IALG_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IALG_Handle</type>
      <name>DSKT2_createAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga5528d73c34724bc310404da0dc2fbd69</anchor>
      <arglist>(Int scratchMutexId, IALG_Fxns *fxns, IALG_Handle parent, IALG_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>IALG_Handle</type>
      <name>DSKT2_createAlg2</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga427904cdb1e2a776ee6dfd32c6529682</anchor>
      <arglist>(Int scratchMutexId, IALG_Fxns *fxns, IALG_Handle parent, IALG_Params *params, xdc_runtime_IHeap_Handle extHeapId)</arglist>
    </member>
    <member kind="function">
      <type>IALG_Handle</type>
      <name>DSKT2_createAlgExt</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga6d39f16af2214fafad89ba06382a9a79</anchor>
      <arglist>(Int scratchId, IALG_Fxns *fxns, IALG_Handle parent, IALG_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_deactivateAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga74b6b6feca63328906acade37d23b597</anchor>
      <arglist>(Int scratchMutexId, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DSKT2_deactivateAll</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga2d252c736a3bb828d9f646cc379ac0e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>DSKT2_freeAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga8dffa02b3ca1ff6856ce3cf610be7435</anchor>
      <arglist>(Int scratchMutexId, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>DSKT2_allocScratch</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga5aa4fbbf031e07f6bf450128ed8bd31d</anchor>
      <arglist>(IALG_Handle alg, Int mutexId, IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DSKT2_getScratchId</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga4eda7abcc1ed22cb2183b27290e034b0</anchor>
      <arglist>(IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_freeScratch</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga48fad0ce89b1de7f65adb9a06b4276a0</anchor>
      <arglist>(Int mutexId, Void *addr, UInt size)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>DSKT2_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga3c37794b3c2fbf0070b473c711e275ca</anchor>
      <arglist>(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga6bc8b2ebbadb2f72325c1b297597fc44</anchor>
      <arglist>(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_NUM_SCRATCH_GROUPS</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga6ea3f0bc0c9a697930cf7d8411975ac2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_MAX_MEM_ALLOCATION_SIZE</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gab7906673f1c60a08206bd37c7f7d1178</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_NUM_SHAREDHEAPS</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gacb5e98129cb03f61436195c9fd240804</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga10d952cbb68bf248a0fcb6cc92c6b58e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>DSKT2_CacheWBInvFxn</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga50724c1a6b3a22edc3c011f26acee8d8</anchor>
      <arglist>)(Ptr blockPtr, size_t byteCnt, Bool wait)</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ DSKT2_CacheWBInvFxn</type>
      <name>DSKT2_cacheWBInvFxn</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga13251e1daaba43dd400d382dbf0dbc58</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_daram0Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga4735a17e9803b69e7a516cc760bf3723</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_daram1Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga72b57fe7ad477cab4f651f6f4b867fa5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_daram2Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga742f9473d76743d2ba321eb0ea03e415</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_saram0Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga52937ef078fa8e077ff10aff27264eaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_saram1Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga9927b8fe81c1a0568f200ee3238324db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_saram2Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gab78a425f912768f8b3e9af7d6192d697</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_iprogHeap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga8db8042f1121b54db259c7310c437aef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_eprogHeap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga36e11ee5b675fd2f16bd48e27285523f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_esdataHeap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gaefe5d33b89715d3ef187ed45bbc7f21d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>_DSKT2_heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga7b2cd47eb6dad98f50f959d035086bb5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ UInt</type>
      <name>_DSKT2_ALLOW_EXTERNAL_SCRATCH</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga5163b360c871f2c8c4e12d6abbb55868</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt</type>
      <name>_DSKT2_DARAM_SCRATCH_SIZES</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga068cb14e316f0318c171347531351cd6</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>UInt</type>
      <name>_DSKT2_SARAM_SCRATCH_SIZES</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gac23f20affc67172dcba96c24cee5e3f3</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ Bool</type>
      <name>ti_sdo_fc_dskt2_DSKT2_disableLazyDeactivate</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gaac47654880b79bdf547b27c46361a2cf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>dskt2_qos.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/dskt2/</path>
    <filename>dskt2__qos_8h</filename>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_QOS_getStat</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>a9e737a55019c3dd16fe9bb7313941270</anchor>
      <arglist>(UInt heapType, UInt mutexId, UInt *sizeSharedScratch, xdc_runtime_IHeap_Handle *inHeap)</arglist>
    </member>
    <member kind="typedef">
      <type>enum DSKT2_QOS_TI_MsgArg1Types</type>
      <name>DSKT2_QOS_TI_MsgArg1Types</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>a495b1a836c770924c2a0cd9bf97a5329</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum DSKT2_QOS_TI_GetSharedScratchMsgArg2</type>
      <name>DSKT2_QOS_TI_GetSharedScratchMsgArg2</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>a76e9bfed31ef5b2c418b02d1a5eed779</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>DSKT2_QOS_TI_MsgArg1Types</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>aa4b7cb5a2c0e1b6d0e6d1eed6ded728c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DSKT2_QOS_SHARED_SCRATCH_ALLHEAPS</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>aa4b7cb5a2c0e1b6d0e6d1eed6ded728ca63f5c0038e10f8a6ca4cdaef1bb025cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DSKT2_QOS_SHARED_SCRATCH_DARAM</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>aa4b7cb5a2c0e1b6d0e6d1eed6ded728ca303c1716cf5a0498bae3f45091a4403f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DSKT2_QOS_SHARED_SCRATCH_SARAM</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>aa4b7cb5a2c0e1b6d0e6d1eed6ded728ca61805a68fdf379e62226985008d3a5be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>DSKT2_QOS_TI_GetSharedScratchMsgArg2</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>a002e0ce93e06aa89b5e4231f7fd0e683</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DSKT2_QOS_ALL_SCRATCHGROUPS</name>
      <anchorfile>dskt2__qos_8h.html</anchorfile>
      <anchor>a002e0ce93e06aa89b5e4231f7fd0e683a9984fcd2b0b4f7f1de979abcf1faa101</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ecpy.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ecpy/</path>
    <filename>ecpy_8h</filename>
    <includes id="ires__edma3_chan_8h" name="ires_edma3Chan.h" local="no" imported="no">ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h</includes>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_configure</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gab36a69debff280508406036c8c998a28</anchor>
      <arglist>(ECPY_Handle handle, ECPY_Params *restrict params, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directConfigure</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf0380c28be53fce116f2c56823d61b7e</anchor>
      <arglist>(ECPY_Handle handle, ECPY_Params *restrict params, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_configure16</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga0b7ae91529bc356a3bd81eda9d21a421</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField16b fieldId, unsigned short value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directConfigure16</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gad27b66a14d13c228eb49b17acbd024aa</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField16b fieldId, unsigned short value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_configure32</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaea38193e1199d4a33d4878e916b9b429</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField32b fieldId, unsigned int value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directConfigure32</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gad46ed17a5d0f1a2a0bc2c7f47aad7fcd</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField32b fieldId, unsigned int value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_setFinal</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga910393e8b722717de7b84b837adb1921</anchor>
      <arglist>(ECPY_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directSetFinal</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gac377bd43289a832c94c73b20a08c8c26</anchor>
      <arglist>(ECPY_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_setDestinationMemoryMode</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga3101247586aa75cc25a7733c6c4a9679</anchor>
      <arglist>(ECPY_Handle handle, short mode)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_start</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf574cd0eabdf2f673009018d7cd3408c</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directStartEdma</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf794837c161e60951b4b0c41af37ce1d</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directStartQdma</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gafeab08ae1a1b97bcaa7b207d62df528b</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_wait</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga8adc4be8a9f83b92484dd3aea18d96b1</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directWait</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga0187836c1fb6e00b16741e5daf69308b</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_activate</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gacc1922d7764bb915e1132d955e4b273f</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>ECPY_Handle</type>
      <name>ECPY_createHandle</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf27ccab70603cbf148f46a5068a497e0</anchor>
      <arglist>(IRES_EDMA3CHAN2_Handle handle, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_deleteHandle</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga7d98039c8cea805547bd8ddde71eff6a</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_deactivate</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga06f88eefc91f79ba958d1dee9e7fbb63</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_setEarlyCompletionMode</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga53d14a24649b65b10b817466c7c5b63f</anchor>
      <arglist>(ECPY_Handle handle, short enabled)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_init</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gae699f2d7ac858fecfc83655b3df12037</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_exit</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gade95f79a09ed57206ae1236a23c03764</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ti_sdo_fc_ires_NOPROTOCOLREV</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga33eacaa6cefc41cfe527b740449250dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ECPY_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga20a251dafbbc7b6f6b630d65f95882a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ECPY_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga41a9eb2392433a4d485892a130a1a0f6</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">ECPY_Params</class>
    <class kind="struct">ECPY_CfgParams</class>
    <member kind="typedef">
      <type>enum ECPY_ParamField16b</type>
      <name>ECPY_ParamField16b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gad6043a14cff5cf11e6124f8ad848e060</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ECPY_ParamField32b</type>
      <name>ECPY_ParamField32b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga9a316b6b71fa073d355c25ef48ddf9e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ECPY_TransferType</type>
      <name>ECPY_TransferType</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga5e69c0ab60fd992aaf644c5dae21a983</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ECPY_Obj *</type>
      <name>ECPY_Handle</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga5e6504458adc98bbbaebfd75c6708add</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ECPY_Params</type>
      <name>ECPY_Params</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga85cefc02e34b1ae7d62fb38564c64422</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Bool(</type>
      <name>ECPY_PersistentAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga76c3270f722c14ccb8f841ddd7ad633b</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(</type>
      <name>ECPY_PersistentFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga26781251cda4ad55a1c42efdded245d3</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Bool(</type>
      <name>ECPY_ScratchAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gae88691e8077d5fd82d748eb7fccba834</anchor>
      <arglist>)(IALG_Handle alg, Int scratchId, IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(</type>
      <name>ECPY_ScratchFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga4643c72b6383f39fb4b0c5b588837006</anchor>
      <arglist>)(Int mutexId, Void *addr, UInt size)</arglist>
    </member>
    <member kind="typedef">
      <type>Int(</type>
      <name>ECPY_getScratchIdFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga1557be200bc42ce9b4def164ea3907e7</anchor>
      <arglist>)(IALG_Handle alg)</arglist>
    </member>
    <member kind="typedef">
      <type>struct ECPY_CfgParams</type>
      <name>ECPY_CfgParams</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga54c1cdb98daaa54a05871b834f02037c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ECPY_ParamField16b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga7d9083dd908144dea99d282b5e4c8b13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTSIZE</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a36d360cbb62ce99c35b580783c8b49b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_NUMELEMENTS</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13ad69a1ddde8138115336b24b29a834f2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTINDEX_SRC</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a7c967b0f24b1cf6ed5b79a4132c9a7a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTINDEX_DST</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a4053f308bce4818e1d6d834a2e3e624e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_FRAMEINDEX_SRC</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a5c9f42f805ad155965c02a5b8626e1fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_FRAMEINDEX_DST</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13adfc48d249dca5f0943e0a6476959d17e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_NUMFRAMES</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a3577d05a60a04c2721acc376bf30d63e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ECPY_ParamField32b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga59f221145cdc648d305f9c2d49ec2f87</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_SRCADDR</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87a098f1b061997d6567579046bc2b7a575</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_DSTADDR</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87aebad51006d8f6e00b018aa9046cd8058</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTINDEXES</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87a1f43197ca7113efa4a522209fc5591f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_FRAMEINDEXES</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87a13c950c2596ae15fe4ee9663d1b0e4f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ECPY_TransferType</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga263a661327490e9f8226271c6f478011</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_1D1D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011a38f001040141d98db06c881ea0dc44d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_1D2D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011aa3447e13f4ccf2ea11c758108a361552</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_2D1D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011a7299b2d257ac0f6eb3caa86366f540ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_2D2D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011afda741865f454dcea45ec1eb2f5c42db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ ECPY_CfgParams</type>
      <name>ECPY_CFG_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gabcc5234b3b928c407413afc3aa15a92b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hdintc.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/hdintc/</path>
    <filename>hdintc_8h</filename>
    <includes id="ialg_8h" name="ialg.h" local="no" imported="no">ti/xdais/ialg.h</includes>
    <includes id="xdas_8h" name="xdas.h" local="no" imported="no">ti/xdais/xdas.h</includes>
    <member kind="function">
      <type>void</type>
      <name>HDVICP_configure</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga009daaee6229d4963d1d6e6e1ea5dfce</anchor>
      <arglist>(IALG_Handle handle, void *hdvicpHandle, void(*ISRfunctionptr)(IALG_Handle handle))</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>HDVICP_wait</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga54da32d8ba2275df7747f13233066197</anchor>
      <arglist>(void *hdvicpHandle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>HDVICP_done</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga9bca27e1d2927d05b90120efed813563</anchor>
      <arglist>(void *hdvicpHandle)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga415467e72b60fa643f411fd7f5c21769</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_SOK</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga05484bfd6b90b363379ded126fe1756f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_EOUTOFMEMORY</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>gadd4ff9534ef2287e5b390953adeda2f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_EFAIL</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>gae38cf9587b601ab07913642d0fdbc149</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">HDINTC_Params</class>
    <class kind="struct">hdvicpAppHandle</class>
    <member kind="typedef">
      <type>struct HDINTC_Params</type>
      <name>HDINTC_Params</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>gaec114ee910a3e016a510173296149621</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct hdvicpAppHandle</type>
      <name>HDVICP_Obj</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga9a8684867f1420ddeb18eed5ebde3d6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>HDVICP_Obj *</type>
      <name>HDVICP_Handle</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga01e5fc5a20a9510b3ae121c3743ff2bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>HDINTC_Params</type>
      <name>HDINTC_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga61af9ab21c54b9cf7351c8261cc1d243</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ialg.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/xdais/</path>
    <filename>ialg_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>IALG_DEFMEMRECS</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga8a220fa863380937542f6a38be47ceda</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_OBJMEMREC</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga0e3202a4d8dc0bd3cb300633922ffd54</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_SYSCMD</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga200f155f9e2720011270e99f17bb6675</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_EOK</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga2c15898121a23a164e4ea2bcc4f7e7dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_EFAIL</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga604e5600815cbd58846e0c5c05b6ba18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_CUSTOMFAILBASE</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga1f655af6b5ce37aaf5328243d1993cf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_CUSTOMFAILEND</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gafbab7f3470d8b5a46615f1aca5c739b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_MPROG</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga86018453b8f991c8cb545b2e43c80c9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_MXTRN</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gafc53b940e2982a2e859bda0555180eb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_isProg</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga93e8704d8e88d2f3dde1a85317232b59</anchor>
      <arglist>(s)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_isOffChip</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gae2530ce6b07542f579871961a3fcfd4f</anchor>
      <arglist>(s)</arglist>
    </member>
    <class kind="struct">IALG_MemRec</class>
    <class kind="struct">IALG_Obj</class>
    <class kind="struct">IALG_Params</class>
    <class kind="struct">IALG_Status</class>
    <class kind="struct">IALG_Fxns</class>
    <member kind="typedef">
      <type>enum IALG_MemAttrs</type>
      <name>IALG_MemAttrs</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga20f514039bf67b319bff425fb8f36e5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IALG_MemSpace</type>
      <name>IALG_MemSpace</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga61ed32f432abc371aece4d839cdaee78</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_MemRec</type>
      <name>IALG_MemRec</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga99aa369e4d2b2e38444d7029ba09caed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Obj</type>
      <name>IALG_Obj</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga056d16e11872c72ef03832ebea91c946</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Obj *</type>
      <name>IALG_Handle</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga16c037803ea218ba3dc5158f55ef27c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Params</type>
      <name>IALG_Params</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gaa3e5c88152dd2b867de749e15c4bd01a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Status</type>
      <name>IALG_Status</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga9cb14b478af2c5636bfb8ba78d06c3ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned int</type>
      <name>IALG_Cmd</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga9032f20923ef2ba1d6b88c87a20075fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Fxns</type>
      <name>IALG_Fxns</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gaf97260de3299a9304375dedca698572a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IALG_MemAttrs</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga805f1c1330403c05633277a073862e3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SCRATCH</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga805f1c1330403c05633277a073862e3da85e0509f7e82ebd01b57f899122de9b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_PERSIST</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga805f1c1330403c05633277a073862e3da68adbe0194074e0474333b76f7d1e090</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_WRITEONCE</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga805f1c1330403c05633277a073862e3da42356e6aa11869bfd15f31472f49a7c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IALG_MemSpace</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga262eb64dc7343999fa07d535ae163497</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_EPROG</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a6410b22d1d073ab55b289ca2f3c03b35</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_IPROG</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a946577db145f691f81d7085fc51e2201</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_ESDATA</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a85fff905ed5e83445e3424ce5ba03175</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_EXTERNAL</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497aa98151c21c55ddaf8c1918d8007e5493</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_DARAM0</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497af6a85bf972a4d090e2c0e4d31565f879</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_DARAM1</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497ad7b3b18fc0263be0f0702d263f600d9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497aa5c6d8cfdb63c11fafd22bb87204c5cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM0</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a4b31d959f6af27a012a87957c05d9c4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM1</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a4ac938c5e58e4d4a30458b63869f0095</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_DARAM2</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a17fc19eac565b29871efbfed54760414</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM2</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a6db79aaafcf9b4354f2828c2a94b8590</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>idma3.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/xdais/</path>
    <filename>idma3_8h</filename>
    <includes id="ialg_8h" name="ialg.h" local="yes" imported="no">ialg.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IDMA3_PROTOCOL_NULL</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga85de540d61ac83857803528f25f44e4b</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IDMA3_MemRec</class>
    <class kind="struct">IDMA3_ChannelRec</class>
    <class kind="struct">IDMA3_Fxns</class>
    <class kind="struct">IDMA3_ProtocolObj</class>
    <class kind="struct">IDMA3_Obj</class>
    <member kind="typedef">
      <type>enum IDMA3_MemType</type>
      <name>IDMA3_MemType</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gad7dca268a0fb944ec7da970a7064c93b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_MemRec</type>
      <name>IDMA3_MemRec</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gad9a9dde19d244a4552965b14abe2d96f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_Obj *</type>
      <name>IDMA3_Handle</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga8960c528f0708a559bcaab34a865e1a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_ProtocolObj *</type>
      <name>IDMA3_ProtocolHandle</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gadd329735609d8384c3625554c0f2c58d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IDMA3_Priority</type>
      <name>IDMA3_Priority</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga04af272ab4f16153137e3f39856078d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_ChannelRec</type>
      <name>IDMA3_ChannelRec</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gac8af8b3447a5ae88f4b14dc96e18eee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_Fxns</type>
      <name>IDMA3_Fxns</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga02d106a910bf5561419a755ab7f97e03</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_ProtocolObj</type>
      <name>IDMA3_ProtocolObj</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga6705287956a84beb7d6f0eee6b6dfb55</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_Obj</type>
      <name>IDMA3_Obj</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gae5a0e05b6797ba0b914a41c90ea47a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IDMA3_MemType</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gabe0577eecc288b36121382daa765093a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_INTERNAL</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggabe0577eecc288b36121382daa765093aa120151b2c6d2d5bcb2d59466b0d13287</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_EXTERNAL</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggabe0577eecc288b36121382daa765093aa9e757f072f4782774d8cd4b647563c54</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IDMA3_Priority</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gafa41dccd2cc8f94915fffdda2c8b4a59</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_URGENT</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a90abf287e878aedcfbc17d19266f207c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_HIGH</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a2bd88e579d019a160876842f0c92f325</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_MEDIUM</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a4f3bbe300c3ce513644f31991b6788ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_LOW</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a8560a79ce3c83622bed84ecb31b57aff</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/xdais/</path>
    <filename>ires_8h</filename>
    <includes id="ires__common_8h" name="ires_common.h" local="yes" imported="no">ires_common.h</includes>
    <class kind="struct">IRES_YieldContext</class>
    <class kind="struct">IRES_Fxns</class>
    <member kind="typedef">
      <type>enum IRES_YieldResourceType</type>
      <name>IRES_YieldResourceType</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga772c04e720ba2b67b4204bbccbe40945</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>IRES_ContextSaveFxn</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gaa00576c8c0c6d1e2c01cc32788c597c9</anchor>
      <arglist>)(IALG_Handle algHandle, Void *contextArgs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>IRES_ContextRestoreFxn</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga618c74da111cc440a47fad6f7f575c89</anchor>
      <arglist>)(IALG_Handle algHandle, Void *contextArgs)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_YieldContext</type>
      <name>IRES_YieldContext</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gad70330927e4683909b1553bf0f2a5c75</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_YieldContext *</type>
      <name>IRES_YieldContextHandle</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gafd901eec352839470db8e386baa1be66</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void *</type>
      <name>IRES_YieldArgs</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gafb1e285a8d30b447dc39fe05d5e4fdf0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>IRES_YieldFxn</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga21803b9b676c2579e59909062dc40079</anchor>
      <arglist>)(IRES_YieldResourceType resourceType, IRES_YieldContextHandle algYieldContext, IRES_YieldArgs yieldArgs)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Fxns</type>
      <name>IRES_Fxns</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gad4918d3ae4c063a0bf6e76ac26c7c297</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_YieldResourceType</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga9a68e109e02bf3f35e832ec4f767d0a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ALL</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3a0fd0c33808e89762c91dca8c2edc6aef</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_SCRATCHMEMORY</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3a99a353ef5a76fad49a805f0e3ba6e8e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_SCRATCHDMA</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3aa8fe0182b728dbcd24900b9bf13221c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_RESOURCEHANDLE</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3a737fd5b62997deb99125d2e0f4e47b74</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_common.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/xdais/</path>
    <filename>ires__common_8h</filename>
    <includes id="ialg_8h" name="ialg.h" local="yes" imported="no">ialg.h</includes>
    <class kind="struct">IRES_ProtocolRevision</class>
    <class kind="struct">IRES_ProtocolArgs</class>
    <class kind="struct">IRES_ResourceDescriptor</class>
    <class kind="struct">IRES_Properties</class>
    <class kind="struct">IRES_Obj</class>
    <member kind="enumeration">
      <name>IRES_Status</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga8db6eab013fc4569e080cb4361dfd65b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_OK</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba30253e67bb1b070685e4177bdf9587b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EALG</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba432505b3fc40c3ae60c7b36624dc100d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EEXISTS</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba5d1871ad076ad79c214cfe753f0513e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EFAIL</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba79fa1a926f2b780120951d084fcc3bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EINIT</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65bacf083017e2e50c9f975e4d956d0dc440</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENOINIT</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba9cb3cdefe2de31efea9a9442e2ed7dd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENOMEM</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba72b429ce0c052c9fe5b079798ee08caa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENORESOURCE</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba82f5c8e224ec5ef57cae62a4e80bf2d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENOTFOUND</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba077a2999bf874acf2b556347a3c71e5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_RequestMode</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_SCRATCH</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963a4edb7db0f8cd8780a263c1e8ec686aa0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_PERSISTENT</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963ab66403426900afab06c1459b4c8a1fc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_LATEACQUIRE</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963aa8d4ddab65248eedc7d1ca3fb43a5ea2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_Status</type>
      <name>IRES_Status</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga09c6ef97314f2d27ce39bfcfac5da287</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_ProtocolRevision</type>
      <name>IRES_ProtocolRevision</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gaf7c3863c0ea3895fb86badf58b809a43</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_RequestMode</type>
      <name>IRES_RequestMode</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gae6d619d30b481ac725448b769d2ae2d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_ProtocolArgs</type>
      <name>IRES_ProtocolArgs</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga4808ad3c47785cbfb8a22bf50b096e11</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_ResourceDescriptor</type>
      <name>IRES_ResourceDescriptor</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga0b4bec3cd4dbe4556d72d9ed894d5246</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Properties</type>
      <name>IRES_Properties</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga2ef376adca27740ff8285b0d1b7e272b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Obj</type>
      <name>IRES_Obj</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga5d11994529489c6809bc2effd5f83f01</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Obj *</type>
      <name>IRES_Handle</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gad0e33217f411f69c326180854b9f1cea</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_edma3Chan.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/edma3chan/</path>
    <filename>ires__edma3_chan_8h</filename>
    <includes id="xdas_8h" name="xdas.h" local="no" imported="no">ti/xdais/xdas.h</includes>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaf4730270fcd589bd84292642aa0767ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>EDMA3CHAN_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gab7814ae21cc501d4882aaeb43153fc0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PROTOCOLREVISION_1_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga3e72cddac269ede3215c67681bd06358</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_SETPROTOCOLREVISION_1_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gabc9fa9788be85eddc9696b9a778270c9</anchor>
      <arglist>(rev)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PROTOCOLREVISION_2_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gafaf0878b09c1cc9708821d19d801e182</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_SETPROTOCOLREVISION_2_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga13b7ccd6e711b7469b8823a5c957b536</anchor>
      <arglist>(rev)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_MAXPARAMS</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga8510375de41242e3526a4afa007e131a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_MAXTCCS</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga18eb05e3510d748f04269c39cce62733</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_NUMDESTTYPES</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gadb7b5e24785c0749d8717e0d740ebdd4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PARAM_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga2b610a75bc94fcf953c9c2c5a5884847</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PARAM_NONE</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga06bed242a94eb48126e04f267f0d4895</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_TCC_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga3dad6458e12ad42c2158727991822037</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_TCC_NONE</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga1920c58bedf3e0cc0609b86ec384c892</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_EDMACHAN_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gae3c157030381908d1353fccf406fdd38</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_QDMACHAN_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga0b99333ee5984dab27d5d84c05b63078</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_CHAN_NONE</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gae4140c679d6eaaf4d20dc4554995edf3</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_EDMA3CHAN_PaRamStruct</class>
    <class kind="struct">IRES_EDMA3CHAN_ProtocolArgs</class>
    <class kind="struct">IRES_EDMA3CHAN_Obj</class>
    <class kind="struct">IRES_EDMA3CHAN_EDMA3ShadowRegister</class>
    <class kind="struct">IRES_EDMA3CHAN_EDMA3DraeRegister</class>
    <class kind="struct">IRES_EDMA3CHAN_EDMA3RegisterLayer</class>
    <class kind="struct">IRES_EDMA3CHAN_Properties</class>
    <class kind="struct">IRES_EDMA3CHAN2_Obj</class>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_Obj *</type>
      <name>IRES_EDMA3CHAN_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga44e66cb70f336bdb105e54983930c8e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN2_Obj *</type>
      <name>IRES_EDMA3CHAN2_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gac7ec31fb6115f2df8b43f0a66d3bb09f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_PaRamStruct</type>
      <name>IRES_EDMA3CHAN_PaRamStruct</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga3d1f7dd722d7b1eac3940a6d0eff63c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_ProtocolArgs</type>
      <name>IRES_EDMA3CHAN_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga4f0e8e331a7135fa21c62da8e1d3fced</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_Obj</type>
      <name>IRES_EDMA3CHAN_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga8910a3fc26939a5f592191fb4400d0d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_EDMA3ShadowRegister</type>
      <name>IRES_EDMA3CHAN_EDMA3ShadowRegister</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaa2977a19f877b1d3cf7538c3457db58d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_EDMA3DraeRegister</type>
      <name>IRES_EDMA3CHAN_EDMA3DraeRegister</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga0a01c3ca97f02a526edb0360eff504ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_EDMA3RegisterLayer</type>
      <name>IRES_EDMA3CHAN_EDMA3RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga2ceee1967c04a37f016e0184b5f6040d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_Properties</type>
      <name>IRES_EDMA3CHAN_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga271d231160ea9cf90f4387b7aecfb34e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_EDMA3CHAN_DmaDestType</type>
      <name>IRES_EDMA3CHAN_DmaDestType</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaa2c61cb7db74a0e2cef3e3c66c383b68</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN2_Obj</type>
      <name>IRES_EDMA3CHAN2_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga5734d8411fde66f0d75892044293e9f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_EDMA3CHAN_DmaDestType</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga6cbd16008d4c8eb007e03412b12fc778</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INTMEMORY0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778ab5b71d03e8f43daec2d60476de20257e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INTMEMORY1</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a3f2d454aa72ffcc696235a4e921e1081</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INTMEMORY2</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a17aba04c48a2fce4159b46fb3e805611</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EXTMEMORY0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778accf6cc4da6f9f212df339285116ceb00</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EXTMEMORY1</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a2cce7020b1c9fd276443476c35340648</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EXTMEMORY2</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a576ed3797b9afdbd3631f744b4890de6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OTHER0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778af83122691b069425c9650cc7ad3ce13e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OTHER1</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a89480a70e3af20e73e799ae2bb07bfae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_hdvicp.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/hdvicp/</path>
    <filename>ires__hdvicp_8h</filename>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gaf41453e3afb59b32d1a0c41961fe50a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDVICP_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gab17613f289eb3239624de87c31d57116</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_HDVICP_ProtocolArgs</class>
    <class kind="struct">IRES_HDVICP_Obj</class>
    <class kind="struct">IRES_HDVICP_RegisterLayer</class>
    <class kind="struct">IRES_HDVICP_Properties</class>
    <member kind="typedef">
      <type>struct IRES_HDVICP_Obj *</type>
      <name>IRES_HDVICP_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gafcb53c4662e46499ee68c7dfad662bfa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_HDVICP_RequestType</type>
      <name>IRES_HDVICP_RequestType</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga4019a15f38f2854f0e52f457d724449b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_ProtocolArgs</type>
      <name>IRES_HDVICP_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga0aeea51623159606d5bc6a7a15ed4043</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_Obj</type>
      <name>IRES_HDVICP_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gad85f85ba4b0fdaf7cf9e8921cad229fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_RegisterLayer</type>
      <name>IRES_HDVICP_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga36d6cd1fdd8c0a88840e5b6af0fabd0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_Properties</type>
      <name>IRES_HDVICP_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga7a41d6c63373b559c3fc5ee90280d4ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_HDVICP_RequestType</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga995d4dd1dfb80daa5eb01690cc33cc7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_HDVICP_ID_0</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gga995d4dd1dfb80daa5eb01690cc33cc7fa10e2fb6fd933237adb33843bb400a4a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_HDVICP_ID_1</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gga995d4dd1dfb80daa5eb01690cc33cc7fa5073e858122fda35b61a1ec8e991aadf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_HDVICP_ID_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gga995d4dd1dfb80daa5eb01690cc33cc7fa33f3ada2c7cd3a08688432d3ba84f65b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_hdvicp2.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/hdvicp/</path>
    <filename>ires__hdvicp2_8h</filename>
    <includes id="xdas_8h" name="xdas.h" local="no" imported="no">ti/xdais/xdas.h</includes>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <includes id="ires_8h" name="ires.h" local="no" imported="no">ti/xdais/ires.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga6e9fc2b0904862eb35cf23ec5d06fd31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDVICP2_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga9c465c385b96523dd172495898a2a648</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_ID_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga5036e671af0585ea57d8e0197e4e90ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_ID_LATE_ACQUIRE</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga64e2059f8468faeac050da0d3db026f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_INVALID_ADDR</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga58cf2d89d0831f062da6b1392dc2630a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_TIMEOUTFOREVER</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga02602060d994d0ee40fade0f38475687</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_UNKNOWNLATEACQUIREARG</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga89573d4d420b01f3b2c3bedb20e52dab</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_HDVICP2_ProtocolArgs</class>
    <class kind="struct">IRES_HDVICP2_Obj</class>
    <class kind="struct">IRES_HDVICP2_RegisterLayer</class>
    <class kind="struct">IRES_HDVICP2_Properties</class>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_Obj *</type>
      <name>IRES_HDVICP2_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gadd0f77cea05c41ade2f2f6c29937eb7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_YieldArgs(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_GetYieldArgsFxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga88a7872c89c42689a690e9224e901fc2</anchor>
      <arglist>)(Int scratchId)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_YieldFxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gae92841af2ce526bc95a26e1c9037cf5d</anchor>
      <arglist>)(IRES_YieldResourceType resource, IRES_YieldContextHandle ctxt, IRES_YieldArgs args)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_ProtocolArgs</type>
      <name>IRES_HDVICP2_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga01d21d4eea4b38bba75890a474f5e146</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>IRES_HDVICP2_CallbackFxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga0aa568ca2dca0947909f348e8893b4fd</anchor>
      <arglist>)(IALG_Handle handle, Void *args)</arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_HDVICP2_Status</type>
      <name>IRES_HDVICP2_Status</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga4d0929cc91ef9058c626bc3f8eb5a580</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_Obj</type>
      <name>IRES_HDVICP2_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gab164d36df22fa1187459bf656fb41f83</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_RegisterLayer</type>
      <name>IRES_HDVICP2_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gab207e5ba3c1be67f41aca898cd1af06c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_Properties</type>
      <name>IRES_HDVICP2_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga347620d5e79bdf4a441045fe9a5efc21</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_Status(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_GetHdvicp2Fxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga089e51e6e0c15b71b6d05f90a805eb7a</anchor>
      <arglist>)(XDAS_Int32 *Id, IALG_Handle alg, IRES_HDVICP2_Handle handle)</arglist>
    </member>
    <member kind="typedef">
      <type>IRES_Status(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_FreeHdvicp2Fxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga4f046888c3242b7bc777fb0922e09c01</anchor>
      <arglist>)(XDAS_Int32 Id, IALG_Handle alg, IRES_HDVICP2_Handle handle)</arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_HDVICP2_Status</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga918fdab9a544c5ffcc1e76117d0f79f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SAMECODEC</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gga918fdab9a544c5ffcc1e76117d0f79f6a9d9e226b105a5fb9f07837c802b899be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SAMECODECTYPE</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gga918fdab9a544c5ffcc1e76117d0f79f6a1973caa402d1fcba41cb15d1472afb65</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DIFFERENTCODEC</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gga918fdab9a544c5ffcc1e76117d0f79f6a19f7f16190662b5b92b9d929d9bcbf40</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_timeoutVal</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga5b423e92e03fa325059695a892b2af42</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_sdma.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/sdma/</path>
    <filename>ires__sdma_8h</filename>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_SDMA_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga6f5038b490bc0ecbf3d21e456c4267e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SDMA_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga0a5073bdc48b6a191ca5ccc325c6d6e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SDMA_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>gab78a0b270839010ccf0882267d4232b3</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_SDMA_ProtocolArgs</class>
    <class kind="struct">IRES_SDMA_Obj</class>
    <class kind="struct">IRES_SDMA_RegisterLayer</class>
    <class kind="struct">IRES_SDMA_Properties</class>
    <member kind="typedef">
      <type>struct IRES_SDMA_Obj *</type>
      <name>IRES_SDMA_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga74d315505deba9f15f679b0df065a63a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_ProtocolArgs</type>
      <name>IRES_SDMA_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga90f6032407d4fe00c5bf0d389c238936</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_Obj</type>
      <name>IRES_SDMA_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>gaa172cc0d89b876e04d5de97512fdba2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_RegisterLayer</type>
      <name>IRES_SDMA_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>gac3f36f80a4634e8175def63b5510c010</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_Properties</type>
      <name>IRES_SDMA_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga0946214387330b97290cb94b3c3e7d69</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_tiledmemory.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/tiledmemory/</path>
    <filename>ires__tiledmemory_8h</filename>
    <includes id="xdas_8h" name="xdas.h" local="no" imported="no">ti/xdais/xdas.h</includes>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <includes id="ires_8h" name="ires.h" local="no" imported="no">ti/xdais/ires.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_TILEDMEMORY_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga68b4b8898e77e090fd96541494fa6422</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TILEDMEMORY_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga623d30fd5f51a591fb1d7ba6bedd0dab</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_TILEDMEMORY_ProtocolArgs</class>
    <class kind="struct">IRES_TILEDMEMORY_Obj</class>
    <class kind="struct">IRES_TILEDMEMORY_RegisterLayer</class>
    <class kind="struct">IRES_TILEDMEMORY_Properties</class>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_Obj *</type>
      <name>IRES_TILEDMEMORY_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga30b122a78fafc18f16f4b584c55ddf39</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_TILEDMEMORY_AccessDimension</type>
      <name>IRES_TILEDMEMORY_AccessDimension</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gaa6cd7292c7e04c77735f0d9b2c0e6a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_TILEDMEMORY_AccessUnit</type>
      <name>IRES_TILEDMEMORY_AccessUnit</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga9a4638e18510604f93bafbaac2d85917</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_ProtocolArgs</type>
      <name>IRES_TILEDMEMORY_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga87e40295a0e896827ff16239c6677182</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_Obj</type>
      <name>IRES_TILEDMEMORY_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga7bd47c3771425981890d1973719bc4e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_RegisterLayer</type>
      <name>IRES_TILEDMEMORY_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gae5bceac65ea5bf226b3985d0a45703a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_Properties</type>
      <name>IRES_TILEDMEMORY_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga3a240a3b912b366e5925b5d4348fe2cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_TILEDMEMORY_AccessDimension</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga6bf19883a3a359c69a7a7cc98b9fb974</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_1D</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gga6bf19883a3a359c69a7a7cc98b9fb974aa4c4820939a3d136b7412f4131aa4df6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_2D</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gga6bf19883a3a359c69a7a7cc98b9fb974a16614330631204f327e743cee9ab1357</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_TILEDMEMORY_AccessUnit</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gac19627dfd380195372144adab80be234</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_RAW</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a98d37e79007bfd16071e40ed1ccb1cd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_PAGE</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234afd35cbb38321a68e4ead2e4658d0c753</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_8BIT</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a7794d72ff22924c113b493852bf13889</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_16BIT</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a6aa4e8e64e0943270bef27b7e554a938</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_32BIT</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a83c19b1f33e69296e7468c3963fe99c9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_vicp.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/vicp/</path>
    <filename>ires__vicp_8h</filename>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>gab443b20263d6d15d38353016d2caef35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga8f238b30de8eb64ef69362f215837eb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VICP_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga6ed720f53f0ec97580795ac36998cc32</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_VICP_ProtocolArgs</class>
    <class kind="struct">IRES_VICP_Obj</class>
    <class kind="struct">IRES_VICP_Registers</class>
    <class kind="struct">IRES_VICP_Properties</class>
    <member kind="typedef">
      <type>struct IRES_VICP_Obj *</type>
      <name>IRES_VICP_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>gaa23fbe3626f54ecc7754e908083f5f14</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_ProtocolArgs</type>
      <name>IRES_VICP_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga6b0466ea2e923232a5f2bf5d99b83663</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_Obj</type>
      <name>IRES_VICP_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga78dd89d90d8364d4ff126b4647228819</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_Registers</type>
      <name>IRES_VICP_Registers</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga12d9b10adf3be5345c5acf16def14707</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_Properties</type>
      <name>IRES_VICP_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>gad8355b5acd95ef810245a947c87a3847</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ires_vicp2.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/vicp/</path>
    <filename>ires__vicp2_8h</filename>
    <includes id="ires_8h" name="ires.h" local="no" imported="no">ti/xdais/ires.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gae2d7e5517bd4a4fdc625666e6c5e5adc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga567229a2f3e00e0e9d21466ed3431cf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VICP2_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaf4c222d61975761f507563a64ab2e8c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_NUMBUFFERS</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaab43148f463371e818a2bb4aa54a7ff0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_BADRESOURCE</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga21eacd7bd8df315da75eead42c69980f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_A</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga93f6c8f9399b62b77358b09b454f1bc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_B</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga7ce68338708f75417578a42e669a3bd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_C</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga651aab779daf95714fc9d4ebbb837025</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_D</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaefc079a47ad6c8b93280472c76489660</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_E</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga36eb2584901bebbb66196bcee110cf8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX0COEFFBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga65bcf315a5d316aaa3e9ab395d2471c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX0CMDBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga1e290134e965fe4a3129f2e2900e7edc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX1COEFFBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga26c31d6fb96a6de743eb2fe693722d79</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX1CMDBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga83ee7ac9cb91930315fe6e0763346047</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_BABYIMXCMDBUFFER</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gab37b9a7af92de477047cf405a34830ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_BABYIMXORIGBUFFER</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gada76039b30f0da7e1f64e62d7d92a573</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_BABYIMXREFBUFFER</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga3f39a6e3bd2bae22df6b420492f8e530</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_SEQUENCERPMEM</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga885d3ffb844c718affe4ab6fa1d82834</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_QIQMEM</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga3754ea74dcb47df85544679a4f790794</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_HUFFMEM</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gacb0523b1f612e97c672d11cf67576f39</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_SEQBUF4</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaf8d8060812977a94c17eb6c0e9e3c944</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_VICP2_ProtocolArgs</class>
    <class kind="struct">IRES_VICP2_Obj</class>
    <class kind="struct">IRES_VICP2_Buffers</class>
    <class kind="struct">IRES_VICP2_Properties</class>
    <member kind="typedef">
      <type>struct IRES_VICP2_Obj *</type>
      <name>IRES_VICP2_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga7297c0d312df3cd6451bdd413ab87e23</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_ProtocolArgs</type>
      <name>IRES_VICP2_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga62fcd51447b19beb9b35180fc28a2087</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_Obj</type>
      <name>IRES_VICP2_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga654e036e45b2ffc40744c5e2316c65b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_Buffers</type>
      <name>IRES_VICP2_Buffers</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga31f4217206b6254628cd32ffad288e6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_Properties</type>
      <name>IRES_VICP2_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gac0df1fe8d22042b361fd4b66f5917dd4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/</path>
    <filename>iresman_8h</filename>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <class kind="struct">IRESMAN_Params</class>
    <class kind="struct">IRESMAN_Fxns</class>
    <member kind="typedef">
      <type>Bool(</type>
      <name>IRESMAN_PersistentAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga830cdb9915da5147ad73e1e8acc18840</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(</type>
      <name>IRESMAN_PersistentFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga3b947da470d58722a8c78073df3c6fd9</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_Params</type>
      <name>IRESMAN_Params</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga2a8b6374104f86177742127e0e9db690</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_Fxns</type>
      <name>IRESMAN_Fxns</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga3ccaac5d069a8c8d1f136c29bf3cbeb0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_edma3Chan.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/edma3chan/</path>
    <filename>iresman__edma3_chan_8h</filename>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <includes id="iresman__protocol_8h" name="iresman_protocol.h" local="no" imported="no">ti/sdo/fc/ires/iresman_protocol.h</includes>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_EDMA3CHAN_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaeb774220d0deb5da8bbfe8aa25c15094</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_EDMA3CHAN_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga695084a1271cf138b383a2a7c42e1e20</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_EDMA3CHAN_init</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga941b3ff64286bcfaa3bb5205bb669d55</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_EDMA3CHAN_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gac67268cf9b8f5bf523caffebfe8dc148</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_EDMA3CHAN_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gad30ebcbc0fed976c39cdf716677b2080</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_EDMA3CHAN_freeHandle</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gabd5e4de994bdaf06fe5a45f5c41fe265</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_Edma3ChanParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_Edma3ChanParams</type>
      <name>IRESMAN_Edma3ChanParams</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga6f72d404957e3bde256dab036a6ee460</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_EDMA3CHAN</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga7fb20979fe105a5310a48f2b2ccaf8c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_ConstructFxns</type>
      <name>IRESMAN_EDMA3CHAN_CONSTRUCTFXNS</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gae89c5c3a2256543b6e7694cc91040be7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_hdvicp.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/hdvicp/</path>
    <filename>iresman__hdvicp_8h</filename>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_HDVICP_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga263a6e5378a5a80ec72cbe1e1996d4e1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_HDVICP_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga1e6757007676bb59bc49b976c7082d68</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_HDVICP_init</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga9b2d49524494e6c589a17b8d3f6e2b83</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_HDVICP_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga66e789620a153083717fe8b73f576ad8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_HDVICP_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga91dcd1ec36206aeb58649b7361d7904b</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_HDVICP_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga8082e13e6d0f726991c2e78659f7d82c</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga626db578ddcda783f8354c734b51a876</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRESMAN_HdVicpParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_HdVicpParams</type>
      <name>IRESMAN_HdVicpParams</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>gaa0cc26209d78b2914c0353319983e7b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_HDVICP</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga3f269556325eb4b7ac1b7aad594e3f6c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_protocol.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/</path>
    <filename>iresman__protocol_8h</filename>
    <includes id="ires__common_8h" name="ires_common.h" local="no" imported="no">ti/xdais/ires_common.h</includes>
    <class kind="struct">IRESMAN_ConstructArgs</class>
    <class kind="struct">IRESMAN_ConstructFxns</class>
    <member kind="typedef">
      <type>struct IRESMAN_ConstructArgs</type>
      <name>IRESMAN_ConstructArgs</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga93fe96948b8c064f1244daae12abba54</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_ConstructFxns</type>
      <name>IRESMAN_ConstructFxns</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>gab9da36e13f19c05d045611d22e23f184</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_sdma.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/sdma/</path>
    <filename>iresman__sdma_8h</filename>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_SDMA_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga42a8ea015edf0a5d67a54be0db2459a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_SDMA_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gafaf6ada6499a564c06d2dce367a5e467</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_SDMA_init</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga8d1a94f3299d0944a6718fb18a18231d</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_SDMA_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga8ca00c2a884b82b77af70fc369f7e49a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_SDMA_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga138711df4f41e30a525b7fe2b5af362b</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_SDMA_freeHandle</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gafabf88b625a9e11f22bb50de925e2b1e</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_SdmaParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_SdmaParams</type>
      <name>IRESMAN_SdmaParams</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gafaaad7c24ff6340d34d7ea34edc0b339</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_SDMA</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga630a46a77d5ce6c783835952a27f71c3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_tiledmemory.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/tiledmemory/</path>
    <filename>iresman__tiledmemory_8h</filename>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_TILEDMEMORY_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gabea58ade569b614d4b8c55f455ea2833</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_TILEDMEMORY_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga4832f10ae177316cf1e73a29c6713531</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_TILEDMEMORY_init</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gaf0587262c783dfdf65faaaf6eea0807a</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_TILEDMEMORY_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga9415a0ced325b5467295b8771e52d304</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_TILEDMEMORY_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gadfa289400bc20009f0a0758bc7087aea</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_TILEDMEMORY_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gac62245768c47931560eeed6d7d73e02b</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_TILEDMEMORY_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga397775317ba851a3c541c861dc455c67</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRESMAN_TiledmemoryParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_TiledmemoryParams</type>
      <name>IRESMAN_TiledmemoryParams</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga53b69a325a2aef702b5627cc01f49400</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_TILEDMEMORY</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gab09c8ecb9ece591a08a86b0b4a51ee23</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_vicp.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/vicp/</path>
    <filename>iresman__vicp_8h</filename>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_VICP_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga4bf0fa4a35386dcd6f04c16a468984dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_VICP_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga01841f095420ce69ce02aaf644d7250d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP_init</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga613cdf62d35efa5fb1a02f9e07c73dd9</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga5d1eb79a6ad9c7a9e75fe48d70a2da58</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_VICP_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga64636048ebc7e7a1a41e96552297f022</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>gaa7bb21ce4147fab50131169877ab7f37</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_VicpParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_VicpParams</type>
      <name>IRESMAN_VicpParams</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga29f8ab6aaf9a18490216e300f12d2522</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_VICP</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga45a0fdbcf9e8610a403161583983578d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iresman_vicp2.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/vicp/</path>
    <filename>iresman__vicp2_8h</filename>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_VICP2_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga3a17b5082edb683f905b8c4db50b7a21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_VICP2_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga2cbfd0894487f1bcb1dd8135453c1637</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP2_init</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gadd12c0a525f152ac57507f77f9cf5a62</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP2_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gabaee5f47990c9c7c661313ab4fca3943</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_VICP2_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gadb99a3dd012edcd0b085f0a75a4b2385</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP2_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga493de59a219f0f9ff5991e40baf295bf</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_VicpParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_VicpParams</type>
      <name>IRESMAN_VicpParams</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga29f8ab6aaf9a18490216e300f12d2522</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_VICP2</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga0cdcf22338a1507b35a1631b87f592d6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>memutils.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/memutils/</path>
    <filename>memutils_8h</filename>
    <member kind="function">
      <type>Void</type>
      <name>MEMUTILS_cacheInv</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>gad07c8ac40bec004e2cc0a386f86570dd</anchor>
      <arglist>(Ptr addr, Int sizeInBytes)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>MEMUTILS_cacheWb</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>ga9ec3a005cfbd44003b9dc57e737d32b1</anchor>
      <arglist>(Ptr addr, Int sizeInBytes)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>MEMUTILS_cacheWbInv</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>ga3ecacfd8a0771af6d1a532fbbe35adfe</anchor>
      <arglist>(Ptr addr, Int sizeInBytes)</arglist>
    </member>
    <member kind="function">
      <type>Void *</type>
      <name>MEMUTILS_getPhysicalAddr</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>gae67c1ceb1e529cbb9b10abee89101f75</anchor>
      <arglist>(Ptr addr)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MEMUTILS_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>gaad6bedcf19bfc91b3b86ae7640ea7a9e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RcmClient.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/rcm/</path>
    <filename>_rcm_client_8h</filename>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_acquireJobId</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga1ca1095af911e152f3c2f1413435c000</anchor>
      <arglist>(RcmClient_Handle handle, UInt16 *jobId)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_addSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gad4a99b35c6b2559efa025ec082bc8672</anchor>
      <arglist>(RcmClient_Handle handle, String name, Fxn addr, UInt32 *index)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_alloc</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga208ac0778da226dede7ca9a0347be396</anchor>
      <arglist>(RcmClient_Handle handle, UInt32 dataSize, RcmClient_Message **message)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_checkForError</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga159d59d3bf1a9cdce0a182b193aa83d2</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_construct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaaacfb4d851275706e163e1ba673b9564</anchor>
      <arglist>(RcmClient_Struct *structPtr, String server, const RcmClient_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_create</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaebe8bf5700c7a702ef8fd8a85fc90952</anchor>
      <arglist>(String server, const RcmClient_Params *params, RcmClient_Handle *handle)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_delete</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf329381265fcec015e9bd8e340bc4e7a</anchor>
      <arglist>(RcmClient_Handle *handlePtr)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_destruct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gacfefde73bc566613b9fe09d2ee4cebcc</anchor>
      <arglist>(RcmClient_Struct *structPtr)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_exec</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf1fd561fb60afc8230358f38fd7194a6</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execAsync</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga950cbd891b6ae4cd59b6c9fe12fcfa5a</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, RcmClient_CallbackFxn callback, Ptr appData)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execCmd</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga7a937da523a65f27357200560a8e8d89</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execDpc</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gacb3388f3a4646c3a44516d01bb941a11</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execNoWait</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga00270eeec2f9efa1a06db5f2c727146f</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, UInt16 *msgId)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmClient_exit</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gafcbe8036ad282bbe432c02b293592f31</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_free</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga3b76d9403edf28dd7067f6413f2e6dba</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *msg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_getSymbolIndex</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga47d577ba88e270e29f00f90ae188aca5</anchor>
      <arglist>(RcmClient_Handle handle, String name, UInt32 *index)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmClient_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae8d23222b6fa4239e04e0a816c0b3a1b</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmClient_Params_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae8cd1b3d8ed02000676760a36c917eb0</anchor>
      <arglist>(RcmClient_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_releaseJobId</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga9644bb7b1b8d0f5d1b382353c2f3dc6d</anchor>
      <arglist>(RcmClient_Handle handle, UInt16 jobId)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_removeSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga107fa5f86177f7f94c62e5cf4c37fa85</anchor>
      <arglist>(RcmClient_Handle handle, String name)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_waitUntilDone</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gac413e8c8ab42cf489bd728ec0fb4fbd9</anchor>
      <arglist>(RcmClient_Handle handle, UInt16 msgId, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_S_SUCCESS</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga6cae0be521867514327de0ecc178e97e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_FAIL</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga5675ad080d5cfee20f983248f9a9a0fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_EXECASYNCNOTENABLED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga4278ec3a1f74d36240fe6bcebb347dcb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_EXECFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga1f370ba6eb5d5c095d5024e695c32d98</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_INVALIDHEAPID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga757b3e821874ff8cdef8bc686e46f28e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_INVALIDFXNIDX</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga8d100f828f732ccdb96a775b4b3acbbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGFXNERROR</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga6b23d24fe17b1bd959ff5ea33d9af8e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_IPCERROR</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gab8098ffd2e3d0a79f98d38ae3bd7b4a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_LISTCREATEFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gad9df39f75871e95d5ce1cbe59465d392</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_LOSTMSG</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga9a1521f72a530e1a9e0b79e3a63538f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGALLOCFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga35af60cede2baccd1f800f1ddbe36de1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGQCREATEFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gad00e49b18709c2319629baa270f347f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGQOPENFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gac7d3fc2d71549991d983040539ecf4d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_SERVERERROR</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga86c9602522a507759580f7839c3b9397</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_SERVERNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf75a16dc21df81d847982ee1ca21f008</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_SYMBOLNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gab3663b04476ee6485aff5bd0fa536259</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_NOMEMORY</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaaa1be00b719d55294eebdce068865875</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_JOBIDNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga8844458810de28658226aa3b0a269a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_INVALIDFXNIDX</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae0872f1d229d368770f6e620f1e81016</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_INVALIDHEAPID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae0d3774d8702446a63c7a425feef10d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_INVALIDMSGID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga7fd49181c3df5128cd9d2e8042f26f34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_DEFAULTPOOLID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga9ae2956af2a09e0af7864cdf36151f0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_DISCRETEJOBID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf23dbd2ea2d1ff26a4643c63b1cd585d</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">RcmClient_Message</class>
    <class kind="struct">RcmClient_Params</class>
    <class kind="struct">RcmClient_Struct</class>
    <member kind="typedef">
      <type>struct RcmClient_Object_tag *</type>
      <name>RcmClient_Handle</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga8c8262c5fbdb3de810b3e18d73b0b57c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>RcmClient_CallbackFxn</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga1a5ec28a9cb0b70076099912b55657e8</anchor>
      <arglist>)(RcmClient_Message *, Ptr)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RcmServer.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/rcm/</path>
    <filename>_rcm_server_8h</filename>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_addSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga9126aa462aff2c9ef26ac5dcacbb531f</anchor>
      <arglist>(RcmServer_Handle handle, String name, RcmServer_MsgFxn addr, UInt32 *index)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_construct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gaa79f4ab038b790fe3384b33a28bf127e</anchor>
      <arglist>(RcmServer_Struct *structPtr, String name, const RcmServer_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_create</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gaac1a45f82e40e83b825be5705437e4c8</anchor>
      <arglist>(String name, RcmServer_Params *params, RcmServer_Handle *handle)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_delete</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gad003898cd71b28429552b13b87551da9</anchor>
      <arglist>(RcmServer_Handle *handlePtr)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_destruct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gabeaa0ddc38279784d7100f5456d89254</anchor>
      <arglist>(RcmServer_Struct *structPtr)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmServer_exit</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga8b95234ed5228d815bb3241008567fce</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmServer_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga05a70dbd79151489d90f1de4680c4555</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmServer_Params_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gaf72c2963894c2667c762b59aa87a690d</anchor>
      <arglist>(RcmServer_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_removeSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga4c81d6367a2e0767974625f4b44e7811</anchor>
      <arglist>(RcmServer_Handle handle, String name)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_start</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga5f80ea61e02ec783341f4362c8a572e3</anchor>
      <arglist>(RcmServer_Handle handle)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_S_SUCCESS</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga72c9606751a94487f21490d5a6d16281</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_FAIL</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gabae883b517fb29ba2448087f45524a6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_NOMEMORY</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga9c4fe2cfcb8fec9aca38cccf930902c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_SYMBOLNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga414bf0858222ae94bd7890a9100d257b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_SYMBOLSTATIC</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga064852117a1c99faa0f0c8f74d5e67af</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_SYMBOLTABLEFULL</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga9744b10c8957c6138d22bcb85f93afca</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">RcmServer_FxnDesc</class>
    <class kind="struct">RcmServer_FxnDescAry</class>
    <class kind="struct">RcmServer_ThreadPoolDesc</class>
    <class kind="struct">RcmServer_ThreadPoolDescAry</class>
    <class kind="struct">RcmServer_Params</class>
    <class kind="struct">RcmServer_Struct</class>
    <member kind="typedef">
      <type>Int32(*</type>
      <name>RcmServer_MsgFxn</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga62c6104fd28f253e06ade10386ec4bc0</anchor>
      <arglist>)(UInt32, UInt32 *)</arglist>
    </member>
    <member kind="typedef">
      <type>struct RcmServer_Object_tag *</type>
      <name>RcmServer_Handle</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga443465f4892e66d44fdd77da82414d46</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rman.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/rman/</path>
    <filename>rman_8h</filename>
    <includes id="ires_8h" name="ires.h" local="no" imported="no">ti/xdais/ires.h</includes>
    <includes id="iresman_8h" name="iresman.h" local="no" imported="no">ti/sdo/fc/ires/iresman.h</includes>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_init</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga2553157eede6b63b0037b0db72fbdae8</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_exit</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaedbbc06da21c2e842c890d4ff4ac9aed</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_register</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gae8fe0e0bcdcb46afb0d09d1997136347</anchor>
      <arglist>(IRESMAN_Fxns *resmanFxns, IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_unregister</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa6f966711380ecf89ad79db2ebf8619a</anchor>
      <arglist>(IRESMAN_Fxns *resmanFxns)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_assignResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa7772ccd9856ccc0b0492c018807b2b3</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_allocateResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga0fdeaec06650e512ffd765613a3accaf</anchor>
      <arglist>(Int requestId, IRES_ResourceDescriptor *resDesc, Int numResources, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_freeResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga98911d4d4049d1805ae9eac2b71d9ec0</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_freeAllocatedResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gafac26c9edf744af2d0b1f4f24862975b</anchor>
      <arglist>(Int requestId, IRES_ResourceDescriptor *resDesc, Int numResources, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_activateResource</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga3135611a668b07aad926247bbd0e37a9</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle resourceHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_activateAllResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga354e1ad9ac34e6c41b0bd2184bc3e9fb</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_deactivateResource</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga1c20b46e28a17783654674f9e109e46e</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle resourceHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_deactivateAllResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga7343843e4acd15df9997315b4cb9bcf3</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>RMAN_yield</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa9da95739776c293fb4e27ec5207a668</anchor>
      <arglist>(IRES_YieldResourceType resource, IRES_YieldContextHandle algYieldContext, IRES_YieldArgs yieldArgs)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ti_sdo_fc_ires_NOPROTOCOLREV</name>
      <anchorfile>rman_8h.html</anchorfile>
      <anchor>a33eacaa6cefc41cfe527b740449250dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RMAN_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga2df9395a0c498e45a8fb68942197a9eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RMAN_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga548fc91df8bfb9a8a30cbaab812110c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RMAN_PROTOCOLNAMESIZE</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga69dd3d9e63a604b0cb10037c60bfd4fa</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">RMAN_Params</class>
    <member kind="typedef">
      <type>struct Sem_Obj *</type>
      <name>RMAN_SemHandle</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga841a70da51acb69fde1f53d60faae1bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_YieldArgs(*</type>
      <name>ti_sdo_fc_rman_RMAN_YieldArgsFxn</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga3b8309d40495cb499b09ce358ebfc029</anchor>
      <arglist>)(Int scratchId, Bool yieldFlag)</arglist>
    </member>
    <member kind="typedef">
      <type>struct RMAN_Params</type>
      <name>RMAN_Params</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga2b477ea38c1ae71bc320a1384f6b536e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ RMAN_Params</type>
      <name>RMAN_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gae12d774b050c8c27f780ed91dd7c2a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_Fxns *</type>
      <name>RMAN_TABLE</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gab2ff62cddcbbbd3c6a2819703a96bcca</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ short</type>
      <name>RMAN_FREE_ENTRIES</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga758ab45c1418c384bf578ea5558b9d7b</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ short</type>
      <name>RMAN_numRegistryEntries</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga60e319affb35f0df44bfa9e5576cbd05</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_Fxns **</type>
      <name>RMAN_registryEntries</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gae4b796a7aead262ea31848120b07d54d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_Params **</type>
      <name>RMAN_registryResmanArgs</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga4a461e9e2f1b613ef55dbe4574abd5b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ unsigned int **</type>
      <name>RMAN_iresVTable</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga343604b8ef45f3565e25b0ea911a4173</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ unsigned int</type>
      <name>ti_sdo_fc_rman_RMAN_MAXALGS</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga8ec03181fc11e30d8c10c7eb54d248d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt32</type>
      <name>ti_sdo_fc_rman_RMAN_ipcKey</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa67b89289e5ff8dab19e2c011417dabb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ti_sdo_fc_rman_RMAN_YieldArgsFxn</type>
      <name>ti_sdo_fc_rman_RMAN_setYieldArgs</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gacfc9b966702c5a037e299e8b7b016ce3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>scpy.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/scpy/</path>
    <filename>scpy_8h</filename>
    <includes id="ires__sdma_8h" name="ires_sdma.h" local="no" imported="no">ti/sdo/fc/ires/sdma/ires_sdma.h</includes>
    <member kind="function">
      <type>void</type>
      <name>SCPY_init</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga1ab752be005b6c97dea0c75b816fea92</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_exit</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gad5bb9359e823883f9bdf583fb4bec6a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_configure</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gabc289b92aac62db2f16adc13a7169f38</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel, SCPY_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_start</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga12cc8c59549b30813a6602110282b9ca</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_wait</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gac68b099a8b213a12b199b9799540671e</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>SCPY_complete</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gace3ec3f056bad890e721fb2f7f19c543</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_DATA_TYPE_S8</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga258faf6d58227cba851a1e5e1f39f07f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_DATA_TYPE_S16</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga85fb4c8f497ebc94ab6dfafff20c8964</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_DATA_TYPE_S32</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gacb8aa19f5bcc98b70ccf5e3d0acb099e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_PORT_EMIFF</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gac5bd339b10aedbaff5a8c61e243ef146</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_CONST</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga9ffd54467a0a6eb22e845fced0abf1b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_INC</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gad3a6456aabb085058f234fd8fb389217</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_SINGLE_INDEX</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gad492a9de7f1b8a8ba250c6a83debcc69</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_DOUBLE_INDEX</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga7c1ca3f4716b7f6b53803c4a10c5cb25</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_MODE_ELEMENT</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga2bddc8d4bf3383645ba33e3eb1a346a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_MODE_FRAME</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga535e7376bc2fe197fd4cff1fbd398290</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_MODE_BLOCK</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gab4a43742db739f882df0473132757ab0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_TYPE_DEST</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga08deedaf80733d17c298b42ece800189</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_TYPE_SRC</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gaba29f0ffd8cafab068ed79cc3263d18a</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">SCPY_AddrParams</class>
    <class kind="struct">SCPY_TransferParams</class>
    <class kind="struct">SCPY_Params</class>
    <member kind="typedef">
      <type>struct SCPY_AddrParams</type>
      <name>SCPY_AddrParams</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga7eab68f6cccf9ce565e81b1265e2eccb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct SCPY_TransferParams</type>
      <name>SCPY_TransferParams</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga6f84be922917b08c9b84ec501fc46bd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct SCPY_Params</type>
      <name>SCPY_Params</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gac87af553e83f8583bb53fe7a68f48c12</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>xdas.h</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/xdais/</path>
    <filename>xdas_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>XDAS_TRUE</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga0a1e9fe6b661ca6eafe982fe2b0787bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>XDAS_FALSE</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga5cd894ca3ba5c100f7f863dae8587293</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void</type>
      <name>XDAS_Void</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga125aad4180e7ca9a3ddaba59c9217513</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint8</type>
      <name>XDAS_Bool</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gac8ce48f3d618a6f0a37b4e55f978b825</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Int8</type>
      <name>XDAS_Int8</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gaa0b0c4cc1bf0d8fa0d9b15de0e9204cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint8</type>
      <name>XDAS_UInt8</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gac9308edb855a360c27a47aaa6f3b39a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Int16</type>
      <name>XDAS_Int16</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga8189aa7a8636f505d6a35e5744ac6392</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint16</type>
      <name>XDAS_UInt16</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gaa27605972947c862397ebee40c2ff917</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Int32</type>
      <name>XDAS_Int32</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gae431579ed9eff9134de78ca00ddd5f3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint32</type>
      <name>XDAS_UInt32</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga615572fcd2279a6780dc1785d72ff421</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>ti_sdo_rcm</name>
    <title>Remote Command Message Overview</title>
    <filename>ti_sdo_rcm</filename>
    <docanchor file="index">modules</docanchor>
  </compound>
  <compound kind="page">
    <name>Disclaimer</name>
    <title></title>
    <filename>_disclaimer</filename>
  </compound>
  <compound kind="group">
    <name>ti_xdais_IALG</name>
    <title>IALG - XDAIS Algorithm Interface</title>
    <filename>group__ti__xdais___i_a_l_g.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IALG_DEFMEMRECS</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga8a220fa863380937542f6a38be47ceda</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_OBJMEMREC</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga0e3202a4d8dc0bd3cb300633922ffd54</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_SYSCMD</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga200f155f9e2720011270e99f17bb6675</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_EOK</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga2c15898121a23a164e4ea2bcc4f7e7dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_EFAIL</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga604e5600815cbd58846e0c5c05b6ba18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_CUSTOMFAILBASE</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga1f655af6b5ce37aaf5328243d1993cf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_CUSTOMFAILEND</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gafbab7f3470d8b5a46615f1aca5c739b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_MPROG</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga86018453b8f991c8cb545b2e43c80c9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_MXTRN</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gafc53b940e2982a2e859bda0555180eb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_isProg</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga93e8704d8e88d2f3dde1a85317232b59</anchor>
      <arglist>(s)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IALG_isOffChip</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gae2530ce6b07542f579871961a3fcfd4f</anchor>
      <arglist>(s)</arglist>
    </member>
    <class kind="struct">IALG_MemRec</class>
    <class kind="struct">IALG_Obj</class>
    <class kind="struct">IALG_Params</class>
    <class kind="struct">IALG_Status</class>
    <class kind="struct">IALG_Fxns</class>
    <member kind="typedef">
      <type>enum IALG_MemAttrs</type>
      <name>IALG_MemAttrs</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga20f514039bf67b319bff425fb8f36e5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IALG_MemSpace</type>
      <name>IALG_MemSpace</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga61ed32f432abc371aece4d839cdaee78</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_MemRec</type>
      <name>IALG_MemRec</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga99aa369e4d2b2e38444d7029ba09caed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Obj</type>
      <name>IALG_Obj</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga056d16e11872c72ef03832ebea91c946</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Obj *</type>
      <name>IALG_Handle</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga16c037803ea218ba3dc5158f55ef27c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Params</type>
      <name>IALG_Params</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gaa3e5c88152dd2b867de749e15c4bd01a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Status</type>
      <name>IALG_Status</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga9cb14b478af2c5636bfb8ba78d06c3ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned int</type>
      <name>IALG_Cmd</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga9032f20923ef2ba1d6b88c87a20075fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IALG_Fxns</type>
      <name>IALG_Fxns</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gaf97260de3299a9304375dedca698572a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IALG_MemAttrs</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga805f1c1330403c05633277a073862e3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SCRATCH</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga805f1c1330403c05633277a073862e3da85e0509f7e82ebd01b57f899122de9b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_PERSIST</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga805f1c1330403c05633277a073862e3da68adbe0194074e0474333b76f7d1e090</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_WRITEONCE</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga805f1c1330403c05633277a073862e3da42356e6aa11869bfd15f31472f49a7c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IALG_MemSpace</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>ga262eb64dc7343999fa07d535ae163497</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_EPROG</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a6410b22d1d073ab55b289ca2f3c03b35</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_IPROG</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a946577db145f691f81d7085fc51e2201</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_ESDATA</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a85fff905ed5e83445e3424ce5ba03175</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_EXTERNAL</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497aa98151c21c55ddaf8c1918d8007e5493</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_DARAM0</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497af6a85bf972a4d090e2c0e4d31565f879</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_DARAM1</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497ad7b3b18fc0263be0f0702d263f600d9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497aa5c6d8cfdb63c11fafd22bb87204c5cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM0</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a4b31d959f6af27a012a87957c05d9c4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM1</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a4ac938c5e58e4d4a30458b63869f0095</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_DARAM2</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a17fc19eac565b29871efbfed54760414</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IALG_SARAM2</name>
      <anchorfile>group__ti__xdais___i_a_l_g.html</anchorfile>
      <anchor>gga262eb64dc7343999fa07d535ae163497a6db79aaafcf9b4354f2828c2a94b8590</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_xdais_IDMA3</name>
    <title>IDMA3 - Interface for requesting EDMA3 resources</title>
    <filename>group__ti__xdais___i_d_m_a3.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IDMA3_PROTOCOL_NULL</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga85de540d61ac83857803528f25f44e4b</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IDMA3_MemRec</class>
    <class kind="struct">IDMA3_ChannelRec</class>
    <class kind="struct">IDMA3_Fxns</class>
    <class kind="struct">IDMA3_ProtocolObj</class>
    <class kind="struct">IDMA3_Obj</class>
    <member kind="typedef">
      <type>enum IDMA3_MemType</type>
      <name>IDMA3_MemType</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gad7dca268a0fb944ec7da970a7064c93b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_MemRec</type>
      <name>IDMA3_MemRec</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gad9a9dde19d244a4552965b14abe2d96f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_Obj *</type>
      <name>IDMA3_Handle</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga8960c528f0708a559bcaab34a865e1a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_ProtocolObj *</type>
      <name>IDMA3_ProtocolHandle</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gadd329735609d8384c3625554c0f2c58d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IDMA3_Priority</type>
      <name>IDMA3_Priority</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga04af272ab4f16153137e3f39856078d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_ChannelRec</type>
      <name>IDMA3_ChannelRec</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gac8af8b3447a5ae88f4b14dc96e18eee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_Fxns</type>
      <name>IDMA3_Fxns</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga02d106a910bf5561419a755ab7f97e03</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_ProtocolObj</type>
      <name>IDMA3_ProtocolObj</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ga6705287956a84beb7d6f0eee6b6dfb55</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IDMA3_Obj</type>
      <name>IDMA3_Obj</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gae5a0e05b6797ba0b914a41c90ea47a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IDMA3_MemType</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gabe0577eecc288b36121382daa765093a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_INTERNAL</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggabe0577eecc288b36121382daa765093aa120151b2c6d2d5bcb2d59466b0d13287</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_EXTERNAL</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggabe0577eecc288b36121382daa765093aa9e757f072f4782774d8cd4b647563c54</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IDMA3_Priority</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>gafa41dccd2cc8f94915fffdda2c8b4a59</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_URGENT</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a90abf287e878aedcfbc17d19266f207c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_HIGH</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a2bd88e579d019a160876842f0c92f325</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_MEDIUM</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a4f3bbe300c3ce513644f31991b6788ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDMA3_PRIORITY_LOW</name>
      <anchorfile>group__ti__xdais___i_d_m_a3.html</anchorfile>
      <anchor>ggafa41dccd2cc8f94915fffdda2c8b4a59a8560a79ce3c83622bed84ecb31b57aff</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>DSPIRES</name>
    <title>IRES</title>
    <filename>group___d_s_p_i_r_e_s.html</filename>
    <class kind="struct">IRES_YieldContext</class>
    <class kind="struct">IRES_Fxns</class>
    <member kind="typedef">
      <type>enum IRES_YieldResourceType</type>
      <name>IRES_YieldResourceType</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga772c04e720ba2b67b4204bbccbe40945</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>IRES_ContextSaveFxn</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gaa00576c8c0c6d1e2c01cc32788c597c9</anchor>
      <arglist>)(IALG_Handle algHandle, Void *contextArgs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>IRES_ContextRestoreFxn</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga618c74da111cc440a47fad6f7f575c89</anchor>
      <arglist>)(IALG_Handle algHandle, Void *contextArgs)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_YieldContext</type>
      <name>IRES_YieldContext</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gad70330927e4683909b1553bf0f2a5c75</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_YieldContext *</type>
      <name>IRES_YieldContextHandle</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gafd901eec352839470db8e386baa1be66</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void *</type>
      <name>IRES_YieldArgs</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gafb1e285a8d30b447dc39fe05d5e4fdf0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>IRES_YieldFxn</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga21803b9b676c2579e59909062dc40079</anchor>
      <arglist>)(IRES_YieldResourceType resourceType, IRES_YieldContextHandle algYieldContext, IRES_YieldArgs yieldArgs)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Fxns</type>
      <name>IRES_Fxns</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gad4918d3ae4c063a0bf6e76ac26c7c297</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_YieldResourceType</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga9a68e109e02bf3f35e832ec4f767d0a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ALL</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3a0fd0c33808e89762c91dca8c2edc6aef</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_SCRATCHMEMORY</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3a99a353ef5a76fad49a805f0e3ba6e8e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_SCRATCHDMA</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3aa8fe0182b728dbcd24900b9bf13221c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_RESOURCEHANDLE</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga9a68e109e02bf3f35e832ec4f767d0a3a737fd5b62997deb99125d2e0f4e47b74</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_Status</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga8db6eab013fc4569e080cb4361dfd65b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_OK</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba30253e67bb1b070685e4177bdf9587b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EALG</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba432505b3fc40c3ae60c7b36624dc100d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EEXISTS</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba5d1871ad076ad79c214cfe753f0513e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EFAIL</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba79fa1a926f2b780120951d084fcc3bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_EINIT</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65bacf083017e2e50c9f975e4d956d0dc440</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENOINIT</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba9cb3cdefe2de31efea9a9442e2ed7dd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENOMEM</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba72b429ce0c052c9fe5b079798ee08caa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENORESOURCE</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba82f5c8e224ec5ef57cae62a4e80bf2d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_ENOTFOUND</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gga8db6eab013fc4569e080cb4361dfd65ba077a2999bf874acf2b556347a3c71e5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_RequestMode</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_SCRATCH</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963a4edb7db0f8cd8780a263c1e8ec686aa0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_PERSISTENT</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963ab66403426900afab06c1459b4c8a1fc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_LATEACQUIRE</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga67d435865304c7bce199194e7ff07963aa8d4ddab65248eedc7d1ca3fb43a5ea2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_Status</type>
      <name>IRES_Status</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga09c6ef97314f2d27ce39bfcfac5da287</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_ProtocolRevision</type>
      <name>IRES_ProtocolRevision</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gaf7c3863c0ea3895fb86badf58b809a43</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_RequestMode</type>
      <name>IRES_RequestMode</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gae6d619d30b481ac725448b769d2ae2d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_ProtocolArgs</type>
      <name>IRES_ProtocolArgs</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga4808ad3c47785cbfb8a22bf50b096e11</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_ResourceDescriptor</type>
      <name>IRES_ResourceDescriptor</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga0b4bec3cd4dbe4556d72d9ed894d5246</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Properties</type>
      <name>IRES_Properties</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga2ef376adca27740ff8285b0d1b7e272b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Obj</type>
      <name>IRES_Obj</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>ga5d11994529489c6809bc2effd5f83f01</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_Obj *</type>
      <name>IRES_Handle</name>
      <anchorfile>group___d_s_p_i_r_e_s.html</anchorfile>
      <anchor>gad0e33217f411f69c326180854b9f1cea</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>DSPACPY3</name>
    <title>ACPY3 (C64P)</title>
    <filename>group___d_s_p_a_c_p_y3.html</filename>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_configure</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga7c968c0683e57ebaaa84f7428316b086</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_Params *params, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_fastConfigure16b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga9b4de2acd317d163d0a1183b0a91749a</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_ParamField16b fieldId, unsigned short value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_fastConfigure32b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga9c2c2ad10eda1f7f9b7c39e1ce6cb72e</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_ParamField32b fieldId, Uns value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_setFinal</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga8f4b393fa67f4344b49f8bf24a1b1e02</anchor>
      <arglist>(IDMA3_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_fastSetFinal</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga6bd96df00b973b8a22a736b913cbb53a</anchor>
      <arglist>(IDMA3_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_start</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gab4102200f00a9df3961a8374c0042bed</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_wait</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga499bc0643a52f5cfd0828c1ce21cd69b</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_waitLinked</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga1209333a83fe6a2b2c75d011dab09a25</anchor>
      <arglist>(IDMA3_Handle handle, unsigned short waitId)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>ACPY3_complete</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae22deca1f6878a359a619cff8654d9de</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>ACPY3_completeLinked</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga3a7afab3f58902acf651345505e6d0b5</anchor>
      <arglist>(IDMA3_Handle handle, unsigned short waitId)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_activate</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gaf9dc07965774895d79323a47b36cc442</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_deactivate</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2736d2e136e868577a71710571027de5</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_init</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gac79227aad8cb9f68ab67da77de81fd17</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_exit</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae7072f7010b53bdeab5ac76737b380af</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_GTNAME</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga9ac4b2a9bdc89338d486453e93aaf560</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_MODNAME</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga5e18ff4ee608d09809a0538c17fa94ed</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">ACPY3_Params</class>
    <member kind="typedef">
      <type>enum ACPY3_ParamField16b</type>
      <name>ACPY3_ParamField16b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae68edf9ac573c2b952a6d40e96103c01</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_ParamField32b</type>
      <name>ACPY3_ParamField32b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga6312b4a2db69af18b3f164836767abf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_TransferType</type>
      <name>ACPY3_TransferType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga730e4286738a2ed77e95b9f5338e719a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_Params</type>
      <name>ACPY3_Params</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae2796cd82f9251f4b6e4dede5b9602aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_ParamField16b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gaf9624d3d925ec0d15bd845967664e608</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTSIZE</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608af590c76a022dbe56043c8a0a577a88c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_NUMELEMENTS</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608ab95b07e80a06c8d2b0ccd191de1fb8aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTINDEX_SRC</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608aa3a4872acfc89e4da1820e0839b0fb87</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTINDEX_DST</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608aa1c08ec69ae102d758b8678c492038e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_FRAMEINDEX_SRC</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608acd1fe7c99a4596d8724a9cf359bf8f57</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_FRAMEINDEX_DST</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608aad2460b82b3834e625dcdb3e1e2c140c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_NUMFRAMES</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggaf9624d3d925ec0d15bd845967664e608a5593f2242b7d6741c9dcb4233909942d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_ParamField32b</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga96f43d4bc010da2d1bb9dc08ea828de0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_SRCADDR</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0a807013269912df7c5dbc2361483d2e1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_DSTADDR</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0a927624fccb072b2ff847a10c4729fedf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_ELEMENTINDEXES</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0ace2eb39c83c77fa1ee38d5c87e045e83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_PARAMFIELD_FRAMEINDEXES</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gga96f43d4bc010da2d1bb9dc08ea828de0a88347f099298128f5989f76636e64dc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_TransferType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gabe2d02fcbde983c823b138f20667cbfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_1D1D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfcaf9cef75ab1829399370006a48d16182e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_1D2D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfca7e3376fb0def5e38484dfb121e7b2fb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_2D1D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfca3ad50651b016c2c96f8fb6f724213623</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_2D2D</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ggabe2d02fcbde983c823b138f20667cbfcad8ac84d79831cfe53a4088a321989a85</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IDMA3_ProtocolObj</type>
      <name>ACPY3_PROTOCOL</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga7171d01619b7fc26dbb11eb9aaf1a3b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_INSTR_HookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_START_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6accd037f87563e0c241a9864c8e8e9590</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_START_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6a5588ac9c1ff6c4925392f50e6f731393</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAIT_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6a9fcc76fd464260e570c90525290ee14d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAIT_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gae02485e17a2ecea162a79e80fc0892e6abe7aad80582e0e0b3178ed75c204993e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ACPY3_INSTR_ExtendedHookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAITLINKED_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05af270a6b21f22cb41834a09e5fcaa7fa8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_WAITLINKED_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a8d848097c2f88c48856f0e12f36a09f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_ACTIVATE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05af08858cedaf5af244a28b03b0f585f16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_ACTIVATE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05acfc9d48e557e5020d68eac5a4a4defb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_DEACTIVATE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a833584c7662cb46bacf3bef67283456a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_DEACTIVATE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a200da6497c774857270e4fc39d0721f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a9a0a6b59022ef1516029bfc8078ca996</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a98691726530703faae4d97aeb3b02ab7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETELINKED_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a2851dab3b27da3b926a53f6d5d1353ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_COMPLETELINKED_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a591a8e532256855c4357b126b93622b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_CONFIGURE_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a64956372df6069db186f8f8c3c485203</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_CONFIGURE_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a0c66a6b4d3985e55e069678e9ef91004</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE16_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a3508a134cbdae98e84000fe171b6ee16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE16_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a6fde3b32ff50ca89aacbead84e71d76f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE32_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05ad7471a5e44a30928433f106a44935aaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_FASTCONFIGURE32_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05ad0be66b12acfbd49dfb73e7a73b145be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFINAL_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a118bb352f15b4e8869e31857b990077c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFINAL_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05a74aebc9d8fe0a6232acf0ad56ba5f612</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFASTFINAL_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05accd8c23a638c8a206536b9935792ef0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_SETFASTFINAL_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05addb6061f2df956cfcb5109447a063aa3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_INIT_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05adab51be6f7d31b79e5b5c064241490a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_INIT_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05abbcc98db88ad1d057b5ee53e1ca90cf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_EXIT_ENTER</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05ae1fdbc8fa67196f1b75f27e1af5904f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACPY3_INSTR_EXIT_EXIT</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga2413e5008c97def56d3a5108d458db05aa17392f0da11248926400167638da551</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_INSTR_HookType</type>
      <name>ACPY3_INSTR_HookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga59cfeeab682e4c6b55da00e0f5fce888</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ACPY3_INSTR_ExtendedHookType</type>
      <name>ACPY3_INSTR_ExtendedHookType</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga66c6cd00c1b29bfade8bb8f9d5f76f45</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>ACPY3_INSTR_HookFxn</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gac637aa469ae9eeb2e0a81009a52a0e6f</anchor>
      <arglist>)(IDMA3_Handle handle, void *param)</arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_INSTR_Hook</type>
      <name>ACPY3_INSTR_Hook</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gafa887e1997a17daf1a52c7024905182c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_INSTR_Hooks</type>
      <name>ACPY3_INSTR_Hooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga71534cee41f006ae9ac546e882366ee4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ACPY3_INSTR_ExtendedHooks</type>
      <name>ACPY3_INSTR_ExtendedHooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gadb5381ffc001bacd16929bcb347c7155</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_INSTR_registerHooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>gaf7b7bfefbb4dc5c7bd20a73b5e0fbaeb</anchor>
      <arglist>(IDMA3_Handle handle, ACPY3_INSTR_Hooks *hooks, ACPY3_INSTR_ExtendedHooks *extended_hooks)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ACPY3_INSTR_unregisterHooks</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga4fbf3aeced924bd7ef7e928742bc1aa9</anchor>
      <arglist>(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_INSTR_NUMHOOKS</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga4cd29b57cda5002d541e9f51b341c4ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACPY3_INSTR_NUMEXTENDEDHOOKS</name>
      <anchorfile>group___d_s_p_a_c_p_y3.html</anchorfile>
      <anchor>ga0ec901a1813d45e43123a03052a774de</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_dman3_DMAN3</name>
    <title>DMAN3</title>
    <filename>group__ti__sdo__fc__dman3___d_m_a_n3.html</filename>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_grantDmaChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gae0e5031bc5e947da1bd5d12cca1c5e00</anchor>
      <arglist>(Int groupId, IALG_Handle algHandle[], IDMA3_Fxns *dmaFxns[], Int numAlgs)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DMAN3_exit</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gac26a2a6153c50b10dc3ae9106bfa8594</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_createChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gaee927c5ad460e5e5a122471ccb047db1</anchor>
      <arglist>(Int groupId, IDMA3_ChannelRec dmaTab[], Int numChans)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DMAN3_init</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gaf0a672c8ba5962dabc8b319978aafd3b</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_releaseDmaChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga664b5e2445c2ec3a0ed9e14f8cfc1d20</anchor>
      <arglist>(IALG_Handle algHandle[], IDMA3_Fxns *dmaFxns[], Int numAlgs)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DMAN3_freeChannels</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga2d14c4952c1194b913ac6e8bb7f0e9d5</anchor>
      <arglist>(IDMA3_Handle channelTab[], Int numChans)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga5588e76c77396c16216bf7475612c9ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gacc2eb308be5d04d2b2bf935505796611</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_MAXGROUPS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gab4a261c271c8d0f1e9843eada6b263e8</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">DMAN3_Params</class>
    <member kind="typedef">
      <type>Bool(*</type>
      <name>DMAN3_ScratchAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gad828e3c20733776991f5d87aaaff7aad</anchor>
      <arglist>)(IALG_Handle alg, Int mutexId, IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>DMAN3_ScratchFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gacf1a15063787f2b589489be6234301fc</anchor>
      <arglist>)(Int mutexId, Void *addr, Uns size)</arglist>
    </member>
    <member kind="typedef">
      <type>struct DMAN3_Params</type>
      <name>DMAN3_Params</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga1ce61c1477d05515d0f27849b3b3f1d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>DMAN3_Params</type>
      <name>DMAN3_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gae3b96522afa89788ab1efdb5154c3e03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>ti_sdo_fc_dman3_DMAN3_numQdmaGroup</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga7a13bbecafc22773c55ca1b257bc75b7</anchor>
      <arglist>[20+1]</arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>ti_sdo_fc_dman3_DMAN3_useCustomDma</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga67d359a006317a42ef47ae82906ed304</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_SOK</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga462d3887266b42b69cf21c65e87dc99d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EOUTOFMEMORY</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga70d091dae946805ff49ab47b903483a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EFAIL</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gae81e9235f9755ac2e6a6279401c8798d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EFREE</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga097f382f6603cc69c2d998c0ce6b9dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EOUTOFTCCS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gab04511fe9f738b3a189758163e75f1d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EOUTOFPARAMS</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga45977d32b34b6e98e33b6510c9164dee</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_ETCCCONFIG</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>ga63c528d94fcf56d1af53b723dd353fb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DMAN3_EPARAMCONFIG</name>
      <anchorfile>group__ti__sdo__fc__dman3___d_m_a_n3.html</anchorfile>
      <anchor>gaadcb78abb90cd713d02bb0b85c021e35</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_dskt2_DSKT2</name>
    <title>DSKT2</title>
    <filename>group__ti__sdo__fc__dskt2___d_s_k_t2.html</filename>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_activateAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gaf946d426d6d9a95040d3967fa746cd7a</anchor>
      <arglist>(Int scratchMutexId, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DSKT2_controlAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga65d8c7ae9d40adcda0c92a9e51c6fd0b</anchor>
      <arglist>(IALG_Handle alg, IALG_Cmd cmd, IALG_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IALG_Handle</type>
      <name>DSKT2_createAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga5528d73c34724bc310404da0dc2fbd69</anchor>
      <arglist>(Int scratchMutexId, IALG_Fxns *fxns, IALG_Handle parent, IALG_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>IALG_Handle</type>
      <name>DSKT2_createAlg2</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga427904cdb1e2a776ee6dfd32c6529682</anchor>
      <arglist>(Int scratchMutexId, IALG_Fxns *fxns, IALG_Handle parent, IALG_Params *params, xdc_runtime_IHeap_Handle extHeapId)</arglist>
    </member>
    <member kind="function">
      <type>IALG_Handle</type>
      <name>DSKT2_createAlgExt</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga6d39f16af2214fafad89ba06382a9a79</anchor>
      <arglist>(Int scratchId, IALG_Fxns *fxns, IALG_Handle parent, IALG_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_deactivateAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga74b6b6feca63328906acade37d23b597</anchor>
      <arglist>(Int scratchMutexId, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DSKT2_deactivateAll</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga2d252c736a3bb828d9f646cc379ac0e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>DSKT2_freeAlg</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga8dffa02b3ca1ff6856ce3cf610be7435</anchor>
      <arglist>(Int scratchMutexId, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>DSKT2_allocScratch</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga5aa4fbbf031e07f6bf450128ed8bd31d</anchor>
      <arglist>(IALG_Handle alg, Int mutexId, IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>DSKT2_getScratchId</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga4eda7abcc1ed22cb2183b27290e034b0</anchor>
      <arglist>(IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_freeScratch</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga48fad0ce89b1de7f65adb9a06b4276a0</anchor>
      <arglist>(Int mutexId, Void *addr, UInt size)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>DSKT2_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga3c37794b3c2fbf0070b473c711e275ca</anchor>
      <arglist>(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>DSKT2_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga6bc8b2ebbadb2f72325c1b297597fc44</anchor>
      <arglist>(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_NUM_SCRATCH_GROUPS</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga6ea3f0bc0c9a697930cf7d8411975ac2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_MAX_MEM_ALLOCATION_SIZE</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gab7906673f1c60a08206bd37c7f7d1178</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_NUM_SHAREDHEAPS</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gacb5e98129cb03f61436195c9fd240804</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DSKT2_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga10d952cbb68bf248a0fcb6cc92c6b58e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>DSKT2_CacheWBInvFxn</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga50724c1a6b3a22edc3c011f26acee8d8</anchor>
      <arglist>)(Ptr blockPtr, size_t byteCnt, Bool wait)</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ DSKT2_CacheWBInvFxn</type>
      <name>DSKT2_cacheWBInvFxn</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga13251e1daaba43dd400d382dbf0dbc58</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_daram0Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga4735a17e9803b69e7a516cc760bf3723</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_daram1Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga72b57fe7ad477cab4f651f6f4b867fa5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_daram2Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga742f9473d76743d2ba321eb0ea03e415</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_saram0Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga52937ef078fa8e077ff10aff27264eaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_saram1Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga9927b8fe81c1a0568f200ee3238324db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_saram2Heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gab78a425f912768f8b3e9af7d6192d697</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_iprogHeap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga8db8042f1121b54db259c7310c437aef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_eprogHeap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga36e11ee5b675fd2f16bd48e27285523f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>DSKT2_esdataHeap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gaefe5d33b89715d3ef187ed45bbc7f21d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>_DSKT2_heap</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga7b2cd47eb6dad98f50f959d035086bb5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ UInt</type>
      <name>_DSKT2_ALLOW_EXTERNAL_SCRATCH</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga5163b360c871f2c8c4e12d6abbb55868</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt</type>
      <name>_DSKT2_DARAM_SCRATCH_SIZES</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>ga068cb14e316f0318c171347531351cd6</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>UInt</type>
      <name>_DSKT2_SARAM_SCRATCH_SIZES</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gac23f20affc67172dcba96c24cee5e3f3</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ Bool</type>
      <name>ti_sdo_fc_dskt2_DSKT2_disableLazyDeactivate</name>
      <anchorfile>group__ti__sdo__fc__dskt2___d_s_k_t2.html</anchorfile>
      <anchor>gaac47654880b79bdf547b27c46361a2cf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ecpy_ECPY</name>
    <title>ECPY (C64P)</title>
    <filename>group__ti__sdo__fc__ecpy___e_c_p_y.html</filename>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_configure</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gab36a69debff280508406036c8c998a28</anchor>
      <arglist>(ECPY_Handle handle, ECPY_Params *restrict params, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directConfigure</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf0380c28be53fce116f2c56823d61b7e</anchor>
      <arglist>(ECPY_Handle handle, ECPY_Params *restrict params, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_configure16</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga0b7ae91529bc356a3bd81eda9d21a421</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField16b fieldId, unsigned short value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directConfigure16</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gad27b66a14d13c228eb49b17acbd024aa</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField16b fieldId, unsigned short value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_configure32</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaea38193e1199d4a33d4878e916b9b429</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField32b fieldId, unsigned int value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directConfigure32</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gad46ed17a5d0f1a2a0bc2c7f47aad7fcd</anchor>
      <arglist>(ECPY_Handle handle, ECPY_ParamField32b fieldId, unsigned int value, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_setFinal</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga910393e8b722717de7b84b837adb1921</anchor>
      <arglist>(ECPY_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directSetFinal</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gac377bd43289a832c94c73b20a08c8c26</anchor>
      <arglist>(ECPY_Handle handle, short transferNo)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_setDestinationMemoryMode</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga3101247586aa75cc25a7733c6c4a9679</anchor>
      <arglist>(ECPY_Handle handle, short mode)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_start</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf574cd0eabdf2f673009018d7cd3408c</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directStartEdma</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf794837c161e60951b4b0c41af37ce1d</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directStartQdma</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gafeab08ae1a1b97bcaa7b207d62df528b</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_wait</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga8adc4be8a9f83b92484dd3aea18d96b1</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_directWait</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga0187836c1fb6e00b16741e5daf69308b</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_activate</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gacc1922d7764bb915e1132d955e4b273f</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>ECPY_Handle</type>
      <name>ECPY_createHandle</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gaf27ccab70603cbf148f46a5068a497e0</anchor>
      <arglist>(IRES_EDMA3CHAN2_Handle handle, IALG_Handle alg)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_deleteHandle</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga7d98039c8cea805547bd8ddde71eff6a</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_deactivate</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga06f88eefc91f79ba958d1dee9e7fbb63</anchor>
      <arglist>(ECPY_Handle handle)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_setEarlyCompletionMode</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga53d14a24649b65b10b817466c7c5b63f</anchor>
      <arglist>(ECPY_Handle handle, short enabled)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_init</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gae699f2d7ac858fecfc83655b3df12037</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>ECPY_exit</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gade95f79a09ed57206ae1236a23c03764</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ti_sdo_fc_ires_NOPROTOCOLREV</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga33eacaa6cefc41cfe527b740449250dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ECPY_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga20a251dafbbc7b6f6b630d65f95882a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ECPY_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga41a9eb2392433a4d485892a130a1a0f6</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">ECPY_Params</class>
    <class kind="struct">ECPY_CfgParams</class>
    <member kind="typedef">
      <type>enum ECPY_ParamField16b</type>
      <name>ECPY_ParamField16b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gad6043a14cff5cf11e6124f8ad848e060</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ECPY_ParamField32b</type>
      <name>ECPY_ParamField32b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga9a316b6b71fa073d355c25ef48ddf9e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum ECPY_TransferType</type>
      <name>ECPY_TransferType</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga5e69c0ab60fd992aaf644c5dae21a983</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ECPY_Obj *</type>
      <name>ECPY_Handle</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga5e6504458adc98bbbaebfd75c6708add</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct ECPY_Params</type>
      <name>ECPY_Params</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga85cefc02e34b1ae7d62fb38564c64422</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Bool(</type>
      <name>ECPY_PersistentAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga76c3270f722c14ccb8f841ddd7ad633b</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(</type>
      <name>ECPY_PersistentFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga26781251cda4ad55a1c42efdded245d3</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Bool(</type>
      <name>ECPY_ScratchAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gae88691e8077d5fd82d748eb7fccba834</anchor>
      <arglist>)(IALG_Handle alg, Int scratchId, IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(</type>
      <name>ECPY_ScratchFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga4643c72b6383f39fb4b0c5b588837006</anchor>
      <arglist>)(Int mutexId, Void *addr, UInt size)</arglist>
    </member>
    <member kind="typedef">
      <type>Int(</type>
      <name>ECPY_getScratchIdFxn</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga1557be200bc42ce9b4def164ea3907e7</anchor>
      <arglist>)(IALG_Handle alg)</arglist>
    </member>
    <member kind="typedef">
      <type>struct ECPY_CfgParams</type>
      <name>ECPY_CfgParams</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga54c1cdb98daaa54a05871b834f02037c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ECPY_ParamField16b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga7d9083dd908144dea99d282b5e4c8b13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTSIZE</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a36d360cbb62ce99c35b580783c8b49b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_NUMELEMENTS</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13ad69a1ddde8138115336b24b29a834f2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTINDEX_SRC</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a7c967b0f24b1cf6ed5b79a4132c9a7a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTINDEX_DST</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a4053f308bce4818e1d6d834a2e3e624e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_FRAMEINDEX_SRC</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a5c9f42f805ad155965c02a5b8626e1fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_FRAMEINDEX_DST</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13adfc48d249dca5f0943e0a6476959d17e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_NUMFRAMES</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga7d9083dd908144dea99d282b5e4c8b13a3577d05a60a04c2721acc376bf30d63e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ECPY_ParamField32b</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga59f221145cdc648d305f9c2d49ec2f87</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_SRCADDR</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87a098f1b061997d6567579046bc2b7a575</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_DSTADDR</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87aebad51006d8f6e00b018aa9046cd8058</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_ELEMENTINDEXES</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87a1f43197ca7113efa4a522209fc5591f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_PARAMFIELD_FRAMEINDEXES</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga59f221145cdc648d305f9c2d49ec2f87a13c950c2596ae15fe4ee9663d1b0e4f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ECPY_TransferType</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>ga263a661327490e9f8226271c6f478011</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_1D1D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011a38f001040141d98db06c881ea0dc44d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_1D2D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011aa3447e13f4ccf2ea11c758108a361552</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_2D1D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011a7299b2d257ac0f6eb3caa86366f540ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ECPY_2D2D</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gga263a661327490e9f8226271c6f478011afda741865f454dcea45ec1eb2f5c42db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ ECPY_CfgParams</type>
      <name>ECPY_CFG_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__ecpy___e_c_p_y.html</anchorfile>
      <anchor>gabcc5234b3b928c407413afc3aa15a92b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_hdintc_HDINTC</name>
    <title>HDINTC</title>
    <filename>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</filename>
    <member kind="function">
      <type>void</type>
      <name>HDVICP_configure</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga009daaee6229d4963d1d6e6e1ea5dfce</anchor>
      <arglist>(IALG_Handle handle, void *hdvicpHandle, void(*ISRfunctionptr)(IALG_Handle handle))</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>HDVICP_wait</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga54da32d8ba2275df7747f13233066197</anchor>
      <arglist>(void *hdvicpHandle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>HDVICP_done</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga9bca27e1d2927d05b90120efed813563</anchor>
      <arglist>(void *hdvicpHandle)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga415467e72b60fa643f411fd7f5c21769</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">HDINTC_Params</class>
    <class kind="struct">hdvicpAppHandle</class>
    <member kind="typedef">
      <type>struct HDINTC_Params</type>
      <name>HDINTC_Params</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>gaec114ee910a3e016a510173296149621</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct hdvicpAppHandle</type>
      <name>HDVICP_Obj</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga9a8684867f1420ddeb18eed5ebde3d6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>HDVICP_Obj *</type>
      <name>HDVICP_Handle</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga01e5fc5a20a9510b3ae121c3743ff2bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>HDINTC_Params</type>
      <name>HDINTC_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga61af9ab21c54b9cf7351c8261cc1d243</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_SOK</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>ga05484bfd6b90b363379ded126fe1756f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_EOUTOFMEMORY</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>gadd4ff9534ef2287e5b390953adeda2f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDINTC_EFAIL</name>
      <anchorfile>group__ti__sdo__fc__hdintc___h_d_i_n_t_c.html</anchorfile>
      <anchor>gae38cf9587b601ab07913642d0fdbc149</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_IRESMAN</name>
    <title>Resource manager interface</title>
    <filename>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</filename>
    <class kind="struct">IRESMAN_Params</class>
    <class kind="struct">IRESMAN_Fxns</class>
    <class kind="struct">IRESMAN_ConstructArgs</class>
    <member kind="typedef">
      <type>Bool(</type>
      <name>IRESMAN_PersistentAllocFxn</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga830cdb9915da5147ad73e1e8acc18840</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(</type>
      <name>IRESMAN_PersistentFreeFxn</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga3b947da470d58722a8c78073df3c6fd9</anchor>
      <arglist>)(IALG_MemRec *memTab, Int numRecs)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_Params</type>
      <name>IRESMAN_Params</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga2a8b6374104f86177742127e0e9db690</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_Fxns</type>
      <name>IRESMAN_Fxns</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga3ccaac5d069a8c8d1f136c29bf3cbeb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_ConstructArgs</type>
      <name>IRESMAN_ConstructArgs</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>ga93fe96948b8c064f1244daae12abba54</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRESMAN_ConstructFxns</type>
      <name>IRESMAN_ConstructFxns</name>
      <anchorfile>group__ti__sdo__fc__ires___i_r_e_s_m_a_n.html</anchorfile>
      <anchor>gab9da36e13f19c05d045611d22e23f184</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_memutils_MEMUTILS</name>
    <title>MEMUTILS</title>
    <filename>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</filename>
    <member kind="function">
      <type>Void</type>
      <name>MEMUTILS_cacheInv</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>gad07c8ac40bec004e2cc0a386f86570dd</anchor>
      <arglist>(Ptr addr, Int sizeInBytes)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>MEMUTILS_cacheWb</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>ga9ec3a005cfbd44003b9dc57e737d32b1</anchor>
      <arglist>(Ptr addr, Int sizeInBytes)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>MEMUTILS_cacheWbInv</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>ga3ecacfd8a0771af6d1a532fbbe35adfe</anchor>
      <arglist>(Ptr addr, Int sizeInBytes)</arglist>
    </member>
    <member kind="function">
      <type>Void *</type>
      <name>MEMUTILS_getPhysicalAddr</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>gae67c1ceb1e529cbb9b10abee89101f75</anchor>
      <arglist>(Ptr addr)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MEMUTILS_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__memutils___m_e_m_u_t_i_l_s.html</anchorfile>
      <anchor>gaad6bedcf19bfc91b3b86ae7640ea7a9e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_rman_RMAN</name>
    <title>Resource Manager for IRES-based resources</title>
    <filename>group__ti__sdo__fc__rman___r_m_a_n.html</filename>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_init</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga2553157eede6b63b0037b0db72fbdae8</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_exit</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaedbbc06da21c2e842c890d4ff4ac9aed</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_register</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gae8fe0e0bcdcb46afb0d09d1997136347</anchor>
      <arglist>(IRESMAN_Fxns *resmanFxns, IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_unregister</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa6f966711380ecf89ad79db2ebf8619a</anchor>
      <arglist>(IRESMAN_Fxns *resmanFxns)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_assignResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa7772ccd9856ccc0b0492c018807b2b3</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_allocateResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga0fdeaec06650e512ffd765613a3accaf</anchor>
      <arglist>(Int requestId, IRES_ResourceDescriptor *resDesc, Int numResources, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_freeResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga98911d4d4049d1805ae9eac2b71d9ec0</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_freeAllocatedResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gafac26c9edf744af2d0b1f4f24862975b</anchor>
      <arglist>(Int requestId, IRES_ResourceDescriptor *resDesc, Int numResources, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_activateResource</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga3135611a668b07aad926247bbd0e37a9</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle resourceHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_activateAllResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga354e1ad9ac34e6c41b0bd2184bc3e9fb</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_deactivateResource</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga1c20b46e28a17783654674f9e109e46e</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle resourceHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>RMAN_deactivateAllResources</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga7343843e4acd15df9997315b4cb9bcf3</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchGroupId)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>RMAN_yield</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa9da95739776c293fb4e27ec5207a668</anchor>
      <arglist>(IRES_YieldResourceType resource, IRES_YieldContextHandle algYieldContext, IRES_YieldArgs yieldArgs)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RMAN_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga2df9395a0c498e45a8fb68942197a9eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RMAN_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga548fc91df8bfb9a8a30cbaab812110c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RMAN_PROTOCOLNAMESIZE</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga69dd3d9e63a604b0cb10037c60bfd4fa</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">RMAN_Params</class>
    <member kind="typedef">
      <type>struct Sem_Obj *</type>
      <name>RMAN_SemHandle</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga841a70da51acb69fde1f53d60faae1bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_YieldArgs(*</type>
      <name>ti_sdo_fc_rman_RMAN_YieldArgsFxn</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga3b8309d40495cb499b09ce358ebfc029</anchor>
      <arglist>)(Int scratchId, Bool yieldFlag)</arglist>
    </member>
    <member kind="typedef">
      <type>struct RMAN_Params</type>
      <name>RMAN_Params</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga2b477ea38c1ae71bc320a1384f6b536e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ RMAN_Params</type>
      <name>RMAN_PARAMS</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gae12d774b050c8c27f780ed91dd7c2a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_Fxns *</type>
      <name>RMAN_TABLE</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gab2ff62cddcbbbd3c6a2819703a96bcca</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ short</type>
      <name>RMAN_FREE_ENTRIES</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga758ab45c1418c384bf578ea5558b9d7b</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ short</type>
      <name>RMAN_numRegistryEntries</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga60e319affb35f0df44bfa9e5576cbd05</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_Fxns **</type>
      <name>RMAN_registryEntries</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gae4b796a7aead262ea31848120b07d54d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_Params **</type>
      <name>RMAN_registryResmanArgs</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga4a461e9e2f1b613ef55dbe4574abd5b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ unsigned int **</type>
      <name>RMAN_iresVTable</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga343604b8ef45f3565e25b0ea911a4173</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ unsigned int</type>
      <name>ti_sdo_fc_rman_RMAN_MAXALGS</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>ga8ec03181fc11e30d8c10c7eb54d248d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt32</type>
      <name>ti_sdo_fc_rman_RMAN_ipcKey</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gaa67b89289e5ff8dab19e2c011417dabb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ti_sdo_fc_rman_RMAN_YieldArgsFxn</type>
      <name>ti_sdo_fc_rman_RMAN_setYieldArgs</name>
      <anchorfile>group__ti__sdo__fc__rman___r_m_a_n.html</anchorfile>
      <anchor>gacfc9b966702c5a037e299e8b7b016ce3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_rcm_RcmClient</name>
    <title>RcmClient</title>
    <filename>group__ti__sdo__rcm___rcm_client.html</filename>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_acquireJobId</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga1ca1095af911e152f3c2f1413435c000</anchor>
      <arglist>(RcmClient_Handle handle, UInt16 *jobId)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_addSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gad4a99b35c6b2559efa025ec082bc8672</anchor>
      <arglist>(RcmClient_Handle handle, String name, Fxn addr, UInt32 *index)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_alloc</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga208ac0778da226dede7ca9a0347be396</anchor>
      <arglist>(RcmClient_Handle handle, UInt32 dataSize, RcmClient_Message **message)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_checkForError</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga159d59d3bf1a9cdce0a182b193aa83d2</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_construct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaaacfb4d851275706e163e1ba673b9564</anchor>
      <arglist>(RcmClient_Struct *structPtr, String server, const RcmClient_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_create</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaebe8bf5700c7a702ef8fd8a85fc90952</anchor>
      <arglist>(String server, const RcmClient_Params *params, RcmClient_Handle *handle)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_delete</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf329381265fcec015e9bd8e340bc4e7a</anchor>
      <arglist>(RcmClient_Handle *handlePtr)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_destruct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gacfefde73bc566613b9fe09d2ee4cebcc</anchor>
      <arglist>(RcmClient_Struct *structPtr)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_exec</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf1fd561fb60afc8230358f38fd7194a6</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execAsync</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga950cbd891b6ae4cd59b6c9fe12fcfa5a</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, RcmClient_CallbackFxn callback, Ptr appData)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execCmd</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga7a937da523a65f27357200560a8e8d89</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execDpc</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gacb3388f3a4646c3a44516d01bb941a11</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_execNoWait</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga00270eeec2f9efa1a06db5f2c727146f</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *cmdMsg, UInt16 *msgId)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmClient_exit</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gafcbe8036ad282bbe432c02b293592f31</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_free</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga3b76d9403edf28dd7067f6413f2e6dba</anchor>
      <arglist>(RcmClient_Handle handle, RcmClient_Message *msg)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_getSymbolIndex</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga47d577ba88e270e29f00f90ae188aca5</anchor>
      <arglist>(RcmClient_Handle handle, String name, UInt32 *index)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmClient_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae8d23222b6fa4239e04e0a816c0b3a1b</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmClient_Params_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae8cd1b3d8ed02000676760a36c917eb0</anchor>
      <arglist>(RcmClient_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_releaseJobId</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga9644bb7b1b8d0f5d1b382353c2f3dc6d</anchor>
      <arglist>(RcmClient_Handle handle, UInt16 jobId)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_removeSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga107fa5f86177f7f94c62e5cf4c37fa85</anchor>
      <arglist>(RcmClient_Handle handle, String name)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmClient_waitUntilDone</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gac413e8c8ab42cf489bd728ec0fb4fbd9</anchor>
      <arglist>(RcmClient_Handle handle, UInt16 msgId, RcmClient_Message **returnMsg)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_S_SUCCESS</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga6cae0be521867514327de0ecc178e97e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_FAIL</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga5675ad080d5cfee20f983248f9a9a0fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_EXECASYNCNOTENABLED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga4278ec3a1f74d36240fe6bcebb347dcb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_EXECFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga1f370ba6eb5d5c095d5024e695c32d98</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_INVALIDHEAPID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga757b3e821874ff8cdef8bc686e46f28e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_INVALIDFXNIDX</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga8d100f828f732ccdb96a775b4b3acbbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGFXNERROR</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga6b23d24fe17b1bd959ff5ea33d9af8e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_IPCERROR</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gab8098ffd2e3d0a79f98d38ae3bd7b4a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_LISTCREATEFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gad9df39f75871e95d5ce1cbe59465d392</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_LOSTMSG</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga9a1521f72a530e1a9e0b79e3a63538f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGALLOCFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga35af60cede2baccd1f800f1ddbe36de1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGQCREATEFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gad00e49b18709c2319629baa270f347f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_MSGQOPENFAILED</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gac7d3fc2d71549991d983040539ecf4d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_SERVERERROR</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga86c9602522a507759580f7839c3b9397</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_SERVERNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf75a16dc21df81d847982ee1ca21f008</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_SYMBOLNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gab3663b04476ee6485aff5bd0fa536259</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_NOMEMORY</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaaa1be00b719d55294eebdce068865875</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_E_JOBIDNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga8844458810de28658226aa3b0a269a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_INVALIDFXNIDX</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae0872f1d229d368770f6e620f1e81016</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_INVALIDHEAPID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gae0d3774d8702446a63c7a425feef10d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_INVALIDMSGID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga7fd49181c3df5128cd9d2e8042f26f34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_DEFAULTPOOLID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga9ae2956af2a09e0af7864cdf36151f0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmClient_DISCRETEJOBID</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>gaf23dbd2ea2d1ff26a4643c63b1cd585d</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">RcmClient_Message</class>
    <class kind="struct">RcmClient_Params</class>
    <class kind="struct">RcmClient_Struct</class>
    <member kind="typedef">
      <type>struct RcmClient_Object_tag *</type>
      <name>RcmClient_Handle</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga8c8262c5fbdb3de810b3e18d73b0b57c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>RcmClient_CallbackFxn</name>
      <anchorfile>group__ti__sdo__rcm___rcm_client.html</anchorfile>
      <anchor>ga1a5ec28a9cb0b70076099912b55657e8</anchor>
      <arglist>)(RcmClient_Message *, Ptr)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_rcm_RcmServer</name>
    <title>RcmServer</title>
    <filename>group__ti__sdo__rcm___rcm_server.html</filename>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_addSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga9126aa462aff2c9ef26ac5dcacbb531f</anchor>
      <arglist>(RcmServer_Handle handle, String name, RcmServer_MsgFxn addr, UInt32 *index)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_construct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gaa79f4ab038b790fe3384b33a28bf127e</anchor>
      <arglist>(RcmServer_Struct *structPtr, String name, const RcmServer_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_create</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gaac1a45f82e40e83b825be5705437e4c8</anchor>
      <arglist>(String name, RcmServer_Params *params, RcmServer_Handle *handle)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_delete</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gad003898cd71b28429552b13b87551da9</anchor>
      <arglist>(RcmServer_Handle *handlePtr)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_destruct</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gabeaa0ddc38279784d7100f5456d89254</anchor>
      <arglist>(RcmServer_Struct *structPtr)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmServer_exit</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga8b95234ed5228d815bb3241008567fce</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmServer_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga05a70dbd79151489d90f1de4680c4555</anchor>
      <arglist>(Void)</arglist>
    </member>
    <member kind="function">
      <type>Void</type>
      <name>RcmServer_Params_init</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gaf72c2963894c2667c762b59aa87a690d</anchor>
      <arglist>(RcmServer_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_removeSymbol</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga4c81d6367a2e0767974625f4b44e7811</anchor>
      <arglist>(RcmServer_Handle handle, String name)</arglist>
    </member>
    <member kind="function">
      <type>Int</type>
      <name>RcmServer_start</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga5f80ea61e02ec783341f4362c8a572e3</anchor>
      <arglist>(RcmServer_Handle handle)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_S_SUCCESS</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga72c9606751a94487f21490d5a6d16281</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_FAIL</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>gabae883b517fb29ba2448087f45524a6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_NOMEMORY</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga9c4fe2cfcb8fec9aca38cccf930902c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_SYMBOLNOTFOUND</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga414bf0858222ae94bd7890a9100d257b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_SYMBOLSTATIC</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga064852117a1c99faa0f0c8f74d5e67af</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RcmServer_E_SYMBOLTABLEFULL</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga9744b10c8957c6138d22bcb85f93afca</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">RcmServer_FxnDesc</class>
    <class kind="struct">RcmServer_FxnDescAry</class>
    <class kind="struct">RcmServer_ThreadPoolDesc</class>
    <class kind="struct">RcmServer_ThreadPoolDescAry</class>
    <class kind="struct">RcmServer_Params</class>
    <class kind="struct">RcmServer_Struct</class>
    <member kind="typedef">
      <type>Int32(*</type>
      <name>RcmServer_MsgFxn</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga62c6104fd28f253e06ade10386ec4bc0</anchor>
      <arglist>)(UInt32, UInt32 *)</arglist>
    </member>
    <member kind="typedef">
      <type>struct RcmServer_Object_tag *</type>
      <name>RcmServer_Handle</name>
      <anchorfile>group__ti__sdo__rcm___rcm_server.html</anchorfile>
      <anchor>ga443465f4892e66d44fdd77da82414d46</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_xdais_XDAS</name>
    <title>XDAIS Types and Constants</title>
    <filename>group__ti__xdais___x_d_a_s.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>XDAS_TRUE</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga0a1e9fe6b661ca6eafe982fe2b0787bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>XDAS_FALSE</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga5cd894ca3ba5c100f7f863dae8587293</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Void</type>
      <name>XDAS_Void</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga125aad4180e7ca9a3ddaba59c9217513</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint8</type>
      <name>XDAS_Bool</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gac8ce48f3d618a6f0a37b4e55f978b825</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Int8</type>
      <name>XDAS_Int8</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gaa0b0c4cc1bf0d8fa0d9b15de0e9204cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint8</type>
      <name>XDAS_UInt8</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gac9308edb855a360c27a47aaa6f3b39a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Int16</type>
      <name>XDAS_Int16</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga8189aa7a8636f505d6a35e5744ac6392</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint16</type>
      <name>XDAS_UInt16</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gaa27605972947c862397ebee40c2ff917</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Int32</type>
      <name>XDAS_Int32</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>gae431579ed9eff9134de78ca00ddd5f3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Uint32</type>
      <name>XDAS_UInt32</name>
      <anchorfile>group__ti__xdais___x_d_a_s.html</anchorfile>
      <anchor>ga615572fcd2279a6780dc1785d72ff421</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_edma3chan_IRES_EDMA3CHAN</name>
    <title>IRES EDMA3 Protocol</title>
    <filename>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaf4730270fcd589bd84292642aa0767ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>EDMA3CHAN_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gab7814ae21cc501d4882aaeb43153fc0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PROTOCOLREVISION_1_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga3e72cddac269ede3215c67681bd06358</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_SETPROTOCOLREVISION_1_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gabc9fa9788be85eddc9696b9a778270c9</anchor>
      <arglist>(rev)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PROTOCOLREVISION_2_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gafaf0878b09c1cc9708821d19d801e182</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_SETPROTOCOLREVISION_2_0_0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga13b7ccd6e711b7469b8823a5c957b536</anchor>
      <arglist>(rev)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_MAXPARAMS</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga8510375de41242e3526a4afa007e131a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_MAXTCCS</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga18eb05e3510d748f04269c39cce62733</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_NUMDESTTYPES</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gadb7b5e24785c0749d8717e0d740ebdd4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PARAM_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga2b610a75bc94fcf953c9c2c5a5884847</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_PARAM_NONE</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga06bed242a94eb48126e04f267f0d4895</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_TCC_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga3dad6458e12ad42c2158727991822037</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_TCC_NONE</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga1920c58bedf3e0cc0609b86ec384c892</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_EDMACHAN_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gae3c157030381908d1353fccf406fdd38</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_QDMACHAN_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga0b99333ee5984dab27d5d84c05b63078</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_EDMA3CHAN_CHAN_NONE</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gae4140c679d6eaaf4d20dc4554995edf3</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_EDMA3CHAN_PaRamStruct</class>
    <class kind="struct">IRES_EDMA3CHAN_ProtocolArgs</class>
    <class kind="struct">IRES_EDMA3CHAN_Obj</class>
    <class kind="struct">IRES_EDMA3CHAN_EDMA3ShadowRegister</class>
    <class kind="struct">IRES_EDMA3CHAN_EDMA3DraeRegister</class>
    <class kind="struct">IRES_EDMA3CHAN_EDMA3RegisterLayer</class>
    <class kind="struct">IRES_EDMA3CHAN_Properties</class>
    <class kind="struct">IRES_EDMA3CHAN2_Obj</class>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_Obj *</type>
      <name>IRES_EDMA3CHAN_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga44e66cb70f336bdb105e54983930c8e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN2_Obj *</type>
      <name>IRES_EDMA3CHAN2_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gac7ec31fb6115f2df8b43f0a66d3bb09f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_PaRamStruct</type>
      <name>IRES_EDMA3CHAN_PaRamStruct</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga3d1f7dd722d7b1eac3940a6d0eff63c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_ProtocolArgs</type>
      <name>IRES_EDMA3CHAN_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga4f0e8e331a7135fa21c62da8e1d3fced</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_Obj</type>
      <name>IRES_EDMA3CHAN_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga8910a3fc26939a5f592191fb4400d0d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_EDMA3ShadowRegister</type>
      <name>IRES_EDMA3CHAN_EDMA3ShadowRegister</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaa2977a19f877b1d3cf7538c3457db58d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_EDMA3DraeRegister</type>
      <name>IRES_EDMA3CHAN_EDMA3DraeRegister</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga0a01c3ca97f02a526edb0360eff504ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_EDMA3RegisterLayer</type>
      <name>IRES_EDMA3CHAN_EDMA3RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga2ceee1967c04a37f016e0184b5f6040d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN_Properties</type>
      <name>IRES_EDMA3CHAN_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga271d231160ea9cf90f4387b7aecfb34e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_EDMA3CHAN_DmaDestType</type>
      <name>IRES_EDMA3CHAN_DmaDestType</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaa2c61cb7db74a0e2cef3e3c66c383b68</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_EDMA3CHAN2_Obj</type>
      <name>IRES_EDMA3CHAN2_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga5734d8411fde66f0d75892044293e9f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_EDMA3CHAN_DmaDestType</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga6cbd16008d4c8eb007e03412b12fc778</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INTMEMORY0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778ab5b71d03e8f43daec2d60476de20257e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INTMEMORY1</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a3f2d454aa72ffcc696235a4e921e1081</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INTMEMORY2</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a17aba04c48a2fce4159b46fb3e805611</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EXTMEMORY0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778accf6cc4da6f9f212df339285116ceb00</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EXTMEMORY1</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a2cce7020b1c9fd276443476c35340648</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EXTMEMORY2</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a576ed3797b9afdbd3631f744b4890de6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OTHER0</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778af83122691b069425c9650cc7ad3ce13e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OTHER1</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gga6cbd16008d4c8eb007e03412b12fc778a89480a70e3af20e73e799ae2bb07bfae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_edma3chan_IRESMAN_EDMA3CHAN</name>
    <title>IRESMAN EDMA3 -</title>
    <filename>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</filename>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_EDMA3CHAN_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaeb774220d0deb5da8bbfe8aa25c15094</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_EDMA3CHAN_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga695084a1271cf138b383a2a7c42e1e20</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_EDMA3CHAN_init</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga941b3ff64286bcfaa3bb5205bb669d55</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_EDMA3CHAN_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gac67268cf9b8f5bf523caffebfe8dc148</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_EDMA3CHAN_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gad30ebcbc0fed976c39cdf716677b2080</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_EDMA3CHAN_freeHandle</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gabd5e4de994bdaf06fe5a45f5c41fe265</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_Edma3ChanParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_Edma3ChanParams</type>
      <name>IRESMAN_Edma3ChanParams</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga6f72d404957e3bde256dab036a6ee460</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_EDMA3CHAN</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>ga7fb20979fe105a5310a48f2b2ccaf8c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_ConstructFxns</type>
      <name>IRESMAN_EDMA3CHAN_CONSTRUCTFXNS</name>
      <anchorfile>group__ti__sdo__fc__ires__edma3chan___i_r_e_s_m_a_n___e_d_m_a3_c_h_a_n.html</anchorfile>
      <anchor>gae89c5c3a2256543b6e7694cc91040be7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_hdvicp_IRES_HDVICP</name>
    <title>IRES HDVICP Protocol</title>
    <filename>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gaf41453e3afb59b32d1a0c41961fe50a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDVICP_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gab17613f289eb3239624de87c31d57116</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_HDVICP_ProtocolArgs</class>
    <class kind="struct">IRES_HDVICP_Obj</class>
    <class kind="struct">IRES_HDVICP_RegisterLayer</class>
    <class kind="struct">IRES_HDVICP_Properties</class>
    <member kind="typedef">
      <type>struct IRES_HDVICP_Obj *</type>
      <name>IRES_HDVICP_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gafcb53c4662e46499ee68c7dfad662bfa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_HDVICP_RequestType</type>
      <name>IRES_HDVICP_RequestType</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga4019a15f38f2854f0e52f457d724449b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_ProtocolArgs</type>
      <name>IRES_HDVICP_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga0aeea51623159606d5bc6a7a15ed4043</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_Obj</type>
      <name>IRES_HDVICP_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gad85f85ba4b0fdaf7cf9e8921cad229fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_RegisterLayer</type>
      <name>IRES_HDVICP_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga36d6cd1fdd8c0a88840e5b6af0fabd0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP_Properties</type>
      <name>IRES_HDVICP_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga7a41d6c63373b559c3fc5ee90280d4ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_HDVICP_RequestType</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga995d4dd1dfb80daa5eb01690cc33cc7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_HDVICP_ID_0</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gga995d4dd1dfb80daa5eb01690cc33cc7fa10e2fb6fd933237adb33843bb400a4a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_HDVICP_ID_1</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gga995d4dd1dfb80daa5eb01690cc33cc7fa5073e858122fda35b61a1ec8e991aadf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_HDVICP_ID_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p.html</anchorfile>
      <anchor>gga995d4dd1dfb80daa5eb01690cc33cc7fa33f3ada2c7cd3a08688432d3ba84f65b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_hdvicp_IRES_HDVICP2</name>
    <title>IRES HDVICP2 Protocol (Beta)</title>
    <filename>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga6e9fc2b0904862eb35cf23ec5d06fd31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HDVICP2_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga9c465c385b96523dd172495898a2a648</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_ID_ANY</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga5036e671af0585ea57d8e0197e4e90ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_ID_LATE_ACQUIRE</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga64e2059f8468faeac050da0d3db026f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_INVALID_ADDR</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga58cf2d89d0831f062da6b1392dc2630a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_TIMEOUTFOREVER</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga02602060d994d0ee40fade0f38475687</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP2_UNKNOWNLATEACQUIREARG</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga89573d4d420b01f3b2c3bedb20e52dab</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_HDVICP2_ProtocolArgs</class>
    <class kind="struct">IRES_HDVICP2_Obj</class>
    <class kind="struct">IRES_HDVICP2_RegisterLayer</class>
    <class kind="struct">IRES_HDVICP2_Properties</class>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_Obj *</type>
      <name>IRES_HDVICP2_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gadd0f77cea05c41ade2f2f6c29937eb7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_YieldArgs(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_GetYieldArgsFxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga88a7872c89c42689a690e9224e901fc2</anchor>
      <arglist>)(Int scratchId)</arglist>
    </member>
    <member kind="typedef">
      <type>Void(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_YieldFxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gae92841af2ce526bc95a26e1c9037cf5d</anchor>
      <arglist>)(IRES_YieldResourceType resource, IRES_YieldContextHandle ctxt, IRES_YieldArgs args)</arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_ProtocolArgs</type>
      <name>IRES_HDVICP2_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga01d21d4eea4b38bba75890a474f5e146</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>IRES_HDVICP2_CallbackFxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga0aa568ca2dca0947909f348e8893b4fd</anchor>
      <arglist>)(IALG_Handle handle, Void *args)</arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_HDVICP2_Status</type>
      <name>IRES_HDVICP2_Status</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga4d0929cc91ef9058c626bc3f8eb5a580</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_Obj</type>
      <name>IRES_HDVICP2_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gab164d36df22fa1187459bf656fb41f83</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_RegisterLayer</type>
      <name>IRES_HDVICP2_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gab207e5ba3c1be67f41aca898cd1af06c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_HDVICP2_Properties</type>
      <name>IRES_HDVICP2_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga347620d5e79bdf4a441045fe9a5efc21</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>IRES_Status(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_GetHdvicp2Fxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga089e51e6e0c15b71b6d05f90a805eb7a</anchor>
      <arglist>)(XDAS_Int32 *Id, IALG_Handle alg, IRES_HDVICP2_Handle handle)</arglist>
    </member>
    <member kind="typedef">
      <type>IRES_Status(*</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_FreeHdvicp2Fxn</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga4f046888c3242b7bc777fb0922e09c01</anchor>
      <arglist>)(XDAS_Int32 Id, IALG_Handle alg, IRES_HDVICP2_Handle handle)</arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_HDVICP2_Status</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga918fdab9a544c5ffcc1e76117d0f79f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SAMECODEC</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gga918fdab9a544c5ffcc1e76117d0f79f6a9d9e226b105a5fb9f07837c802b899be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SAMECODECTYPE</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gga918fdab9a544c5ffcc1e76117d0f79f6a1973caa402d1fcba41cb15d1472afb65</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DIFFERENTCODEC</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>gga918fdab9a544c5ffcc1e76117d0f79f6a19f7f16190662b5b92b9d929d9bcbf40</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>ti_sdo_fc_ires_hdvicp_HDVICP2_timeoutVal</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s___h_d_v_i_c_p2.html</anchorfile>
      <anchor>ga5b423e92e03fa325059695a892b2af42</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_hdvicp_IRESMAN_HDVICP</name>
    <title>IRESMAN PROTOCOL - HDVICP</title>
    <filename>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</filename>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_HDVICP_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga263a6e5378a5a80ec72cbe1e1996d4e1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_HDVICP_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga1e6757007676bb59bc49b976c7082d68</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_HDVICP_init</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga9b2d49524494e6c589a17b8d3f6e2b83</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_HDVICP_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga66e789620a153083717fe8b73f576ad8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_HDVICP_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga91dcd1ec36206aeb58649b7361d7904b</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_HDVICP_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga8082e13e6d0f726991c2e78659f7d82c</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_HDVICP_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga626db578ddcda783f8354c734b51a876</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRESMAN_HdVicpParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_HdVicpParams</type>
      <name>IRESMAN_HdVicpParams</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>gaa0cc26209d78b2914c0353319983e7b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_HDVICP</name>
      <anchorfile>group__ti__sdo__fc__ires__hdvicp___i_r_e_s_m_a_n___h_d_v_i_c_p.html</anchorfile>
      <anchor>ga3f269556325eb4b7ac1b7aad594e3f6c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_sdma_IRES_SDMA</name>
    <title>IRES SDMA Protocol</title>
    <filename>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_SDMA_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga6f5038b490bc0ecbf3d21e456c4267e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SDMA_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga0a5073bdc48b6a191ca5ccc325c6d6e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SDMA_GTNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>gab78a0b270839010ccf0882267d4232b3</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_SDMA_ProtocolArgs</class>
    <class kind="struct">IRES_SDMA_Obj</class>
    <class kind="struct">IRES_SDMA_RegisterLayer</class>
    <class kind="struct">IRES_SDMA_Properties</class>
    <member kind="typedef">
      <type>struct IRES_SDMA_Obj *</type>
      <name>IRES_SDMA_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga74d315505deba9f15f679b0df065a63a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_ProtocolArgs</type>
      <name>IRES_SDMA_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga90f6032407d4fe00c5bf0d389c238936</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_Obj</type>
      <name>IRES_SDMA_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>gaa172cc0d89b876e04d5de97512fdba2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_RegisterLayer</type>
      <name>IRES_SDMA_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>gac3f36f80a4634e8175def63b5510c010</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_SDMA_Properties</type>
      <name>IRES_SDMA_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s___s_d_m_a.html</anchorfile>
      <anchor>ga0946214387330b97290cb94b3c3e7d69</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_sdma_IRESMAN_SDMA</name>
    <title>IRESMAN SDMA -</title>
    <filename>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</filename>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_SDMA_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga42a8ea015edf0a5d67a54be0db2459a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_SDMA_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gafaf6ada6499a564c06d2dce367a5e467</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_SDMA_init</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga8d1a94f3299d0944a6718fb18a18231d</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_SDMA_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga8ca00c2a884b82b77af70fc369f7e49a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_SDMA_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga138711df4f41e30a525b7fe2b5af362b</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_SDMA_freeHandle</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gafabf88b625a9e11f22bb50de925e2b1e</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_SdmaParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_SdmaParams</type>
      <name>IRESMAN_SdmaParams</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gafaaad7c24ff6340d34d7ea34edc0b339</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_SDMA</name>
      <anchorfile>group__ti__sdo__fc__ires__sdma___i_r_e_s_m_a_n___s_d_m_a.html</anchorfile>
      <anchor>ga630a46a77d5ce6c783835952a27f71c3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_tiledmemory_IRES_TILEDMEMORY</name>
    <title>IRES TILEDMEMORY Protocol (Beta)</title>
    <filename>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_TILEDMEMORY_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga68b4b8898e77e090fd96541494fa6422</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TILEDMEMORY_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga623d30fd5f51a591fb1d7ba6bedd0dab</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_TILEDMEMORY_ProtocolArgs</class>
    <class kind="struct">IRES_TILEDMEMORY_Obj</class>
    <class kind="struct">IRES_TILEDMEMORY_RegisterLayer</class>
    <class kind="struct">IRES_TILEDMEMORY_Properties</class>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_Obj *</type>
      <name>IRES_TILEDMEMORY_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga30b122a78fafc18f16f4b584c55ddf39</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_TILEDMEMORY_AccessDimension</type>
      <name>IRES_TILEDMEMORY_AccessDimension</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gaa6cd7292c7e04c77735f0d9b2c0e6a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum IRES_TILEDMEMORY_AccessUnit</type>
      <name>IRES_TILEDMEMORY_AccessUnit</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga9a4638e18510604f93bafbaac2d85917</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_ProtocolArgs</type>
      <name>IRES_TILEDMEMORY_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga87e40295a0e896827ff16239c6677182</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_Obj</type>
      <name>IRES_TILEDMEMORY_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga7bd47c3771425981890d1973719bc4e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_RegisterLayer</type>
      <name>IRES_TILEDMEMORY_RegisterLayer</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gae5bceac65ea5bf226b3985d0a45703a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_TILEDMEMORY_Properties</type>
      <name>IRES_TILEDMEMORY_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga3a240a3b912b366e5925b5d4348fe2cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_TILEDMEMORY_AccessDimension</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga6bf19883a3a359c69a7a7cc98b9fb974</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_1D</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gga6bf19883a3a359c69a7a7cc98b9fb974aa4c4820939a3d136b7412f4131aa4df6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_2D</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gga6bf19883a3a359c69a7a7cc98b9fb974a16614330631204f327e743cee9ab1357</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IRES_TILEDMEMORY_AccessUnit</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gac19627dfd380195372144adab80be234</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_RAW</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a98d37e79007bfd16071e40ed1ccb1cd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_PAGE</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234afd35cbb38321a68e4ead2e4658d0c753</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_8BIT</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a7794d72ff22924c113b493852bf13889</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_16BIT</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a6aa4e8e64e0943270bef27b7e554a938</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IRES_TILEDMEMORY_32BIT</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ggac19627dfd380195372144adab80be234a83c19b1f33e69296e7468c3963fe99c9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_tiledmemory_IRESMAN_TILEDMEMORY</name>
    <title>IRESMAN TILEDMEM</title>
    <filename>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</filename>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_TILEDMEMORY_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gabea58ade569b614d4b8c55f455ea2833</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_TILEDMEMORY_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga4832f10ae177316cf1e73a29c6713531</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_TILEDMEMORY_init</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gaf0587262c783dfdf65faaaf6eea0807a</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_TILEDMEMORY_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga9415a0ced325b5467295b8771e52d304</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_TILEDMEMORY_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gadfa289400bc20009f0a0758bc7087aea</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_TILEDMEMORY_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gac62245768c47931560eeed6d7d73e02b</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_TILEDMEMORY_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga397775317ba851a3c541c861dc455c67</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRESMAN_TiledmemoryParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_TiledmemoryParams</type>
      <name>IRESMAN_TiledmemoryParams</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga53b69a325a2aef702b5627cc01f49400</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_TILEDMEMORY</name>
      <anchorfile>group__ti__sdo__fc__ires__tiledmemory___i_r_e_s_m_a_n___t_i_l_e_d_m_e_m_o_r_y.html</anchorfile>
      <anchor>gab09c8ecb9ece591a08a86b0b4a51ee23</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_vicp_IRES_VICP</name>
    <title>IRES VICP Protocol</title>
    <filename>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>gab443b20263d6d15d38353016d2caef35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga8f238b30de8eb64ef69362f215837eb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VICP_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga6ed720f53f0ec97580795ac36998cc32</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_VICP_ProtocolArgs</class>
    <class kind="struct">IRES_VICP_Obj</class>
    <class kind="struct">IRES_VICP_Registers</class>
    <class kind="struct">IRES_VICP_Properties</class>
    <member kind="typedef">
      <type>struct IRES_VICP_Obj *</type>
      <name>IRES_VICP_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>gaa23fbe3626f54ecc7754e908083f5f14</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_ProtocolArgs</type>
      <name>IRES_VICP_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga6b0466ea2e923232a5f2bf5d99b83663</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_Obj</type>
      <name>IRES_VICP_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga78dd89d90d8364d4ff126b4647228819</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_Registers</type>
      <name>IRES_VICP_Registers</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>ga12d9b10adf3be5345c5acf16def14707</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP_Properties</type>
      <name>IRES_VICP_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p.html</anchorfile>
      <anchor>gad8355b5acd95ef810245a947c87a3847</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_vicp_IRES_VICP2</name>
    <title>IRES VICP2 Protocol</title>
    <filename>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_MAXRESOURCES</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gae2d7e5517bd4a4fdc625666e6c5e5adc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_PROTOCOLNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga567229a2f3e00e0e9d21466ed3431cf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VICP2_MODNAME</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaf4c222d61975761f507563a64ab2e8c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_NUMBUFFERS</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaab43148f463371e818a2bb4aa54a7ff0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IRES_VICP2_BADRESOURCE</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga21eacd7bd8df315da75eead42c69980f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_A</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga93f6c8f9399b62b77358b09b454f1bc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_B</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga7ce68338708f75417578a42e669a3bd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_C</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga651aab779daf95714fc9d4ebbb837025</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_D</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaefc079a47ad6c8b93280472c76489660</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMGBUF_E</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga36eb2584901bebbb66196bcee110cf8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX0COEFFBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga65bcf315a5d316aaa3e9ab395d2471c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX0CMDBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga1e290134e965fe4a3129f2e2900e7edc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX1COEFFBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga26c31d6fb96a6de743eb2fe693722d79</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_IMX1CMDBUF</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga83ee7ac9cb91930315fe6e0763346047</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_BABYIMXCMDBUFFER</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gab37b9a7af92de477047cf405a34830ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_BABYIMXORIGBUFFER</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gada76039b30f0da7e1f64e62d7d92a573</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_BABYIMXREFBUFFER</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga3f39a6e3bd2bae22df6b420492f8e530</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_SEQUENCERPMEM</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga885d3ffb844c718affe4ab6fa1d82834</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_QIQMEM</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga3754ea74dcb47df85544679a4f790794</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_HUFFMEM</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gacb0523b1f612e97c672d11cf67576f39</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMCOP_BUFFER_SEQBUF4</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gaf8d8060812977a94c17eb6c0e9e3c944</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">IRES_VICP2_ProtocolArgs</class>
    <class kind="struct">IRES_VICP2_Obj</class>
    <class kind="struct">IRES_VICP2_Buffers</class>
    <class kind="struct">IRES_VICP2_Properties</class>
    <member kind="typedef">
      <type>struct IRES_VICP2_Obj *</type>
      <name>IRES_VICP2_Handle</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga7297c0d312df3cd6451bdd413ab87e23</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_ProtocolArgs</type>
      <name>IRES_VICP2_ProtocolArgs</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga62fcd51447b19beb9b35180fc28a2087</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_Obj</type>
      <name>IRES_VICP2_Obj</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga654e036e45b2ffc40744c5e2316c65b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_Buffers</type>
      <name>IRES_VICP2_Buffers</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>ga31f4217206b6254628cd32ffad288e6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct IRES_VICP2_Properties</type>
      <name>IRES_VICP2_Properties</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s___v_i_c_p2.html</anchorfile>
      <anchor>gac0df1fe8d22042b361fd4b66f5917dd4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_vicp_IRESMAN_VICP</name>
    <title>IRESMAN PROTOCOL - VICP</title>
    <filename>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</filename>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_VICP_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga4bf0fa4a35386dcd6f04c16a468984dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_VICP_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga01841f095420ce69ce02aaf644d7250d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP_init</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga613cdf62d35efa5fb1a02f9e07c73dd9</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga5d1eb79a6ad9c7a9e75fe48d70a2da58</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_VICP_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga64636048ebc7e7a1a41e96552297f022</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>gaa7bb21ce4147fab50131169877ab7f37</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_VicpParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_VicpParams</type>
      <name>IRESMAN_VicpParams</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga29f8ab6aaf9a18490216e300f12d2522</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_VICP</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p.html</anchorfile>
      <anchor>ga45a0fdbcf9e8610a403161583983578d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_ires_vicp_IRESMAN_VICP2</name>
    <title>IRESMAN PROTOCOL - VICP</title>
    <filename>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</filename>
    <member kind="function">
      <type>String</type>
      <name>IRESMAN_VICP2_getProtocolName</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga3a17b5082edb683f905b8c4db50b7a21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_ProtocolRevision *</type>
      <name>IRESMAN_VICP2_getProtocolRevision</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga2cbfd0894487f1bcb1dd8135453c1637</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP2_init</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gadd12c0a525f152ac57507f77f9cf5a62</anchor>
      <arglist>(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP2_exit</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gabaee5f47990c9c7c661313ab4fca3943</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IRES_Handle</type>
      <name>IRESMAN_VICP2_getHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gadb99a3dd012edcd0b085f0a75a4b2385</anchor>
      <arglist>(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="function">
      <type>IRES_Status</type>
      <name>IRESMAN_VICP2_freeHandles</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga493de59a219f0f9ff5991e40baf295bf</anchor>
      <arglist>(IALG_Handle algHandle, IRES_Handle algResourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
    <class kind="struct">IRESMAN_VicpParams</class>
    <member kind="typedef">
      <type>struct IRESMAN_VicpParams</type>
      <name>IRESMAN_VicpParams</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga29f8ab6aaf9a18490216e300f12d2522</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentAllocFxn</type>
      <name>_RMAN_allocPersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>gaadc2b94c8a7fe6dd08fcc18deec7d992</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>__FAR__ IRESMAN_PersistentFreeFxn</type>
      <name>_RMAN_freePersistent</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga0c23ac2d5d2854f5941c0b3098790df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_Fxns</type>
      <name>IRESMAN_VICP2</name>
      <anchorfile>group__ti__sdo__fc__ires__vicp___i_r_e_s_m_a_n___v_i_c_p2.html</anchorfile>
      <anchor>ga0cdcf22338a1507b35a1631b87f592d6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>ti_sdo_fc_scpy_SCPY</name>
    <title>SCPY - Functional library for SDMA resources</title>
    <filename>group__ti__sdo__fc__scpy___s_c_p_y.html</filename>
    <member kind="function">
      <type>void</type>
      <name>SCPY_init</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga1ab752be005b6c97dea0c75b816fea92</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_exit</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gad5bb9359e823883f9bdf583fb4bec6a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_configure</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gabc289b92aac62db2f16adc13a7169f38</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel, SCPY_Params *params)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_start</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga12cc8c59549b30813a6602110282b9ca</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SCPY_wait</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gac68b099a8b213a12b199b9799540671e</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel)</arglist>
    </member>
    <member kind="function">
      <type>Bool</type>
      <name>SCPY_complete</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gace3ec3f056bad890e721fb2f7f19c543</anchor>
      <arglist>(IRES_SDMA_Handle logicalChannel)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_DATA_TYPE_S8</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga258faf6d58227cba851a1e5e1f39f07f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_DATA_TYPE_S16</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga85fb4c8f497ebc94ab6dfafff20c8964</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_DATA_TYPE_S32</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gacb8aa19f5bcc98b70ccf5e3d0acb099e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_PORT_EMIFF</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gac5bd339b10aedbaff5a8c61e243ef146</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_CONST</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga9ffd54467a0a6eb22e845fced0abf1b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_INC</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gad3a6456aabb085058f234fd8fb389217</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_SINGLE_INDEX</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gad492a9de7f1b8a8ba250c6a83debcc69</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_AMODE_POST_DOUBLE_INDEX</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga7c1ca3f4716b7f6b53803c4a10c5cb25</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_MODE_ELEMENT</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga2bddc8d4bf3383645ba33e3eb1a346a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_MODE_FRAME</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga535e7376bc2fe197fd4cff1fbd398290</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_MODE_BLOCK</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gab4a43742db739f882df0473132757ab0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_TYPE_DEST</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga08deedaf80733d17c298b42ece800189</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OMAP_DMA_SYNC_TYPE_SRC</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gaba29f0ffd8cafab068ed79cc3263d18a</anchor>
      <arglist></arglist>
    </member>
    <class kind="struct">SCPY_AddrParams</class>
    <class kind="struct">SCPY_TransferParams</class>
    <class kind="struct">SCPY_Params</class>
    <member kind="typedef">
      <type>struct SCPY_AddrParams</type>
      <name>SCPY_AddrParams</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga7eab68f6cccf9ce565e81b1265e2eccb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct SCPY_TransferParams</type>
      <name>SCPY_TransferParams</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>ga6f84be922917b08c9b84ec501fc46bd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct SCPY_Params</type>
      <name>SCPY_Params</name>
      <anchorfile>group__ti__sdo__fc__scpy___s_c_p_y.html</anchorfile>
      <anchor>gac87af553e83f8583bb53fe7a68f48c12</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ACPY3_INSTR_ExtendedHooks</name>
    <filename>struct_a_c_p_y3___i_n_s_t_r___extended_hooks.html</filename>
    <member kind="variable">
      <type>ACPY3_INSTR_Hook</type>
      <name>InstrHooks</name>
      <anchorfile>struct_a_c_p_y3___i_n_s_t_r___extended_hooks.html</anchorfile>
      <anchor>a56936971f6f51fc79dea6fbb46d4f802</anchor>
      <arglist>[22]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ACPY3_INSTR_Hook</name>
    <filename>struct_a_c_p_y3___i_n_s_t_r___hook.html</filename>
    <member kind="variable">
      <type>ACPY3_INSTR_HookFxn</type>
      <name>fxn</name>
      <anchorfile>struct_a_c_p_y3___i_n_s_t_r___hook.html</anchorfile>
      <anchor>a09a13fd1658896bf618a65159b7166a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>args</name>
      <anchorfile>struct_a_c_p_y3___i_n_s_t_r___hook.html</anchorfile>
      <anchor>a67f500a37d4a9c952b753c8a6085cc6a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ACPY3_INSTR_Hooks</name>
    <filename>struct_a_c_p_y3___i_n_s_t_r___hooks.html</filename>
    <member kind="variable">
      <type>ACPY3_INSTR_Hook</type>
      <name>InstrHooks</name>
      <anchorfile>struct_a_c_p_y3___i_n_s_t_r___hooks.html</anchorfile>
      <anchor>a6b4fd44b198e49f949eda0c4c1a6a938</anchor>
      <arglist>[4]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ACPY3_Params</name>
    <filename>struct_a_c_p_y3___params.html</filename>
    <member kind="variable">
      <type>ACPY3_TransferType</type>
      <name>transferType</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a6c3d7890c527cbdaaf381bde2850c01c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>srcAddr</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a856068e9bcada2a38df9704fac8cdcce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>dstAddr</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a5af0ce6af53e9072085a2e7d358469af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>elementSize</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a92cde9a9809c3e94d55d3052c46cbf9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numElements</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a45b29827b5b2c1fc95c9830319937ff9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numFrames</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a73ed40d38b47f7666545f7b85e9128f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>srcElementIndex</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a6355aa8a5d167963f0460d646e226ad4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>dstElementIndex</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a21862eeec6cfe0a31fdf178e9c31330d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>srcFrameIndex</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>ae4acfee747a9a15056c51d724c48c1e4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>dstFrameIndex</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a5d6591c6cd74dbc65b6d0a15ac15f6a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>waitId</name>
      <anchorfile>struct_a_c_p_y3___params.html</anchorfile>
      <anchor>a1f5928622a6006a35c91fe8d0cb9dd8b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>DMAN3_Params</name>
    <filename>struct_d_m_a_n3___params.html</filename>
    <member kind="variable">
      <type>Uns *</type>
      <name>qdmaPaRamBase</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a766e441c25336fb3a36d56c711cb08e4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>maxPaRamEntries</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a58339ef320bf8a83a2b995124965405e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>paRamBaseIndex</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>acd68bdec25ab7f38188f61bf2fda5ceb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>numPaRamEntries</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>acde436b501fefb284f4cf43d87dd9e0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>maxQdmaChannels</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>ac8625cdf0b069aea5d9456be100aef33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>numQdmaChannels</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a354db3352d61cd71924bdd6c8827f5a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns *</type>
      <name>qdmaChannels</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a3ce746095fcc42779b01362ba9fe2359</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>tccAllocationMaskH</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a1866abe117288a1d94b9ac62039b7f46</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>tccAllocationMaskL</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>ace9a03fc79f8cf2727f2753693a66caa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>heapInternal</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>aba07cb30dd0310eb1bca27e3bf422861</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>xdc_runtime_IHeap_Handle</type>
      <name>heapExternal</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a4c5477f9c4aa989b7d0a2ecc2de9be65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>numTccGroup</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a884350bdeb758d35cd8aed1d5dca73af</anchor>
      <arglist>[20]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numPaRamGroup</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a3d885b052986eaf243861f19e5cb984c</anchor>
      <arglist>[20]</arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>idma3Internal</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>ac1550ea0e1f8b5442f88eccc395a491c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>DMAN3_ScratchAllocFxn</type>
      <name>scratchAllocFxn</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a5fd92c4be106cf2614490abffdd09b60</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>DMAN3_ScratchFreeFxn</type>
      <name>scratchFreeFxn</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a383ff9a30cfc36cb8ab0b0d8a4701fce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>nullPaRamIndex</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a35fa90f301f8b215cb385a78d4fb215d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>maxTCs</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a065faab1be429c33fe2237f4257e5e2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns *</type>
      <name>qdmaQueueMap</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a7b124ddb617616f17eb3992d13f79595</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns *</type>
      <name>queueTCMap</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a89fdbfb8dc13a06a368f0a69bb371604</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns *</type>
      <name>queuePri</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>aab16bffddce331441e0e0469a2bb53b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>allowUnshared</name>
      <anchorfile>struct_d_m_a_n3___params.html</anchorfile>
      <anchor>a0ca70e028eaa88968473cdfa6145c9c8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ECPY_CfgParams</name>
    <filename>struct_e_c_p_y___cfg_params.html</filename>
    <member kind="variable">
      <type>ECPY_PersistentAllocFxn *</type>
      <name>allocFxn</name>
      <anchorfile>struct_e_c_p_y___cfg_params.html</anchorfile>
      <anchor>ad05322d9c1c310c23f5c95812132d11d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ECPY_PersistentFreeFxn *</type>
      <name>freeFxn</name>
      <anchorfile>struct_e_c_p_y___cfg_params.html</anchorfile>
      <anchor>a68e01584bcf9d7050a770a5e3554203c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ECPY_ScratchAllocFxn *</type>
      <name>scratchAllocFxn</name>
      <anchorfile>struct_e_c_p_y___cfg_params.html</anchorfile>
      <anchor>a270e23d4710def5f1c22dcbed00f640e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ECPY_ScratchFreeFxn *</type>
      <name>scratchFreeFxn</name>
      <anchorfile>struct_e_c_p_y___cfg_params.html</anchorfile>
      <anchor>ab0dc3d5147909e3ff2c9cb48c200195a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ECPY_getScratchIdFxn *</type>
      <name>getScratchIdFxn</name>
      <anchorfile>struct_e_c_p_y___cfg_params.html</anchorfile>
      <anchor>a0493036e00791d10fd0e31ee1bd4d85e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ECPY_Params</name>
    <filename>struct_e_c_p_y___params.html</filename>
    <member kind="variable">
      <type>ECPY_TransferType</type>
      <name>transferType</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>a93f77d9aaa134ee7df1849b412560d30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>srcAddr</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>a33a9323129706ecf45051f0511b44418</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>dstAddr</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>a3384cbdf302872ec290f2fabde55a785</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>elementSize</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>a89c95f8116ac4779f91e035c23d51a8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numElements</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>adb8d423582c44e4f2fa494ffdc999b09</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numFrames</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>aa789f8cdd9701c66d83baf481cdee923</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>srcElementIndex</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>af8e28f9a7b11381ec681076b4a6ad049</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>dstElementIndex</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>a91cacfb281c520af816662bc1aec0ba6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>srcFrameIndex</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>a6d373a3f073e84972388028101e19f6d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>dstFrameIndex</name>
      <anchorfile>struct_e_c_p_y___params.html</anchorfile>
      <anchor>af84438c2ec8c98dc6ee6442a5e79ee8e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>HDINTC_Params</name>
    <filename>struct_h_d_i_n_t_c___params.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>interruptVectorId_0</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>ab84edbc3e4d262b0c896330b7a913130</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>interruptVectorId_1</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>aaf21c4e636c70271ecfc51746b411aca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>hdvicpInterruptEventNo_0</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>a0a707dee3eb6b62a6b9c5716f434dcd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>hdvicpInterruptEventNo_1</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>a5a04880a6cb3b179a677229b0485239a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>biosInterruptVectorId_0</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>a136618de21df8d51e81599e88596f3e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>biosInterruptVectorId_1</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>a337d6a0f93c7ebc1f3ebdfc3c8357011</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>biosInterruptEventNo_0</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>a80e1068552d8faa436c2cf23521ed144</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>biosInterruptEventNo_1</name>
      <anchorfile>struct_h_d_i_n_t_c___params.html</anchorfile>
      <anchor>abef47b1f4789922b629643a47fb7c89e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>hdvicpAppHandle</name>
    <filename>structhdvicp_app_handle.html</filename>
    <member kind="variable">
      <type>XDAS_UInt32</type>
      <name>handleSize</name>
      <anchorfile>structhdvicp_app_handle.html</anchorfile>
      <anchor>a7e1b19b418228c0937f209a79a855279</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32</type>
      <name>processId</name>
      <anchorfile>structhdvicp_app_handle.html</anchorfile>
      <anchor>abe4d78eaf6839d4a310ab3d5431eb000</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>info</name>
      <anchorfile>structhdvicp_app_handle.html</anchorfile>
      <anchor>a67953ca357aa9b2cf19a1938f074857c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IALG_Fxns</name>
    <filename>struct_i_a_l_g___fxns.html</filename>
    <member kind="variable">
      <type>Void *</type>
      <name>implementationId</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a83963e2ca17632c15bdb01494481a615</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void(*</type>
      <name>algActivate</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>af1213efc8ac6fdfb72b50da9950baaa7</anchor>
      <arglist>)(IALG_Handle handle)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>algAlloc</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a1640ba8f4033af1ce3887283c7a12746</anchor>
      <arglist>)(const IALG_Params *params, struct IALG_Fxns **parentFxns, IALG_MemRec *memTab)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>algControl</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a4c506a1599a604b02b30097e61ff4b89</anchor>
      <arglist>)(IALG_Handle handle, IALG_Cmd cmd, IALG_Status *status)</arglist>
    </member>
    <member kind="variable">
      <type>Void(*</type>
      <name>algDeactivate</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a10f29860ab8b3beab69b0f0128c3d969</anchor>
      <arglist>)(IALG_Handle handle)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>algFree</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>ac6f87b240d96486e3e88e80b95046ade</anchor>
      <arglist>)(IALG_Handle handle, IALG_MemRec *memTab)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>algInit</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a94eca7c58cceb112eccd970a6cf3f569</anchor>
      <arglist>)(IALG_Handle handle, const IALG_MemRec *memTab, IALG_Handle parent, const IALG_Params *params)</arglist>
    </member>
    <member kind="variable">
      <type>Void(*</type>
      <name>algMoved</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a5456c5087825b808e18000c551a66ef1</anchor>
      <arglist>)(IALG_Handle handle, const IALG_MemRec *memTab, IALG_Handle parent, const IALG_Params *params)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>algNumAlloc</name>
      <anchorfile>struct_i_a_l_g___fxns.html</anchorfile>
      <anchor>a098c1ca275465bb4acc1d3d0cf060160</anchor>
      <arglist>)(Void)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IALG_MemRec</name>
    <filename>struct_i_a_l_g___mem_rec.html</filename>
    <member kind="variable">
      <type>Uns</type>
      <name>size</name>
      <anchorfile>struct_i_a_l_g___mem_rec.html</anchorfile>
      <anchor>a6d4138068c5a30b4399464f5a8e3aca2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>alignment</name>
      <anchorfile>struct_i_a_l_g___mem_rec.html</anchorfile>
      <anchor>a86daec3754a4b918fff07efe28461748</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IALG_MemSpace</type>
      <name>space</name>
      <anchorfile>struct_i_a_l_g___mem_rec.html</anchorfile>
      <anchor>a41e307f25d01a4329f4f4bd794c9087c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IALG_MemAttrs</type>
      <name>attrs</name>
      <anchorfile>struct_i_a_l_g___mem_rec.html</anchorfile>
      <anchor>aa9dca3a637dc7e26069f4a11e7c82593</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>base</name>
      <anchorfile>struct_i_a_l_g___mem_rec.html</anchorfile>
      <anchor>a2a51de211c96021ca4aa360e352aa90f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IALG_Obj</name>
    <filename>struct_i_a_l_g___obj.html</filename>
    <member kind="variable">
      <type>struct IALG_Fxns *</type>
      <name>fxns</name>
      <anchorfile>struct_i_a_l_g___obj.html</anchorfile>
      <anchor>aa80d0fb968dce61561689d3793bd5b6c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IALG_Params</name>
    <filename>struct_i_a_l_g___params.html</filename>
    <member kind="variable">
      <type>Int</type>
      <name>size</name>
      <anchorfile>struct_i_a_l_g___params.html</anchorfile>
      <anchor>af8fa239e38c54b8202e30292e99089c4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IALG_Status</name>
    <filename>struct_i_a_l_g___status.html</filename>
    <member kind="variable">
      <type>Int</type>
      <name>size</name>
      <anchorfile>struct_i_a_l_g___status.html</anchorfile>
      <anchor>a852361d0183829e930a949268d9b0b02</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IDMA3_ChannelRec</name>
    <filename>struct_i_d_m_a3___channel_rec.html</filename>
    <member kind="variable">
      <type>IDMA3_Handle</type>
      <name>handle</name>
      <anchorfile>struct_i_d_m_a3___channel_rec.html</anchorfile>
      <anchor>a5632bb9719d49836987e3b4ae9b3d692</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>numTransfers</name>
      <anchorfile>struct_i_d_m_a3___channel_rec.html</anchorfile>
      <anchor>a725990b773355d1dfd5fc9af66179d22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>numWaits</name>
      <anchorfile>struct_i_d_m_a3___channel_rec.html</anchorfile>
      <anchor>a9be5abbc86b57d28e1d65cc6ea1ed294</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IDMA3_Priority</type>
      <name>priority</name>
      <anchorfile>struct_i_d_m_a3___channel_rec.html</anchorfile>
      <anchor>ae8b3740a842ad7ebb28cecf135f0c88f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IDMA3_ProtocolHandle</type>
      <name>protocol</name>
      <anchorfile>struct_i_d_m_a3___channel_rec.html</anchorfile>
      <anchor>aa7a4ff7549fd7be65a22cba0b8d50fad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>persistent</name>
      <anchorfile>struct_i_d_m_a3___channel_rec.html</anchorfile>
      <anchor>ac7a418727b547fe8f9d88f74f7d4c764</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IDMA3_Fxns</name>
    <filename>struct_i_d_m_a3___fxns.html</filename>
    <member kind="variable">
      <type>Void *</type>
      <name>implementationId</name>
      <anchorfile>struct_i_d_m_a3___fxns.html</anchorfile>
      <anchor>a4ee5aca6d6f29e0e09c83eaae2a44aec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void(*</type>
      <name>dmaChangeChannels</name>
      <anchorfile>struct_i_d_m_a3___fxns.html</anchorfile>
      <anchor>a1b05e503408ceb2849174d520932aa08</anchor>
      <arglist>)(IALG_Handle handle, IDMA3_ChannelRec *chnlRec)</arglist>
    </member>
    <member kind="variable">
      <type>Uns(*</type>
      <name>dmaGetChannelCnt</name>
      <anchorfile>struct_i_d_m_a3___fxns.html</anchorfile>
      <anchor>a2f893a5ce598a401aecf9e79a5d973d2</anchor>
      <arglist>)(Void)</arglist>
    </member>
    <member kind="variable">
      <type>Uns(*</type>
      <name>dmaGetChannels</name>
      <anchorfile>struct_i_d_m_a3___fxns.html</anchorfile>
      <anchor>a91d2edc4e5202ab46028a272cf8f7ad6</anchor>
      <arglist>)(IALG_Handle handle, IDMA3_ChannelRec *chnlRec)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>dmaInit</name>
      <anchorfile>struct_i_d_m_a3___fxns.html</anchorfile>
      <anchor>a080578d0edab90882b4fe8124c74eea2</anchor>
      <arglist>)(IALG_Handle handle, IDMA3_ChannelRec *chnlRec)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IDMA3_MemRec</name>
    <filename>struct_i_d_m_a3___mem_rec.html</filename>
    <member kind="variable">
      <type>Void *</type>
      <name>base</name>
      <anchorfile>struct_i_d_m_a3___mem_rec.html</anchorfile>
      <anchor>a2b6835f2ed01fd1ffc7e45c5daa04de1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>size</name>
      <anchorfile>struct_i_d_m_a3___mem_rec.html</anchorfile>
      <anchor>a667c10232578b390f66e698d796b4d2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns</type>
      <name>align</name>
      <anchorfile>struct_i_d_m_a3___mem_rec.html</anchorfile>
      <anchor>a18a74cc1005f251748f198ff09f8e76f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IDMA3_MemType</type>
      <name>memType</name>
      <anchorfile>struct_i_d_m_a3___mem_rec.html</anchorfile>
      <anchor>a6036233a20bd80fe13a6921db305ee9d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IDMA3_Obj</name>
    <filename>struct_i_d_m_a3___obj.html</filename>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numTccs</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>aa76e185f21e92e2949ecce7991f22780</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>numPaRams</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>aa5adc01f587497ae3f7fac70d55116e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>tccTable</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>a185dbbfdd7f200a4d692e6b6fcc6a7f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Uns *</type>
      <name>paRamAddr</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>a61e6a45019fbc04e526cdd8cadbb6d59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>qdmaChan</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>a105710f5f0915241d4ebfb7640385338</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>transferPending</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>a95914721dbaef8bce045253b0cb81468</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>env</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>a900c29cb46bab73d88002d88a5ca41a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IDMA3_ProtocolHandle</type>
      <name>protocol</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>a74d1aa95d8583438686b86229a33a429</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>persistent</name>
      <anchorfile>struct_i_d_m_a3___obj.html</anchorfile>
      <anchor>aa45d155055413e89a97d98744809ee12</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IDMA3_ProtocolObj</name>
    <filename>struct_i_d_m_a3___protocol_obj.html</filename>
    <member kind="variable">
      <type>String</type>
      <name>name</name>
      <anchorfile>struct_i_d_m_a3___protocol_obj.html</anchorfile>
      <anchor>ae79494308149dd394cf13ceb8ba7c439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void(*</type>
      <name>getEnvMemRec</name>
      <anchorfile>struct_i_d_m_a3___protocol_obj.html</anchorfile>
      <anchor>a8985b385f24d611a7e65f1b6fc867159</anchor>
      <arglist>)(IDMA3_ChannelRec *chnlRec, IDMA3_MemRec *memRec)</arglist>
    </member>
    <member kind="variable">
      <type>Bool(*</type>
      <name>initHandle</name>
      <anchorfile>struct_i_d_m_a3___protocol_obj.html</anchorfile>
      <anchor>a147bfd9a69a93542195adcdea86a6a58</anchor>
      <arglist>)(IDMA3_Handle handle)</arglist>
    </member>
    <member kind="variable">
      <type>Bool(*</type>
      <name>deInitHandle</name>
      <anchorfile>struct_i_d_m_a3___protocol_obj.html</anchorfile>
      <anchor>a7ce1036a56ee66ca9d0a195c04e40518</anchor>
      <arglist>)(IDMA3_Handle handle)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN2_Obj</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>af8a6fbcd41a7bfea6d4ce035538b3689</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_EDMA3CHAN_PaRamStruct *</type>
      <name>shadowPaRams</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>aaf1fbddf122d96bb6802b5c2bc164bc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>assignedPaRamAddresses</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>a0d2ae43094786a57bebdffadd1be15cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short *</type>
      <name>assignedPaRamIndices</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>aa507f3c6c6b5cc44a0ab667cef3c5310</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short *</type>
      <name>assignedTccIndices</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>aea7fc25d4d88d7618610d1f45e079109</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedNumPaRams</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>a664ed2015328cde495a15cf518826628</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedNumTccs</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>ae2957a5c4a885db0e6132adeab685b6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedQdmaChannelIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>aebfec493501da098ecac1439800b45de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedEdmaChannelIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>ad4c37d53c1ea67522e5bb7496c74d82a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>esrBitMaskL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>ab81943b0dbe175e744af97bfc29bd3e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>esrBitMaskH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>ae575185c8df81406240f13d5cb05ceae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>iprBitMaskL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>ab0477b5b9fccf326eeca05c5fa1d7c9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>iprBitMaskH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>ad60f9ce1eb9b09de81a877baa73e472a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Int32 *</type>
      <name>queueMap</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n2___obj.html</anchorfile>
      <anchor>a845e36697dc7ccbf7e013f954fb0fc6f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_EDMA3DraeRegister</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_drae_register.html</filename>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>DRAE</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_drae_register.html</anchorfile>
      <anchor>a9e808ae96d25190d8514ec5797518bef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>DRAEH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_drae_register.html</anchorfile>
      <anchor>a8ae174d478321b4e40afc98a14fadfe4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_EDMA3RegisterLayer</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</filename>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>REV</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ac54e4d8b303bae2fc0aa242f68e7b1be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CCCFG</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a7a12dcd2b6c210b9a9307d70e5c401da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD0</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>affea5712c405c19ae00f5773fbf4a83c</anchor>
      <arglist>[248]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>DCHMAP</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aef4650a40f852f94c4976d3e0c2b368f</anchor>
      <arglist>[64]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QCHMAP</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>adbfc0ec2fe907f29ea58107e2f2a8bbf</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD1</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a1ef92ffe3d8a2623596fcebcd49e07e8</anchor>
      <arglist>[32]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>DMAQNUM</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a437e85b07c251f21a1c6bfacaa30c220</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QDMAQNUM</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a8b394162eec4bd1245fe84c83328a79f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD2</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aac1cb8c69373226881a063059125f72c</anchor>
      <arglist>[28]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QUETCMAP</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aac61c501760dfa8716596d30f11c1bf3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QUEPRI</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ae9503cd36dace0bb203fcd0698929c08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD3</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ab7634b40b367fc2eef9be4b429d94407</anchor>
      <arglist>[120]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EMR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ae03a011b22283645271cef808affd3b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EMRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ac1b9c9e9a35b03e2836a8ce8e09fe6a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EMCR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a288ebef22b61b85aa372a589e3791197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EMCRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a53cabc051fae87880ad326a6131efc19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEMR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a55a88ea4d8813e2d66f4737e86838a00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEMCR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a40ab7ec5b7d762f038642bf071067026</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CCERR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a3122e94a7d0229cb1b11bffdf48f5d74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CCERRCLR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a87fbd1a5fb5b206384da5c0a3f01dc97</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EEVAL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>adb9f4a5ee2fee596d1002fcb81921e63</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD4</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a92a72b6f9f27d90fc8016a60a07318cd</anchor>
      <arglist>[28]</arglist>
    </member>
    <member kind="variable">
      <type>IRES_EDMA3CHAN_EDMA3DraeRegister</type>
      <name>DRA</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a03d33a097d27d6e7119829df50a0eb8a</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QRAE</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a150169c8b6c463e24f641b2685a5621f</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD5</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a4d92cb7657c85619bd9470c4d8dd4fb0</anchor>
      <arglist>[96]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QUEEVTENTRY</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>abcdcfb3fb01888f9d16a1153e6d9dd06</anchor>
      <arglist>[8][16]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QSTAT</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a6e919f590b7e2543a00b6477175d585f</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QWMTHRA</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aada7476d787c8300951abadb3520c0b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QWMTHRB</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a856fa7ff1cc28d896ab8a71b8fd977e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD6</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>acee1638682f2c80864c05be606279551</anchor>
      <arglist>[24]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CCSTAT</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>af3e8e8e61da799a8c12696f9b2b5aacb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD7</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aa86878e266fc897493ff26f5a219b75b</anchor>
      <arglist>[188]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>AETCTL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a7d96f9048e37ac74146857f5c9fefc84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>AETSTAT</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>adad98cc5663eb941ef5fcfba4bcdccf4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>AETCMD</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ad0d6f7f01770a93b46c7903b7bdb4f27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD8</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a59e10a5efae47b72bfe5d0d0c3377f61</anchor>
      <arglist>[244]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>MPFAR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ae2219e147269e62e12ff77dbf3061e1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>MPFSR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ab27bd35a6b1d568b3e940fde95cf39e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>MPFCR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a9cbf38b017c3e9507587483e23594826</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>MPPAG</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aa6618180fb1ace6ab623c3dec0a87508</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>MPPA</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>abb43d07de6af261423ed1dcf119f6de7</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD9</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a807214d2a8a2f0662cc49ceb98b64a9b</anchor>
      <arglist>[2000]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a6965d078d0b04d266a9991bf9c9830ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a031bd43d639c4d6150809e82088569dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ac4a3851eee637396ca269f8d93e1835c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a220964a3364efa894f37f769aab2434b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a5bdc0cf6e86492817018f55ad876ce60</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ESRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ae7d659959adf2f5dd16caaab3671537f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ab7567083f34aaf3e455fb68c17bc8805</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a7b15dfa0f19d1a41183fcda8cc80f41d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>af5ca383e2d00e408c57d2cf1c1ddb449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a3960ec87a5529a08ff0a512148f18f59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ab6121bab1262f1a716d3037f1f14dd35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aa8a3dcd54a0ec08ac423c73134f482f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>adede8230a0476ee4e92771d6a7946b81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EESRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a8632fa9dfdab0717d8eebac48e9ea7d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a00412e6d3a41f2eb2684d5b6e11b121b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aaa86a93aa8c0f5b22e9414face78e3ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a0fdcba15b63d16547ca36d36a3370a7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a054a21331013040c2e0e26a84fa3b997</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD10</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ab3fdd9f0150bf4ab0837ba22d8efdcc2</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a8c61e1695ecdca0d8bbb9f6649c3c1d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a618aab4bb2abe895c57cbbdeda846718</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ad86c88e1823be37f36b55191da7adbc7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>abe5fbf1a714fad9a2f3d6c7d651d7245</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aca60ccffd95dec84500ea4b01713f4ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IESRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a7645192f36a2cf333fbb0aabab54184d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IPR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aa044b6f447c8b65f26d4ef0145ca7259</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IPRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>af0467677613773f41c4c24636d919765</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ICR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aa2cac41d44028fd3041c1cdc2a21c71e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ICRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a5155f2bd21c7c575d024f2e8370a9fbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IEVAL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a38f807cbc5488bc3bab38e921a3da631</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD11</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a67545db52008b0061deac7f739f1a996</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>af0261cb0f503a97ef2bfd0bc0da5d88e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a9b330d2d57f24bf9e9fc700b2409afd7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ad8d5d4bf7b036c73f0f88fd93a0c3176</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>af92bb426d5bf017e78cb8dd47df88324</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QSER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a01d3fefa43a804c82cd6680aee3a2ce4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QSECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ac8acc518f9e72c5e3071b031597dba59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD12</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>aae236f70ae48f7335f7c33fad85b2386</anchor>
      <arglist>[3944]</arglist>
    </member>
    <member kind="variable">
      <type>IRES_EDMA3CHAN_EDMA3ShadowRegister</type>
      <name>SHADOW</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a4310e25138662eb7ca91776c07446726</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD13</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>ae4b83eef72621e2bcf549bd75d023d80</anchor>
      <arglist>[4096]</arglist>
    </member>
    <member kind="variable">
      <type>IRES_EDMA3CHAN_PaRamStruct</type>
      <name>PARAMENTRY</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_register_layer.html</anchorfile>
      <anchor>a38304d07bef1e415081f467fab48def6</anchor>
      <arglist>[512]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_EDMA3ShadowRegister</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</filename>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>aee23cdf984110f26d52b3487251a5bc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a8162f08b6b337da84b2c39eec97ed7ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>aae811c5b95e7ff7efb8bb6cf3264979d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>add9f0a486048274ea7e4443fefa62276</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a6af4dec422b16655e8811bd7307700e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ESRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a27c406f710a7fa7ef2f838398c6c9801</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>aed02a479ec8ea7eeb04207858bef1c08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>CERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a92862b2078232caa5bf2a7f5e27eb95c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a34f42f3e84ca1fb9baad0bc8d625a14c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a3075403fd0ed0300a22313a351853e01</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a8f8503639eb8151ed829ff3ef0f1b5e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ae4843261a7e8e6fb28f9d3cfd258ea5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a7940489d971522c98e43962a5aa4640e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>EESRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ae80f612ea4be945a70fc8b409b25d661</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>aeccb35f278854ab17fc2db8442f46989</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a2a15c9130f535881a525596fb0acac2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ac98f10cb00323a98ec3b04d6977f34e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>SECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a591011f3b030e83ceae7e607d297bbd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD0</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ae796ce9db0169d174dbbb3a3d1ea0108</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ae9a3c71acbbbc96f74fabc239adcf6cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IERH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>af26ffeebd6430e416be7b8df2cc019fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ae314a97c5a28fe56b97f220f9d0b0554</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IECRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ad9d12d3ed110cec8eebe07d1f5873689</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a687cd004877cc6fb3d39353cad624b32</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IESRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a248019fbc22fe2972c1502d6028b77be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IPR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a9a7ce2c9eb6d1722b903f2b4f14dcde6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IPRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ab7f1ada93243bf3958db3177ce2ee631</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ICR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>af22a274535b89aea6a936172cc99ad96</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>ICRH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a2749efe7a75210c5bb5e01e8d8fb6ebd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>IEVAL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a31f09ac9bb272adb473e2b9dfb165365</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD1</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a7a1b4ed06a1f0b69c57710784651b3be</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a69946bd3f4fb9815d771ff8c7793e888</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ad5e12ab54cc9bdef77f75151de348255</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a0946e306b21dca2ef1b1eac81339bc20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QEESR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a2fa6787ac82799457610e55bf353ba2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QSER</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>ab31e4248421eb24e3372e20bb3002fbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned int</type>
      <name>QSECR</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a3294a3855b38f96ab1958fe5647aa377</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>volatile unsigned char</type>
      <name>RSVD2</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___e_d_m_a3_shadow_register.html</anchorfile>
      <anchor>a06affbc35d9f64fc8ba04ebf50317fca</anchor>
      <arglist>[360]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_Obj</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a40e1756b5ade03bf300b54f9b5eab496</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_EDMA3CHAN_PaRamStruct *</type>
      <name>shadowPaRams</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a3f596af3cf04045734257017a2faab51</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>assignedPaRamAddresses</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>abeba0335a802812f0e33b6203b525f14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short *</type>
      <name>assignedPaRamIndices</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>aee12c9bbedb02739f17d845cabc8c7bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short *</type>
      <name>assignedTccIndices</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a0705537b7ed97c2e2d73c9bf8882a790</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedNumPaRams</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>aacdfe6d10510f6672a07fdbac1a51317</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedNumTccs</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a37a425062c3fb91289537baec35e97f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedQdmaChannelIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a3cbedb9826bb63c25f5210b82c97b372</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedEdmaChannelIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a130ad94d4cf5e93304628f196b6135b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>esrBitMaskL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a7490ef52be82d57a2037dc3cfbe74126</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>esrBitMaskH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a079c7289178eea20f68ffda6d1168c23</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>iprBitMaskL</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>ab3108be5ce9944687096baee11ed4eb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>iprBitMaskH</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___obj.html</anchorfile>
      <anchor>a95cd4bdd4c90afd49e95f6bebc5423b7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_PaRamStruct</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>opt</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a54a02381e9429650b325c4d1847293ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>src</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a2d0bfd960a1bc7d869cca153eaa4ae38</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>acnt</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a16d93e85dcea4eca1e6707f16917d570</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>bcnt</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a8ad41154ec256a516f99fd554dd30c13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>dst</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a785e14c057576dd51a7b5568c4c62210</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>srcElementIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>ab73b73792be92a58b09ea552765dad08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>dstElementIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a3ec0b8153b52d319894302579e938b40</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>link</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>ad46dd22e92d137d72facd6ff4c0967a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>bCntrld</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a5b69579dcbe7038ea31152c099be3360</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>srcFrameIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a2aa917bf2e3f21fb3eacea36607d5433</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>dstFrameIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a8114c17ee881e165d8ce6dd41858a4ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>ccnt</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>ad7737b41e5ed2c3d61188833c3ff415b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>rsvd</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___pa_ram_struct.html</anchorfile>
      <anchor>a6ae099a297021bdbdc77b95823078520</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_Properties</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numDmaChannels</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>a2b72ba415dbad5a579d88d5da0d5ea21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numQdmaChannels</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>ad7c214e2680edf2f4d37383d0ea9f4fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numTccs</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>af85f3c00300b2022b36910b9428de0e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numPaRAMSets</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>a21f26eed1ca54246f784e1a4851ec934</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numEvtQueue</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>aed314c1dd26caa680e199c1ef831dd8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numTcs</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>aa1fc9e49b3edbd219de01ceb1f3d5d25</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numRegions</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>a7d823a7951834832d0a9ea78810f1e1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>dmaChPaRAMMapExists</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>a7d85ecf6b8c1543397a2a32d716045a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>memProtectionExists</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>aaf9a918aba3ab6d7958928613f3a438a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_EDMA3CHAN_EDMA3RegisterLayer *</type>
      <name>globalRegs</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___properties.html</anchorfile>
      <anchor>a617dc2263a7b5e3ce910840494e1bd1e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_EDMA3CHAN_ProtocolArgs</name>
    <filename>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a398c7be80d9e6c2f3fd1c7025f8b7a79</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_RequestMode</type>
      <name>mode</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a8fd3eb87fd47f66fcb2f268fe9f5c77f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>numPaRams</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a3582de3c4dceaedbedf669da00fbd6cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>paRamIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a0d8ca2609faf57e0bd0f7315d7404510</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>numTccs</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a4fe328fbbdcd32def3074a8905c7d0b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>tccIndex</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a4aaabc6616f5a34186e87667316ce0a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>qdmaChan</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a04f48281a7c858224698bf0e24d5d22c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>edmaChan</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a23001551faec579b5b5d049258fb8f28</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>contiguousAllocation</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a019cb773321cee58f158e42532b412b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>shadowPaRamsAllocation</name>
      <anchorfile>struct_i_r_e_s___e_d_m_a3_c_h_a_n___protocol_args.html</anchorfile>
      <anchor>a7105c440bacc9831a3057c8bec804647</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_Fxns</name>
    <filename>struct_i_r_e_s___fxns.html</filename>
    <member kind="variable">
      <type>Void *</type>
      <name>implementationId</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a9e320f3ea97f6746f6687ab970cd1648</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>getResourceDescriptors</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a7a09d4c2d0b9d6ea00a238434f13a896</anchor>
      <arglist>)(IALG_Handle handle, IRES_ResourceDescriptor *resourceDescriptors)</arglist>
    </member>
    <member kind="variable">
      <type>Int32(*</type>
      <name>numResourceDescriptors</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a4dfe8c6eb0bc509a9a74517d06ec444b</anchor>
      <arglist>)(IALG_Handle handle)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>initResources</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a13d55bc4ddf27675771fc591cca1bebd</anchor>
      <arglist>)(IALG_Handle handle, IRES_ResourceDescriptor *resourceDescriptor, IRES_YieldFxn yieldFxn, IRES_YieldArgs yieldArgs)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>reinitResources</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a53b93ddb7af70df1b4d30de8a68b14f4</anchor>
      <arglist>)(IALG_Handle handle, IRES_ResourceDescriptor *resourceDescriptor, IRES_YieldFxn yieldFxn, IRES_YieldArgs yieldArgs)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>deinitResources</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a505e5cc4df9d8df3afa1fd93d79607d8</anchor>
      <arglist>)(IALG_Handle handle, IRES_ResourceDescriptor *resourceDescriptor)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>activateResource</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a168fba039eac1b1e5b69cc3837ae4c30</anchor>
      <arglist>)(IALG_Handle handle, IRES_Handle resourceHandle)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>activateAllResources</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a5be6be2dd432d0df47c45b40c0f9741f</anchor>
      <arglist>)(IALG_Handle handle)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>deactivateResource</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a3b3bd5cfca1d704cc9801585b7702f46</anchor>
      <arglist>)(IALG_Handle handle, IRES_Handle resourceHandle)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>deactivateAllResources</name>
      <anchorfile>struct_i_r_e_s___fxns.html</anchorfile>
      <anchor>a1aa3029eea7a037909974f2f39d80a98</anchor>
      <arglist>)(IALG_Handle handle)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP2_Obj</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>ae06d76d124b8511ed08ac8f70086bbb5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>info</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a5b06dc398640e9f6f70eafdf73cc2489</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Int32</type>
      <name>id</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a4cf3360bf2107055e1c09487cfcf4e85</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>registerBaseAddress</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a0e330a5db9f04cf398e47ffe91fb5ece</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>memoryBaseAddress</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>ad2d09f4a58ec8e2332cd7f89bcd27305</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>resetControlAddress</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a95360d5c2f0f17dad26880ea0114ae8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void(*</type>
      <name>acquire</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a114747241bf4fb3757ddecb9790e66a0</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this, IRES_YieldContext *yieldCtxt, XDAS_UInt32 *hdvicp2Status, XDAS_UInt32 *configurationId, XDAS_Int32 lateAcquireArg)</arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void(*</type>
      <name>release</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>aaea49c1250395a0ccc9396efeb792616</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this)</arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32(*</type>
      <name>reacquireIfOwner</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a023202a1edf28ffabbc0c0bbb28a7229</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this)</arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void(*</type>
      <name>configure</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a7b0639762900b6b48dbff0c4300c0aac</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this, IRES_HDVICP2_CallbackFxn cbFunctionPtr, XDAS_Void *cbArgs)</arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32(*</type>
      <name>wait</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>af507a888d54318fdefa7adf5f04db34b</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this, IRES_YieldContext *yieldCtxt)</arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void(*</type>
      <name>done</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>ad715de64290d08ee060849b4d732c12d</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this)</arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32(*</type>
      <name>reset</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___obj.html</anchorfile>
      <anchor>a5ec71062659a2d5f6efdc0f60d5555f1</anchor>
      <arglist>)(IALG_Handle algHandle, struct IRES_HDVICP2_Obj *this)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP2_Properties</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p2___properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___properties.html</anchorfile>
      <anchor>a98a0846453e1074c7d4982f016dc64b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_HDVICP2_RegisterLayer *</type>
      <name>globalRegs</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___properties.html</anchorfile>
      <anchor>ab0ef58b1868d8263b659f77b5ada49d7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP2_ProtocolArgs</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p2___protocol_args.html</filename>
    <member kind="variable">
      <type>IRES_ProtocolArgs</type>
      <name>base</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a66f759dc45020ec40885177ab6b48de7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Int32</type>
      <name>id</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>abe3d3255bf68273f33603bc44e0f74bb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP2_RegisterLayer</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p2___register_layer.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p2___register_layer.html</anchorfile>
      <anchor>ad0b49c8186268337bd18d8ead510db2c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP_Obj</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___obj.html</anchorfile>
      <anchor>a5d4026e15d60feda5e84dd3eb918e6fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>info</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___obj.html</anchorfile>
      <anchor>aa313d7af9092b431d6667e704df8ed44</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>id</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___obj.html</anchorfile>
      <anchor>ad310c8bdd68ee2f2ff8942c29359ac5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>registerBaseAddress</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___obj.html</anchorfile>
      <anchor>ac573c0a37c83536214a504e20bc36805</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>memoryBaseAddress</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___obj.html</anchorfile>
      <anchor>acb98c73e26d8845171ce86e6d5a77894</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>pscRegisterSpace</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___obj.html</anchorfile>
      <anchor>a3fdc51d26670a7c19226d1b290e75655</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP_Properties</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p___properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___properties.html</anchorfile>
      <anchor>aba443d8563f35b2c823f0fb1785731cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_HDVICP_RegisterLayer *</type>
      <name>globalRegs</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___properties.html</anchorfile>
      <anchor>aac58b5a8cbb86d0c5f0ff397d795fb93</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP_ProtocolArgs</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p___protocol_args.html</filename>
    <member kind="variable">
      <type>IRES_ProtocolArgs</type>
      <name>base</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___protocol_args.html</anchorfile>
      <anchor>a997ef9081ec10e67512ddfd5323ff86b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_HDVICP_RequestType</type>
      <name>id</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___protocol_args.html</anchorfile>
      <anchor>a1e0d8a64eff399ecbc6d3f9f569d0ccf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_HDVICP_RegisterLayer</name>
    <filename>struct_i_r_e_s___h_d_v_i_c_p___register_layer.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___h_d_v_i_c_p___register_layer.html</anchorfile>
      <anchor>a64b05fc704c8ca0f5292f0e4d67cf86c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_Obj</name>
    <filename>struct_i_r_e_s___obj.html</filename>
    <member kind="variable">
      <type>Int32</type>
      <name>persistent</name>
      <anchorfile>struct_i_r_e_s___obj.html</anchorfile>
      <anchor>a3e006a68f51d639510a5c4c40a9f6c5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void(*</type>
      <name>getStaticProperties</name>
      <anchorfile>struct_i_r_e_s___obj.html</anchorfile>
      <anchor>a6f851ab721d73bb546632ca59176fcc9</anchor>
      <arglist>)(struct IRES_Obj *resourceHandle, IRES_Properties *resourceProperties)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_Properties</name>
    <filename>struct_i_r_e_s___properties.html</filename>
    <member kind="variable">
      <type>Int32</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___properties.html</anchorfile>
      <anchor>a1a09949a3cf97c048bb9de995fae07bf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_ProtocolArgs</name>
    <filename>struct_i_r_e_s___protocol_args.html</filename>
    <member kind="variable">
      <type>Int32</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___protocol_args.html</anchorfile>
      <anchor>a22815469d186167c7c6ef6a61e8370e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_RequestMode</type>
      <name>mode</name>
      <anchorfile>struct_i_r_e_s___protocol_args.html</anchorfile>
      <anchor>afc5243b51314f144cd8e1c6e9a8aa339</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_ProtocolRevision</name>
    <filename>struct_i_r_e_s___protocol_revision.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>Major</name>
      <anchorfile>struct_i_r_e_s___protocol_revision.html</anchorfile>
      <anchor>ab87b0887f1cddec8bce82b58cdd7f128</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>Source</name>
      <anchorfile>struct_i_r_e_s___protocol_revision.html</anchorfile>
      <anchor>af316c476cb1698db013aa50b30681178</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>Radius</name>
      <anchorfile>struct_i_r_e_s___protocol_revision.html</anchorfile>
      <anchor>ab3d416ec6cf89163f2a4c71b4e90e00e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_ResourceDescriptor</name>
    <filename>struct_i_r_e_s___resource_descriptor.html</filename>
    <member kind="variable">
      <type>String</type>
      <name>resourceName</name>
      <anchorfile>struct_i_r_e_s___resource_descriptor.html</anchorfile>
      <anchor>a5973fb17ebaef2af33b062c83b80dc09</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct IRES_ProtocolArgs *</type>
      <name>protocolArgs</name>
      <anchorfile>struct_i_r_e_s___resource_descriptor.html</anchorfile>
      <anchor>abf4eb84081251fe2ae5f47edfec3b277</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_ProtocolRevision *</type>
      <name>revision</name>
      <anchorfile>struct_i_r_e_s___resource_descriptor.html</anchorfile>
      <anchor>ac763c830eaa0da73edafcabdc9990b05</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct IRES_Obj *</type>
      <name>handle</name>
      <anchorfile>struct_i_r_e_s___resource_descriptor.html</anchorfile>
      <anchor>a45b8e88d5f2e1dd20292f6f90783fed2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_SDMA_Obj</name>
    <filename>struct_i_r_e_s___s_d_m_a___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___obj.html</anchorfile>
      <anchor>af23043b5ec56d38ca026df18c4c79f0f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDMA_ChannelDescriptor *</type>
      <name>channel</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___obj.html</anchorfile>
      <anchor>a7fa1f1ac81279c8bd764be8f6d9d3b81</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_SDMA_Properties</name>
    <filename>struct_i_r_e_s___s_d_m_a___properties.html</filename>
    <member kind="variable">
      <type>IRES_SDMA_RegisterLayer *</type>
      <name>globalRegs</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___properties.html</anchorfile>
      <anchor>a0c573058839c9febe7a7ea95f1cf166c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_SDMA_ProtocolArgs</name>
    <filename>struct_i_r_e_s___s_d_m_a___protocol_args.html</filename>
    <member kind="variable">
      <type>IRES_ProtocolArgs</type>
      <name>base</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___protocol_args.html</anchorfile>
      <anchor>a4920fdec46b32b3c24d174f050c35dfb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_SDMA_RegisterLayer</name>
    <filename>struct_i_r_e_s___s_d_m_a___register_layer.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CCR</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>aa0507b123500c0738eb94baa70ea62bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CLNK_CTRL</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>afce8e9ca416c7a8d1a135b5c819c44fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CICR</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a87d858f415bca654ab6e05406d1216a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CSR</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>ab59c0f8164dafc4c20ae0e6cd24ea005</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CSDP</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>af9cb662387ff0115d07f2210934575db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CEN</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>abe499f2823a06300443bc69fb273fac9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CFN</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a335835388ada2d54b86cfa06d57630ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CSSA</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>acf5204d8179433c28803433dc811b9d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CDSA</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>ae1d91296667b6974ee3c77593e63df9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CSE</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a2d415296b33f5dfbda7541138e1bf3d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CSF</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a4d9f109a2313a456ff01060d1fa75fbb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CDE</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a4ed51b0918b612d4b4f6d557aebec504</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CDF</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a23eee898836ecf628811533527cdf1c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CSAC</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a76bb1781047703cde967f628081fb431</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CDAC</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>af7cf191cd16ea4a3060cb80984eefa85</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CCEN</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a4c4b185ce908895fe0f89b902ebdc8bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_CCFN</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a7bbe5545fc49351114d092d132e6a87c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>DMA4_COLOR</name>
      <anchorfile>struct_i_r_e_s___s_d_m_a___register_layer.html</anchorfile>
      <anchor>a578082af311916b451077c1aac032cc4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_TILEDMEMORY_Obj</name>
    <filename>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>a3146482fb8a79ddbfe7a9604441baad9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>info</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>a1d3fe9f1186f47f828cd6e199ea0382c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>memoryBaseAddress</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>a5a7b295412151d5acac69137dd72567c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32</type>
      <name>isTiledMemory</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>af13e300742f1fdef8ac212eb3b7831de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32</type>
      <name>accessUnit</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>a3fdec399b3ce2e3094e31aca70b06f91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>tilerBaseAddress</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>a61656ed9ab49f6945894411dacf4bd3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_Void *</type>
      <name>systemSpaceBaseAddress</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___obj.html</anchorfile>
      <anchor>a96d0e320468088dff50d952cc89df656</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_TILEDMEMORY_Properties</name>
    <filename>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___properties.html</anchorfile>
      <anchor>a90c348d66f0ff30c7c0bb76f5382c2eb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_TILEDMEMORY_ProtocolArgs</name>
    <filename>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</filename>
    <member kind="variable">
      <type>IRES_ProtocolArgs</type>
      <name>base</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</anchorfile>
      <anchor>ac80bb14fb6b3fd931c5c78b7d19831bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32</type>
      <name>accessDimension</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</anchorfile>
      <anchor>a573824791ca49e9ebe7cc1118787267b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>XDAS_UInt32</type>
      <name>accessUnit</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</anchorfile>
      <anchor>ae2328111c90b608ba8f8b48d698004ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>sizeDim0</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</anchorfile>
      <anchor>aa8dc63bf23d93a8961b99ae58d9834ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>sizeDim1</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</anchorfile>
      <anchor>a0292f4b3d664923a98bcff201c33fdf7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>alignment</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___protocol_args.html</anchorfile>
      <anchor>a8b065e50b2f796e03ac8931a8e578315</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_TILEDMEMORY_RegisterLayer</name>
    <filename>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___register_layer.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___t_i_l_e_d_m_e_m_o_r_y___register_layer.html</anchorfile>
      <anchor>a1b16edf76dc04230e1898ad2942fb40d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP2_Buffers</name>
    <filename>struct_i_r_e_s___v_i_c_p2___buffers.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>ab5755f730b25c17caab169fc3f45c7d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>vicp_cfg_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a481a2765f84cd9e7aa77afb2ae316b00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufA_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>adeae5433144a8f8cd7fa08a40ce30cb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufB_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>ae9a43f965f8d02dbc630b59ca1012376</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufC_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a01b45cfb3dc858439a3b84720ddccf6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufD_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a00eb1b196bf183e1ad61369cc93ec89d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufE_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a8cbba5917a02ca0355f0549ddbcb00a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imx0CoeffBuff_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>ac9d9a7a7b19db7be7e8a9824111f9c3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imx0CmdBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a902f7fd6071f8688e047defebec9d986</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imx1CoeffBuff_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a9cc15a6e03a9d3defcf9a855c275acd7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imx1CmdBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>ab74fe3e194b4b47b053a4ccbb6a8bb19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>babyImxCmdBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a9402b9ea2e03d5a6b522fb619f9ce333</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>babyImxOrigBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a0058249d205f1d3dda30d53c443dc9b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>babyImxRefBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a14b839f9e8f69c7b372909cd6a9270ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>sequencerPmem_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a6668815da72cba4e64e8ab96e37c97bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>qiqmem_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a551c8f7d1a82a81635995bbd0c5f4c78</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>predmem_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>af411628f92467ae7375f35b3d1bcda8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>mvmem</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a7adf0dd348980f48756ba0b3b4a9bf70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>huffmem</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>ab61f96ba1c7abe3b0e9ebef19b7e1f4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>seqBuf1</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>af1cf122f14857c79d37365214e700d12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>seqBuf2</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a709d57885b8d85465e849f5db0785e06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>seqBuf3</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>a3015f49a44bc48651c8728fdd8ca04d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>seqBuf4</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>aba9bbba2749f4eacb68e3b470c08b39f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int *</type>
      <name>sequencerDmem</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___buffers.html</anchorfile>
      <anchor>aa1b0756c0986dd6583aeb93ede583556</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP2_Obj</name>
    <filename>struct_i_r_e_s___v_i_c_p2___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>a5e3040baefc52a30bf55ddebf2e56a28</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedIMX0</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>a0f8be020face1829a60307e7023ce809</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedIMX1</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>ab20dd133aefdfed41be057fad07653db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedMJCP</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>ab7c35605ffdb61a360cfa0da254cf7be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedNSF</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>abe151dd6e033c9ce81ed4853953848c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>assignedIMCOPBuffers</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>aa92f0e3f5bc191b3ca5041119b1775e0</anchor>
      <arglist>[16]</arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>numMemBufs</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>a6f1a3fed6d313996d11f7c3a4e4a584e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>assignedMemAddrs</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>a197f5ff0f2de17d87f65bd20c398626f</anchor>
      <arglist>[16]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>assignedMemSizes</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>aa6909916240c6fffe8295f4163ed60fc</anchor>
      <arglist>[16]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>configBaseAddress</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>afae9568ed0a7ee5f900c26cfab906a85</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>dmaViewConfigBaseAddr</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>abe3151c5d108373be7bc148cce6afb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>pscRegisterSpace</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___obj.html</anchorfile>
      <anchor>a0e55ce5730f5db422399350fb6ce7133</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP2_Properties</name>
    <filename>struct_i_r_e_s___v_i_c_p2___properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___properties.html</anchorfile>
      <anchor>a3a711d127b0349d5cf7ee970d2bbd418</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_VICP2_Buffers</type>
      <name>buffers</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___properties.html</anchorfile>
      <anchor>a651f96e138f5e48a156cfa8bc1a0d3ab</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP2_ProtocolArgs</name>
    <filename>struct_i_r_e_s___v_i_c_p2___protocol_args.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a9ae91f885eee0a74c10c850922c9db11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_RequestMode</type>
      <name>mode</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>af4db39ced63fd088cd7032b3149e0cbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestIMX0</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a0f415a7218339e64755cbcf3da1a3b68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestIMX1</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a676bc519172e4a4970242c33e0d46043</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestMJCP</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>aebb657314e60ea19042be759ec0bb400</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestNSF</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a2e3d602003cc9ba37c74b0564942b7a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>requestIMCOPBuffers</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a321a4ac45de2c684ba434d5b15f270cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>numMemoryRequests</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>ac83ed1df16c27feffc6247eb528b31f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>memRequestSizes</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p2___protocol_args.html</anchorfile>
      <anchor>a6adfc67a07dde636837524bca93f2569</anchor>
      <arglist>[16]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP_Obj</name>
    <filename>struct_i_r_e_s___v_i_c_p___obj.html</filename>
    <member kind="variable">
      <type>IRES_Obj</type>
      <name>ires</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___obj.html</anchorfile>
      <anchor>a947469519efc1b89aafbdc1075c21571</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedIMX</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___obj.html</anchorfile>
      <anchor>a1bffad04e8b1cb7dbb813f8c6d558653</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedVLCD</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___obj.html</anchorfile>
      <anchor>afcb450273d9ff097fdf2415fcf6dfb4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>assignedSEQ</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___obj.html</anchorfile>
      <anchor>a6fbc47f1d1cf64977bba5a0cb81545e8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP_Properties</name>
    <filename>struct_i_r_e_s___v_i_c_p___properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___properties.html</anchorfile>
      <anchor>a6090b7a3e55c436f481f03f4cb76d7a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_VICP_Registers *</type>
      <name>globalRegs</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___properties.html</anchorfile>
      <anchor>a6de89d575cca5a32a08ad0e3534047d1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP_ProtocolArgs</name>
    <filename>struct_i_r_e_s___v_i_c_p___protocol_args.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___protocol_args.html</anchorfile>
      <anchor>a079d6d341243657f2d4d03f0447e5dd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_RequestMode</type>
      <name>mode</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___protocol_args.html</anchorfile>
      <anchor>a07d4c5c4fff6cf66b40b193193f9304e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestIMX</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___protocol_args.html</anchorfile>
      <anchor>ac9de71be6f9a0b7a54c67149dcfc3b11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestVLCD</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___protocol_args.html</anchorfile>
      <anchor>a7e180a4534bfe1b6b468340fd6fb4268</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>requestSEQ</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___protocol_args.html</anchorfile>
      <anchor>a67c3d1339650ff811984920fb027a968</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_VICP_Registers</name>
    <filename>struct_i_r_e_s___v_i_c_p___registers.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a151ad24c1e02ade3cd04d85650c32a20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>vicp_umap1_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a0f6e91812dbffc7874114af66ffae1d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>vicp_cfg_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>af5d2bbf3f9b074f99162a777a46896a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a53be2eeac69bc66286611dab8556952b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufA_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a38de26b57d6fa4f496e4049342f44e0c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imgBufB_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a0052d755403ef88539c3af79d914f4a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imxCoeffBuff_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a96b47040a92ab913e5c7157edb30a989</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>imxCmdBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>ac0bf909463fe7446736195c5bc288a37</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>vlcdDataBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a0caf5299ac86fdf415017d714e626a08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>qiqBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a323a1f84109536b6f71e1e9d48f65ccd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>vlcdBuf_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>af2b38d1142a8f7632ffb21919b33fe2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>seqProgMem_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a68c918e30670319fbaee2fb4f8c1e99e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>seqDataMem_base</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>ab83e637507a80ff5eee3c28b60f15618</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>imgBuf_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a708e8eba45c595f2dd37656c4815f1d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>imgBufA_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a48b731bdb2fe5657af2c049ab1386a70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>imgBufB_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a63465f075fe4ce3fe35b910051419152</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>imxCoeffBuff_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a936609723cb277e5fe735edc272bd9f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>imxCmdBuf_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>aca2da2ad8a380af56a0ab206a11691c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>vlcdDataBuf_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a5f9f73ce6c861d9e154d349d3a7607fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>qiqBuf_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a4dbb358ce7b28e86a8bbe81f52b7756a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>vlcdBuf_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>a3849f0810461dde216c3dfe42a079dad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>seqProgMem_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>acbe08afc7b5cee0ab62eab82754b3889</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>seqDataMem_length</name>
      <anchorfile>struct_i_r_e_s___v_i_c_p___registers.html</anchorfile>
      <anchor>ab17337e4cff1feff72b414f268a1a97b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRES_YieldContext</name>
    <filename>struct_i_r_e_s___yield_context.html</filename>
    <member kind="variable">
      <type>IALG_Handle</type>
      <name>algHandle</name>
      <anchorfile>struct_i_r_e_s___yield_context.html</anchorfile>
      <anchor>a7e57c67d7eaa92e777ec01ee783235a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_Handle</type>
      <name>resourceHandle</name>
      <anchorfile>struct_i_r_e_s___yield_context.html</anchorfile>
      <anchor>ad641392437c775a78dfeae74d8f6ab24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_ContextSaveFxn</type>
      <name>contextSave</name>
      <anchorfile>struct_i_r_e_s___yield_context.html</anchorfile>
      <anchor>a916710952108beb0b6d5d2ef0dac3094</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_ContextRestoreFxn</type>
      <name>contextRestore</name>
      <anchorfile>struct_i_r_e_s___yield_context.html</anchorfile>
      <anchor>aac53739996c8c602f74949c1c350b9c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>contextArgs</name>
      <anchorfile>struct_i_r_e_s___yield_context.html</anchorfile>
      <anchor>adf3ac7ac9954a2b8df2dafbc42041f3f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_ConstructArgs</name>
    <filename>struct_i_r_e_s_m_a_n___construct_args.html</filename>
    <member kind="variable">
      <type>Int32</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_args.html</anchorfile>
      <anchor>a60cbf903a6dd0a5d169facc760176aba</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_ConstructFxns</name>
    <filename>struct_i_r_e_s_m_a_n___construct_fxns.html</filename>
    <member kind="variable">
      <type>String(*</type>
      <name>getName</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_fxns.html</anchorfile>
      <anchor>a05e474b72c94eabbe6d0b81c2250c78c</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="variable">
      <type>IRES_ProtocolRevision *(*</type>
      <name>getRevision</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_fxns.html</anchorfile>
      <anchor>aea8d658a3140f2a7ef9c7bc5e1d7dd77</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>getMemRecs</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_fxns.html</anchorfile>
      <anchor>a4ab9b1d3fd768d37f99cad4302f893e1</anchor>
      <arglist>)(IRES_Handle handle, IRES_ProtocolArgs *protocolArgs, IALG_MemRec *memRecs)</arglist>
    </member>
    <member kind="variable">
      <type>Int(*</type>
      <name>getNumMemRecs</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_fxns.html</anchorfile>
      <anchor>aea2c0395f0d57386d9d82a7c97d6d907</anchor>
      <arglist>)(IRES_ProtocolArgs *protocolArgs)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Handle(*</type>
      <name>constructHandle</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_fxns.html</anchorfile>
      <anchor>a9407972da90618c9f3224f901d1d00b3</anchor>
      <arglist>)(IRES_ProtocolArgs *protocolArgs, IALG_MemRec *memRecs, IRESMAN_ConstructArgs *constructHandleArgs, IRES_Status *status)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>destructHandle</name>
      <anchorfile>struct_i_r_e_s_m_a_n___construct_fxns.html</anchorfile>
      <anchor>aa015866843f79cf215810cc4fabe1fb3</anchor>
      <arglist>)(IRES_Handle handle)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_Edma3ChanParams</name>
    <filename>struct_i_r_e_s_m_a_n___edma3_chan_params.html</filename>
    <member kind="variable">
      <type>IRESMAN_Params</type>
      <name>baseConfig</name>
      <anchorfile>struct_i_r_e_s_m_a_n___edma3_chan_params.html</anchorfile>
      <anchor>a89c283e85347fd83686db9f2d6c3919a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_Fxns</name>
    <filename>struct_i_r_e_s_m_a_n___fxns.html</filename>
    <member kind="variable">
      <type>String(*</type>
      <name>getProtocolName</name>
      <anchorfile>struct_i_r_e_s_m_a_n___fxns.html</anchorfile>
      <anchor>ab2d4b4fbc77e7a84549266022b9669a7</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="variable">
      <type>IRES_ProtocolRevision *(*</type>
      <name>getProtocolRevision</name>
      <anchorfile>struct_i_r_e_s_m_a_n___fxns.html</anchorfile>
      <anchor>aeedc2cd2aa193cf9e014db5dbb8611b7</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>init</name>
      <anchorfile>struct_i_r_e_s_m_a_n___fxns.html</anchorfile>
      <anchor>a7a339b74e73d3e257a93a80a18b54f74</anchor>
      <arglist>)(IRESMAN_Params *initArgs)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>exit</name>
      <anchorfile>struct_i_r_e_s_m_a_n___fxns.html</anchorfile>
      <anchor>a24dc3b165fb260670338f701a443ba7f</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Handle(*</type>
      <name>getHandle</name>
      <anchorfile>struct_i_r_e_s_m_a_n___fxns.html</anchorfile>
      <anchor>ade93bfa0ddc3adb8e4364398b140ff02</anchor>
      <arglist>)(IALG_Handle algHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId, IRES_Status *status)</arglist>
    </member>
    <member kind="variable">
      <type>IRES_Status(*</type>
      <name>freeHandle</name>
      <anchorfile>struct_i_r_e_s_m_a_n___fxns.html</anchorfile>
      <anchor>ad67acf67ef7fbd37668a42f6b1007c41</anchor>
      <arglist>)(IALG_Handle algHandle, IRES_Handle resourceHandle, IRES_ResourceDescriptor *resDesc, Int scratchGroupId)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_HdVicpParams</name>
    <filename>struct_i_r_e_s_m_a_n___hd_vicp_params.html</filename>
    <member kind="variable">
      <type>IRESMAN_Params</type>
      <name>baseConfig</name>
      <anchorfile>struct_i_r_e_s_m_a_n___hd_vicp_params.html</anchorfile>
      <anchor>af7f3a53efe26e5fc55e354fb2ff08375</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>numResources</name>
      <anchorfile>struct_i_r_e_s_m_a_n___hd_vicp_params.html</anchorfile>
      <anchor>a6954cbbcc7ad4251557b6fb6fb6e5916</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>info</name>
      <anchorfile>struct_i_r_e_s_m_a_n___hd_vicp_params.html</anchorfile>
      <anchor>a3e92352df809d1ac42bdc8c7fd22a722</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_Params</name>
    <filename>struct_i_r_e_s_m_a_n___params.html</filename>
    <member kind="variable">
      <type>Int32</type>
      <name>size</name>
      <anchorfile>struct_i_r_e_s_m_a_n___params.html</anchorfile>
      <anchor>a21a3aeee735737e5767d99156dae769e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_PersistentAllocFxn *</type>
      <name>allocFxn</name>
      <anchorfile>struct_i_r_e_s_m_a_n___params.html</anchorfile>
      <anchor>ad69d52192d1c92a341b82656762bad3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_PersistentFreeFxn *</type>
      <name>freeFxn</name>
      <anchorfile>struct_i_r_e_s_m_a_n___params.html</anchorfile>
      <anchor>a8f3146cbb29a050aad883b46bc9e00ea</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_SdmaParams</name>
    <filename>struct_i_r_e_s_m_a_n___sdma_params.html</filename>
    <member kind="variable">
      <type>IRESMAN_Params</type>
      <name>baseConfig</name>
      <anchorfile>struct_i_r_e_s_m_a_n___sdma_params.html</anchorfile>
      <anchor>a566ab717af7a7ae3190b8f12b9706970</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_TiledmemoryParams</name>
    <filename>struct_i_r_e_s_m_a_n___tiledmemory_params.html</filename>
    <member kind="variable">
      <type>IRESMAN_Params</type>
      <name>baseConfig</name>
      <anchorfile>struct_i_r_e_s_m_a_n___tiledmemory_params.html</anchorfile>
      <anchor>ae41f3d6524df4e2f70d4f3b16cfe3987</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>numResources</name>
      <anchorfile>struct_i_r_e_s_m_a_n___tiledmemory_params.html</anchorfile>
      <anchor>a2a694e21cec68d304953fcc378f75cde</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Void *</type>
      <name>info</name>
      <anchorfile>struct_i_r_e_s_m_a_n___tiledmemory_params.html</anchorfile>
      <anchor>ac67616da6720aabc7c7bad3126cc73ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>IRESMAN_VicpParams</name>
    <filename>struct_i_r_e_s_m_a_n___vicp_params.html</filename>
    <member kind="variable">
      <type>IRESMAN_Params</type>
      <name>baseConfig</name>
      <anchorfile>struct_i_r_e_s_m_a_n___vicp_params.html</anchorfile>
      <anchor>af538db4fdee7057e68a32664a22d8c13</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmClient_Message</name>
    <filename>struct_rcm_client___message.html</filename>
    <member kind="variable">
      <type>UInt16</type>
      <name>poolId</name>
      <anchorfile>struct_rcm_client___message.html</anchorfile>
      <anchor>acbb771cd858578f6840ceb1f894a7c11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt16</type>
      <name>jobId</name>
      <anchorfile>struct_rcm_client___message.html</anchorfile>
      <anchor>a0588c189ec2106d73353c7893e0c13e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt32</type>
      <name>fxnIdx</name>
      <anchorfile>struct_rcm_client___message.html</anchorfile>
      <anchor>a8b486a18a8ab2ac9336361a062eead21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int32</type>
      <name>result</name>
      <anchorfile>struct_rcm_client___message.html</anchorfile>
      <anchor>a4ecd13d69bc839ef89735368b0984740</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt32</type>
      <name>dataSize</name>
      <anchorfile>struct_rcm_client___message.html</anchorfile>
      <anchor>a1ac1c7253b05f88df82157537c1a191e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt32</type>
      <name>data</name>
      <anchorfile>struct_rcm_client___message.html</anchorfile>
      <anchor>ac1fa9c506248f375cb0f2bdca1d3decb</anchor>
      <arglist>[1]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmClient_Params</name>
    <filename>struct_rcm_client___params.html</filename>
    <member kind="variable">
      <type>UInt16</type>
      <name>heapId</name>
      <anchorfile>struct_rcm_client___params.html</anchorfile>
      <anchor>a749d7bf2f910bed2e3c303d8730141e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>callbackNotification</name>
      <anchorfile>struct_rcm_client___params.html</anchorfile>
      <anchor>ab507acff4f4c36dbcad01e67a0f2b8de</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmClient_Struct</name>
    <filename>struct_rcm_client___struct.html</filename>
    <member kind="variable">
      <type>xdc_runtime_knl_GateThread_Struct</type>
      <name>_f1</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a908a9f7257f5cde1512434c169b3eba4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f2</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a8d59efd1fb4cf90fec41eb55d3b17f43</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f3</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a15bfe1ddbe30feb7fd02a9a545ab8b3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt16</type>
      <name>_f4</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a9c7c060c316801a1a12300a1b5a83877</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f5</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a2fcbc9378d6ada0f954ced6a77528723</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt32</type>
      <name>_f6</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>aa53cb3357ca11b7fd435ec7d4c1f033a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>_f7</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>aebf1c1457efedfc023ced6433dc7b13c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt16</type>
      <name>_f8</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a52b982ca4e4d613ef3c57b3620c11a0f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f9</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a773d4910f6ab6e57f8039e1cd3fae7ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f10</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a971e9409c22bcc14ef8fb1f5ba265ddc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f11</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a4cdba7dea7294f82e33d1d2320505342</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f12</name>
      <anchorfile>struct_rcm_client___struct.html</anchorfile>
      <anchor>a840636249f911f9bc6bd595e150d7e7d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmServer_FxnDesc</name>
    <filename>struct_rcm_server___fxn_desc.html</filename>
    <member kind="variable">
      <type>String</type>
      <name>name</name>
      <anchorfile>struct_rcm_server___fxn_desc.html</anchorfile>
      <anchor>ac99289e8f5fc33ce2394f55ed77d344f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RcmServer_MsgFxn</type>
      <name>addr</name>
      <anchorfile>struct_rcm_server___fxn_desc.html</anchorfile>
      <anchor>a4c3688a4dab0c457cad06a973edbe7f7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmServer_FxnDescAry</name>
    <filename>struct_rcm_server___fxn_desc_ary.html</filename>
    <member kind="variable">
      <type>Int</type>
      <name>length</name>
      <anchorfile>struct_rcm_server___fxn_desc_ary.html</anchorfile>
      <anchor>aeb7260d09011043b9cf72ba068f47bc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RcmServer_FxnDesc *</type>
      <name>elem</name>
      <anchorfile>struct_rcm_server___fxn_desc_ary.html</anchorfile>
      <anchor>a1b2a5123c1ae9718d416796978362df3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmServer_Params</name>
    <filename>struct_rcm_server___params.html</filename>
    <member kind="variable">
      <type>Thread_Priority</type>
      <name>priority</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>aa518bb44202c0c87bc3c687ee728d413</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>osPriority</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>a731c1f510e16f11876f5d158d0bee610</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SizeT</type>
      <name>stackSize</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>a0e1f83a8bd84bdae4ddd2087219b8ffa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>stackSeg</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>ace1d409f01c49541518ee3a628b32840</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RcmServer_ThreadPoolDesc</type>
      <name>defaultPool</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>a15f1c24426d6a8ce93bbba0caf70a602</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RcmServer_ThreadPoolDescAry</type>
      <name>workerPools</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>a348c886a457ec0404fe704a50a0d674d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RcmServer_FxnDescAry</type>
      <name>fxns</name>
      <anchorfile>struct_rcm_server___params.html</anchorfile>
      <anchor>ae6b2faad86e274fce4901c89bdc0e43c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmServer_Struct</name>
    <filename>struct_rcm_server___struct.html</filename>
    <member kind="variable">
      <type>GateThread_Struct</type>
      <name>_f1</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>abea144a4717866ce14a0973e12f26390</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f2</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a6614efb74bbf383ccbf0b5971be4e017</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f3</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a4291e97d3a0c64d6d0dbe60c67d52c8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f4</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>afce34f878c0a208a419d8e7854c41bee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct RcmServer_Struct::@0</type>
      <name>_f5</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a768dea0c2a61313ac56c1ff6abf1d19d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>_f1</name>
      <anchorfile>struct_rcm_server___struct_1_1@0.html</anchorfile>
      <anchor>aae113f67f124f27e668ef8743634cdc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f2</name>
      <anchorfile>struct_rcm_server___struct_1_1@0.html</anchorfile>
      <anchor>abf852f011d5087c8623760a8da837440</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f6</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>ac9ba43ce6a0624a4dbc7553f0797af9d</anchor>
      <arglist>[9]</arglist>
    </member>
    <member kind="variable">
      <type>UInt16</type>
      <name>_f7</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>ab0ea371ae7e0f50f4d9e7e01d16b5734</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt16</type>
      <name>_f8</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a2af61bee74d689cb3aa65168553fa8db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>_f9</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a3798bb90da2b07566d803562ba0539b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>_f10</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a0a8b80e9bac98e0ca1a38d21d3657217</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f11</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a775e39c83b4ee15931ed9d86de7952dd</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>Ptr</type>
      <name>_f12</name>
      <anchorfile>struct_rcm_server___struct.html</anchorfile>
      <anchor>a8483423b894355a252b35514f6d6ec45</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmServer_ThreadPoolDesc</name>
    <filename>struct_rcm_server___thread_pool_desc.html</filename>
    <member kind="variable">
      <type>String</type>
      <name>name</name>
      <anchorfile>struct_rcm_server___thread_pool_desc.html</anchorfile>
      <anchor>a54560b4a9c1c1fd035d7bcdd519dfb79</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UInt</type>
      <name>count</name>
      <anchorfile>struct_rcm_server___thread_pool_desc.html</anchorfile>
      <anchor>ad613b4a2d44265ec67f997924c5bcb8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Thread_Priority</type>
      <name>priority</name>
      <anchorfile>struct_rcm_server___thread_pool_desc.html</anchorfile>
      <anchor>ab99ead20a5033616e7c74c2b6cb7fc94</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Int</type>
      <name>osPriority</name>
      <anchorfile>struct_rcm_server___thread_pool_desc.html</anchorfile>
      <anchor>af04a7c6b8cf162fe3f989286c878634b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SizeT</type>
      <name>stackSize</name>
      <anchorfile>struct_rcm_server___thread_pool_desc.html</anchorfile>
      <anchor>a91be2ca2b0c7033e84ae5d71f609441c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>stackSeg</name>
      <anchorfile>struct_rcm_server___thread_pool_desc.html</anchorfile>
      <anchor>a0ad628d3c30cfa40ae0cd4b7e1b28cb9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RcmServer_ThreadPoolDescAry</name>
    <filename>struct_rcm_server___thread_pool_desc_ary.html</filename>
    <member kind="variable">
      <type>Int</type>
      <name>length</name>
      <anchorfile>struct_rcm_server___thread_pool_desc_ary.html</anchorfile>
      <anchor>a5369f901ee28df784e3db4a7cef3e477</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RcmServer_ThreadPoolDesc *</type>
      <name>elem</name>
      <anchorfile>struct_rcm_server___thread_pool_desc_ary.html</anchorfile>
      <anchor>a71eb46f740a6356e947a61a0d891e638</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RMAN_Params</name>
    <filename>struct_r_m_a_n___params.html</filename>
    <member kind="variable">
      <type>short</type>
      <name>numRegistries</name>
      <anchorfile>struct_r_m_a_n___params.html</anchorfile>
      <anchor>a634fc86d4de527ca05223b36f8e0bf2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_PersistentAllocFxn *</type>
      <name>allocFxn</name>
      <anchorfile>struct_r_m_a_n___params.html</anchorfile>
      <anchor>ad115f18b64e09188be8d2094ac41fc53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRESMAN_PersistentFreeFxn *</type>
      <name>freeFxn</name>
      <anchorfile>struct_r_m_a_n___params.html</anchorfile>
      <anchor>ab3319fbf76d2fd7df082ad50ea027a9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IRES_YieldFxn</type>
      <name>yieldFxn</name>
      <anchorfile>struct_r_m_a_n___params.html</anchorfile>
      <anchor>abde199a7e3a760e5b0b85d5ec8a9da71</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Bool</type>
      <name>yieldSamePriority</name>
      <anchorfile>struct_r_m_a_n___params.html</anchorfile>
      <anchor>a2767cefebab08289f0522bdf2940d722</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>SCPY_AddrParams</name>
    <filename>struct_s_c_p_y___addr_params.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>addr_mode</name>
      <anchorfile>struct_s_c_p_y___addr_params.html</anchorfile>
      <anchor>a90ba071b33238869fa8255b2545c35a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>addr</name>
      <anchorfile>struct_s_c_p_y___addr_params.html</anchorfile>
      <anchor>aa8b6bcb869eb269a16836054920cadc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>elem_index</name>
      <anchorfile>struct_s_c_p_y___addr_params.html</anchorfile>
      <anchor>ad7a191113128501b84d23d8c3ab59fae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>frame_index</name>
      <anchorfile>struct_s_c_p_y___addr_params.html</anchorfile>
      <anchor>ab48c7f007caf936988cda543b985161a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>SCPY_Params</name>
    <filename>struct_s_c_p_y___params.html</filename>
    <member kind="variable">
      <type>SCPY_AddrParams *</type>
      <name>src</name>
      <anchorfile>struct_s_c_p_y___params.html</anchorfile>
      <anchor>a77a1bd4f987bd3a58338e9558b53ceb5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SCPY_AddrParams *</type>
      <name>dst</name>
      <anchorfile>struct_s_c_p_y___params.html</anchorfile>
      <anchor>a94da3c91c28f5a47f4e0a84897eccea1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SCPY_TransferParams *</type>
      <name>transfer</name>
      <anchorfile>struct_s_c_p_y___params.html</anchorfile>
      <anchor>a4a6fc42a8657cd545328dc4b3159b5ba</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>SCPY_TransferParams</name>
    <filename>struct_s_c_p_y___transfer_params.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>dataType</name>
      <anchorfile>struct_s_c_p_y___transfer_params.html</anchorfile>
      <anchor>a5dc06a9e8e964e66b58d972c6a73ba7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>elemCount</name>
      <anchorfile>struct_s_c_p_y___transfer_params.html</anchorfile>
      <anchor>ab8e20cbd773b973e002fc02a9dbea24a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>frameCount</name>
      <anchorfile>struct_s_c_p_y___transfer_params.html</anchorfile>
      <anchor>a160bccc965b3c7d6e05ae194f45b8040</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/acpy3/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/acpy3/</path>
    <filename>dir_e7fa5fd7788b4b9030e1ba5046d3bdf4.html</filename>
    <file>acpy3.h</file>
    <file>acpy3_instr.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/dman3/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/dman3/</path>
    <filename>dir_4666d21e0cba5738781e236914dd5677.html</filename>
    <file>dman3.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/dskt2/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/dskt2/</path>
    <filename>dir_7123fd00431ebf8a5d609a8dde0e10a9.html</filename>
    <file>dskt2.h</file>
    <file>dskt2_qos.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ecpy/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ecpy/</path>
    <filename>dir_51c50b2160eb9e0170348461b4910175.html</filename>
    <file>ecpy.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ires/edma3chan/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/edma3chan/</path>
    <filename>dir_c5fae19179475d38c5a612deedc3d5e6.html</filename>
    <file>ires_edma3Chan.h</file>
    <file>iresman_edma3Chan.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/</path>
    <filename>dir_64d4c30e6d9c7c842759ab2a301da572.html</filename>
    <dir>packages/ti/sdo/fc/acpy3/</dir>
    <dir>packages/ti/sdo/fc/dman3/</dir>
    <dir>packages/ti/sdo/fc/dskt2/</dir>
    <dir>packages/ti/sdo/fc/ecpy/</dir>
    <dir>packages/ti/sdo/fc/hdintc/</dir>
    <dir>packages/ti/sdo/fc/ires/</dir>
    <dir>packages/ti/sdo/fc/memutils/</dir>
    <dir>packages/ti/sdo/fc/rman/</dir>
    <dir>packages/ti/sdo/fc/scpy/</dir>
  </compound>
  <compound kind="dir">
    <name>fctools/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/</path>
    <filename>dir_9ec5b608a14a7d18ed5f7a1ccc6f53f7.html</filename>
    <dir>fctools/packages/</dir>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/hdintc/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/hdintc/</path>
    <filename>dir_00514b8d43e41671f8d967db1076c0dc.html</filename>
    <file>hdintc.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ires/hdvicp/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/hdvicp/</path>
    <filename>dir_2ae4bd91b8c52f875b3f8a6c3fd54380.html</filename>
    <file>ires_hdvicp.h</file>
    <file>ires_hdvicp2.h</file>
    <file>iresman_hdvicp.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ires/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/</path>
    <filename>dir_bff8447dec4db5e32af83ac76d6075ff.html</filename>
    <dir>packages/ti/sdo/fc/ires/edma3chan/</dir>
    <dir>packages/ti/sdo/fc/ires/hdvicp/</dir>
    <dir>packages/ti/sdo/fc/ires/sdma/</dir>
    <dir>packages/ti/sdo/fc/ires/tiledmemory/</dir>
    <dir>packages/ti/sdo/fc/ires/vicp/</dir>
    <file>iresman.h</file>
    <file>iresman_protocol.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/memutils/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/memutils/</path>
    <filename>dir_c362116fcd9bdb9489bfd2c06b9c54e8.html</filename>
    <file>memutils.h</file>
  </compound>
  <compound kind="dir">
    <name>fctools/packages/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/</path>
    <filename>dir_4b3eaf241b4b4a25ec00ab6f7de853c3.html</filename>
    <dir>fctools/packages/ti/</dir>
  </compound>
  <compound kind="dir">
    <name>packages/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/</path>
    <filename>dir_30e0fa339f1092512eed2eead310c67d.html</filename>
    <dir>packages/ti/</dir>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/rcm/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/rcm/</path>
    <filename>dir_c239a9e96643a1c705d5c865d807ec8a.html</filename>
    <file>RcmClient.h</file>
    <file>RcmServer.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/rman/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/rman/</path>
    <filename>dir_183e577e20ede1b2065a09af784711b1.html</filename>
    <file>rman.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/scpy/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/scpy/</path>
    <filename>dir_5745c59495d1725e4dffa3a4b2affb00.html</filename>
    <file>scpy.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ires/sdma/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/sdma/</path>
    <filename>dir_84080925c6dbc513ffaa509c89acc303.html</filename>
    <file>ires_sdma.h</file>
    <file>iresman_sdma.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/</path>
    <filename>dir_b2ff838680510c5fb87b9eef504a7fd5.html</filename>
    <dir>packages/ti/sdo/fc/</dir>
    <dir>packages/ti/sdo/rcm/</dir>
  </compound>
  <compound kind="dir">
    <name>fctools/packages/ti/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/</path>
    <filename>dir_885a0722e51e3da96bf1508aa1e7061e.html</filename>
    <dir>fctools/packages/ti/xdais/</dir>
  </compound>
  <compound kind="dir">
    <name>packages/ti/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/</path>
    <filename>dir_9190066eb80f69f965f927f1a26f9d80.html</filename>
    <dir>packages/ti/sdo/</dir>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ires/tiledmemory/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/tiledmemory/</path>
    <filename>dir_4d6c40fa89e7284e67fccbd73906bdc8.html</filename>
    <file>ires_tiledmemory.h</file>
    <file>iresman_tiledmemory.h</file>
  </compound>
  <compound kind="dir">
    <name>packages/ti/sdo/fc/ires/vicp/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/packages/ti/sdo/fc/ires/vicp/</path>
    <filename>dir_04627c4b16c8ec6ee4b25a42a6328dc6.html</filename>
    <file>ires_vicp.h</file>
    <file>ires_vicp2.h</file>
    <file>iresman_vicp.h</file>
    <file>iresman_vicp2.h</file>
  </compound>
  <compound kind="dir">
    <name>fctools/packages/ti/xdais/</name>
    <path>/db/atree/library/trees/fc/fc-q07/src/framework_components_3_22_01_07/fctools/packages/ti/xdais/</path>
    <filename>dir_74ac1e63270acc89b407a701d8794477.html</filename>
    <file>ialg.h</file>
    <file>idma3.h</file>
    <file>ires.h</file>
    <file>ires_common.h</file>
    <file>xdas.h</file>
  </compound>
</tagfile>
