//
// Generated by Microsoft (R) HLSL Shader Compiler 9.30.9200.20499
//
//
///
// Buffer Definitions: 
//
// cbuffer $Globals
// {
//
//   float Time;                        // Offset:    0 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// Output                                UAV  float4          2d    0        1
// $Globals                          cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[1], immediateIndexed
dcl_uav_typed_texture2d (float,float,float,float) u0
dcl_input vThreadIDInGroup.xy
dcl_input vThreadID.xy
dcl_temps 3
dcl_thread_group 32, 32, 1
utof r0.xy, vThreadIDInGroup.xyxx
dp2 r0.x, r0.xyxx, r0.xyxx
sqrt r0.x, r0.x
mul r0.x, r0.x, l(0.031250)
mov r0.yzw, l(0,0,0,1.000000)
add r1.xyzw, -r0.xzzw, r0.zxzw
sincos r2.x, null, cb0[0].x
mad r0.xyzw, r2.xxxx, r1.xyzw, r0.xyzw
store_uav_typed u0.xyzw, vThreadID.xyyy, r0.xyzw
ret 
// Approximately 10 instruction slots used