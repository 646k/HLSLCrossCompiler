#ifndef TOKENS_H
#define TOKENS_H

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

typedef enum
{
    PIXEL_SHADER,
    VERTEX_SHADER,
    GEOMETRY_SHADER,
    HULL_SHADER,
    DOMAIN_SHADER,
    COMPUTE_SHADER,
} SHADER_TYPE;

static SHADER_TYPE DecodeShaderType(uint32_t ui32Token)
{
	return (SHADER_TYPE)((ui32Token & 0xffff0000) >> 16);
}

static uint32_t DecodeProgramMajorVersion(uint32_t ui32Token)
{
    return (ui32Token & 0x000000f0) >> 4;
}

static uint32_t DecodeProgramMinorVersion(uint32_t ui32Token)
{
    return (ui32Token & 0x0000000f);
}

static uint32_t DecodeInstructionLength(uint32_t ui32Token)
{
    return (ui32Token & 0x7f000000) >> 24;
}

static uint32_t DecodeIsOpcodeExtended(uint32_t ui32Token)
{
    return (ui32Token & 0x80000000) >> 31;
}

typedef enum
{
    OPCODE_ADD,
    OPCODE_AND,
    OPCODE_BREAK,
    OPCODE_BREAKC,
    OPCODE_CALL,
    OPCODE_CALLC,
    OPCODE_CASE,
    OPCODE_CONTINUE,
    OPCODE_CONTINUEC,
    OPCODE_CUT,
    OPCODE_DEFAULT,
    OPCODE_DERIV_RTX,
    OPCODE_DERIV_RTY,
    OPCODE_DISCARD,
    OPCODE_DIV,
    OPCODE_DP2,
    OPCODE_DP3,
    OPCODE_DP4,
    OPCODE_ELSE,
    OPCODE_EMIT,
    OPCODE_EMITTHENCUT,
    OPCODE_ENDIF,
    OPCODE_ENDLOOP,
    OPCODE_ENDSWITCH,
    OPCODE_EQ,
    OPCODE_EXP,
    OPCODE_FRC,
    OPCODE_FTOI,
    OPCODE_FTOU,
    OPCODE_GE,
    OPCODE_IADD,
    OPCODE_IF,
    OPCODE_IEQ,
    OPCODE_IGE,
    OPCODE_ILT,
    OPCODE_IMAD,
    OPCODE_IMAX,
    OPCODE_IMIN,
    OPCODE_IMUL,
    OPCODE_INE,
    OPCODE_INEG,
    OPCODE_ISHL,
    OPCODE_ISHR,
    OPCODE_ITOF,
    OPCODE_LABEL,
    OPCODE_LD,
    OPCODE_LD_MS,
    OPCODE_LOG,
    OPCODE_LOOP,
    OPCODE_LT,
    OPCODE_MAD,
    OPCODE_MIN,
    OPCODE_MAX,
    OPCODE_CUSTOMDATA,
    OPCODE_MOV,
    OPCODE_MOVC,
    OPCODE_MUL,
    OPCODE_NE,
    OPCODE_NOP,
    OPCODE_NOT,
    OPCODE_OR,
    OPCODE_RESINFO,
    OPCODE_RET,
    OPCODE_RETC,
    OPCODE_ROUND_NE,
    OPCODE_ROUND_NI,
    OPCODE_ROUND_PI,
    OPCODE_ROUND_Z,
    OPCODE_RSQ,
    OPCODE_SAMPLE,
    OPCODE_SAMPLE_C,
    OPCODE_SAMPLE_C_LZ,
    OPCODE_SAMPLE_L,
    OPCODE_SAMPLE_D,
    OPCODE_SAMPLE_B,
    OPCODE_SQRT,
    OPCODE_SWITCH,
    OPCODE_SINCOS,
    OPCODE_UDIV,
    OPCODE_ULT,
    OPCODE_UGE,
    OPCODE_UMUL,
    OPCODE_UMAD,
    OPCODE_UMAX,
    OPCODE_UMIN,
    OPCODE_USHR,
    OPCODE_UTOF,
    OPCODE_XOR,
    OPCODE_DCL_RESOURCE, // DCL* opcodes have
    OPCODE_DCL_CONSTANT_BUFFER, // custom operand formats.
    OPCODE_DCL_SAMPLER,
    OPCODE_DCL_INDEX_RANGE,
    OPCODE_DCL_GS_OUTPUT_PRIMITIVE_TOPOLOGY,
    OPCODE_DCL_GS_INPUT_PRIMITIVE,
    OPCODE_DCL_MAX_OUTPUT_VERTEX_COUNT,
    OPCODE_DCL_INPUT,
    OPCODE_DCL_INPUT_SGV,
    OPCODE_DCL_INPUT_SIV,
    OPCODE_DCL_INPUT_PS,
    OPCODE_DCL_INPUT_PS_SGV,
    OPCODE_DCL_INPUT_PS_SIV,
    OPCODE_DCL_OUTPUT,
    OPCODE_DCL_OUTPUT_SGV,
    OPCODE_DCL_OUTPUT_SIV,
    OPCODE_DCL_TEMPS,
    OPCODE_DCL_INDEXABLE_TEMP,
    OPCODE_DCL_GLOBAL_FLAGS,

// -----------------------------------------------

    OPCODE_RESERVED0,
    
// ---------- DX 10.1 op codes---------------------

    OPCODE_LOD,
    OPCODE_GATHER4,
    OPCODE_SAMPLE_POS,
    OPCODE_SAMPLE_INFO,

// -----------------------------------------------

    // This should be 10.1's version of NUM_OPCODES
    OPCODE_RESERVED1,

// ---------- DX 11 op codes---------------------
    OPCODE_HS_DECLS, // token marks beginning of HS sub-shader
    OPCODE_HS_CONTROL_POINT_PHASE, // token marks beginning of HS sub-shader
    OPCODE_HS_FORK_PHASE, // token marks beginning of HS sub-shader
    OPCODE_HS_JOIN_PHASE, // token marks beginning of HS sub-shader

    OPCODE_EMIT_STREAM,
    OPCODE_CUT_STREAM,
    OPCODE_EMITTHENCUT_STREAM,
    OPCODE_INTERFACE_CALL,

    OPCODE_BUFINFO,
    OPCODE_DERIV_RTX_COARSE,
    OPCODE_DERIV_RTX_FINE,
    OPCODE_DERIV_RTY_COARSE,
    OPCODE_DERIV_RTY_FINE,
    OPCODE_GATHER4_C,
    OPCODE_GATHER4_PO,
    OPCODE_GATHER4_PO_C,
    OPCODE_RCP,
    OPCODE_F32TOF16,
    OPCODE_F16TOF32,
    OPCODE_UADDC,
    OPCODE_USUBB,
    OPCODE_COUNTBITS,
    OPCODE_FIRSTBIT_HI,
    OPCODE_FIRSTBIT_LO,
    OPCODE_FIRSTBIT_SHI,
    OPCODE_UBFE,
    OPCODE_IBFE,
    OPCODE_BFI,
    OPCODE_BFREV,
    OPCODE_SWAPC,

    OPCODE_DCL_STREAM,
    OPCODE_DCL_FUNCTION_BODY,
    OPCODE_DCL_FUNCTION_TABLE,
    OPCODE_DCL_INTERFACE,
    
    OPCODE_DCL_INPUT_CONTROL_POINT_COUNT,
    OPCODE_DCL_OUTPUT_CONTROL_POINT_COUNT,
    OPCODE_DCL_TESS_DOMAIN,
    OPCODE_DCL_TESS_PARTITIONING,
    OPCODE_DCL_TESS_OUTPUT_PRIMITIVE,
    OPCODE_DCL_HS_MAX_TESSFACTOR,
    OPCODE_DCL_HS_FORK_PHASE_INSTANCE_COUNT,
    OPCODE_DCL_HS_JOIN_PHASE_INSTANCE_COUNT,

    OPCODE_DCL_THREAD_GROUP,
    OPCODE_DCL_UNORDERED_ACCESS_VIEW_TYPED,
    OPCODE_DCL_UNORDERED_ACCESS_VIEW_RAW,
    OPCODE_DCL_UNORDERED_ACCESS_VIEW_STRUCTURED,
    OPCODE_DCL_THREAD_GROUP_SHARED_MEMORY_RAW,
    OPCODE_DCL_THREAD_GROUP_SHARED_MEMORY_STRUCTURED,
    OPCODE_DCL_RESOURCE_RAW,
    OPCODE_DCL_RESOURCE_STRUCTURED,
    OPCODE_LD_UAV_TYPED,
    OPCODE_STORE_UAV_TYPED,
    OPCODE_LD_RAW,
    OPCODE_STORE_RAW,
    OPCODE_LD_STRUCTURED,
    OPCODE_STORE_STRUCTURED,
    OPCODE_ATOMIC_AND,
    OPCODE_ATOMIC_OR,
    OPCODE_ATOMIC_XOR,
    OPCODE_ATOMIC_CMP_STORE,
    OPCODE_ATOMIC_IADD,
    OPCODE_ATOMIC_IMAX,
    OPCODE_ATOMIC_IMIN,
    OPCODE_ATOMIC_UMAX,
    OPCODE_ATOMIC_UMIN,
    OPCODE_IMM_ATOMIC_ALLOC,
    OPCODE_IMM_ATOMIC_CONSUME,
    OPCODE_IMM_ATOMIC_IADD,
    OPCODE_IMM_ATOMIC_AND,
    OPCODE_IMM_ATOMIC_OR,
    OPCODE_IMM_ATOMIC_XOR,
    OPCODE_IMM_ATOMIC_EXCH,
    OPCODE_IMM_ATOMIC_CMP_EXCH,
    OPCODE_IMM_ATOMIC_IMAX,
    OPCODE_IMM_ATOMIC_IMIN,
    OPCODE_IMM_ATOMIC_UMAX,
    OPCODE_IMM_ATOMIC_UMIN,   
    OPCODE_SYNC,
    
    OPCODE_DADD,
    OPCODE_DMAX,
    OPCODE_DMIN,
    OPCODE_DMUL,
    OPCODE_DEQ,
    OPCODE_DGE,
    OPCODE_DLT,
    OPCODE_DNE,
    OPCODE_DMOV,
    OPCODE_DMOVC,
    OPCODE_DTOF,
    OPCODE_FTOD,

    OPCODE_EVAL_SNAPPED,
    OPCODE_EVAL_SAMPLE_INDEX,
    OPCODE_EVAL_CENTROID,
    
    OPCODE_DCL_GS_INSTANCE_COUNT,

    NUM_OPCODES,
    OPCODE_INVAILD = NUM_OPCODES,
} OPCODE_TYPE;

static OPCODE_TYPE DecodeOpcodeType(uint32_t ui32Token)
{
    return (OPCODE_TYPE)(ui32Token & 0x00007ff);
}

typedef enum
{
    INDEX_0D,
    INDEX_1D,
    INDEX_2D,
    INDEX_3D,
} OPERAND_INDEX_DIMENSION;

static OPERAND_INDEX_DIMENSION DecodeOperandIndexDimension(uint32_t ui32Token)
{
	return (OPERAND_INDEX_DIMENSION)((ui32Token & 0x00300000) >> 20);
}

typedef enum OPERAND_TYPE
{
    OPERAND_TYPE_TEMP           = 0,  // Temporary Register File
    OPERAND_TYPE_INPUT          = 1,  // General Input Register File
    OPERAND_TYPE_OUTPUT         = 2,  // General Output Register File
    OPERAND_TYPE_INDEXABLE_TEMP = 3,  // Temporary Register File (indexable)
    OPERAND_TYPE_IMMEDIATE32    = 4,  // 32bit/component immediate value(s)
                                          // If for example, operand token bits
                                          // [01:00]==OPERAND_4_COMPONENT,
                                          // this means that the operand type:
                                          // OPERAND_TYPE_IMMEDIATE32
                                          // results in 4 additional 32bit
                                          // DWORDS present for the operand.
    OPERAND_TYPE_IMMEDIATE64    = 5,  // 64bit/comp.imm.val(s)HI:LO
    OPERAND_TYPE_SAMPLER        = 6,  // Reference to sampler state
    OPERAND_TYPE_RESOURCE       = 7,  // Reference to memory resource (e.g. texture)
    OPERAND_TYPE_CONSTANT_BUFFER= 8,  // Reference to constant buffer
    OPERAND_TYPE_IMMEDIATE_CONSTANT_BUFFER= 9,  // Reference to immediate constant buffer
    OPERAND_TYPE_LABEL          = 10, // Label
    OPERAND_TYPE_INPUT_PRIMITIVEID = 11, // Input primitive ID
    OPERAND_TYPE_OUTPUT_DEPTH   = 12, // Output Depth
    OPERAND_TYPE_NULL           = 13, // Null register, used to discard results of operations
                                               // Below Are operands new in DX 10.1
    OPERAND_TYPE_RASTERIZER     = 14, // DX10.1 Rasterizer register, used to denote the depth/stencil and render target resources
    OPERAND_TYPE_OUTPUT_COVERAGE_MASK = 15, // DX10.1 PS output MSAA coverage mask (scalar)
                                               // Below Are operands new in DX 11
    OPERAND_TYPE_STREAM         = 16, // Reference to GS stream output resource
    OPERAND_TYPE_FUNCTION_BODY  = 17, // Reference to a function definition
    OPERAND_TYPE_FUNCTION_TABLE = 18, // Reference to a set of functions used by a class
    OPERAND_TYPE_INTERFACE      = 19, // Reference to an interface
    OPERAND_TYPE_FUNCTION_INPUT = 20, // Reference to an input parameter to a function
    OPERAND_TYPE_FUNCTION_OUTPUT = 21, // Reference to an output parameter to a function
    OPERAND_TYPE_OUTPUT_CONTROL_POINT_ID = 22, // HS Control Point phase input saying which output control point ID this is
    OPERAND_TYPE_INPUT_FORK_INSTANCE_ID = 23, // HS Fork Phase input instance ID
    OPERAND_TYPE_INPUT_JOIN_INSTANCE_ID = 24, // HS Join Phase input instance ID
    OPERAND_TYPE_INPUT_CONTROL_POINT = 25, // HS Fork+Join, DS phase input control points (array of them)
    OPERAND_TYPE_OUTPUT_CONTROL_POINT = 26, // HS Fork+Join phase output control points (array of them)
    OPERAND_TYPE_INPUT_PATCH_CONSTANT = 27, // DS+HSJoin Input Patch Constants (array of them)
    OPERAND_TYPE_INPUT_DOMAIN_POINT = 28, // DS Input Domain point
    OPERAND_TYPE_THIS_POINTER       = 29, // Reference to an interface this pointer
    OPERAND_TYPE_UNORDERED_ACCESS_VIEW = 30, // Reference to UAV u#
    OPERAND_TYPE_THREAD_GROUP_SHARED_MEMORY = 31, // Reference to Thread Group Shared Memory g#
    OPERAND_TYPE_INPUT_THREAD_ID = 32, // Compute Shader Thread ID
    OPERAND_TYPE_INPUT_THREAD_GROUP_ID = 33, // Compute Shader Thread Group ID
    OPERAND_TYPE_INPUT_THREAD_ID_IN_GROUP = 34, // Compute Shader Thread ID In Thread Group
    OPERAND_TYPE_INPUT_COVERAGE_MASK = 35, // Pixel shader coverage mask input
    OPERAND_TYPE_INPUT_THREAD_ID_IN_GROUP_FLATTENED = 36, // Compute Shader Thread ID In Group Flattened to a 1D value.
    OPERAND_TYPE_INPUT_GS_INSTANCE_ID = 37, // Input GS instance ID
    OPERAND_TYPE_OUTPUT_DEPTH_GREATER_EQUAL = 38, // Output Depth, forced to be greater than or equal than current depth
    OPERAND_TYPE_OUTPUT_DEPTH_LESS_EQUAL    = 39, // Output Depth, forced to be less than or equal to current depth
    OPERAND_TYPE_CYCLE_COUNTER = 40, // Cycle counter
} OPERAND_TYPE;

#endif

static OPERAND_TYPE DecodeOperandType(uint32_t ui32Token)
{
	return (OPERAND_TYPE)((ui32Token & 0x000ff000) >> 12);
}

typedef enum SPECIAL_NAME
{
    NAME_UNDEFINED = 0,
    NAME_POSITION = 1,
    NAME_CLIP_DISTANCE = 2,
    NAME_CULL_DISTANCE = 3,
    NAME_RENDER_TARGET_ARRAY_INDEX = 4,
    NAME_VIEWPORT_ARRAY_INDEX = 5,
    NAME_VERTEX_ID = 6,
    NAME_PRIMITIVE_ID = 7,
    NAME_INSTANCE_ID = 8,
    NAME_IS_FRONT_FACE = 9,
    NAME_SAMPLE_INDEX = 10,
    // The following are added for D3D11
    NAME_FINAL_QUAD_U_EQ_0_EDGE_TESSFACTOR = 11, 
    NAME_FINAL_QUAD_V_EQ_0_EDGE_TESSFACTOR = 12, 
    NAME_FINAL_QUAD_U_EQ_1_EDGE_TESSFACTOR = 13, 
    NAME_FINAL_QUAD_V_EQ_1_EDGE_TESSFACTOR = 14, 
    NAME_FINAL_QUAD_U_INSIDE_TESSFACTOR = 15, 
    NAME_FINAL_QUAD_V_INSIDE_TESSFACTOR = 16, 
    NAME_FINAL_TRI_U_EQ_0_EDGE_TESSFACTOR = 17, 
    NAME_FINAL_TRI_V_EQ_0_EDGE_TESSFACTOR = 18, 
    NAME_FINAL_TRI_W_EQ_0_EDGE_TESSFACTOR = 19, 
    NAME_FINAL_TRI_INSIDE_TESSFACTOR = 20, 
    NAME_FINAL_LINE_DETAIL_TESSFACTOR = 21,
    NAME_FINAL_LINE_DENSITY_TESSFACTOR = 22,
} SPECIAL_NAME;

static SPECIAL_NAME DecodeOperandSpecialName(uint32_t ui32Token)
{
	return (SPECIAL_NAME)(ui32Token & 0x0000ffff);
}

typedef enum OPERAND_INDEX_REPRESENTATION
{
    OPERAND_INDEX_IMMEDIATE32               = 0, // Extra DWORD
    OPERAND_INDEX_IMMEDIATE64               = 1, // 2 Extra DWORDs
                                                     //   (HI32:LO32)
    OPERAND_INDEX_RELATIVE                  = 2, // Extra operand
    OPERAND_INDEX_IMMEDIATE32_PLUS_RELATIVE = 3, // Extra DWORD followed by
                                                     //   extra operand
    OPERAND_INDEX_IMMEDIATE64_PLUS_RELATIVE = 4, // 2 Extra DWORDS
                                                     //   (HI32:LO32) followed
                                                     //   by extra operand
} OPERAND_INDEX_REPRESENTATION;

static OPERAND_INDEX_REPRESENTATION DecodeOperandIndexRepresentation(uint32_t ui32Dimension, uint32_t ui32Token)
{
	return (OPERAND_INDEX_REPRESENTATION)((ui32Token & (0x3<<(22+3*((ui32Dimension)&3)))) >> (22+3*((ui32Dimension)&3)));
}
