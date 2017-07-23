#include <string.h>
#include "glad.hpp"

namespace glad {


#ifdef GLAD_USE_SDL
#include <SDL.h>
#if !SDL_VERSION_ATLEAST(2,0,0)
#error SDL 2 is required!
#endif
#else
#include <assert.h>
#endif

bool gladLoadGL(void) {
#ifdef GLAD_USE_SDL
    return gladLoadGLLoader(SDL_GL_GetProcAddress);
#else
    // generic gladLoadGL is not implemented, use gladLoadGLLoader or define GLAD_USE_SDL
    assert(0);
    return false;
#endif
}

struct {
    int major;
    int minor;
    int gles;
} GLVersion;


static bool has_ext(const char *ext) {
    if(GLVersion.major < 3) {
        const char *extensions;
        const char *loc;
        const char *terminator;
        extensions = (const char *)fp_glGetString(GL_EXTENSIONS);
        if(extensions == NULL || ext == NULL) {
            return false;
        }

        while(1) {
            loc = strstr(extensions, ext);
            if(loc == NULL) {
                return false;
            }

            terminator = loc + strlen(ext);
            if((loc == extensions || *(loc - 1) == ' ') &&
                (*terminator == ' ' || *terminator == '\0')) {
                return true;
            }
            extensions = terminator;
        }
    } else {
        int num;
        fp_glGetIntegerv(GL_NUM_EXTENSIONS, &num);

        int index;
        for(index = 0; index < num; index++) {
            const char *e = (const char*)fp_glGetStringi(GL_EXTENSIONS, index);
            if(strcmp(e, ext) == 0) {
                return true;
            }
        }
    }

    return false;
}

pfn_glCopyTexImage1D fp_glCopyTexImage1D;
pfn_glTextureParameterf fp_glTextureParameterf;
pfn_glVertexAttribI3ui fp_glVertexAttribI3ui;
pfn_glVertexArrayElementBuffer fp_glVertexArrayElementBuffer;
pfn_glWindowPos2s fp_glWindowPos2s;
pfn_glTextureStorage3DMultisample fp_glTextureStorage3DMultisample;
pfn_glTextureParameterfv fp_glTextureParameterfv;
pfn_glWindowPos2i fp_glWindowPos2i;
pfn_glWindowPos2f fp_glWindowPos2f;
pfn_glWindowPos2d fp_glWindowPos2d;
pfn_glVertex2fv fp_glVertex2fv;
pfn_glIndexi fp_glIndexi;
pfn_glFramebufferRenderbuffer fp_glFramebufferRenderbuffer;
pfn_glUniformSubroutinesuiv fp_glUniformSubroutinesuiv;
pfn_glRectdv fp_glRectdv;
pfn_glCompressedTexSubImage3D fp_glCompressedTexSubImage3D;
pfn_glEvalCoord2d fp_glEvalCoord2d;
pfn_glEvalCoord2f fp_glEvalCoord2f;
pfn_glGetDoublei_v fp_glGetDoublei_v;
pfn_glIndexd fp_glIndexd;
pfn_glVertexAttrib1sv fp_glVertexAttrib1sv;
pfn_glIndexf fp_glIndexf;
pfn_glBindSampler fp_glBindSampler;
pfn_glLineWidth fp_glLineWidth;
pfn_glColorP3uiv fp_glColorP3uiv;
pfn_glGetIntegeri_v fp_glGetIntegeri_v;
pfn_glGetMapfv fp_glGetMapfv;
pfn_glIndexs fp_glIndexs;
pfn_glCompileShader fp_glCompileShader;
pfn_glGetTransformFeedbackVarying fp_glGetTransformFeedbackVarying;
pfn_glWindowPos2iv fp_glWindowPos2iv;
pfn_glDrawTransformFeedbackStreamInstanced fp_glDrawTransformFeedbackStreamInstanced;
pfn_glIndexfv fp_glIndexfv;
pfn_glGetCompressedTextureImage fp_glGetCompressedTextureImage;
pfn_glGetnMapfv fp_glGetnMapfv;
pfn_glFogiv fp_glFogiv;
pfn_glStencilMaskSeparate fp_glStencilMaskSeparate;
pfn_glRasterPos2fv fp_glRasterPos2fv;
pfn_glLightModeliv fp_glLightModeliv;
pfn_glDepthRangef fp_glDepthRangef;
pfn_glColor4ui fp_glColor4ui;
pfn_glSecondaryColor3fv fp_glSecondaryColor3fv;
pfn_glMultiTexCoordP3ui fp_glMultiTexCoordP3ui;
pfn_glMemoryBarrierByRegion fp_glMemoryBarrierByRegion;
pfn_glGetNamedBufferParameteriv fp_glGetNamedBufferParameteriv;
pfn_glFogfv fp_glFogfv;
pfn_glVertexP4ui fp_glVertexP4ui;
pfn_glDrawElementsInstancedBaseInstance fp_glDrawElementsInstancedBaseInstance;
pfn_glEnablei fp_glEnablei;
pfn_glProgramUniform3dv fp_glProgramUniform3dv;
pfn_glVertex4iv fp_glVertex4iv;
pfn_glEvalCoord1fv fp_glEvalCoord1fv;
pfn_glWindowPos2sv fp_glWindowPos2sv;
pfn_glVertexAttribP4ui fp_glVertexAttribP4ui;
pfn_glCreateShader fp_glCreateShader;
pfn_glIsBuffer fp_glIsBuffer;
pfn_glGetMultisamplefv fp_glGetMultisamplefv;
pfn_glProgramUniformMatrix2dv fp_glProgramUniformMatrix2dv;
pfn_glGenRenderbuffers fp_glGenRenderbuffers;
pfn_glCopyTexSubImage2D fp_glCopyTexSubImage2D;
pfn_glCompressedTexImage2D fp_glCompressedTexImage2D;
pfn_glVertexAttrib1f fp_glVertexAttrib1f;
pfn_glBlendFuncSeparate fp_glBlendFuncSeparate;
pfn_glVertex4fv fp_glVertex4fv;
pfn_glMinSampleShading fp_glMinSampleShading;
pfn_glClearNamedFramebufferfi fp_glClearNamedFramebufferfi;
pfn_glGetQueryBufferObjectuiv fp_glGetQueryBufferObjectuiv;
pfn_glBindTexture fp_glBindTexture;
pfn_glVertexAttrib1s fp_glVertexAttrib1s;
pfn_glTexCoord2fv fp_glTexCoord2fv;
pfn_glSampleMaski fp_glSampleMaski;
pfn_glVertexP2ui fp_glVertexP2ui;
pfn_glDrawRangeElementsBaseVertex fp_glDrawRangeElementsBaseVertex;
pfn_glTexCoord4fv fp_glTexCoord4fv;
pfn_glUniformMatrix3x2fv fp_glUniformMatrix3x2fv;
pfn_glDebugMessageControl fp_glDebugMessageControl;
pfn_glPointSize fp_glPointSize;
pfn_glBindTextureUnit fp_glBindTextureUnit;
pfn_glVertexAttrib2dv fp_glVertexAttrib2dv;
pfn_glDeleteProgram fp_glDeleteProgram;
pfn_glColor4bv fp_glColor4bv;
pfn_glRasterPos2f fp_glRasterPos2f;
pfn_glRasterPos2d fp_glRasterPos2d;
pfn_glLoadIdentity fp_glLoadIdentity;
pfn_glRasterPos2i fp_glRasterPos2i;
pfn_glMultiDrawArraysIndirect fp_glMultiDrawArraysIndirect;
pfn_glRenderbufferStorage fp_glRenderbufferStorage;
pfn_glUniformMatrix4x3fv fp_glUniformMatrix4x3fv;
pfn_glColor3b fp_glColor3b;
pfn_glClearBufferfv fp_glClearBufferfv;
pfn_glEdgeFlag fp_glEdgeFlag;
pfn_glDeleteSamplers fp_glDeleteSamplers;
pfn_glVertex3d fp_glVertex3d;
pfn_glVertex3f fp_glVertex3f;
pfn_glGetnMapiv fp_glGetnMapiv;
pfn_glVertex3i fp_glVertex3i;
pfn_glColor3i fp_glColor3i;
pfn_glUniform3d fp_glUniform3d;
pfn_glUniform3f fp_glUniform3f;
pfn_glVertexAttrib4ubv fp_glVertexAttrib4ubv;
pfn_glColor3s fp_glColor3s;
pfn_glVertex3s fp_glVertex3s;
pfn_glTexCoordP2ui fp_glTexCoordP2ui;
pfn_glColorMaski fp_glColorMaski;
pfn_glClearBufferfi fp_glClearBufferfi;
pfn_glDrawArraysIndirect fp_glDrawArraysIndirect;
pfn_glTexCoord1iv fp_glTexCoord1iv;
pfn_glBlitFramebuffer fp_glBlitFramebuffer;
pfn_glPauseTransformFeedback fp_glPauseTransformFeedback;
pfn_glMultiTexCoordP2ui fp_glMultiTexCoordP2ui;
pfn_glProgramUniformMatrix3x2dv fp_glProgramUniformMatrix3x2dv;
pfn_glCopyNamedBufferSubData fp_glCopyNamedBufferSubData;
pfn_glNamedFramebufferTexture fp_glNamedFramebufferTexture;
pfn_glProgramUniformMatrix3x2fv fp_glProgramUniformMatrix3x2fv;
pfn_glGetSamplerParameterIiv fp_glGetSamplerParameterIiv;
pfn_glGetFragDataIndex fp_glGetFragDataIndex;
pfn_glVertexAttribL4d fp_glVertexAttribL4d;
pfn_glBindImageTexture fp_glBindImageTexture;
pfn_glVertexAttrib3f fp_glVertexAttrib3f;
pfn_glProgramUniformMatrix4fv fp_glProgramUniformMatrix4fv;
pfn_glVertex2iv fp_glVertex2iv;
pfn_glGetQueryBufferObjecti64v fp_glGetQueryBufferObjecti64v;
pfn_glColor3sv fp_glColor3sv;
pfn_glGetVertexAttribdv fp_glGetVertexAttribdv;
pfn_glActiveShaderProgram fp_glActiveShaderProgram;
pfn_glUniformMatrix3x4fv fp_glUniformMatrix3x4fv;
pfn_glUniformMatrix3dv fp_glUniformMatrix3dv;
pfn_glNormalPointer fp_glNormalPointer;
pfn_glTexCoordP3uiv fp_glTexCoordP3uiv;
pfn_glVertex4sv fp_glVertex4sv;
pfn_glVertexArrayAttribLFormat fp_glVertexArrayAttribLFormat;
pfn_glInvalidateBufferSubData fp_glInvalidateBufferSubData;
pfn_glPassThrough fp_glPassThrough;
pfn_glMultiTexCoordP4ui fp_glMultiTexCoordP4ui;
pfn_glFogi fp_glFogi;
pfn_glBegin fp_glBegin;
pfn_glEvalCoord2dv fp_glEvalCoord2dv;
pfn_glColor3ubv fp_glColor3ubv;
pfn_glVertexPointer fp_glVertexPointer;
pfn_glSecondaryColor3uiv fp_glSecondaryColor3uiv;
pfn_glDeleteFramebuffers fp_glDeleteFramebuffers;
pfn_glDrawArrays fp_glDrawArrays;
pfn_glUniform1ui fp_glUniform1ui;
pfn_glGetTransformFeedbackiv fp_glGetTransformFeedbackiv;
pfn_glMultiTexCoord1d fp_glMultiTexCoord1d;
pfn_glMultiTexCoord1f fp_glMultiTexCoord1f;
pfn_glProgramParameteri fp_glProgramParameteri;
pfn_glLightfv fp_glLightfv;
pfn_glTexCoordP3ui fp_glTexCoordP3ui;
pfn_glVertexAttrib3d fp_glVertexAttrib3d;
pfn_glClear fp_glClear;
pfn_glMultiTexCoord1i fp_glMultiTexCoord1i;
pfn_glGetActiveUniformName fp_glGetActiveUniformName;
pfn_glMemoryBarrier fp_glMemoryBarrier;
pfn_glGetGraphicsResetStatus fp_glGetGraphicsResetStatus;
pfn_glMultiTexCoord1s fp_glMultiTexCoord1s;
pfn_glIsEnabled fp_glIsEnabled;
pfn_glStencilOp fp_glStencilOp;
pfn_glGetQueryObjectuiv fp_glGetQueryObjectuiv;
pfn_glFramebufferTexture2D fp_glFramebufferTexture2D;
pfn_glGetFramebufferAttachmentParameteriv fp_glGetFramebufferAttachmentParameteriv;
pfn_glTranslatef fp_glTranslatef;
pfn_glVertexAttrib4Nub fp_glVertexAttrib4Nub;
pfn_glTranslated fp_glTranslated;
pfn_glTexCoord3sv fp_glTexCoord3sv;
pfn_glGetFragDataLocation fp_glGetFragDataLocation;
pfn_glGetTextureParameterIiv fp_glGetTextureParameterIiv;
pfn_glTexImage1D fp_glTexImage1D;
pfn_glCopyTextureSubImage3D fp_glCopyTextureSubImage3D;
pfn_glVertexP3uiv fp_glVertexP3uiv;
pfn_glTexParameteriv fp_glTexParameteriv;
pfn_glVertexArrayAttribIFormat fp_glVertexArrayAttribIFormat;
pfn_glSecondaryColor3bv fp_glSecondaryColor3bv;
pfn_glGetMaterialfv fp_glGetMaterialfv;
pfn_glGetTexImage fp_glGetTexImage;
pfn_glFogCoordfv fp_glFogCoordfv;
pfn_glPixelMapuiv fp_glPixelMapuiv;
pfn_glGetShaderInfoLog fp_glGetShaderInfoLog;
pfn_glGetQueryObjecti64v fp_glGetQueryObjecti64v;
pfn_glGenFramebuffers fp_glGenFramebuffers;
pfn_glCreateTextures fp_glCreateTextures;
pfn_glTransformFeedbackBufferBase fp_glTransformFeedbackBufferBase;
pfn_glIndexsv fp_glIndexsv;
pfn_glClearTexSubImage fp_glClearTexSubImage;
pfn_glProgramUniformMatrix3x4dv fp_glProgramUniformMatrix3x4dv;
pfn_glGetAttachedShaders fp_glGetAttachedShaders;
pfn_glIsRenderbuffer fp_glIsRenderbuffer;
pfn_glVertex3iv fp_glVertex3iv;
pfn_glBitmap fp_glBitmap;
pfn_glGetDebugMessageLog fp_glGetDebugMessageLog;
pfn_glProgramUniform1uiv fp_glProgramUniform1uiv;
pfn_glMateriali fp_glMateriali;
pfn_glIsVertexArray fp_glIsVertexArray;
pfn_glDisableVertexAttribArray fp_glDisableVertexAttribArray;
pfn_glProgramUniform2iv fp_glProgramUniform2iv;
pfn_glGetQueryiv fp_glGetQueryiv;
pfn_glTexCoord4f fp_glTexCoord4f;
pfn_glBlitNamedFramebuffer fp_glBlitNamedFramebuffer;
pfn_glTexCoord4d fp_glTexCoord4d;
pfn_glCreateQueries fp_glCreateQueries;
pfn_glGetSamplerParameterfv fp_glGetSamplerParameterfv;
pfn_glTexCoord4i fp_glTexCoord4i;
pfn_glShaderStorageBlockBinding fp_glShaderStorageBlockBinding;
pfn_glMaterialf fp_glMaterialf;
pfn_glTexCoord4s fp_glTexCoord4s;
pfn_glProgramUniformMatrix4x2dv fp_glProgramUniformMatrix4x2dv;
pfn_glGetUniformIndices fp_glGetUniformIndices;
pfn_glIsShader fp_glIsShader;
pfn_glMultiTexCoord2s fp_glMultiTexCoord2s;
pfn_glVertexAttribI4ubv fp_glVertexAttribI4ubv;
pfn_glVertex3dv fp_glVertex3dv;
pfn_glGetInteger64v fp_glGetInteger64v;
pfn_glPointParameteriv fp_glPointParameteriv;
pfn_glGetnMinmax fp_glGetnMinmax;
pfn_glEnable fp_glEnable;
pfn_glGetActiveUniformsiv fp_glGetActiveUniformsiv;
pfn_glColor4fv fp_glColor4fv;
pfn_glTexCoord1fv fp_glTexCoord1fv;
pfn_glVertexArrayAttribBinding fp_glVertexArrayAttribBinding;
pfn_glTextureStorage1D fp_glTextureStorage1D;
pfn_glPopDebugGroup fp_glPopDebugGroup;
pfn_glBlendEquationi fp_glBlendEquationi;
pfn_glTexCoord2sv fp_glTexCoord2sv;
pfn_glVertexAttrib4dv fp_glVertexAttrib4dv;
pfn_glMultiTexCoord1dv fp_glMultiTexCoord1dv;
pfn_glGetProgramInterfaceiv fp_glGetProgramInterfaceiv;
pfn_glMultiTexCoord2i fp_glMultiTexCoord2i;
pfn_glTexCoord3fv fp_glTexCoord3fv;
pfn_glSecondaryColor3usv fp_glSecondaryColor3usv;
pfn_glTexGenf fp_glTexGenf;
pfn_glMapNamedBuffer fp_glMapNamedBuffer;
pfn_glMultiTexCoordP3uiv fp_glMultiTexCoordP3uiv;
pfn_glVertexAttribP3ui fp_glVertexAttribP3ui;
pfn_glVertexAttribL1dv fp_glVertexAttribL1dv;
pfn_glTextureBufferRange fp_glTextureBufferRange;
pfn_glGetnUniformdv fp_glGetnUniformdv;
pfn_glMultiTexCoordP1ui fp_glMultiTexCoordP1ui;
pfn_glProgramUniform3ui fp_glProgramUniform3ui;
pfn_glTransformFeedbackBufferRange fp_glTransformFeedbackBufferRange;
pfn_glGetPointerv fp_glGetPointerv;
pfn_glVertexBindingDivisor fp_glVertexBindingDivisor;
pfn_glPolygonOffset fp_glPolygonOffset;
pfn_glGetUniformuiv fp_glGetUniformuiv;
pfn_glNormal3fv fp_glNormal3fv;
pfn_glSecondaryColor3s fp_glSecondaryColor3s;
pfn_glNamedFramebufferDrawBuffers fp_glNamedFramebufferDrawBuffers;
pfn_glDepthRange fp_glDepthRange;
pfn_glFrustum fp_glFrustum;
pfn_glMultiTexCoord4sv fp_glMultiTexCoord4sv;
pfn_glVertexArrayBindingDivisor fp_glVertexArrayBindingDivisor;
pfn_glDrawBuffer fp_glDrawBuffer;
pfn_glPushMatrix fp_glPushMatrix;
pfn_glGetnPixelMapusv fp_glGetnPixelMapusv;
pfn_glRasterPos3fv fp_glRasterPos3fv;
pfn_glOrtho fp_glOrtho;
pfn_glDrawElementsInstanced fp_glDrawElementsInstanced;
pfn_glWindowPos3sv fp_glWindowPos3sv;
pfn_glVertexAttribL4dv fp_glVertexAttribL4dv;
pfn_glProgramUniform1i fp_glProgramUniform1i;
pfn_glUniform2dv fp_glUniform2dv;
pfn_glProgramUniform1d fp_glProgramUniform1d;
pfn_glProgramUniform1f fp_glProgramUniform1f;
pfn_glClearIndex fp_glClearIndex;
pfn_glMap1d fp_glMap1d;
pfn_glMap1f fp_glMap1f;
pfn_glFlush fp_glFlush;
pfn_glGetRenderbufferParameteriv fp_glGetRenderbufferParameteriv;
pfn_glBeginQueryIndexed fp_glBeginQueryIndexed;
pfn_glProgramUniform3iv fp_glProgramUniform3iv;
pfn_glIndexiv fp_glIndexiv;
pfn_glNamedRenderbufferStorage fp_glNamedRenderbufferStorage;
pfn_glRasterPos3sv fp_glRasterPos3sv;
pfn_glGetVertexAttribPointerv fp_glGetVertexAttribPointerv;
pfn_glPixelZoom fp_glPixelZoom;
pfn_glFenceSync fp_glFenceSync;
pfn_glDeleteVertexArrays fp_glDeleteVertexArrays;
pfn_glColorP3ui fp_glColorP3ui;
pfn_glDrawElementsInstancedBaseVertexBaseInstance fp_glDrawElementsInstancedBaseVertexBaseInstance;
pfn_glTextureStorage2DMultisample fp_glTextureStorage2DMultisample;
pfn_glVertexAttrib3sv fp_glVertexAttrib3sv;
pfn_glBeginConditionalRender fp_glBeginConditionalRender;
pfn_glPushDebugGroup fp_glPushDebugGroup;
pfn_glGetShaderPrecisionFormat fp_glGetShaderPrecisionFormat;
pfn_glValidateProgramPipeline fp_glValidateProgramPipeline;
pfn_glDrawElementsBaseVertex fp_glDrawElementsBaseVertex;
pfn_glGetTexLevelParameteriv fp_glGetTexLevelParameteriv;
pfn_glLighti fp_glLighti;
pfn_glMultiTexCoordP4uiv fp_glMultiTexCoordP4uiv;
pfn_glVertexArrayVertexBuffer fp_glVertexArrayVertexBuffer;
pfn_glLightf fp_glLightf;
pfn_glBindVertexBuffers fp_glBindVertexBuffers;
pfn_glGetAttribLocation fp_glGetAttribLocation;
pfn_glTexStorage3DMultisample fp_glTexStorage3DMultisample;
pfn_glStencilFuncSeparate fp_glStencilFuncSeparate;
pfn_glDisableVertexArrayAttrib fp_glDisableVertexArrayAttrib;
pfn_glGenSamplers fp_glGenSamplers;
pfn_glClampColor fp_glClampColor;
pfn_glUniform4iv fp_glUniform4iv;
pfn_glClearStencil fp_glClearStencil;
pfn_glTexCoordP1uiv fp_glTexCoordP1uiv;
pfn_glGetNamedRenderbufferParameteriv fp_glGetNamedRenderbufferParameteriv;
pfn_glDrawTransformFeedbackInstanced fp_glDrawTransformFeedbackInstanced;
pfn_glMultiTexCoord3fv fp_glMultiTexCoord3fv;
pfn_glGetPixelMapuiv fp_glGetPixelMapuiv;
pfn_glGenTextures fp_glGenTextures;
pfn_glTexCoord4iv fp_glTexCoord4iv;
pfn_glDrawTransformFeedback fp_glDrawTransformFeedback;
pfn_glUniform1dv fp_glUniform1dv;
pfn_glGetTexParameterIuiv fp_glGetTexParameterIuiv;
pfn_glGetTransformFeedbacki_v fp_glGetTransformFeedbacki_v;
pfn_glIndexPointer fp_glIndexPointer;
pfn_glGetnPolygonStipple fp_glGetnPolygonStipple;
pfn_glVertexAttrib4Nbv fp_glVertexAttrib4Nbv;
pfn_glClearNamedFramebufferuiv fp_glClearNamedFramebufferuiv;
pfn_glGetVertexArrayIndexediv fp_glGetVertexArrayIndexediv;
pfn_glIsSync fp_glIsSync;
pfn_glVertex2f fp_glVertex2f;
pfn_glVertex2d fp_glVertex2d;
pfn_glDeleteRenderbuffers fp_glDeleteRenderbuffers;
pfn_glUniform2i fp_glUniform2i;
pfn_glMapGrid2d fp_glMapGrid2d;
pfn_glMapGrid2f fp_glMapGrid2f;
pfn_glTexCoordP4ui fp_glTexCoordP4ui;
pfn_glVertex2i fp_glVertex2i;
pfn_glVertexAttribPointer fp_glVertexAttribPointer;
pfn_glProgramUniform1ui fp_glProgramUniform1ui;
pfn_glFramebufferTextureLayer fp_glFramebufferTextureLayer;
pfn_glVertex2s fp_glVertex2s;
pfn_glGetObjectPtrLabel fp_glGetObjectPtrLabel;
pfn_glTextureParameteri fp_glTextureParameteri;
pfn_glNormal3bv fp_glNormal3bv;
pfn_glVertexAttrib4Nuiv fp_glVertexAttrib4Nuiv;
pfn_glFlushMappedBufferRange fp_glFlushMappedBufferRange;
pfn_glProgramUniform2fv fp_glProgramUniform2fv;
pfn_glUniformMatrix2x3dv fp_glUniformMatrix2x3dv;
pfn_glProgramUniformMatrix4dv fp_glProgramUniformMatrix4dv;
pfn_glSecondaryColor3sv fp_glSecondaryColor3sv;
pfn_glPrimitiveBoundingBox fp_glPrimitiveBoundingBox;
pfn_glProgramUniformMatrix2x4dv fp_glProgramUniformMatrix2x4dv;
pfn_glDispatchCompute fp_glDispatchCompute;
pfn_glVertex3sv fp_glVertex3sv;
pfn_glGenQueries fp_glGenQueries;
pfn_glGetPixelMapfv fp_glGetPixelMapfv;
pfn_glTexEnvf fp_glTexEnvf;
pfn_glVertexAttribP1ui fp_glVertexAttribP1ui;
pfn_glTexSubImage3D fp_glTexSubImage3D;
pfn_glGetInteger64i_v fp_glGetInteger64i_v;
pfn_glFogCoordd fp_glFogCoordd;
pfn_glFogCoordf fp_glFogCoordf;
pfn_glCopyTexImage2D fp_glCopyTexImage2D;
pfn_glTexEnvi fp_glTexEnvi;
pfn_glMultiTexCoord1iv fp_glMultiTexCoord1iv;
pfn_glIsEnabledi fp_glIsEnabledi;
pfn_glBindBuffersRange fp_glBindBuffersRange;
pfn_glSecondaryColorP3ui fp_glSecondaryColorP3ui;
pfn_glVertexAttribI2i fp_glVertexAttribI2i;
pfn_glBindFragDataLocationIndexed fp_glBindFragDataLocationIndexed;
pfn_glCopyImageSubData fp_glCopyImageSubData;
pfn_glMultiTexCoord2dv fp_glMultiTexCoord2dv;
pfn_glUniform2iv fp_glUniform2iv;
pfn_glVertexAttrib1fv fp_glVertexAttrib1fv;
pfn_glGetInternalformativ fp_glGetInternalformativ;
pfn_glUniform4uiv fp_glUniform4uiv;
pfn_glMatrixMode fp_glMatrixMode;
pfn_glGetTextureImage fp_glGetTextureImage;
pfn_glFeedbackBuffer fp_glFeedbackBuffer;
pfn_glProgramUniform2dv fp_glProgramUniform2dv;
pfn_glEndQueryIndexed fp_glEndQueryIndexed;
pfn_glGetMapiv fp_glGetMapiv;
pfn_glTextureSubImage3D fp_glTextureSubImage3D;
pfn_glFramebufferTexture1D fp_glFramebufferTexture1D;
pfn_glUniform4d fp_glUniform4d;
pfn_glGetShaderiv fp_glGetShaderiv;
pfn_glMultiTexCoord2d fp_glMultiTexCoord2d;
pfn_glMultiTexCoord2f fp_glMultiTexCoord2f;
pfn_glProgramUniformMatrix3fv fp_glProgramUniformMatrix3fv;
pfn_glObjectPtrLabel fp_glObjectPtrLabel;
pfn_glInvalidateFramebuffer fp_glInvalidateFramebuffer;
pfn_glBindTextures fp_glBindTextures;
pfn_glBindFragDataLocation fp_glBindFragDataLocation;
pfn_glNamedBufferStorage fp_glNamedBufferStorage;
pfn_glScissorArrayv fp_glScissorArrayv;
pfn_glPrioritizeTextures fp_glPrioritizeTextures;
pfn_glCallList fp_glCallList;
pfn_glPatchParameterfv fp_glPatchParameterfv;
pfn_glSecondaryColor3ubv fp_glSecondaryColor3ubv;
pfn_glGetDoublev fp_glGetDoublev;
pfn_glMultiTexCoord3iv fp_glMultiTexCoord3iv;
pfn_glVertexAttrib1d fp_glVertexAttrib1d;
pfn_glUniform4dv fp_glUniform4dv;
pfn_glLightModelf fp_glLightModelf;
pfn_glGetUniformiv fp_glGetUniformiv;
pfn_glInvalidateBufferData fp_glInvalidateBufferData;
pfn_glVertex2sv fp_glVertex2sv;
pfn_glVertexArrayVertexBuffers fp_glVertexArrayVertexBuffers;
pfn_glCompressedTextureSubImage1D fp_glCompressedTextureSubImage1D;
pfn_glLightModeli fp_glLightModeli;
pfn_glWindowPos3iv fp_glWindowPos3iv;
pfn_glMultiTexCoordP1uiv fp_glMultiTexCoordP1uiv;
pfn_glUniform3fv fp_glUniform3fv;
pfn_glPixelStorei fp_glPixelStorei;
pfn_glGetProgramPipelineInfoLog fp_glGetProgramPipelineInfoLog;
pfn_glCallLists fp_glCallLists;
pfn_glProgramUniformMatrix3x4fv fp_glProgramUniformMatrix3x4fv;
pfn_glInvalidateSubFramebuffer fp_glInvalidateSubFramebuffer;
pfn_glMapBuffer fp_glMapBuffer;
pfn_glSecondaryColor3d fp_glSecondaryColor3d;
pfn_glTexCoord3i fp_glTexCoord3i;
pfn_glMultiTexCoord4fv fp_glMultiTexCoord4fv;
pfn_glRasterPos3i fp_glRasterPos3i;
pfn_glSecondaryColor3b fp_glSecondaryColor3b;
pfn_glRasterPos3d fp_glRasterPos3d;
pfn_glRasterPos3f fp_glRasterPos3f;
pfn_glCompressedTexImage3D fp_glCompressedTexImage3D;
pfn_glTexCoord3f fp_glTexCoord3f;
pfn_glDeleteSync fp_glDeleteSync;
pfn_glTexCoord3d fp_glTexCoord3d;
pfn_glGetTransformFeedbacki64_v fp_glGetTransformFeedbacki64_v;
pfn_glUniformMatrix4dv fp_glUniformMatrix4dv;
pfn_glTexImage2DMultisample fp_glTexImage2DMultisample;
pfn_glGetVertexAttribiv fp_glGetVertexAttribiv;
pfn_glUniformMatrix4x2dv fp_glUniformMatrix4x2dv;
pfn_glMultiDrawElements fp_glMultiDrawElements;
pfn_glVertexAttrib3fv fp_glVertexAttrib3fv;
pfn_glTexCoord3s fp_glTexCoord3s;
pfn_glUniform3iv fp_glUniform3iv;
pfn_glRasterPos3s fp_glRasterPos3s;
pfn_glPolygonMode fp_glPolygonMode;
pfn_glDrawBuffers fp_glDrawBuffers;
pfn_glGetnHistogram fp_glGetnHistogram;
pfn_glGetActiveUniformBlockiv fp_glGetActiveUniformBlockiv;
pfn_glAreTexturesResident fp_glAreTexturesResident;
pfn_glProgramUniform2d fp_glProgramUniform2d;
pfn_glProgramUniformMatrix4x3dv fp_glProgramUniformMatrix4x3dv;
pfn_glIsList fp_glIsList;
pfn_glProgramUniform4iv fp_glProgramUniform4iv;
pfn_glRasterPos2sv fp_glRasterPos2sv;
pfn_glRasterPos4sv fp_glRasterPos4sv;
pfn_glColor4s fp_glColor4s;
pfn_glGetProgramBinary fp_glGetProgramBinary;
pfn_glUseProgram fp_glUseProgram;
pfn_glLineStipple fp_glLineStipple;
pfn_glMultiTexCoord1sv fp_glMultiTexCoord1sv;
pfn_glGetProgramInfoLog fp_glGetProgramInfoLog;
pfn_glClearTexImage fp_glClearTexImage;
pfn_glGetBufferParameteriv fp_glGetBufferParameteriv;
pfn_glMultiTexCoord2iv fp_glMultiTexCoord2iv;
pfn_glUniformMatrix2x4fv fp_glUniformMatrix2x4fv;
pfn_glBindVertexArray fp_glBindVertexArray;
pfn_glColor4b fp_glColor4b;
pfn_glSecondaryColor3f fp_glSecondaryColor3f;
pfn_glColor4f fp_glColor4f;
pfn_glColor4d fp_glColor4d;
pfn_glColor4i fp_glColor4i;
pfn_glSamplerParameterIiv fp_glSamplerParameterIiv;
pfn_glMultiDrawElementsBaseVertex fp_glMultiDrawElementsBaseVertex;
pfn_glVertexAttribLFormat fp_glVertexAttribLFormat;
pfn_glRasterPos3iv fp_glRasterPos3iv;
pfn_glTextureStorage2D fp_glTextureStorage2D;
pfn_glGenerateTextureMipmap fp_glGenerateTextureMipmap;
pfn_glVertex2dv fp_glVertex2dv;
pfn_glTexCoord4sv fp_glTexCoord4sv;
pfn_glUniform2uiv fp_glUniform2uiv;
pfn_glCompressedTexSubImage1D fp_glCompressedTexSubImage1D;
pfn_glFinish fp_glFinish;
pfn_glDepthRangeIndexed fp_glDepthRangeIndexed;
pfn_glGetBooleanv fp_glGetBooleanv;
pfn_glDeleteShader fp_glDeleteShader;
pfn_glDrawElements fp_glDrawElements;
pfn_glGetInternalformati64v fp_glGetInternalformati64v;
pfn_glRasterPos2s fp_glRasterPos2s;
pfn_glCopyTextureSubImage1D fp_glCopyTextureSubImage1D;
pfn_glGetMapdv fp_glGetMapdv;
pfn_glVertexAttrib4Nsv fp_glVertexAttrib4Nsv;
pfn_glMaterialfv fp_glMaterialfv;
pfn_glTextureParameterIuiv fp_glTextureParameterIuiv;
pfn_glViewport fp_glViewport;
pfn_glUniform1uiv fp_glUniform1uiv;
pfn_glTransformFeedbackVaryings fp_glTransformFeedbackVaryings;
pfn_glIndexdv fp_glIndexdv;
pfn_glCopyTexSubImage3D fp_glCopyTexSubImage3D;
pfn_glTexCoord3iv fp_glTexCoord3iv;
pfn_glDebugMessageCallback fp_glDebugMessageCallback;
pfn_glVertexAttribI3i fp_glVertexAttribI3i;
pfn_glInvalidateTexImage fp_glInvalidateTexImage;
pfn_glVertexAttribFormat fp_glVertexAttribFormat;
pfn_glClearDepth fp_glClearDepth;
pfn_glVertexAttribI4usv fp_glVertexAttribI4usv;
pfn_glTexParameterf fp_glTexParameterf;
pfn_glVertexAttribBinding fp_glVertexAttribBinding;
pfn_glTexParameteri fp_glTexParameteri;
pfn_glGetActiveSubroutineUniformiv fp_glGetActiveSubroutineUniformiv;
pfn_glGetShaderSource fp_glGetShaderSource;
pfn_glCreateTransformFeedbacks fp_glCreateTransformFeedbacks;
pfn_glGetnTexImage fp_glGetnTexImage;
pfn_glTexBuffer fp_glTexBuffer;
pfn_glPopName fp_glPopName;
pfn_glValidateProgram fp_glValidateProgram;
pfn_glPixelStoref fp_glPixelStoref;
pfn_glUniform3uiv fp_glUniform3uiv;
pfn_glViewportIndexedf fp_glViewportIndexedf;
pfn_glRasterPos4fv fp_glRasterPos4fv;
pfn_glEvalCoord1dv fp_glEvalCoord1dv;
pfn_glMultiTexCoordP2uiv fp_glMultiTexCoordP2uiv;
pfn_glGenProgramPipelines fp_glGenProgramPipelines;
pfn_glRecti fp_glRecti;
pfn_glColor4ub fp_glColor4ub;
pfn_glMultTransposeMatrixf fp_glMultTransposeMatrixf;
pfn_glRectf fp_glRectf;
pfn_glRectd fp_glRectd;
pfn_glNormal3sv fp_glNormal3sv;
pfn_glNewList fp_glNewList;
pfn_glProgramUniformMatrix2x3dv fp_glProgramUniformMatrix2x3dv;
pfn_glColor4us fp_glColor4us;
pfn_glVertexAttribP1uiv fp_glVertexAttribP1uiv;
pfn_glLinkProgram fp_glLinkProgram;
pfn_glHint fp_glHint;
pfn_glRects fp_glRects;
pfn_glTexCoord2dv fp_glTexCoord2dv;
pfn_glRasterPos4iv fp_glRasterPos4iv;
pfn_glGetObjectLabel fp_glGetObjectLabel;
pfn_glProgramUniform2f fp_glProgramUniform2f;
pfn_glGetString fp_glGetString;
pfn_glVertexAttribP2uiv fp_glVertexAttribP2uiv;
pfn_glEdgeFlagv fp_glEdgeFlagv;
pfn_glDetachShader fp_glDetachShader;
pfn_glProgramUniform3i fp_glProgramUniform3i;
pfn_glScalef fp_glScalef;
pfn_glEndQuery fp_glEndQuery;
pfn_glScaled fp_glScaled;
pfn_glEdgeFlagPointer fp_glEdgeFlagPointer;
pfn_glFramebufferParameteri fp_glFramebufferParameteri;
pfn_glGetProgramResourceName fp_glGetProgramResourceName;
pfn_glUniformMatrix4x3dv fp_glUniformMatrix4x3dv;
pfn_glDepthRangeArrayv fp_glDepthRangeArrayv;
pfn_glCopyPixels fp_glCopyPixels;
pfn_glVertexAttribI2ui fp_glVertexAttribI2ui;
pfn_glGetProgramResourceLocation fp_glGetProgramResourceLocation;
pfn_glPopAttrib fp_glPopAttrib;
pfn_glDeleteTextures fp_glDeleteTextures;
pfn_glGetActiveAtomicCounterBufferiv fp_glGetActiveAtomicCounterBufferiv;
pfn_glStencilOpSeparate fp_glStencilOpSeparate;
pfn_glGetTextureParameteriv fp_glGetTextureParameteriv;
pfn_glDeleteQueries fp_glDeleteQueries;
pfn_glNormalP3uiv fp_glNormalP3uiv;
pfn_glVertexAttrib4f fp_glVertexAttrib4f;
pfn_glVertexAttrib4d fp_glVertexAttrib4d;
pfn_glViewportIndexedfv fp_glViewportIndexedfv;
pfn_glInitNames fp_glInitNames;
pfn_glGetBufferParameteri64v fp_glGetBufferParameteri64v;
pfn_glColor3dv fp_glColor3dv;
pfn_glVertexAttribI1i fp_glVertexAttribI1i;
pfn_glGetTexParameteriv fp_glGetTexParameteriv;
pfn_glWaitSync fp_glWaitSync;
pfn_glCreateVertexArrays fp_glCreateVertexArrays;
pfn_glProgramUniform1dv fp_glProgramUniform1dv;
pfn_glVertexAttrib4s fp_glVertexAttrib4s;
pfn_glColorMaterial fp_glColorMaterial;
pfn_glSampleCoverage fp_glSampleCoverage;
pfn_glSamplerParameteri fp_glSamplerParameteri;
pfn_glClearBufferSubData fp_glClearBufferSubData;
pfn_glSamplerParameterf fp_glSamplerParameterf;
pfn_glTexStorage1D fp_glTexStorage1D;
pfn_glUniform1f fp_glUniform1f;
pfn_glGetVertexAttribfv fp_glGetVertexAttribfv;
pfn_glUniform1d fp_glUniform1d;
pfn_glRenderMode fp_glRenderMode;
pfn_glGetCompressedTexImage fp_glGetCompressedTexImage;
pfn_glGetnCompressedTexImage fp_glGetnCompressedTexImage;
pfn_glWindowPos2dv fp_glWindowPos2dv;
pfn_glUniform1i fp_glUniform1i;
pfn_glGetActiveAttrib fp_glGetActiveAttrib;
pfn_glUniform3i fp_glUniform3i;
pfn_glPixelTransferi fp_glPixelTransferi;
pfn_glTexSubImage2D fp_glTexSubImage2D;
pfn_glDisable fp_glDisable;
pfn_glLogicOp fp_glLogicOp;
pfn_glEvalPoint2 fp_glEvalPoint2;
pfn_glPixelTransferf fp_glPixelTransferf;
pfn_glSecondaryColor3i fp_glSecondaryColor3i;
pfn_glProgramUniform4uiv fp_glProgramUniform4uiv;
pfn_glUniform4ui fp_glUniform4ui;
pfn_glColor3f fp_glColor3f;
pfn_glNamedFramebufferReadBuffer fp_glNamedFramebufferReadBuffer;
pfn_glBindFramebuffer fp_glBindFramebuffer;
pfn_glGetTexEnvfv fp_glGetTexEnvfv;
pfn_glRectfv fp_glRectfv;
pfn_glCullFace fp_glCullFace;
pfn_glGetLightfv fp_glGetLightfv;
pfn_glGetnUniformiv fp_glGetnUniformiv;
pfn_glColor3d fp_glColor3d;
pfn_glProgramUniform4i fp_glProgramUniform4i;
pfn_glTexGend fp_glTexGend;
pfn_glProgramUniform4f fp_glProgramUniform4f;
pfn_glTexGeni fp_glTexGeni;
pfn_glProgramUniform4d fp_glProgramUniform4d;
pfn_glTextureParameterIiv fp_glTextureParameterIiv;
pfn_glMultiTexCoord3s fp_glMultiTexCoord3s;
pfn_glGetStringi fp_glGetStringi;
pfn_glGetTextureParameterfv fp_glGetTextureParameterfv;
pfn_glTextureSubImage2D fp_glTextureSubImage2D;
pfn_glMultiTexCoord3i fp_glMultiTexCoord3i;
pfn_glMultiTexCoord3f fp_glMultiTexCoord3f;
pfn_glDrawTransformFeedbackStream fp_glDrawTransformFeedbackStream;
pfn_glMultiTexCoord3d fp_glMultiTexCoord3d;
pfn_glAttachShader fp_glAttachShader;
pfn_glFogCoorddv fp_glFogCoorddv;
pfn_glUniformMatrix2x3fv fp_glUniformMatrix2x3fv;
pfn_glGetTexGenfv fp_glGetTexGenfv;
pfn_glQueryCounter fp_glQueryCounter;
pfn_glFogCoordPointer fp_glFogCoordPointer;
pfn_glProgramUniformMatrix3dv fp_glProgramUniformMatrix3dv;
pfn_glProvokingVertex fp_glProvokingVertex;
pfn_glShaderBinary fp_glShaderBinary;
pfn_glUnmapNamedBuffer fp_glUnmapNamedBuffer;
pfn_glGetnColorTable fp_glGetnColorTable;
pfn_glFramebufferTexture3D fp_glFramebufferTexture3D;
pfn_glTexGeniv fp_glTexGeniv;
pfn_glRasterPos2dv fp_glRasterPos2dv;
pfn_glSecondaryColor3dv fp_glSecondaryColor3dv;
pfn_glClientActiveTexture fp_glClientActiveTexture;
pfn_glNamedRenderbufferStorageMultisample fp_glNamedRenderbufferStorageMultisample;
pfn_glVertexAttribI4sv fp_glVertexAttribI4sv;
pfn_glClearNamedBufferData fp_glClearNamedBufferData;
pfn_glSecondaryColor3us fp_glSecondaryColor3us;
pfn_glNormalP3ui fp_glNormalP3ui;
pfn_glTexEnvfv fp_glTexEnvfv;
pfn_glReadBuffer fp_glReadBuffer;
pfn_glViewportArrayv fp_glViewportArrayv;
pfn_glTexParameterIuiv fp_glTexParameterIuiv;
pfn_glDrawArraysInstanced fp_glDrawArraysInstanced;
pfn_glGenerateMipmap fp_glGenerateMipmap;
pfn_glCompressedTextureSubImage2D fp_glCompressedTextureSubImage2D;
pfn_glProgramUniformMatrix2fv fp_glProgramUniformMatrix2fv;
pfn_glWindowPos3fv fp_glWindowPos3fv;
pfn_glUniformMatrix3x4dv fp_glUniformMatrix3x4dv;
pfn_glLightModelfv fp_glLightModelfv;
pfn_glSamplerParameteriv fp_glSamplerParameteriv;
pfn_glDeleteLists fp_glDeleteLists;
pfn_glGetClipPlane fp_glGetClipPlane;
pfn_glVertex4dv fp_glVertex4dv;
pfn_glTexCoord2d fp_glTexCoord2d;
pfn_glPopMatrix fp_glPopMatrix;
pfn_glTexCoord2f fp_glTexCoord2f;
pfn_glColor4iv fp_glColor4iv;
pfn_glIndexubv fp_glIndexubv;
pfn_glCheckNamedFramebufferStatus fp_glCheckNamedFramebufferStatus;
pfn_glUnmapBuffer fp_glUnmapBuffer;
pfn_glTexCoord2i fp_glTexCoord2i;
pfn_glRasterPos4d fp_glRasterPos4d;
pfn_glRasterPos4f fp_glRasterPos4f;
pfn_glProgramUniform1iv fp_glProgramUniform1iv;
pfn_glGetVertexArrayiv fp_glGetVertexArrayiv;
pfn_glCopyTextureSubImage2D fp_glCopyTextureSubImage2D;
pfn_glVertexAttrib3s fp_glVertexAttrib3s;
pfn_glTexCoord2s fp_glTexCoord2s;
pfn_glBindRenderbuffer fp_glBindRenderbuffer;
pfn_glVertex3fv fp_glVertex3fv;
pfn_glTexCoord4dv fp_glTexCoord4dv;
pfn_glMaterialiv fp_glMaterialiv;
pfn_glVertexAttribP4uiv fp_glVertexAttribP4uiv;
pfn_glGetProgramStageiv fp_glGetProgramStageiv;
pfn_glIsProgram fp_glIsProgram;
pfn_glVertexAttrib4bv fp_glVertexAttrib4bv;
pfn_glVertex4s fp_glVertex4s;
pfn_glUniformMatrix3x2dv fp_glUniformMatrix3x2dv;
pfn_glVertexAttrib4fv fp_glVertexAttrib4fv;
pfn_glNormal3dv fp_glNormal3dv;
pfn_glIsTransformFeedback fp_glIsTransformFeedback;
pfn_glUniform4i fp_glUniform4i;
pfn_glActiveTexture fp_glActiveTexture;
pfn_glEnableVertexAttribArray fp_glEnableVertexAttribArray;
pfn_glRotated fp_glRotated;
pfn_glIsProgramPipeline fp_glIsProgramPipeline;
pfn_glRotatef fp_glRotatef;
pfn_glVertex4i fp_glVertex4i;
pfn_glReadPixels fp_glReadPixels;
pfn_glVertexAttribI3iv fp_glVertexAttribI3iv;
pfn_glLoadName fp_glLoadName;
pfn_glUniform4f fp_glUniform4f;
pfn_glRenderbufferStorageMultisample fp_glRenderbufferStorageMultisample;
pfn_glCreateProgramPipelines fp_glCreateProgramPipelines;
pfn_glGenVertexArrays fp_glGenVertexArrays;
pfn_glShadeModel fp_glShadeModel;
pfn_glMapGrid1d fp_glMapGrid1d;
pfn_glGetUniformfv fp_glGetUniformfv;
pfn_glMapGrid1f fp_glMapGrid1f;
pfn_glSamplerParameterfv fp_glSamplerParameterfv;
pfn_glVertexAttribLPointer fp_glVertexAttribLPointer;
pfn_glDisableClientState fp_glDisableClientState;
pfn_glMultiTexCoord3sv fp_glMultiTexCoord3sv;
pfn_glGetnUniformfv fp_glGetnUniformfv;
pfn_glDrawElementsInstancedBaseVertex fp_glDrawElementsInstancedBaseVertex;
pfn_glVertexAttribL2dv fp_glVertexAttribL2dv;
pfn_glMultiDrawElementsIndirect fp_glMultiDrawElementsIndirect;
pfn_glEnableVertexArrayAttrib fp_glEnableVertexArrayAttrib;
pfn_glSecondaryColorPointer fp_glSecondaryColorPointer;
pfn_glAlphaFunc fp_glAlphaFunc;
pfn_glUniform1iv fp_glUniform1iv;
pfn_glCreateShaderProgramv fp_glCreateShaderProgramv;
pfn_glGetActiveSubroutineName fp_glGetActiveSubroutineName;
pfn_glMultiTexCoord4iv fp_glMultiTexCoord4iv;
pfn_glVertexAttribL2d fp_glVertexAttribL2d;
pfn_glGetQueryObjectiv fp_glGetQueryObjectiv;
pfn_glStencilFunc fp_glStencilFunc;
pfn_glInvalidateNamedFramebufferData fp_glInvalidateNamedFramebufferData;
pfn_glMultiTexCoord1fv fp_glMultiTexCoord1fv;
pfn_glUniformBlockBinding fp_glUniformBlockBinding;
pfn_glColor4uiv fp_glColor4uiv;
pfn_glRectiv fp_glRectiv;
pfn_glColorP4ui fp_glColorP4ui;
pfn_glUseProgramStages fp_glUseProgramStages;
pfn_glRasterPos3dv fp_glRasterPos3dv;
pfn_glEvalMesh2 fp_glEvalMesh2;
pfn_glEvalMesh1 fp_glEvalMesh1;
pfn_glTexCoordPointer fp_glTexCoordPointer;
pfn_glProgramUniform3f fp_glProgramUniform3f;
pfn_glProgramUniform3d fp_glProgramUniform3d;
pfn_glVertexAttrib4Nubv fp_glVertexAttrib4Nubv;
pfn_glVertexAttribI4iv fp_glVertexAttribI4iv;
pfn_glGetProgramPipelineiv fp_glGetProgramPipelineiv;
pfn_glTexStorage3D fp_glTexStorage3D;
pfn_glEvalCoord2fv fp_glEvalCoord2fv;
pfn_glNamedFramebufferDrawBuffer fp_glNamedFramebufferDrawBuffer;
pfn_glGetQueryIndexediv fp_glGetQueryIndexediv;
pfn_glColor4ubv fp_glColor4ubv;
pfn_glLoadTransposeMatrixd fp_glLoadTransposeMatrixd;
pfn_glLoadTransposeMatrixf fp_glLoadTransposeMatrixf;
pfn_glTextureParameteriv fp_glTextureParameteriv;
pfn_glObjectLabel fp_glObjectLabel;
pfn_glVertexAttribI4i fp_glVertexAttribI4i;
pfn_glRasterPos2iv fp_glRasterPos2iv;
pfn_glGetBufferSubData fp_glGetBufferSubData;
pfn_glGetVertexAttribLdv fp_glGetVertexAttribLdv;
pfn_glGetnUniformuiv fp_glGetnUniformuiv;
pfn_glGetQueryBufferObjectiv fp_glGetQueryBufferObjectiv;
pfn_glTexEnviv fp_glTexEnviv;
pfn_glBlendEquationSeparate fp_glBlendEquationSeparate;
pfn_glVertexAttribI1ui fp_glVertexAttribI1ui;
pfn_glGenBuffers fp_glGenBuffers;
pfn_glSelectBuffer fp_glSelectBuffer;
pfn_glGetSubroutineIndex fp_glGetSubroutineIndex;
pfn_glVertexAttrib2sv fp_glVertexAttrib2sv;
pfn_glScissorIndexedv fp_glScissorIndexedv;
pfn_glPushAttrib fp_glPushAttrib;
pfn_glVertexAttribIPointer fp_glVertexAttribIPointer;
pfn_glBlendFunc fp_glBlendFunc;
pfn_glCreateProgram fp_glCreateProgram;
pfn_glNamedBufferSubData fp_glNamedBufferSubData;
pfn_glTexImage3D fp_glTexImage3D;
pfn_glIsFramebuffer fp_glIsFramebuffer;
pfn_glClearNamedFramebufferfv fp_glClearNamedFramebufferfv;
pfn_glLightiv fp_glLightiv;
pfn_glGetNamedBufferSubData fp_glGetNamedBufferSubData;
pfn_glCompressedTextureSubImage3D fp_glCompressedTextureSubImage3D;
pfn_glPrimitiveRestartIndex fp_glPrimitiveRestartIndex;
pfn_glFlushMappedNamedBufferRange fp_glFlushMappedNamedBufferRange;
pfn_glInvalidateTexSubImage fp_glInvalidateTexSubImage;
pfn_glTexGenfv fp_glTexGenfv;
pfn_glGetTextureParameterIuiv fp_glGetTextureParameterIuiv;
pfn_glGetnConvolutionFilter fp_glGetnConvolutionFilter;
pfn_glBindImageTextures fp_glBindImageTextures;
pfn_glEnd fp_glEnd;
pfn_glDeleteBuffers fp_glDeleteBuffers;
pfn_glBindProgramPipeline fp_glBindProgramPipeline;
pfn_glScissor fp_glScissor;
pfn_glTexCoordP4uiv fp_glTexCoordP4uiv;
pfn_glClipPlane fp_glClipPlane;
pfn_glPushName fp_glPushName;
pfn_glTexGendv fp_glTexGendv;
pfn_glIndexub fp_glIndexub;
pfn_glGetNamedFramebufferAttachmentParameteriv fp_glGetNamedFramebufferAttachmentParameteriv;
pfn_glNamedFramebufferRenderbuffer fp_glNamedFramebufferRenderbuffer;
pfn_glVertexP2uiv fp_glVertexP2uiv;
pfn_glSecondaryColor3iv fp_glSecondaryColor3iv;
pfn_glRasterPos4i fp_glRasterPos4i;
pfn_glMultTransposeMatrixd fp_glMultTransposeMatrixd;
pfn_glClearColor fp_glClearColor;
pfn_glVertexAttrib4uiv fp_glVertexAttrib4uiv;
pfn_glNormal3s fp_glNormal3s;
pfn_glVertexAttrib4Niv fp_glVertexAttrib4Niv;
pfn_glProgramUniformMatrix2x3fv fp_glProgramUniformMatrix2x3fv;
pfn_glClearBufferiv fp_glClearBufferiv;
pfn_glPointParameteri fp_glPointParameteri;
pfn_glProgramUniform4dv fp_glProgramUniform4dv;
pfn_glColorP4uiv fp_glColorP4uiv;
pfn_glBlendColor fp_glBlendColor;
pfn_glGetnPixelMapuiv fp_glGetnPixelMapuiv;
pfn_glGetTextureLevelParameteriv fp_glGetTextureLevelParameteriv;
pfn_glWindowPos3d fp_glWindowPos3d;
pfn_glProgramUniform3fv fp_glProgramUniform3fv;
pfn_glVertexAttribI2uiv fp_glVertexAttribI2uiv;
pfn_glGetNamedFramebufferParameteriv fp_glGetNamedFramebufferParameteriv;
pfn_glSamplerParameterIuiv fp_glSamplerParameterIuiv;
pfn_glUniform3ui fp_glUniform3ui;
pfn_glProgramUniform3uiv fp_glProgramUniform3uiv;
pfn_glColor4dv fp_glColor4dv;
pfn_glVertexAttribI4uiv fp_glVertexAttribI4uiv;
pfn_glPointParameterfv fp_glPointParameterfv;
pfn_glResumeTransformFeedback fp_glResumeTransformFeedback;
pfn_glUniform2fv fp_glUniform2fv;
pfn_glGetActiveSubroutineUniformName fp_glGetActiveSubroutineUniformName;
pfn_glGetProgramResourceIndex fp_glGetProgramResourceIndex;
pfn_glSecondaryColor3ub fp_glSecondaryColor3ub;
pfn_glDrawElementsIndirect fp_glDrawElementsIndirect;
pfn_glGetTextureLevelParameterfv fp_glGetTextureLevelParameterfv;
pfn_glSecondaryColor3ui fp_glSecondaryColor3ui;
pfn_glTexCoord3dv fp_glTexCoord3dv;
pfn_glGetNamedBufferPointerv fp_glGetNamedBufferPointerv;
pfn_glDispatchComputeIndirect fp_glDispatchComputeIndirect;
pfn_glInvalidateNamedFramebufferSubData fp_glInvalidateNamedFramebufferSubData;
pfn_glGetSamplerParameterIuiv fp_glGetSamplerParameterIuiv;
pfn_glBindBufferRange fp_glBindBufferRange;
pfn_glNormal3iv fp_glNormal3iv;
pfn_glTextureSubImage1D fp_glTextureSubImage1D;
pfn_glVertexAttribL3dv fp_glVertexAttribL3dv;
pfn_glGetUniformdv fp_glGetUniformdv;
pfn_glWindowPos3s fp_glWindowPos3s;
pfn_glPointParameterf fp_glPointParameterf;
pfn_glClearDepthf fp_glClearDepthf;
pfn_glGetVertexAttribIuiv fp_glGetVertexAttribIuiv;
pfn_glWindowPos3i fp_glWindowPos3i;
pfn_glMultiTexCoord4s fp_glMultiTexCoord4s;
pfn_glGetTextureSubImage fp_glGetTextureSubImage;
pfn_glWindowPos3f fp_glWindowPos3f;
pfn_glGenTransformFeedbacks fp_glGenTransformFeedbacks;
pfn_glColor3us fp_glColor3us;
pfn_glColor3uiv fp_glColor3uiv;
pfn_glVertexAttrib4Nusv fp_glVertexAttrib4Nusv;
pfn_glGetLightiv fp_glGetLightiv;
pfn_glDepthFunc fp_glDepthFunc;
pfn_glCompressedTexSubImage2D fp_glCompressedTexSubImage2D;
pfn_glListBase fp_glListBase;
pfn_glMultiTexCoord4f fp_glMultiTexCoord4f;
pfn_glColor3ub fp_glColor3ub;
pfn_glMultiTexCoord4d fp_glMultiTexCoord4d;
pfn_glVertexAttribI4bv fp_glVertexAttribI4bv;
pfn_glBlendEquationSeparatei fp_glBlendEquationSeparatei;
pfn_glGetTexParameterfv fp_glGetTexParameterfv;
pfn_glColor3ui fp_glColor3ui;
pfn_glGetProgramResourceLocationIndex fp_glGetProgramResourceLocationIndex;
pfn_glMultiTexCoord4i fp_glMultiTexCoord4i;
pfn_glBufferStorage fp_glBufferStorage;
pfn_glGetPolygonStipple fp_glGetPolygonStipple;
pfn_glClientWaitSync fp_glClientWaitSync;
pfn_glVertexAttribI4ui fp_glVertexAttribI4ui;
pfn_glGetFloati_v fp_glGetFloati_v;
pfn_glMultiTexCoord4dv fp_glMultiTexCoord4dv;
pfn_glColorMask fp_glColorMask;
pfn_glTextureBuffer fp_glTextureBuffer;
pfn_glTexParameterIiv fp_glTexParameterIiv;
pfn_glBlendEquation fp_glBlendEquation;
pfn_glGetUniformLocation fp_glGetUniformLocation;
pfn_glGetSamplerParameteriv fp_glGetSamplerParameteriv;
pfn_glVertexArrayAttribFormat fp_glVertexArrayAttribFormat;
pfn_glReadnPixels fp_glReadnPixels;
pfn_glRasterPos4s fp_glRasterPos4s;
pfn_glEndTransformFeedback fp_glEndTransformFeedback;
pfn_glVertexAttrib4usv fp_glVertexAttrib4usv;
pfn_glGetUniformSubroutineuiv fp_glGetUniformSubroutineuiv;
pfn_glMultiTexCoord3dv fp_glMultiTexCoord3dv;
pfn_glBindVertexBuffer fp_glBindVertexBuffer;
pfn_glColor4sv fp_glColor4sv;
pfn_glDebugMessageInsert fp_glDebugMessageInsert;
pfn_glCreateSamplers fp_glCreateSamplers;
pfn_glPopClientAttrib fp_glPopClientAttrib;
pfn_glClearBufferData fp_glClearBufferData;
pfn_glBeginTransformFeedback fp_glBeginTransformFeedback;
pfn_glFogf fp_glFogf;
pfn_glVertexAttribI1iv fp_glVertexAttribI1iv;
pfn_glProgramBinary fp_glProgramBinary;
pfn_glIsSampler fp_glIsSampler;
pfn_glVertexP3ui fp_glVertexP3ui;
pfn_glVertexAttribDivisor fp_glVertexAttribDivisor;
pfn_glBindSamplers fp_glBindSamplers;
pfn_glColor3iv fp_glColor3iv;
pfn_glCompressedTexImage1D fp_glCompressedTexImage1D;
pfn_glDeleteTransformFeedbacks fp_glDeleteTransformFeedbacks;
pfn_glCopyTexSubImage1D fp_glCopyTexSubImage1D;
pfn_glTexCoord1i fp_glTexCoord1i;
pfn_glCheckFramebufferStatus fp_glCheckFramebufferStatus;
pfn_glTexCoord1d fp_glTexCoord1d;
pfn_glTexCoord1f fp_glTexCoord1f;
pfn_glTextureStorage3D fp_glTextureStorage3D;
pfn_glEndConditionalRender fp_glEndConditionalRender;
pfn_glEnableClientState fp_glEnableClientState;
pfn_glBindAttribLocation fp_glBindAttribLocation;
pfn_glUniformMatrix4x2fv fp_glUniformMatrix4x2fv;
pfn_glUniformMatrix2dv fp_glUniformMatrix2dv;
pfn_glBlendFunci fp_glBlendFunci;
pfn_glMultiTexCoord2sv fp_glMultiTexCoord2sv;
pfn_glVertexAttrib1dv fp_glVertexAttrib1dv;
pfn_glDrawRangeElements fp_glDrawRangeElements;
pfn_glTexCoord1s fp_glTexCoord1s;
pfn_glBindBufferBase fp_glBindBufferBase;
pfn_glBufferSubData fp_glBufferSubData;
pfn_glVertexAttrib4iv fp_glVertexAttrib4iv;
pfn_glGenLists fp_glGenLists;
pfn_glColor3bv fp_glColor3bv;
pfn_glMapBufferRange fp_glMapBufferRange;
pfn_glFramebufferTexture fp_glFramebufferTexture;
pfn_glBlendFuncSeparatei fp_glBlendFuncSeparatei;
pfn_glProgramUniformMatrix4x2fv fp_glProgramUniformMatrix4x2fv;
pfn_glVertexAttribL1d fp_glVertexAttribL1d;
pfn_glGetTexGendv fp_glGetTexGendv;
pfn_glClearNamedFramebufferiv fp_glClearNamedFramebufferiv;
pfn_glMultiDrawArrays fp_glMultiDrawArrays;
pfn_glEndList fp_glEndList;
pfn_glScissorIndexed fp_glScissorIndexed;
pfn_glVertexP4uiv fp_glVertexP4uiv;
pfn_glUniform2ui fp_glUniform2ui;
pfn_glVertexAttribI2iv fp_glVertexAttribI2iv;
pfn_glGetnMapdv fp_glGetnMapdv;
pfn_glColor3usv fp_glColor3usv;
pfn_glWindowPos2fv fp_glWindowPos2fv;
pfn_glTextureView fp_glTextureView;
pfn_glDisablei fp_glDisablei;
pfn_glProgramUniformMatrix2x4fv fp_glProgramUniformMatrix2x4fv;
pfn_glCreateRenderbuffers fp_glCreateRenderbuffers;
pfn_glIndexMask fp_glIndexMask;
pfn_glPushClientAttrib fp_glPushClientAttrib;
pfn_glShaderSource fp_glShaderSource;
pfn_glGetnSeparableFilter fp_glGetnSeparableFilter;
pfn_glGetActiveUniformBlockName fp_glGetActiveUniformBlockName;
pfn_glVertexAttribI3uiv fp_glVertexAttribI3uiv;
pfn_glReleaseShaderCompiler fp_glReleaseShaderCompiler;
pfn_glVertexAttribIFormat fp_glVertexAttribIFormat;
pfn_glCreateFramebuffers fp_glCreateFramebuffers;
pfn_glClearAccum fp_glClearAccum;
pfn_glGetSynciv fp_glGetSynciv;
pfn_glProgramUniform2uiv fp_glProgramUniform2uiv;
pfn_glGetnPixelMapfv fp_glGetnPixelMapfv;
pfn_glTexCoordP2uiv fp_glTexCoordP2uiv;
pfn_glPatchParameteri fp_glPatchParameteri;
pfn_glProgramUniform2i fp_glProgramUniform2i;
pfn_glUniform2f fp_glUniform2f;
pfn_glGetNamedBufferParameteri64v fp_glGetNamedBufferParameteri64v;
pfn_glBeginQuery fp_glBeginQuery;
pfn_glGetUniformBlockIndex fp_glGetUniformBlockIndex;
pfn_glBindBuffer fp_glBindBuffer;
pfn_glMap2d fp_glMap2d;
pfn_glMap2f fp_glMap2f;
pfn_glTexStorage2DMultisample fp_glTexStorage2DMultisample;
pfn_glUniform2d fp_glUniform2d;
pfn_glVertex4d fp_glVertex4d;
pfn_glUniformMatrix2fv fp_glUniformMatrix2fv;
pfn_glTexCoord1sv fp_glTexCoord1sv;
pfn_glBufferData fp_glBufferData;
pfn_glEvalPoint1 fp_glEvalPoint1;
pfn_glGetTexParameterIiv fp_glGetTexParameterIiv;
pfn_glGetQueryBufferObjectui64v fp_glGetQueryBufferObjectui64v;
pfn_glTexCoord1dv fp_glTexCoord1dv;
pfn_glTexCoordP1ui fp_glTexCoordP1ui;
pfn_glGetError fp_glGetError;
pfn_glGetTexEnviv fp_glGetTexEnviv;
pfn_glGetProgramiv fp_glGetProgramiv;
pfn_glVertexAttribP2ui fp_glVertexAttribP2ui;
pfn_glGetFloatv fp_glGetFloatv;
pfn_glTexSubImage1D fp_glTexSubImage1D;
pfn_glMultiTexCoord2fv fp_glMultiTexCoord2fv;
pfn_glUniformMatrix2x4dv fp_glUniformMatrix2x4dv;
pfn_glVertexAttrib2fv fp_glVertexAttrib2fv;
pfn_glEvalCoord1d fp_glEvalCoord1d;
pfn_glGetTexLevelParameterfv fp_glGetTexLevelParameterfv;
pfn_glEvalCoord1f fp_glEvalCoord1f;
pfn_glPixelMapfv fp_glPixelMapfv;
pfn_glVertexAttribP3uiv fp_glVertexAttribP3uiv;
pfn_glGetPixelMapusv fp_glGetPixelMapusv;
pfn_glSecondaryColorP3uiv fp_glSecondaryColorP3uiv;
pfn_glGetIntegerv fp_glGetIntegerv;
pfn_glAccum fp_glAccum;
pfn_glGetVertexArrayIndexed64iv fp_glGetVertexArrayIndexed64iv;
pfn_glGetBufferPointerv fp_glGetBufferPointerv;
pfn_glGetVertexAttribIiv fp_glGetVertexAttribIiv;
pfn_glRasterPos4dv fp_glRasterPos4dv;
pfn_glProgramUniform4fv fp_glProgramUniform4fv;
pfn_glTexCoord2iv fp_glTexCoord2iv;
pfn_glTextureBarrier fp_glTextureBarrier;
pfn_glIsQuery fp_glIsQuery;
pfn_glBlendBarrier fp_glBlendBarrier;
pfn_glProgramUniform2ui fp_glProgramUniform2ui;
pfn_glProgramUniform4ui fp_glProgramUniform4ui;
pfn_glVertexAttrib4sv fp_glVertexAttrib4sv;
pfn_glWindowPos3dv fp_glWindowPos3dv;
pfn_glTexImage2D fp_glTexImage2D;
pfn_glStencilMask fp_glStencilMask;
pfn_glDrawPixels fp_glDrawPixels;
pfn_glMultMatrixd fp_glMultMatrixd;
pfn_glMultMatrixf fp_glMultMatrixf;
pfn_glIsTexture fp_glIsTexture;
pfn_glGetMaterialiv fp_glGetMaterialiv;
pfn_glNamedBufferData fp_glNamedBufferData;
pfn_glUniform1fv fp_glUniform1fv;
pfn_glLoadMatrixf fp_glLoadMatrixf;
pfn_glTexStorage2D fp_glTexStorage2D;
pfn_glLoadMatrixd fp_glLoadMatrixd;
pfn_glClearNamedBufferSubData fp_glClearNamedBufferSubData;
pfn_glMapNamedBufferRange fp_glMapNamedBufferRange;
pfn_glNamedFramebufferTextureLayer fp_glNamedFramebufferTextureLayer;
pfn_glTexParameterfv fp_glTexParameterfv;
pfn_glUniformMatrix3fv fp_glUniformMatrix3fv;
pfn_glVertex4f fp_glVertex4f;
pfn_glRectsv fp_glRectsv;
pfn_glColor4usv fp_glColor4usv;
pfn_glUniform3dv fp_glUniform3dv;
pfn_glProgramUniformMatrix4x3fv fp_glProgramUniformMatrix4x3fv;
pfn_glPolygonStipple fp_glPolygonStipple;
pfn_glBindBuffersBase fp_glBindBuffersBase;
pfn_glInterleavedArrays fp_glInterleavedArrays;
pfn_glGetSubroutineUniformLocation fp_glGetSubroutineUniformLocation;
pfn_glNormal3i fp_glNormal3i;
pfn_glNormal3f fp_glNormal3f;
pfn_glNormal3d fp_glNormal3d;
pfn_glNormal3b fp_glNormal3b;
pfn_glGetFramebufferParameteriv fp_glGetFramebufferParameteriv;
pfn_glPixelMapusv fp_glPixelMapusv;
pfn_glGetTexGeniv fp_glGetTexGeniv;
pfn_glArrayElement fp_glArrayElement;
pfn_glGetCompressedTextureSubImage fp_glGetCompressedTextureSubImage;
pfn_glCopyBufferSubData fp_glCopyBufferSubData;
pfn_glVertexAttribI1uiv fp_glVertexAttribI1uiv;
pfn_glVertexAttrib2d fp_glVertexAttrib2d;
pfn_glBindTransformFeedback fp_glBindTransformFeedback;
pfn_glVertexAttrib2f fp_glVertexAttrib2f;
pfn_glVertexAttrib3dv fp_glVertexAttrib3dv;
pfn_glGetQueryObjectui64v fp_glGetQueryObjectui64v;
pfn_glDepthMask fp_glDepthMask;
pfn_glVertexAttrib2s fp_glVertexAttrib2s;
pfn_glColor3fv fp_glColor3fv;
pfn_glTexImage3DMultisample fp_glTexImage3DMultisample;
pfn_glProgramUniform1fv fp_glProgramUniform1fv;
pfn_glUniformMatrix4fv fp_glUniformMatrix4fv;
pfn_glUniform4fv fp_glUniform4fv;
pfn_glGetActiveUniform fp_glGetActiveUniform;
pfn_glColorPointer fp_glColorPointer;
pfn_glFrontFace fp_glFrontFace;
pfn_glTexBufferRange fp_glTexBufferRange;
pfn_glCreateBuffers fp_glCreateBuffers;
pfn_glNamedFramebufferParameteri fp_glNamedFramebufferParameteri;
pfn_glDrawArraysInstancedBaseInstance fp_glDrawArraysInstancedBaseInstance;
pfn_glGetBooleani_v fp_glGetBooleani_v;
pfn_glVertexAttribL3d fp_glVertexAttribL3d;
pfn_glDeleteProgramPipelines fp_glDeleteProgramPipelines;
pfn_glClearBufferuiv fp_glClearBufferuiv;
pfn_glClipControl fp_glClipControl;
pfn_glGetProgramResourceiv fp_glGetProgramResourceiv;
pfn_glBlendBarrierKHR fp_glBlendBarrierKHR;
pfn_glDebugMessageControlKHR fp_glDebugMessageControlKHR;
pfn_glDebugMessageInsertKHR fp_glDebugMessageInsertKHR;
pfn_glDebugMessageCallbackKHR fp_glDebugMessageCallbackKHR;
pfn_glGetDebugMessageLogKHR fp_glGetDebugMessageLogKHR;
pfn_glPushDebugGroupKHR fp_glPushDebugGroupKHR;
pfn_glPopDebugGroupKHR fp_glPopDebugGroupKHR;
pfn_glObjectLabelKHR fp_glObjectLabelKHR;
pfn_glGetObjectLabelKHR fp_glGetObjectLabelKHR;
pfn_glObjectPtrLabelKHR fp_glObjectPtrLabelKHR;
pfn_glGetObjectPtrLabelKHR fp_glGetObjectPtrLabelKHR;
pfn_glGetPointervKHR fp_glGetPointervKHR;
pfn_glGetGraphicsResetStatusKHR fp_glGetGraphicsResetStatusKHR;
pfn_glReadnPixelsKHR fp_glReadnPixelsKHR;
pfn_glGetnUniformfvKHR fp_glGetnUniformfvKHR;
pfn_glGetnUniformivKHR fp_glGetnUniformivKHR;
pfn_glGetnUniformuivKHR fp_glGetnUniformuivKHR;
pfn_glGetTextureHandleARB fp_glGetTextureHandleARB;
pfn_glGetTextureSamplerHandleARB fp_glGetTextureSamplerHandleARB;
pfn_glMakeTextureHandleResidentARB fp_glMakeTextureHandleResidentARB;
pfn_glMakeTextureHandleNonResidentARB fp_glMakeTextureHandleNonResidentARB;
pfn_glGetImageHandleARB fp_glGetImageHandleARB;
pfn_glMakeImageHandleResidentARB fp_glMakeImageHandleResidentARB;
pfn_glMakeImageHandleNonResidentARB fp_glMakeImageHandleNonResidentARB;
pfn_glUniformHandleui64ARB fp_glUniformHandleui64ARB;
pfn_glUniformHandleui64vARB fp_glUniformHandleui64vARB;
pfn_glProgramUniformHandleui64ARB fp_glProgramUniformHandleui64ARB;
pfn_glProgramUniformHandleui64vARB fp_glProgramUniformHandleui64vARB;
pfn_glIsTextureHandleResidentARB fp_glIsTextureHandleResidentARB;
pfn_glIsImageHandleResidentARB fp_glIsImageHandleResidentARB;
pfn_glVertexAttribL1ui64ARB fp_glVertexAttribL1ui64ARB;
pfn_glVertexAttribL1ui64vARB fp_glVertexAttribL1ui64vARB;
pfn_glGetVertexAttribLui64vARB fp_glGetVertexAttribLui64vARB;
pfn_glCreateSyncFromCLeventARB fp_glCreateSyncFromCLeventARB;
pfn_glClampColorARB fp_glClampColorARB;
pfn_glDispatchComputeGroupSizeARB fp_glDispatchComputeGroupSizeARB;
pfn_glDebugMessageControlARB fp_glDebugMessageControlARB;
pfn_glDebugMessageInsertARB fp_glDebugMessageInsertARB;
pfn_glDebugMessageCallbackARB fp_glDebugMessageCallbackARB;
pfn_glGetDebugMessageLogARB fp_glGetDebugMessageLogARB;
pfn_glBlendEquationiARB fp_glBlendEquationiARB;
pfn_glBlendEquationSeparateiARB fp_glBlendEquationSeparateiARB;
pfn_glBlendFunciARB fp_glBlendFunciARB;
pfn_glBlendFuncSeparateiARB fp_glBlendFuncSeparateiARB;
pfn_glDrawArraysInstancedARB fp_glDrawArraysInstancedARB;
pfn_glDrawElementsInstancedARB fp_glDrawElementsInstancedARB;
pfn_glPrimitiveBoundingBoxARB fp_glPrimitiveBoundingBoxARB;
pfn_glProgramParameteriARB fp_glProgramParameteriARB;
pfn_glFramebufferTextureARB fp_glFramebufferTextureARB;
pfn_glFramebufferTextureLayerARB fp_glFramebufferTextureLayerARB;
pfn_glFramebufferTextureFaceARB fp_glFramebufferTextureFaceARB;
pfn_glUniform1i64ARB fp_glUniform1i64ARB;
pfn_glUniform2i64ARB fp_glUniform2i64ARB;
pfn_glUniform3i64ARB fp_glUniform3i64ARB;
pfn_glUniform4i64ARB fp_glUniform4i64ARB;
pfn_glUniform1i64vARB fp_glUniform1i64vARB;
pfn_glUniform2i64vARB fp_glUniform2i64vARB;
pfn_glUniform3i64vARB fp_glUniform3i64vARB;
pfn_glUniform4i64vARB fp_glUniform4i64vARB;
pfn_glUniform1ui64ARB fp_glUniform1ui64ARB;
pfn_glUniform2ui64ARB fp_glUniform2ui64ARB;
pfn_glUniform3ui64ARB fp_glUniform3ui64ARB;
pfn_glUniform4ui64ARB fp_glUniform4ui64ARB;
pfn_glUniform1ui64vARB fp_glUniform1ui64vARB;
pfn_glUniform2ui64vARB fp_glUniform2ui64vARB;
pfn_glUniform3ui64vARB fp_glUniform3ui64vARB;
pfn_glUniform4ui64vARB fp_glUniform4ui64vARB;
pfn_glGetUniformi64vARB fp_glGetUniformi64vARB;
pfn_glGetUniformui64vARB fp_glGetUniformui64vARB;
pfn_glGetnUniformi64vARB fp_glGetnUniformi64vARB;
pfn_glGetnUniformui64vARB fp_glGetnUniformui64vARB;
pfn_glProgramUniform1i64ARB fp_glProgramUniform1i64ARB;
pfn_glProgramUniform2i64ARB fp_glProgramUniform2i64ARB;
pfn_glProgramUniform3i64ARB fp_glProgramUniform3i64ARB;
pfn_glProgramUniform4i64ARB fp_glProgramUniform4i64ARB;
pfn_glProgramUniform1i64vARB fp_glProgramUniform1i64vARB;
pfn_glProgramUniform2i64vARB fp_glProgramUniform2i64vARB;
pfn_glProgramUniform3i64vARB fp_glProgramUniform3i64vARB;
pfn_glProgramUniform4i64vARB fp_glProgramUniform4i64vARB;
pfn_glProgramUniform1ui64ARB fp_glProgramUniform1ui64ARB;
pfn_glProgramUniform2ui64ARB fp_glProgramUniform2ui64ARB;
pfn_glProgramUniform3ui64ARB fp_glProgramUniform3ui64ARB;
pfn_glProgramUniform4ui64ARB fp_glProgramUniform4ui64ARB;
pfn_glProgramUniform1ui64vARB fp_glProgramUniform1ui64vARB;
pfn_glProgramUniform2ui64vARB fp_glProgramUniform2ui64vARB;
pfn_glProgramUniform3ui64vARB fp_glProgramUniform3ui64vARB;
pfn_glProgramUniform4ui64vARB fp_glProgramUniform4ui64vARB;
pfn_glMultiDrawArraysIndirectCountARB fp_glMultiDrawArraysIndirectCountARB;
pfn_glMultiDrawElementsIndirectCountARB fp_glMultiDrawElementsIndirectCountARB;
pfn_glVertexAttribDivisorARB fp_glVertexAttribDivisorARB;
pfn_glMaxShaderCompilerThreadsARB fp_glMaxShaderCompilerThreadsARB;
pfn_glGetGraphicsResetStatusARB fp_glGetGraphicsResetStatusARB;
pfn_glGetnTexImageARB fp_glGetnTexImageARB;
pfn_glReadnPixelsARB fp_glReadnPixelsARB;
pfn_glGetnCompressedTexImageARB fp_glGetnCompressedTexImageARB;
pfn_glGetnUniformfvARB fp_glGetnUniformfvARB;
pfn_glGetnUniformivARB fp_glGetnUniformivARB;
pfn_glGetnUniformuivARB fp_glGetnUniformuivARB;
pfn_glGetnUniformdvARB fp_glGetnUniformdvARB;
pfn_glGetnMapdvARB fp_glGetnMapdvARB;
pfn_glGetnMapfvARB fp_glGetnMapfvARB;
pfn_glGetnMapivARB fp_glGetnMapivARB;
pfn_glGetnPixelMapfvARB fp_glGetnPixelMapfvARB;
pfn_glGetnPixelMapuivARB fp_glGetnPixelMapuivARB;
pfn_glGetnPixelMapusvARB fp_glGetnPixelMapusvARB;
pfn_glGetnPolygonStippleARB fp_glGetnPolygonStippleARB;
pfn_glGetnColorTableARB fp_glGetnColorTableARB;
pfn_glGetnConvolutionFilterARB fp_glGetnConvolutionFilterARB;
pfn_glGetnSeparableFilterARB fp_glGetnSeparableFilterARB;
pfn_glGetnHistogramARB fp_glGetnHistogramARB;
pfn_glGetnMinmaxARB fp_glGetnMinmaxARB;
pfn_glFramebufferSampleLocationsfvARB fp_glFramebufferSampleLocationsfvARB;
pfn_glNamedFramebufferSampleLocationsfvARB fp_glNamedFramebufferSampleLocationsfvARB;
pfn_glEvaluateDepthValuesARB fp_glEvaluateDepthValuesARB;
pfn_glMinSampleShadingARB fp_glMinSampleShadingARB;
pfn_glNamedStringARB fp_glNamedStringARB;
pfn_glDeleteNamedStringARB fp_glDeleteNamedStringARB;
pfn_glCompileShaderIncludeARB fp_glCompileShaderIncludeARB;
pfn_glIsNamedStringARB fp_glIsNamedStringARB;
pfn_glGetNamedStringARB fp_glGetNamedStringARB;
pfn_glGetNamedStringivARB fp_glGetNamedStringivARB;
pfn_glBufferPageCommitmentARB fp_glBufferPageCommitmentARB;
pfn_glNamedBufferPageCommitmentEXT fp_glNamedBufferPageCommitmentEXT;
pfn_glNamedBufferPageCommitmentARB fp_glNamedBufferPageCommitmentARB;
pfn_glTexPageCommitmentARB fp_glTexPageCommitmentARB;
pfn_glTexBufferARB fp_glTexBufferARB;
pfn_glDrawArraysInstancedBaseInstanceEXT fp_glDrawArraysInstancedBaseInstanceEXT;
pfn_glDrawElementsInstancedBaseInstanceEXT fp_glDrawElementsInstancedBaseInstanceEXT;
pfn_glDrawElementsInstancedBaseVertexBaseInstanceEXT fp_glDrawElementsInstancedBaseVertexBaseInstanceEXT;
pfn_glUniformBufferEXT fp_glUniformBufferEXT;
pfn_glGetUniformBufferSizeEXT fp_glGetUniformBufferSizeEXT;
pfn_glGetUniformOffsetEXT fp_glGetUniformOffsetEXT;
pfn_glBindFragDataLocationIndexedEXT fp_glBindFragDataLocationIndexedEXT;
pfn_glBindFragDataLocationEXT fp_glBindFragDataLocationEXT;
pfn_glGetProgramResourceLocationIndexEXT fp_glGetProgramResourceLocationIndexEXT;
pfn_glGetFragDataIndexEXT fp_glGetFragDataIndexEXT;
pfn_glBlendEquationEXT fp_glBlendEquationEXT;
pfn_glBufferStorageEXT fp_glBufferStorageEXT;
pfn_glCopyImageSubDataEXT fp_glCopyImageSubDataEXT;
pfn_glLabelObjectEXT fp_glLabelObjectEXT;
pfn_glGetObjectLabelEXT fp_glGetObjectLabelEXT;
pfn_glInsertEventMarkerEXT fp_glInsertEventMarkerEXT;
pfn_glPushGroupMarkerEXT fp_glPushGroupMarkerEXT;
pfn_glPopGroupMarkerEXT fp_glPopGroupMarkerEXT;
pfn_glMatrixLoadfEXT fp_glMatrixLoadfEXT;
pfn_glMatrixLoaddEXT fp_glMatrixLoaddEXT;
pfn_glMatrixMultfEXT fp_glMatrixMultfEXT;
pfn_glMatrixMultdEXT fp_glMatrixMultdEXT;
pfn_glMatrixLoadIdentityEXT fp_glMatrixLoadIdentityEXT;
pfn_glMatrixRotatefEXT fp_glMatrixRotatefEXT;
pfn_glMatrixRotatedEXT fp_glMatrixRotatedEXT;
pfn_glMatrixScalefEXT fp_glMatrixScalefEXT;
pfn_glMatrixScaledEXT fp_glMatrixScaledEXT;
pfn_glMatrixTranslatefEXT fp_glMatrixTranslatefEXT;
pfn_glMatrixTranslatedEXT fp_glMatrixTranslatedEXT;
pfn_glMatrixFrustumEXT fp_glMatrixFrustumEXT;
pfn_glMatrixOrthoEXT fp_glMatrixOrthoEXT;
pfn_glMatrixPopEXT fp_glMatrixPopEXT;
pfn_glMatrixPushEXT fp_glMatrixPushEXT;
pfn_glClientAttribDefaultEXT fp_glClientAttribDefaultEXT;
pfn_glPushClientAttribDefaultEXT fp_glPushClientAttribDefaultEXT;
pfn_glTextureParameterfEXT fp_glTextureParameterfEXT;
pfn_glTextureParameterfvEXT fp_glTextureParameterfvEXT;
pfn_glTextureParameteriEXT fp_glTextureParameteriEXT;
pfn_glTextureParameterivEXT fp_glTextureParameterivEXT;
pfn_glTextureImage1DEXT fp_glTextureImage1DEXT;
pfn_glTextureImage2DEXT fp_glTextureImage2DEXT;
pfn_glTextureSubImage1DEXT fp_glTextureSubImage1DEXT;
pfn_glTextureSubImage2DEXT fp_glTextureSubImage2DEXT;
pfn_glCopyTextureImage1DEXT fp_glCopyTextureImage1DEXT;
pfn_glCopyTextureImage2DEXT fp_glCopyTextureImage2DEXT;
pfn_glCopyTextureSubImage1DEXT fp_glCopyTextureSubImage1DEXT;
pfn_glCopyTextureSubImage2DEXT fp_glCopyTextureSubImage2DEXT;
pfn_glGetTextureImageEXT fp_glGetTextureImageEXT;
pfn_glGetTextureParameterfvEXT fp_glGetTextureParameterfvEXT;
pfn_glGetTextureParameterivEXT fp_glGetTextureParameterivEXT;
pfn_glGetTextureLevelParameterfvEXT fp_glGetTextureLevelParameterfvEXT;
pfn_glGetTextureLevelParameterivEXT fp_glGetTextureLevelParameterivEXT;
pfn_glTextureImage3DEXT fp_glTextureImage3DEXT;
pfn_glTextureSubImage3DEXT fp_glTextureSubImage3DEXT;
pfn_glCopyTextureSubImage3DEXT fp_glCopyTextureSubImage3DEXT;
pfn_glBindMultiTextureEXT fp_glBindMultiTextureEXT;
pfn_glMultiTexCoordPointerEXT fp_glMultiTexCoordPointerEXT;
pfn_glMultiTexEnvfEXT fp_glMultiTexEnvfEXT;
pfn_glMultiTexEnvfvEXT fp_glMultiTexEnvfvEXT;
pfn_glMultiTexEnviEXT fp_glMultiTexEnviEXT;
pfn_glMultiTexEnvivEXT fp_glMultiTexEnvivEXT;
pfn_glMultiTexGendEXT fp_glMultiTexGendEXT;
pfn_glMultiTexGendvEXT fp_glMultiTexGendvEXT;
pfn_glMultiTexGenfEXT fp_glMultiTexGenfEXT;
pfn_glMultiTexGenfvEXT fp_glMultiTexGenfvEXT;
pfn_glMultiTexGeniEXT fp_glMultiTexGeniEXT;
pfn_glMultiTexGenivEXT fp_glMultiTexGenivEXT;
pfn_glGetMultiTexEnvfvEXT fp_glGetMultiTexEnvfvEXT;
pfn_glGetMultiTexEnvivEXT fp_glGetMultiTexEnvivEXT;
pfn_glGetMultiTexGendvEXT fp_glGetMultiTexGendvEXT;
pfn_glGetMultiTexGenfvEXT fp_glGetMultiTexGenfvEXT;
pfn_glGetMultiTexGenivEXT fp_glGetMultiTexGenivEXT;
pfn_glMultiTexParameteriEXT fp_glMultiTexParameteriEXT;
pfn_glMultiTexParameterivEXT fp_glMultiTexParameterivEXT;
pfn_glMultiTexParameterfEXT fp_glMultiTexParameterfEXT;
pfn_glMultiTexParameterfvEXT fp_glMultiTexParameterfvEXT;
pfn_glMultiTexImage1DEXT fp_glMultiTexImage1DEXT;
pfn_glMultiTexImage2DEXT fp_glMultiTexImage2DEXT;
pfn_glMultiTexSubImage1DEXT fp_glMultiTexSubImage1DEXT;
pfn_glMultiTexSubImage2DEXT fp_glMultiTexSubImage2DEXT;
pfn_glCopyMultiTexImage1DEXT fp_glCopyMultiTexImage1DEXT;
pfn_glCopyMultiTexImage2DEXT fp_glCopyMultiTexImage2DEXT;
pfn_glCopyMultiTexSubImage1DEXT fp_glCopyMultiTexSubImage1DEXT;
pfn_glCopyMultiTexSubImage2DEXT fp_glCopyMultiTexSubImage2DEXT;
pfn_glGetMultiTexImageEXT fp_glGetMultiTexImageEXT;
pfn_glGetMultiTexParameterfvEXT fp_glGetMultiTexParameterfvEXT;
pfn_glGetMultiTexParameterivEXT fp_glGetMultiTexParameterivEXT;
pfn_glGetMultiTexLevelParameterfvEXT fp_glGetMultiTexLevelParameterfvEXT;
pfn_glGetMultiTexLevelParameterivEXT fp_glGetMultiTexLevelParameterivEXT;
pfn_glMultiTexImage3DEXT fp_glMultiTexImage3DEXT;
pfn_glMultiTexSubImage3DEXT fp_glMultiTexSubImage3DEXT;
pfn_glCopyMultiTexSubImage3DEXT fp_glCopyMultiTexSubImage3DEXT;
pfn_glEnableClientStateIndexedEXT fp_glEnableClientStateIndexedEXT;
pfn_glDisableClientStateIndexedEXT fp_glDisableClientStateIndexedEXT;
pfn_glGetFloatIndexedvEXT fp_glGetFloatIndexedvEXT;
pfn_glGetDoubleIndexedvEXT fp_glGetDoubleIndexedvEXT;
pfn_glGetPointerIndexedvEXT fp_glGetPointerIndexedvEXT;
pfn_glEnableIndexedEXT fp_glEnableIndexedEXT;
pfn_glDisableIndexedEXT fp_glDisableIndexedEXT;
pfn_glIsEnabledIndexedEXT fp_glIsEnabledIndexedEXT;
pfn_glGetIntegerIndexedvEXT fp_glGetIntegerIndexedvEXT;
pfn_glGetBooleanIndexedvEXT fp_glGetBooleanIndexedvEXT;
pfn_glCompressedTextureImage3DEXT fp_glCompressedTextureImage3DEXT;
pfn_glCompressedTextureImage2DEXT fp_glCompressedTextureImage2DEXT;
pfn_glCompressedTextureImage1DEXT fp_glCompressedTextureImage1DEXT;
pfn_glCompressedTextureSubImage3DEXT fp_glCompressedTextureSubImage3DEXT;
pfn_glCompressedTextureSubImage2DEXT fp_glCompressedTextureSubImage2DEXT;
pfn_glCompressedTextureSubImage1DEXT fp_glCompressedTextureSubImage1DEXT;
pfn_glGetCompressedTextureImageEXT fp_glGetCompressedTextureImageEXT;
pfn_glCompressedMultiTexImage3DEXT fp_glCompressedMultiTexImage3DEXT;
pfn_glCompressedMultiTexImage2DEXT fp_glCompressedMultiTexImage2DEXT;
pfn_glCompressedMultiTexImage1DEXT fp_glCompressedMultiTexImage1DEXT;
pfn_glCompressedMultiTexSubImage3DEXT fp_glCompressedMultiTexSubImage3DEXT;
pfn_glCompressedMultiTexSubImage2DEXT fp_glCompressedMultiTexSubImage2DEXT;
pfn_glCompressedMultiTexSubImage1DEXT fp_glCompressedMultiTexSubImage1DEXT;
pfn_glGetCompressedMultiTexImageEXT fp_glGetCompressedMultiTexImageEXT;
pfn_glMatrixLoadTransposefEXT fp_glMatrixLoadTransposefEXT;
pfn_glMatrixLoadTransposedEXT fp_glMatrixLoadTransposedEXT;
pfn_glMatrixMultTransposefEXT fp_glMatrixMultTransposefEXT;
pfn_glMatrixMultTransposedEXT fp_glMatrixMultTransposedEXT;
pfn_glNamedBufferDataEXT fp_glNamedBufferDataEXT;
pfn_glNamedBufferSubDataEXT fp_glNamedBufferSubDataEXT;
pfn_glMapNamedBufferEXT fp_glMapNamedBufferEXT;
pfn_glUnmapNamedBufferEXT fp_glUnmapNamedBufferEXT;
pfn_glGetNamedBufferParameterivEXT fp_glGetNamedBufferParameterivEXT;
pfn_glGetNamedBufferPointervEXT fp_glGetNamedBufferPointervEXT;
pfn_glGetNamedBufferSubDataEXT fp_glGetNamedBufferSubDataEXT;
pfn_glProgramUniform1fEXT fp_glProgramUniform1fEXT;
pfn_glProgramUniform2fEXT fp_glProgramUniform2fEXT;
pfn_glProgramUniform3fEXT fp_glProgramUniform3fEXT;
pfn_glProgramUniform4fEXT fp_glProgramUniform4fEXT;
pfn_glProgramUniform1iEXT fp_glProgramUniform1iEXT;
pfn_glProgramUniform2iEXT fp_glProgramUniform2iEXT;
pfn_glProgramUniform3iEXT fp_glProgramUniform3iEXT;
pfn_glProgramUniform4iEXT fp_glProgramUniform4iEXT;
pfn_glProgramUniform1fvEXT fp_glProgramUniform1fvEXT;
pfn_glProgramUniform2fvEXT fp_glProgramUniform2fvEXT;
pfn_glProgramUniform3fvEXT fp_glProgramUniform3fvEXT;
pfn_glProgramUniform4fvEXT fp_glProgramUniform4fvEXT;
pfn_glProgramUniform1ivEXT fp_glProgramUniform1ivEXT;
pfn_glProgramUniform2ivEXT fp_glProgramUniform2ivEXT;
pfn_glProgramUniform3ivEXT fp_glProgramUniform3ivEXT;
pfn_glProgramUniform4ivEXT fp_glProgramUniform4ivEXT;
pfn_glProgramUniformMatrix2fvEXT fp_glProgramUniformMatrix2fvEXT;
pfn_glProgramUniformMatrix3fvEXT fp_glProgramUniformMatrix3fvEXT;
pfn_glProgramUniformMatrix4fvEXT fp_glProgramUniformMatrix4fvEXT;
pfn_glProgramUniformMatrix2x3fvEXT fp_glProgramUniformMatrix2x3fvEXT;
pfn_glProgramUniformMatrix3x2fvEXT fp_glProgramUniformMatrix3x2fvEXT;
pfn_glProgramUniformMatrix2x4fvEXT fp_glProgramUniformMatrix2x4fvEXT;
pfn_glProgramUniformMatrix4x2fvEXT fp_glProgramUniformMatrix4x2fvEXT;
pfn_glProgramUniformMatrix3x4fvEXT fp_glProgramUniformMatrix3x4fvEXT;
pfn_glProgramUniformMatrix4x3fvEXT fp_glProgramUniformMatrix4x3fvEXT;
pfn_glTextureBufferEXT fp_glTextureBufferEXT;
pfn_glMultiTexBufferEXT fp_glMultiTexBufferEXT;
pfn_glTextureParameterIivEXT fp_glTextureParameterIivEXT;
pfn_glTextureParameterIuivEXT fp_glTextureParameterIuivEXT;
pfn_glGetTextureParameterIivEXT fp_glGetTextureParameterIivEXT;
pfn_glGetTextureParameterIuivEXT fp_glGetTextureParameterIuivEXT;
pfn_glMultiTexParameterIivEXT fp_glMultiTexParameterIivEXT;
pfn_glMultiTexParameterIuivEXT fp_glMultiTexParameterIuivEXT;
pfn_glGetMultiTexParameterIivEXT fp_glGetMultiTexParameterIivEXT;
pfn_glGetMultiTexParameterIuivEXT fp_glGetMultiTexParameterIuivEXT;
pfn_glProgramUniform1uiEXT fp_glProgramUniform1uiEXT;
pfn_glProgramUniform2uiEXT fp_glProgramUniform2uiEXT;
pfn_glProgramUniform3uiEXT fp_glProgramUniform3uiEXT;
pfn_glProgramUniform4uiEXT fp_glProgramUniform4uiEXT;
pfn_glProgramUniform1uivEXT fp_glProgramUniform1uivEXT;
pfn_glProgramUniform2uivEXT fp_glProgramUniform2uivEXT;
pfn_glProgramUniform3uivEXT fp_glProgramUniform3uivEXT;
pfn_glProgramUniform4uivEXT fp_glProgramUniform4uivEXT;
pfn_glNamedProgramLocalParameters4fvEXT fp_glNamedProgramLocalParameters4fvEXT;
pfn_glNamedProgramLocalParameterI4iEXT fp_glNamedProgramLocalParameterI4iEXT;
pfn_glNamedProgramLocalParameterI4ivEXT fp_glNamedProgramLocalParameterI4ivEXT;
pfn_glNamedProgramLocalParametersI4ivEXT fp_glNamedProgramLocalParametersI4ivEXT;
pfn_glNamedProgramLocalParameterI4uiEXT fp_glNamedProgramLocalParameterI4uiEXT;
pfn_glNamedProgramLocalParameterI4uivEXT fp_glNamedProgramLocalParameterI4uivEXT;
pfn_glNamedProgramLocalParametersI4uivEXT fp_glNamedProgramLocalParametersI4uivEXT;
pfn_glGetNamedProgramLocalParameterIivEXT fp_glGetNamedProgramLocalParameterIivEXT;
pfn_glGetNamedProgramLocalParameterIuivEXT fp_glGetNamedProgramLocalParameterIuivEXT;
pfn_glEnableClientStateiEXT fp_glEnableClientStateiEXT;
pfn_glDisableClientStateiEXT fp_glDisableClientStateiEXT;
pfn_glGetFloati_vEXT fp_glGetFloati_vEXT;
pfn_glGetDoublei_vEXT fp_glGetDoublei_vEXT;
pfn_glGetPointeri_vEXT fp_glGetPointeri_vEXT;
pfn_glNamedProgramStringEXT fp_glNamedProgramStringEXT;
pfn_glNamedProgramLocalParameter4dEXT fp_glNamedProgramLocalParameter4dEXT;
pfn_glNamedProgramLocalParameter4dvEXT fp_glNamedProgramLocalParameter4dvEXT;
pfn_glNamedProgramLocalParameter4fEXT fp_glNamedProgramLocalParameter4fEXT;
pfn_glNamedProgramLocalParameter4fvEXT fp_glNamedProgramLocalParameter4fvEXT;
pfn_glGetNamedProgramLocalParameterdvEXT fp_glGetNamedProgramLocalParameterdvEXT;
pfn_glGetNamedProgramLocalParameterfvEXT fp_glGetNamedProgramLocalParameterfvEXT;
pfn_glGetNamedProgramivEXT fp_glGetNamedProgramivEXT;
pfn_glGetNamedProgramStringEXT fp_glGetNamedProgramStringEXT;
pfn_glNamedRenderbufferStorageEXT fp_glNamedRenderbufferStorageEXT;
pfn_glGetNamedRenderbufferParameterivEXT fp_glGetNamedRenderbufferParameterivEXT;
pfn_glNamedRenderbufferStorageMultisampleEXT fp_glNamedRenderbufferStorageMultisampleEXT;
pfn_glNamedRenderbufferStorageMultisampleCoverageEXT fp_glNamedRenderbufferStorageMultisampleCoverageEXT;
pfn_glCheckNamedFramebufferStatusEXT fp_glCheckNamedFramebufferStatusEXT;
pfn_glNamedFramebufferTexture1DEXT fp_glNamedFramebufferTexture1DEXT;
pfn_glNamedFramebufferTexture2DEXT fp_glNamedFramebufferTexture2DEXT;
pfn_glNamedFramebufferTexture3DEXT fp_glNamedFramebufferTexture3DEXT;
pfn_glNamedFramebufferRenderbufferEXT fp_glNamedFramebufferRenderbufferEXT;
pfn_glGetNamedFramebufferAttachmentParameterivEXT fp_glGetNamedFramebufferAttachmentParameterivEXT;
pfn_glGenerateTextureMipmapEXT fp_glGenerateTextureMipmapEXT;
pfn_glGenerateMultiTexMipmapEXT fp_glGenerateMultiTexMipmapEXT;
pfn_glFramebufferDrawBufferEXT fp_glFramebufferDrawBufferEXT;
pfn_glFramebufferDrawBuffersEXT fp_glFramebufferDrawBuffersEXT;
pfn_glFramebufferReadBufferEXT fp_glFramebufferReadBufferEXT;
pfn_glGetFramebufferParameterivEXT fp_glGetFramebufferParameterivEXT;
pfn_glNamedCopyBufferSubDataEXT fp_glNamedCopyBufferSubDataEXT;
pfn_glNamedFramebufferTextureEXT fp_glNamedFramebufferTextureEXT;
pfn_glNamedFramebufferTextureLayerEXT fp_glNamedFramebufferTextureLayerEXT;
pfn_glNamedFramebufferTextureFaceEXT fp_glNamedFramebufferTextureFaceEXT;
pfn_glTextureRenderbufferEXT fp_glTextureRenderbufferEXT;
pfn_glMultiTexRenderbufferEXT fp_glMultiTexRenderbufferEXT;
pfn_glVertexArrayVertexOffsetEXT fp_glVertexArrayVertexOffsetEXT;
pfn_glVertexArrayColorOffsetEXT fp_glVertexArrayColorOffsetEXT;
pfn_glVertexArrayEdgeFlagOffsetEXT fp_glVertexArrayEdgeFlagOffsetEXT;
pfn_glVertexArrayIndexOffsetEXT fp_glVertexArrayIndexOffsetEXT;
pfn_glVertexArrayNormalOffsetEXT fp_glVertexArrayNormalOffsetEXT;
pfn_glVertexArrayTexCoordOffsetEXT fp_glVertexArrayTexCoordOffsetEXT;
pfn_glVertexArrayMultiTexCoordOffsetEXT fp_glVertexArrayMultiTexCoordOffsetEXT;
pfn_glVertexArrayFogCoordOffsetEXT fp_glVertexArrayFogCoordOffsetEXT;
pfn_glVertexArraySecondaryColorOffsetEXT fp_glVertexArraySecondaryColorOffsetEXT;
pfn_glVertexArrayVertexAttribOffsetEXT fp_glVertexArrayVertexAttribOffsetEXT;
pfn_glVertexArrayVertexAttribIOffsetEXT fp_glVertexArrayVertexAttribIOffsetEXT;
pfn_glEnableVertexArrayEXT fp_glEnableVertexArrayEXT;
pfn_glDisableVertexArrayEXT fp_glDisableVertexArrayEXT;
pfn_glEnableVertexArrayAttribEXT fp_glEnableVertexArrayAttribEXT;
pfn_glDisableVertexArrayAttribEXT fp_glDisableVertexArrayAttribEXT;
pfn_glGetVertexArrayIntegervEXT fp_glGetVertexArrayIntegervEXT;
pfn_glGetVertexArrayPointervEXT fp_glGetVertexArrayPointervEXT;
pfn_glGetVertexArrayIntegeri_vEXT fp_glGetVertexArrayIntegeri_vEXT;
pfn_glGetVertexArrayPointeri_vEXT fp_glGetVertexArrayPointeri_vEXT;
pfn_glMapNamedBufferRangeEXT fp_glMapNamedBufferRangeEXT;
pfn_glFlushMappedNamedBufferRangeEXT fp_glFlushMappedNamedBufferRangeEXT;
pfn_glNamedBufferStorageEXT fp_glNamedBufferStorageEXT;
pfn_glClearNamedBufferDataEXT fp_glClearNamedBufferDataEXT;
pfn_glClearNamedBufferSubDataEXT fp_glClearNamedBufferSubDataEXT;
pfn_glNamedFramebufferParameteriEXT fp_glNamedFramebufferParameteriEXT;
pfn_glGetNamedFramebufferParameterivEXT fp_glGetNamedFramebufferParameterivEXT;
pfn_glProgramUniform1dEXT fp_glProgramUniform1dEXT;
pfn_glProgramUniform2dEXT fp_glProgramUniform2dEXT;
pfn_glProgramUniform3dEXT fp_glProgramUniform3dEXT;
pfn_glProgramUniform4dEXT fp_glProgramUniform4dEXT;
pfn_glProgramUniform1dvEXT fp_glProgramUniform1dvEXT;
pfn_glProgramUniform2dvEXT fp_glProgramUniform2dvEXT;
pfn_glProgramUniform3dvEXT fp_glProgramUniform3dvEXT;
pfn_glProgramUniform4dvEXT fp_glProgramUniform4dvEXT;
pfn_glProgramUniformMatrix2dvEXT fp_glProgramUniformMatrix2dvEXT;
pfn_glProgramUniformMatrix3dvEXT fp_glProgramUniformMatrix3dvEXT;
pfn_glProgramUniformMatrix4dvEXT fp_glProgramUniformMatrix4dvEXT;
pfn_glProgramUniformMatrix2x3dvEXT fp_glProgramUniformMatrix2x3dvEXT;
pfn_glProgramUniformMatrix2x4dvEXT fp_glProgramUniformMatrix2x4dvEXT;
pfn_glProgramUniformMatrix3x2dvEXT fp_glProgramUniformMatrix3x2dvEXT;
pfn_glProgramUniformMatrix3x4dvEXT fp_glProgramUniformMatrix3x4dvEXT;
pfn_glProgramUniformMatrix4x2dvEXT fp_glProgramUniformMatrix4x2dvEXT;
pfn_glProgramUniformMatrix4x3dvEXT fp_glProgramUniformMatrix4x3dvEXT;
pfn_glTextureBufferRangeEXT fp_glTextureBufferRangeEXT;
pfn_glTextureStorage1DEXT fp_glTextureStorage1DEXT;
pfn_glTextureStorage2DEXT fp_glTextureStorage2DEXT;
pfn_glTextureStorage3DEXT fp_glTextureStorage3DEXT;
pfn_glTextureStorage2DMultisampleEXT fp_glTextureStorage2DMultisampleEXT;
pfn_glTextureStorage3DMultisampleEXT fp_glTextureStorage3DMultisampleEXT;
pfn_glVertexArrayBindVertexBufferEXT fp_glVertexArrayBindVertexBufferEXT;
pfn_glVertexArrayVertexAttribFormatEXT fp_glVertexArrayVertexAttribFormatEXT;
pfn_glVertexArrayVertexAttribIFormatEXT fp_glVertexArrayVertexAttribIFormatEXT;
pfn_glVertexArrayVertexAttribLFormatEXT fp_glVertexArrayVertexAttribLFormatEXT;
pfn_glVertexArrayVertexAttribBindingEXT fp_glVertexArrayVertexAttribBindingEXT;
pfn_glVertexArrayVertexBindingDivisorEXT fp_glVertexArrayVertexBindingDivisorEXT;
pfn_glVertexArrayVertexAttribLOffsetEXT fp_glVertexArrayVertexAttribLOffsetEXT;
pfn_glTexturePageCommitmentEXT fp_glTexturePageCommitmentEXT;
pfn_glVertexArrayVertexAttribDivisorEXT fp_glVertexArrayVertexAttribDivisorEXT;
pfn_glDiscardFramebufferEXT fp_glDiscardFramebufferEXT;
pfn_glGenQueriesEXT fp_glGenQueriesEXT;
pfn_glDeleteQueriesEXT fp_glDeleteQueriesEXT;
pfn_glIsQueryEXT fp_glIsQueryEXT;
pfn_glBeginQueryEXT fp_glBeginQueryEXT;
pfn_glEndQueryEXT fp_glEndQueryEXT;
pfn_glQueryCounterEXT fp_glQueryCounterEXT;
pfn_glGetQueryivEXT fp_glGetQueryivEXT;
pfn_glGetQueryObjectivEXT fp_glGetQueryObjectivEXT;
pfn_glGetQueryObjectuivEXT fp_glGetQueryObjectuivEXT;
pfn_glGetQueryObjecti64vEXT fp_glGetQueryObjecti64vEXT;
pfn_glGetQueryObjectui64vEXT fp_glGetQueryObjectui64vEXT;
pfn_glDrawBuffersEXT fp_glDrawBuffersEXT;
pfn_glColorMaskIndexedEXT fp_glColorMaskIndexedEXT;
pfn_glEnableiEXT fp_glEnableiEXT;
pfn_glDisableiEXT fp_glDisableiEXT;
pfn_glBlendEquationiEXT fp_glBlendEquationiEXT;
pfn_glBlendEquationSeparateiEXT fp_glBlendEquationSeparateiEXT;
pfn_glBlendFunciEXT fp_glBlendFunciEXT;
pfn_glBlendFuncSeparateiEXT fp_glBlendFuncSeparateiEXT;
pfn_glColorMaskiEXT fp_glColorMaskiEXT;
pfn_glIsEnablediEXT fp_glIsEnablediEXT;
pfn_glDrawElementsBaseVertexEXT fp_glDrawElementsBaseVertexEXT;
pfn_glDrawRangeElementsBaseVertexEXT fp_glDrawRangeElementsBaseVertexEXT;
pfn_glDrawElementsInstancedBaseVertexEXT fp_glDrawElementsInstancedBaseVertexEXT;
pfn_glMultiDrawElementsBaseVertexEXT fp_glMultiDrawElementsBaseVertexEXT;
pfn_glDrawArraysInstancedEXT fp_glDrawArraysInstancedEXT;
pfn_glDrawElementsInstancedEXT fp_glDrawElementsInstancedEXT;
pfn_glBlitFramebufferEXT fp_glBlitFramebufferEXT;
pfn_glRenderbufferStorageMultisampleEXT fp_glRenderbufferStorageMultisampleEXT;
pfn_glIsRenderbufferEXT fp_glIsRenderbufferEXT;
pfn_glBindRenderbufferEXT fp_glBindRenderbufferEXT;
pfn_glDeleteRenderbuffersEXT fp_glDeleteRenderbuffersEXT;
pfn_glGenRenderbuffersEXT fp_glGenRenderbuffersEXT;
pfn_glRenderbufferStorageEXT fp_glRenderbufferStorageEXT;
pfn_glGetRenderbufferParameterivEXT fp_glGetRenderbufferParameterivEXT;
pfn_glIsFramebufferEXT fp_glIsFramebufferEXT;
pfn_glBindFramebufferEXT fp_glBindFramebufferEXT;
pfn_glDeleteFramebuffersEXT fp_glDeleteFramebuffersEXT;
pfn_glGenFramebuffersEXT fp_glGenFramebuffersEXT;
pfn_glCheckFramebufferStatusEXT fp_glCheckFramebufferStatusEXT;
pfn_glFramebufferTexture1DEXT fp_glFramebufferTexture1DEXT;
pfn_glFramebufferTexture2DEXT fp_glFramebufferTexture2DEXT;
pfn_glFramebufferTexture3DEXT fp_glFramebufferTexture3DEXT;
pfn_glFramebufferRenderbufferEXT fp_glFramebufferRenderbufferEXT;
pfn_glGetFramebufferAttachmentParameterivEXT fp_glGetFramebufferAttachmentParameterivEXT;
pfn_glGenerateMipmapEXT fp_glGenerateMipmapEXT;
pfn_glFramebufferTextureEXT fp_glFramebufferTextureEXT;
pfn_glProgramParameteriEXT fp_glProgramParameteriEXT;
pfn_glProgramEnvParameters4fvEXT fp_glProgramEnvParameters4fvEXT;
pfn_glProgramLocalParameters4fvEXT fp_glProgramLocalParameters4fvEXT;
pfn_glGetUniformuivEXT fp_glGetUniformuivEXT;
pfn_glGetFragDataLocationEXT fp_glGetFragDataLocationEXT;
pfn_glUniform1uiEXT fp_glUniform1uiEXT;
pfn_glUniform2uiEXT fp_glUniform2uiEXT;
pfn_glUniform3uiEXT fp_glUniform3uiEXT;
pfn_glUniform4uiEXT fp_glUniform4uiEXT;
pfn_glUniform1uivEXT fp_glUniform1uivEXT;
pfn_glUniform2uivEXT fp_glUniform2uivEXT;
pfn_glUniform3uivEXT fp_glUniform3uivEXT;
pfn_glUniform4uivEXT fp_glUniform4uivEXT;
pfn_glVertexAttribDivisorEXT fp_glVertexAttribDivisorEXT;
pfn_glMapBufferRangeEXT fp_glMapBufferRangeEXT;
pfn_glFlushMappedBufferRangeEXT fp_glFlushMappedBufferRangeEXT;
pfn_glMultiDrawArraysIndirectEXT fp_glMultiDrawArraysIndirectEXT;
pfn_glMultiDrawElementsIndirectEXT fp_glMultiDrawElementsIndirectEXT;
pfn_glFramebufferTexture2DMultisampleEXT fp_glFramebufferTexture2DMultisampleEXT;
pfn_glReadBufferIndexedEXT fp_glReadBufferIndexedEXT;
pfn_glDrawBuffersIndexedEXT fp_glDrawBuffersIndexedEXT;
pfn_glGetIntegeri_vEXT fp_glGetIntegeri_vEXT;
pfn_glPolygonOffsetClampEXT fp_glPolygonOffsetClampEXT;
pfn_glPrimitiveBoundingBoxEXT fp_glPrimitiveBoundingBoxEXT;
pfn_glProvokingVertexEXT fp_glProvokingVertexEXT;
pfn_glRasterSamplesEXT fp_glRasterSamplesEXT;
pfn_glGetGraphicsResetStatusEXT fp_glGetGraphicsResetStatusEXT;
pfn_glReadnPixelsEXT fp_glReadnPixelsEXT;
pfn_glGetnUniformfvEXT fp_glGetnUniformfvEXT;
pfn_glGetnUniformivEXT fp_glGetnUniformivEXT;
pfn_glUseShaderProgramEXT fp_glUseShaderProgramEXT;
pfn_glActiveProgramEXT fp_glActiveProgramEXT;
pfn_glCreateShaderProgramEXT fp_glCreateShaderProgramEXT;
pfn_glActiveShaderProgramEXT fp_glActiveShaderProgramEXT;
pfn_glBindProgramPipelineEXT fp_glBindProgramPipelineEXT;
pfn_glCreateShaderProgramvEXT fp_glCreateShaderProgramvEXT;
pfn_glDeleteProgramPipelinesEXT fp_glDeleteProgramPipelinesEXT;
pfn_glGenProgramPipelinesEXT fp_glGenProgramPipelinesEXT;
pfn_glGetProgramPipelineInfoLogEXT fp_glGetProgramPipelineInfoLogEXT;
pfn_glGetProgramPipelineivEXT fp_glGetProgramPipelineivEXT;
pfn_glIsProgramPipelineEXT fp_glIsProgramPipelineEXT;
pfn_glUseProgramStagesEXT fp_glUseProgramStagesEXT;
pfn_glValidateProgramPipelineEXT fp_glValidateProgramPipelineEXT;
pfn_glBindImageTextureEXT fp_glBindImageTextureEXT;
pfn_glMemoryBarrierEXT fp_glMemoryBarrierEXT;
pfn_glTexPageCommitmentEXT fp_glTexPageCommitmentEXT;
pfn_glStencilClearTagEXT fp_glStencilClearTagEXT;
pfn_glPatchParameteriEXT fp_glPatchParameteriEXT;
pfn_glFramebufferTextureLayerEXT fp_glFramebufferTextureLayerEXT;
pfn_glTexParameterIivEXT fp_glTexParameterIivEXT;
pfn_glTexParameterIuivEXT fp_glTexParameterIuivEXT;
pfn_glGetTexParameterIivEXT fp_glGetTexParameterIivEXT;
pfn_glGetTexParameterIuivEXT fp_glGetTexParameterIuivEXT;
pfn_glSamplerParameterIivEXT fp_glSamplerParameterIivEXT;
pfn_glSamplerParameterIuivEXT fp_glSamplerParameterIuivEXT;
pfn_glGetSamplerParameterIivEXT fp_glGetSamplerParameterIivEXT;
pfn_glGetSamplerParameterIuivEXT fp_glGetSamplerParameterIuivEXT;
pfn_glTexBufferEXT fp_glTexBufferEXT;
pfn_glTexBufferRangeEXT fp_glTexBufferRangeEXT;
pfn_glClearColorIiEXT fp_glClearColorIiEXT;
pfn_glClearColorIuiEXT fp_glClearColorIuiEXT;
pfn_glTexStorage1DEXT fp_glTexStorage1DEXT;
pfn_glTexStorage2DEXT fp_glTexStorage2DEXT;
pfn_glTexStorage3DEXT fp_glTexStorage3DEXT;
pfn_glTextureViewEXT fp_glTextureViewEXT;
pfn_glBeginTransformFeedbackEXT fp_glBeginTransformFeedbackEXT;
pfn_glEndTransformFeedbackEXT fp_glEndTransformFeedbackEXT;
pfn_glBindBufferRangeEXT fp_glBindBufferRangeEXT;
pfn_glBindBufferOffsetEXT fp_glBindBufferOffsetEXT;
pfn_glBindBufferBaseEXT fp_glBindBufferBaseEXT;
pfn_glTransformFeedbackVaryingsEXT fp_glTransformFeedbackVaryingsEXT;
pfn_glGetTransformFeedbackVaryingEXT fp_glGetTransformFeedbackVaryingEXT;
pfn_glVertexAttribL1dEXT fp_glVertexAttribL1dEXT;
pfn_glVertexAttribL2dEXT fp_glVertexAttribL2dEXT;
pfn_glVertexAttribL3dEXT fp_glVertexAttribL3dEXT;
pfn_glVertexAttribL4dEXT fp_glVertexAttribL4dEXT;
pfn_glVertexAttribL1dvEXT fp_glVertexAttribL1dvEXT;
pfn_glVertexAttribL2dvEXT fp_glVertexAttribL2dvEXT;
pfn_glVertexAttribL3dvEXT fp_glVertexAttribL3dvEXT;
pfn_glVertexAttribL4dvEXT fp_glVertexAttribL4dvEXT;
pfn_glVertexAttribLPointerEXT fp_glVertexAttribLPointerEXT;
pfn_glGetVertexAttribLdvEXT fp_glGetVertexAttribLdvEXT;
pfn_glImportSyncEXT fp_glImportSyncEXT;
pfn_glCopyImageSubDataOES fp_glCopyImageSubDataOES;
pfn_glEnableiOES fp_glEnableiOES;
pfn_glDisableiOES fp_glDisableiOES;
pfn_glBlendEquationiOES fp_glBlendEquationiOES;
pfn_glBlendEquationSeparateiOES fp_glBlendEquationSeparateiOES;
pfn_glBlendFunciOES fp_glBlendFunciOES;
pfn_glBlendFuncSeparateiOES fp_glBlendFuncSeparateiOES;
pfn_glColorMaskiOES fp_glColorMaskiOES;
pfn_glIsEnablediOES fp_glIsEnablediOES;
pfn_glDrawElementsBaseVertexOES fp_glDrawElementsBaseVertexOES;
pfn_glDrawRangeElementsBaseVertexOES fp_glDrawRangeElementsBaseVertexOES;
pfn_glDrawElementsInstancedBaseVertexOES fp_glDrawElementsInstancedBaseVertexOES;
pfn_glMultiDrawElementsBaseVertexOES fp_glMultiDrawElementsBaseVertexOES;
pfn_glEGLImageTargetTexture2DOES fp_glEGLImageTargetTexture2DOES;
pfn_glEGLImageTargetRenderbufferStorageOES fp_glEGLImageTargetRenderbufferStorageOES;
pfn_glFramebufferTextureOES fp_glFramebufferTextureOES;
pfn_glGetProgramBinaryOES fp_glGetProgramBinaryOES;
pfn_glProgramBinaryOES fp_glProgramBinaryOES;
pfn_glMapBufferOES fp_glMapBufferOES;
pfn_glUnmapBufferOES fp_glUnmapBufferOES;
pfn_glGetBufferPointervOES fp_glGetBufferPointervOES;
pfn_glPrimitiveBoundingBoxOES fp_glPrimitiveBoundingBoxOES;
pfn_glMinSampleShadingOES fp_glMinSampleShadingOES;
pfn_glPatchParameteriOES fp_glPatchParameteriOES;
pfn_glTexImage3DOES fp_glTexImage3DOES;
pfn_glTexSubImage3DOES fp_glTexSubImage3DOES;
pfn_glCopyTexSubImage3DOES fp_glCopyTexSubImage3DOES;
pfn_glCompressedTexImage3DOES fp_glCompressedTexImage3DOES;
pfn_glCompressedTexSubImage3DOES fp_glCompressedTexSubImage3DOES;
pfn_glFramebufferTexture3DOES fp_glFramebufferTexture3DOES;
pfn_glTexParameterIivOES fp_glTexParameterIivOES;
pfn_glTexParameterIuivOES fp_glTexParameterIuivOES;
pfn_glGetTexParameterIivOES fp_glGetTexParameterIivOES;
pfn_glGetTexParameterIuivOES fp_glGetTexParameterIuivOES;
pfn_glSamplerParameterIivOES fp_glSamplerParameterIivOES;
pfn_glSamplerParameterIuivOES fp_glSamplerParameterIuivOES;
pfn_glGetSamplerParameterIivOES fp_glGetSamplerParameterIivOES;
pfn_glGetSamplerParameterIuivOES fp_glGetSamplerParameterIuivOES;
pfn_glTexBufferOES fp_glTexBufferOES;
pfn_glTexBufferRangeOES fp_glTexBufferRangeOES;
pfn_glTexStorage3DMultisampleOES fp_glTexStorage3DMultisampleOES;
pfn_glTextureViewOES fp_glTextureViewOES;
pfn_glBindVertexArrayOES fp_glBindVertexArrayOES;
pfn_glDeleteVertexArraysOES fp_glDeleteVertexArraysOES;
pfn_glGenVertexArraysOES fp_glGenVertexArraysOES;
pfn_glIsVertexArrayOES fp_glIsVertexArrayOES;
pfn_glDebugMessageEnableAMD fp_glDebugMessageEnableAMD;
pfn_glDebugMessageInsertAMD fp_glDebugMessageInsertAMD;
pfn_glDebugMessageCallbackAMD fp_glDebugMessageCallbackAMD;
pfn_glGetDebugMessageLogAMD fp_glGetDebugMessageLogAMD;
pfn_glBlendFuncIndexedAMD fp_glBlendFuncIndexedAMD;
pfn_glBlendFuncSeparateIndexedAMD fp_glBlendFuncSeparateIndexedAMD;
pfn_glBlendEquationIndexedAMD fp_glBlendEquationIndexedAMD;
pfn_glBlendEquationSeparateIndexedAMD fp_glBlendEquationSeparateIndexedAMD;
pfn_glUniform1i64NV fp_glUniform1i64NV;
pfn_glUniform2i64NV fp_glUniform2i64NV;
pfn_glUniform3i64NV fp_glUniform3i64NV;
pfn_glUniform4i64NV fp_glUniform4i64NV;
pfn_glUniform1i64vNV fp_glUniform1i64vNV;
pfn_glUniform2i64vNV fp_glUniform2i64vNV;
pfn_glUniform3i64vNV fp_glUniform3i64vNV;
pfn_glUniform4i64vNV fp_glUniform4i64vNV;
pfn_glUniform1ui64NV fp_glUniform1ui64NV;
pfn_glUniform2ui64NV fp_glUniform2ui64NV;
pfn_glUniform3ui64NV fp_glUniform3ui64NV;
pfn_glUniform4ui64NV fp_glUniform4ui64NV;
pfn_glUniform1ui64vNV fp_glUniform1ui64vNV;
pfn_glUniform2ui64vNV fp_glUniform2ui64vNV;
pfn_glUniform3ui64vNV fp_glUniform3ui64vNV;
pfn_glUniform4ui64vNV fp_glUniform4ui64vNV;
pfn_glGetUniformi64vNV fp_glGetUniformi64vNV;
pfn_glGetUniformui64vNV fp_glGetUniformui64vNV;
pfn_glProgramUniform1i64NV fp_glProgramUniform1i64NV;
pfn_glProgramUniform2i64NV fp_glProgramUniform2i64NV;
pfn_glProgramUniform3i64NV fp_glProgramUniform3i64NV;
pfn_glProgramUniform4i64NV fp_glProgramUniform4i64NV;
pfn_glProgramUniform1i64vNV fp_glProgramUniform1i64vNV;
pfn_glProgramUniform2i64vNV fp_glProgramUniform2i64vNV;
pfn_glProgramUniform3i64vNV fp_glProgramUniform3i64vNV;
pfn_glProgramUniform4i64vNV fp_glProgramUniform4i64vNV;
pfn_glProgramUniform1ui64NV fp_glProgramUniform1ui64NV;
pfn_glProgramUniform2ui64NV fp_glProgramUniform2ui64NV;
pfn_glProgramUniform3ui64NV fp_glProgramUniform3ui64NV;
pfn_glProgramUniform4ui64NV fp_glProgramUniform4ui64NV;
pfn_glProgramUniform1ui64vNV fp_glProgramUniform1ui64vNV;
pfn_glProgramUniform2ui64vNV fp_glProgramUniform2ui64vNV;
pfn_glProgramUniform3ui64vNV fp_glProgramUniform3ui64vNV;
pfn_glProgramUniform4ui64vNV fp_glProgramUniform4ui64vNV;
pfn_glVertexAttribParameteriAMD fp_glVertexAttribParameteriAMD;
pfn_glMultiDrawArraysIndirectAMD fp_glMultiDrawArraysIndirectAMD;
pfn_glMultiDrawElementsIndirectAMD fp_glMultiDrawElementsIndirectAMD;
pfn_glGenNamesAMD fp_glGenNamesAMD;
pfn_glDeleteNamesAMD fp_glDeleteNamesAMD;
pfn_glIsNameAMD fp_glIsNameAMD;
pfn_glQueryObjectParameteruiAMD fp_glQueryObjectParameteruiAMD;
pfn_glGetPerfMonitorGroupsAMD fp_glGetPerfMonitorGroupsAMD;
pfn_glGetPerfMonitorCountersAMD fp_glGetPerfMonitorCountersAMD;
pfn_glGetPerfMonitorGroupStringAMD fp_glGetPerfMonitorGroupStringAMD;
pfn_glGetPerfMonitorCounterStringAMD fp_glGetPerfMonitorCounterStringAMD;
pfn_glGetPerfMonitorCounterInfoAMD fp_glGetPerfMonitorCounterInfoAMD;
pfn_glGenPerfMonitorsAMD fp_glGenPerfMonitorsAMD;
pfn_glDeletePerfMonitorsAMD fp_glDeletePerfMonitorsAMD;
pfn_glSelectPerfMonitorCountersAMD fp_glSelectPerfMonitorCountersAMD;
pfn_glBeginPerfMonitorAMD fp_glBeginPerfMonitorAMD;
pfn_glEndPerfMonitorAMD fp_glEndPerfMonitorAMD;
pfn_glGetPerfMonitorCounterDataAMD fp_glGetPerfMonitorCounterDataAMD;
pfn_glSetMultisamplefvAMD fp_glSetMultisamplefvAMD;
pfn_glTexStorageSparseAMD fp_glTexStorageSparseAMD;
pfn_glTextureStorageSparseAMD fp_glTextureStorageSparseAMD;
pfn_glStencilOpValueAMD fp_glStencilOpValueAMD;
pfn_glTessellationFactorAMD fp_glTessellationFactorAMD;
pfn_glTessellationModeAMD fp_glTessellationModeAMD;
pfn_glBlitFramebufferANGLE fp_glBlitFramebufferANGLE;
pfn_glRenderbufferStorageMultisampleANGLE fp_glRenderbufferStorageMultisampleANGLE;
pfn_glDrawArraysInstancedANGLE fp_glDrawArraysInstancedANGLE;
pfn_glDrawElementsInstancedANGLE fp_glDrawElementsInstancedANGLE;
pfn_glVertexAttribDivisorANGLE fp_glVertexAttribDivisorANGLE;
pfn_glGetTranslatedShaderSourceANGLE fp_glGetTranslatedShaderSourceANGLE;
pfn_glCopyTextureLevelsAPPLE fp_glCopyTextureLevelsAPPLE;
pfn_glElementPointerAPPLE fp_glElementPointerAPPLE;
pfn_glDrawElementArrayAPPLE fp_glDrawElementArrayAPPLE;
pfn_glDrawRangeElementArrayAPPLE fp_glDrawRangeElementArrayAPPLE;
pfn_glMultiDrawElementArrayAPPLE fp_glMultiDrawElementArrayAPPLE;
pfn_glMultiDrawRangeElementArrayAPPLE fp_glMultiDrawRangeElementArrayAPPLE;
pfn_glGenFencesAPPLE fp_glGenFencesAPPLE;
pfn_glDeleteFencesAPPLE fp_glDeleteFencesAPPLE;
pfn_glSetFenceAPPLE fp_glSetFenceAPPLE;
pfn_glIsFenceAPPLE fp_glIsFenceAPPLE;
pfn_glTestFenceAPPLE fp_glTestFenceAPPLE;
pfn_glFinishFenceAPPLE fp_glFinishFenceAPPLE;
pfn_glTestObjectAPPLE fp_glTestObjectAPPLE;
pfn_glFinishObjectAPPLE fp_glFinishObjectAPPLE;
pfn_glBufferParameteriAPPLE fp_glBufferParameteriAPPLE;
pfn_glFlushMappedBufferRangeAPPLE fp_glFlushMappedBufferRangeAPPLE;
pfn_glRenderbufferStorageMultisampleAPPLE fp_glRenderbufferStorageMultisampleAPPLE;
pfn_glResolveMultisampleFramebufferAPPLE fp_glResolveMultisampleFramebufferAPPLE;
pfn_glObjectPurgeableAPPLE fp_glObjectPurgeableAPPLE;
pfn_glObjectUnpurgeableAPPLE fp_glObjectUnpurgeableAPPLE;
pfn_glGetObjectParameterivAPPLE fp_glGetObjectParameterivAPPLE;
pfn_glFenceSyncAPPLE fp_glFenceSyncAPPLE;
pfn_glIsSyncAPPLE fp_glIsSyncAPPLE;
pfn_glDeleteSyncAPPLE fp_glDeleteSyncAPPLE;
pfn_glClientWaitSyncAPPLE fp_glClientWaitSyncAPPLE;
pfn_glWaitSyncAPPLE fp_glWaitSyncAPPLE;
pfn_glGetInteger64vAPPLE fp_glGetInteger64vAPPLE;
pfn_glGetSyncivAPPLE fp_glGetSyncivAPPLE;
pfn_glTextureRangeAPPLE fp_glTextureRangeAPPLE;
pfn_glGetTexParameterPointervAPPLE fp_glGetTexParameterPointervAPPLE;
pfn_glBindVertexArrayAPPLE fp_glBindVertexArrayAPPLE;
pfn_glDeleteVertexArraysAPPLE fp_glDeleteVertexArraysAPPLE;
pfn_glGenVertexArraysAPPLE fp_glGenVertexArraysAPPLE;
pfn_glIsVertexArrayAPPLE fp_glIsVertexArrayAPPLE;
pfn_glVertexArrayRangeAPPLE fp_glVertexArrayRangeAPPLE;
pfn_glFlushVertexArrayRangeAPPLE fp_glFlushVertexArrayRangeAPPLE;
pfn_glVertexArrayParameteriAPPLE fp_glVertexArrayParameteriAPPLE;
pfn_glEnableVertexAttribAPPLE fp_glEnableVertexAttribAPPLE;
pfn_glDisableVertexAttribAPPLE fp_glDisableVertexAttribAPPLE;
pfn_glIsVertexAttribEnabledAPPLE fp_glIsVertexAttribEnabledAPPLE;
pfn_glMapVertexAttrib1dAPPLE fp_glMapVertexAttrib1dAPPLE;
pfn_glMapVertexAttrib1fAPPLE fp_glMapVertexAttrib1fAPPLE;
pfn_glMapVertexAttrib2dAPPLE fp_glMapVertexAttrib2dAPPLE;
pfn_glMapVertexAttrib2fAPPLE fp_glMapVertexAttrib2fAPPLE;
pfn_glFrameTerminatorGREMEDY fp_glFrameTerminatorGREMEDY;
pfn_glStringMarkerGREMEDY fp_glStringMarkerGREMEDY;
pfn_glRenderbufferStorageMultisampleIMG fp_glRenderbufferStorageMultisampleIMG;
pfn_glFramebufferTexture2DMultisampleIMG fp_glFramebufferTexture2DMultisampleIMG;
pfn_glBlendFuncSeparateINGR fp_glBlendFuncSeparateINGR;
pfn_glApplyFramebufferAttachmentCMAAINTEL fp_glApplyFramebufferAttachmentCMAAINTEL;
pfn_glSyncTextureINTEL fp_glSyncTextureINTEL;
pfn_glUnmapTexture2DINTEL fp_glUnmapTexture2DINTEL;
pfn_glMapTexture2DINTEL fp_glMapTexture2DINTEL;
pfn_glBeginPerfQueryINTEL fp_glBeginPerfQueryINTEL;
pfn_glCreatePerfQueryINTEL fp_glCreatePerfQueryINTEL;
pfn_glDeletePerfQueryINTEL fp_glDeletePerfQueryINTEL;
pfn_glEndPerfQueryINTEL fp_glEndPerfQueryINTEL;
pfn_glGetFirstPerfQueryIdINTEL fp_glGetFirstPerfQueryIdINTEL;
pfn_glGetNextPerfQueryIdINTEL fp_glGetNextPerfQueryIdINTEL;
pfn_glGetPerfCounterInfoINTEL fp_glGetPerfCounterInfoINTEL;
pfn_glGetPerfQueryDataINTEL fp_glGetPerfQueryDataINTEL;
pfn_glGetPerfQueryIdByNameINTEL fp_glGetPerfQueryIdByNameINTEL;
pfn_glGetPerfQueryInfoINTEL fp_glGetPerfQueryInfoINTEL;
pfn_glMultiDrawArraysIndirectBindlessNV fp_glMultiDrawArraysIndirectBindlessNV;
pfn_glMultiDrawElementsIndirectBindlessNV fp_glMultiDrawElementsIndirectBindlessNV;
pfn_glMultiDrawArraysIndirectBindlessCountNV fp_glMultiDrawArraysIndirectBindlessCountNV;
pfn_glMultiDrawElementsIndirectBindlessCountNV fp_glMultiDrawElementsIndirectBindlessCountNV;
pfn_glGetTextureHandleNV fp_glGetTextureHandleNV;
pfn_glGetTextureSamplerHandleNV fp_glGetTextureSamplerHandleNV;
pfn_glMakeTextureHandleResidentNV fp_glMakeTextureHandleResidentNV;
pfn_glMakeTextureHandleNonResidentNV fp_glMakeTextureHandleNonResidentNV;
pfn_glGetImageHandleNV fp_glGetImageHandleNV;
pfn_glMakeImageHandleResidentNV fp_glMakeImageHandleResidentNV;
pfn_glMakeImageHandleNonResidentNV fp_glMakeImageHandleNonResidentNV;
pfn_glUniformHandleui64NV fp_glUniformHandleui64NV;
pfn_glUniformHandleui64vNV fp_glUniformHandleui64vNV;
pfn_glProgramUniformHandleui64NV fp_glProgramUniformHandleui64NV;
pfn_glProgramUniformHandleui64vNV fp_glProgramUniformHandleui64vNV;
pfn_glIsTextureHandleResidentNV fp_glIsTextureHandleResidentNV;
pfn_glIsImageHandleResidentNV fp_glIsImageHandleResidentNV;
pfn_glBlendParameteriNV fp_glBlendParameteriNV;
pfn_glBlendBarrierNV fp_glBlendBarrierNV;
pfn_glCreateStatesNV fp_glCreateStatesNV;
pfn_glDeleteStatesNV fp_glDeleteStatesNV;
pfn_glIsStateNV fp_glIsStateNV;
pfn_glStateCaptureNV fp_glStateCaptureNV;
pfn_glGetCommandHeaderNV fp_glGetCommandHeaderNV;
pfn_glGetStageIndexNV fp_glGetStageIndexNV;
pfn_glDrawCommandsNV fp_glDrawCommandsNV;
pfn_glDrawCommandsAddressNV fp_glDrawCommandsAddressNV;
pfn_glDrawCommandsStatesNV fp_glDrawCommandsStatesNV;
pfn_glDrawCommandsStatesAddressNV fp_glDrawCommandsStatesAddressNV;
pfn_glCreateCommandListsNV fp_glCreateCommandListsNV;
pfn_glDeleteCommandListsNV fp_glDeleteCommandListsNV;
pfn_glIsCommandListNV fp_glIsCommandListNV;
pfn_glListDrawCommandsStatesClientNV fp_glListDrawCommandsStatesClientNV;
pfn_glCommandListSegmentsNV fp_glCommandListSegmentsNV;
pfn_glCompileCommandListNV fp_glCompileCommandListNV;
pfn_glCallCommandListNV fp_glCallCommandListNV;
pfn_glBeginConditionalRenderNV fp_glBeginConditionalRenderNV;
pfn_glEndConditionalRenderNV fp_glEndConditionalRenderNV;
pfn_glSubpixelPrecisionBiasNV fp_glSubpixelPrecisionBiasNV;
pfn_glConservativeRasterParameterfNV fp_glConservativeRasterParameterfNV;
pfn_glCopyBufferSubDataNV fp_glCopyBufferSubDataNV;
pfn_glCopyImageSubDataNV fp_glCopyImageSubDataNV;
pfn_glCoverageMaskNV fp_glCoverageMaskNV;
pfn_glCoverageOperationNV fp_glCoverageOperationNV;
pfn_glDepthRangedNV fp_glDepthRangedNV;
pfn_glClearDepthdNV fp_glClearDepthdNV;
pfn_glDepthBoundsdNV fp_glDepthBoundsdNV;
pfn_glDrawBuffersNV fp_glDrawBuffersNV;
pfn_glDrawArraysInstancedNV fp_glDrawArraysInstancedNV;
pfn_glDrawElementsInstancedNV fp_glDrawElementsInstancedNV;
pfn_glDrawTextureNV fp_glDrawTextureNV;
pfn_glGetMultisamplefvNV fp_glGetMultisamplefvNV;
pfn_glSampleMaskIndexedNV fp_glSampleMaskIndexedNV;
pfn_glTexRenderbufferNV fp_glTexRenderbufferNV;
pfn_glDeleteFencesNV fp_glDeleteFencesNV;
pfn_glGenFencesNV fp_glGenFencesNV;
pfn_glIsFenceNV fp_glIsFenceNV;
pfn_glTestFenceNV fp_glTestFenceNV;
pfn_glGetFenceivNV fp_glGetFenceivNV;
pfn_glFinishFenceNV fp_glFinishFenceNV;
pfn_glSetFenceNV fp_glSetFenceNV;
pfn_glFragmentCoverageColorNV fp_glFragmentCoverageColorNV;
pfn_glBlitFramebufferNV fp_glBlitFramebufferNV;
pfn_glCoverageModulationTableNV fp_glCoverageModulationTableNV;
pfn_glGetCoverageModulationTableNV fp_glGetCoverageModulationTableNV;
pfn_glCoverageModulationNV fp_glCoverageModulationNV;
pfn_glRenderbufferStorageMultisampleNV fp_glRenderbufferStorageMultisampleNV;
pfn_glRenderbufferStorageMultisampleCoverageNV fp_glRenderbufferStorageMultisampleCoverageNV;
pfn_glProgramVertexLimitNV fp_glProgramVertexLimitNV;
pfn_glFramebufferTextureFaceEXT fp_glFramebufferTextureFaceEXT;
pfn_glProgramLocalParameterI4iNV fp_glProgramLocalParameterI4iNV;
pfn_glProgramLocalParameterI4ivNV fp_glProgramLocalParameterI4ivNV;
pfn_glProgramLocalParametersI4ivNV fp_glProgramLocalParametersI4ivNV;
pfn_glProgramLocalParameterI4uiNV fp_glProgramLocalParameterI4uiNV;
pfn_glProgramLocalParameterI4uivNV fp_glProgramLocalParameterI4uivNV;
pfn_glProgramLocalParametersI4uivNV fp_glProgramLocalParametersI4uivNV;
pfn_glProgramEnvParameterI4iNV fp_glProgramEnvParameterI4iNV;
pfn_glProgramEnvParameterI4ivNV fp_glProgramEnvParameterI4ivNV;
pfn_glProgramEnvParametersI4ivNV fp_glProgramEnvParametersI4ivNV;
pfn_glProgramEnvParameterI4uiNV fp_glProgramEnvParameterI4uiNV;
pfn_glProgramEnvParameterI4uivNV fp_glProgramEnvParameterI4uivNV;
pfn_glProgramEnvParametersI4uivNV fp_glProgramEnvParametersI4uivNV;
pfn_glGetProgramLocalParameterIivNV fp_glGetProgramLocalParameterIivNV;
pfn_glGetProgramLocalParameterIuivNV fp_glGetProgramLocalParameterIuivNV;
pfn_glGetProgramEnvParameterIivNV fp_glGetProgramEnvParameterIivNV;
pfn_glGetProgramEnvParameterIuivNV fp_glGetProgramEnvParameterIuivNV;
pfn_glProgramSubroutineParametersuivNV fp_glProgramSubroutineParametersuivNV;
pfn_glGetProgramSubroutineParameteruivNV fp_glGetProgramSubroutineParameteruivNV;
pfn_glVertex2hNV fp_glVertex2hNV;
pfn_glVertex2hvNV fp_glVertex2hvNV;
pfn_glVertex3hNV fp_glVertex3hNV;
pfn_glVertex3hvNV fp_glVertex3hvNV;
pfn_glVertex4hNV fp_glVertex4hNV;
pfn_glVertex4hvNV fp_glVertex4hvNV;
pfn_glNormal3hNV fp_glNormal3hNV;
pfn_glNormal3hvNV fp_glNormal3hvNV;
pfn_glColor3hNV fp_glColor3hNV;
pfn_glColor3hvNV fp_glColor3hvNV;
pfn_glColor4hNV fp_glColor4hNV;
pfn_glColor4hvNV fp_glColor4hvNV;
pfn_glTexCoord1hNV fp_glTexCoord1hNV;
pfn_glTexCoord1hvNV fp_glTexCoord1hvNV;
pfn_glTexCoord2hNV fp_glTexCoord2hNV;
pfn_glTexCoord2hvNV fp_glTexCoord2hvNV;
pfn_glTexCoord3hNV fp_glTexCoord3hNV;
pfn_glTexCoord3hvNV fp_glTexCoord3hvNV;
pfn_glTexCoord4hNV fp_glTexCoord4hNV;
pfn_glTexCoord4hvNV fp_glTexCoord4hvNV;
pfn_glMultiTexCoord1hNV fp_glMultiTexCoord1hNV;
pfn_glMultiTexCoord1hvNV fp_glMultiTexCoord1hvNV;
pfn_glMultiTexCoord2hNV fp_glMultiTexCoord2hNV;
pfn_glMultiTexCoord2hvNV fp_glMultiTexCoord2hvNV;
pfn_glMultiTexCoord3hNV fp_glMultiTexCoord3hNV;
pfn_glMultiTexCoord3hvNV fp_glMultiTexCoord3hvNV;
pfn_glMultiTexCoord4hNV fp_glMultiTexCoord4hNV;
pfn_glMultiTexCoord4hvNV fp_glMultiTexCoord4hvNV;
pfn_glFogCoordhNV fp_glFogCoordhNV;
pfn_glFogCoordhvNV fp_glFogCoordhvNV;
pfn_glSecondaryColor3hNV fp_glSecondaryColor3hNV;
pfn_glSecondaryColor3hvNV fp_glSecondaryColor3hvNV;
pfn_glVertexWeighthNV fp_glVertexWeighthNV;
pfn_glVertexWeighthvNV fp_glVertexWeighthvNV;
pfn_glVertexAttrib1hNV fp_glVertexAttrib1hNV;
pfn_glVertexAttrib1hvNV fp_glVertexAttrib1hvNV;
pfn_glVertexAttrib2hNV fp_glVertexAttrib2hNV;
pfn_glVertexAttrib2hvNV fp_glVertexAttrib2hvNV;
pfn_glVertexAttrib3hNV fp_glVertexAttrib3hNV;
pfn_glVertexAttrib3hvNV fp_glVertexAttrib3hvNV;
pfn_glVertexAttrib4hNV fp_glVertexAttrib4hNV;
pfn_glVertexAttrib4hvNV fp_glVertexAttrib4hvNV;
pfn_glVertexAttribs1hvNV fp_glVertexAttribs1hvNV;
pfn_glVertexAttribs2hvNV fp_glVertexAttribs2hvNV;
pfn_glVertexAttribs3hvNV fp_glVertexAttribs3hvNV;
pfn_glVertexAttribs4hvNV fp_glVertexAttribs4hvNV;
pfn_glVertexAttribDivisorNV fp_glVertexAttribDivisorNV;
pfn_glGetInternalformatSampleivNV fp_glGetInternalformatSampleivNV;
pfn_glUniformMatrix2x3fvNV fp_glUniformMatrix2x3fvNV;
pfn_glUniformMatrix3x2fvNV fp_glUniformMatrix3x2fvNV;
pfn_glUniformMatrix2x4fvNV fp_glUniformMatrix2x4fvNV;
pfn_glUniformMatrix4x2fvNV fp_glUniformMatrix4x2fvNV;
pfn_glUniformMatrix3x4fvNV fp_glUniformMatrix3x4fvNV;
pfn_glUniformMatrix4x3fvNV fp_glUniformMatrix4x3fvNV;
pfn_glGenOcclusionQueriesNV fp_glGenOcclusionQueriesNV;
pfn_glDeleteOcclusionQueriesNV fp_glDeleteOcclusionQueriesNV;
pfn_glIsOcclusionQueryNV fp_glIsOcclusionQueryNV;
pfn_glBeginOcclusionQueryNV fp_glBeginOcclusionQueryNV;
pfn_glEndOcclusionQueryNV fp_glEndOcclusionQueryNV;
pfn_glGetOcclusionQueryivNV fp_glGetOcclusionQueryivNV;
pfn_glGetOcclusionQueryuivNV fp_glGetOcclusionQueryuivNV;
pfn_glProgramBufferParametersfvNV fp_glProgramBufferParametersfvNV;
pfn_glProgramBufferParametersIivNV fp_glProgramBufferParametersIivNV;
pfn_glProgramBufferParametersIuivNV fp_glProgramBufferParametersIuivNV;
pfn_glGenPathsNV fp_glGenPathsNV;
pfn_glDeletePathsNV fp_glDeletePathsNV;
pfn_glIsPathNV fp_glIsPathNV;
pfn_glPathCommandsNV fp_glPathCommandsNV;
pfn_glPathCoordsNV fp_glPathCoordsNV;
pfn_glPathSubCommandsNV fp_glPathSubCommandsNV;
pfn_glPathSubCoordsNV fp_glPathSubCoordsNV;
pfn_glPathStringNV fp_glPathStringNV;
pfn_glPathGlyphsNV fp_glPathGlyphsNV;
pfn_glPathGlyphRangeNV fp_glPathGlyphRangeNV;
pfn_glWeightPathsNV fp_glWeightPathsNV;
pfn_glCopyPathNV fp_glCopyPathNV;
pfn_glInterpolatePathsNV fp_glInterpolatePathsNV;
pfn_glTransformPathNV fp_glTransformPathNV;
pfn_glPathParameterivNV fp_glPathParameterivNV;
pfn_glPathParameteriNV fp_glPathParameteriNV;
pfn_glPathParameterfvNV fp_glPathParameterfvNV;
pfn_glPathParameterfNV fp_glPathParameterfNV;
pfn_glPathDashArrayNV fp_glPathDashArrayNV;
pfn_glPathStencilFuncNV fp_glPathStencilFuncNV;
pfn_glPathStencilDepthOffsetNV fp_glPathStencilDepthOffsetNV;
pfn_glStencilFillPathNV fp_glStencilFillPathNV;
pfn_glStencilStrokePathNV fp_glStencilStrokePathNV;
pfn_glStencilFillPathInstancedNV fp_glStencilFillPathInstancedNV;
pfn_glStencilStrokePathInstancedNV fp_glStencilStrokePathInstancedNV;
pfn_glPathCoverDepthFuncNV fp_glPathCoverDepthFuncNV;
pfn_glCoverFillPathNV fp_glCoverFillPathNV;
pfn_glCoverStrokePathNV fp_glCoverStrokePathNV;
pfn_glCoverFillPathInstancedNV fp_glCoverFillPathInstancedNV;
pfn_glCoverStrokePathInstancedNV fp_glCoverStrokePathInstancedNV;
pfn_glGetPathParameterivNV fp_glGetPathParameterivNV;
pfn_glGetPathParameterfvNV fp_glGetPathParameterfvNV;
pfn_glGetPathCommandsNV fp_glGetPathCommandsNV;
pfn_glGetPathCoordsNV fp_glGetPathCoordsNV;
pfn_glGetPathDashArrayNV fp_glGetPathDashArrayNV;
pfn_glGetPathMetricsNV fp_glGetPathMetricsNV;
pfn_glGetPathMetricRangeNV fp_glGetPathMetricRangeNV;
pfn_glGetPathSpacingNV fp_glGetPathSpacingNV;
pfn_glIsPointInFillPathNV fp_glIsPointInFillPathNV;
pfn_glIsPointInStrokePathNV fp_glIsPointInStrokePathNV;
pfn_glGetPathLengthNV fp_glGetPathLengthNV;
pfn_glPointAlongPathNV fp_glPointAlongPathNV;
pfn_glMatrixLoad3x2fNV fp_glMatrixLoad3x2fNV;
pfn_glMatrixLoad3x3fNV fp_glMatrixLoad3x3fNV;
pfn_glMatrixLoadTranspose3x3fNV fp_glMatrixLoadTranspose3x3fNV;
pfn_glMatrixMult3x2fNV fp_glMatrixMult3x2fNV;
pfn_glMatrixMult3x3fNV fp_glMatrixMult3x3fNV;
pfn_glMatrixMultTranspose3x3fNV fp_glMatrixMultTranspose3x3fNV;
pfn_glStencilThenCoverFillPathNV fp_glStencilThenCoverFillPathNV;
pfn_glStencilThenCoverStrokePathNV fp_glStencilThenCoverStrokePathNV;
pfn_glStencilThenCoverFillPathInstancedNV fp_glStencilThenCoverFillPathInstancedNV;
pfn_glStencilThenCoverStrokePathInstancedNV fp_glStencilThenCoverStrokePathInstancedNV;
pfn_glPathGlyphIndexRangeNV fp_glPathGlyphIndexRangeNV;
pfn_glPathGlyphIndexArrayNV fp_glPathGlyphIndexArrayNV;
pfn_glPathMemoryGlyphIndexArrayNV fp_glPathMemoryGlyphIndexArrayNV;
pfn_glProgramPathFragmentInputGenNV fp_glProgramPathFragmentInputGenNV;
pfn_glGetProgramResourcefvNV fp_glGetProgramResourcefvNV;
pfn_glPathColorGenNV fp_glPathColorGenNV;
pfn_glPathTexGenNV fp_glPathTexGenNV;
pfn_glPathFogGenNV fp_glPathFogGenNV;
pfn_glGetPathColorGenivNV fp_glGetPathColorGenivNV;
pfn_glGetPathColorGenfvNV fp_glGetPathColorGenfvNV;
pfn_glGetPathTexGenivNV fp_glGetPathTexGenivNV;
pfn_glGetPathTexGenfvNV fp_glGetPathTexGenfvNV;
pfn_glPolygonModeNV fp_glPolygonModeNV;
pfn_glPresentFrameKeyedNV fp_glPresentFrameKeyedNV;
pfn_glPresentFrameDualFillNV fp_glPresentFrameDualFillNV;
pfn_glGetVideoivNV fp_glGetVideoivNV;
pfn_glGetVideouivNV fp_glGetVideouivNV;
pfn_glGetVideoi64vNV fp_glGetVideoi64vNV;
pfn_glGetVideoui64vNV fp_glGetVideoui64vNV;
pfn_glPrimitiveRestartNV fp_glPrimitiveRestartNV;
pfn_glPrimitiveRestartIndexNV fp_glPrimitiveRestartIndexNV;
pfn_glReadBufferNV fp_glReadBufferNV;
pfn_glFramebufferSampleLocationsfvNV fp_glFramebufferSampleLocationsfvNV;
pfn_glNamedFramebufferSampleLocationsfvNV fp_glNamedFramebufferSampleLocationsfvNV;
pfn_glResolveDepthValuesNV fp_glResolveDepthValuesNV;
pfn_glMakeBufferResidentNV fp_glMakeBufferResidentNV;
pfn_glMakeBufferNonResidentNV fp_glMakeBufferNonResidentNV;
pfn_glIsBufferResidentNV fp_glIsBufferResidentNV;
pfn_glMakeNamedBufferResidentNV fp_glMakeNamedBufferResidentNV;
pfn_glMakeNamedBufferNonResidentNV fp_glMakeNamedBufferNonResidentNV;
pfn_glIsNamedBufferResidentNV fp_glIsNamedBufferResidentNV;
pfn_glGetBufferParameterui64vNV fp_glGetBufferParameterui64vNV;
pfn_glGetNamedBufferParameterui64vNV fp_glGetNamedBufferParameterui64vNV;
pfn_glGetIntegerui64vNV fp_glGetIntegerui64vNV;
pfn_glUniformui64NV fp_glUniformui64NV;
pfn_glUniformui64vNV fp_glUniformui64vNV;
pfn_glProgramUniformui64NV fp_glProgramUniformui64NV;
pfn_glProgramUniformui64vNV fp_glProgramUniformui64vNV;
pfn_glTextureBarrierNV fp_glTextureBarrierNV;
pfn_glTexImage2DMultisampleCoverageNV fp_glTexImage2DMultisampleCoverageNV;
pfn_glTexImage3DMultisampleCoverageNV fp_glTexImage3DMultisampleCoverageNV;
pfn_glTextureImage2DMultisampleNV fp_glTextureImage2DMultisampleNV;
pfn_glTextureImage3DMultisampleNV fp_glTextureImage3DMultisampleNV;
pfn_glTextureImage2DMultisampleCoverageNV fp_glTextureImage2DMultisampleCoverageNV;
pfn_glTextureImage3DMultisampleCoverageNV fp_glTextureImage3DMultisampleCoverageNV;
pfn_glBeginTransformFeedbackNV fp_glBeginTransformFeedbackNV;
pfn_glEndTransformFeedbackNV fp_glEndTransformFeedbackNV;
pfn_glTransformFeedbackAttribsNV fp_glTransformFeedbackAttribsNV;
pfn_glBindBufferRangeNV fp_glBindBufferRangeNV;
pfn_glBindBufferOffsetNV fp_glBindBufferOffsetNV;
pfn_glBindBufferBaseNV fp_glBindBufferBaseNV;
pfn_glTransformFeedbackVaryingsNV fp_glTransformFeedbackVaryingsNV;
pfn_glActiveVaryingNV fp_glActiveVaryingNV;
pfn_glGetVaryingLocationNV fp_glGetVaryingLocationNV;
pfn_glGetActiveVaryingNV fp_glGetActiveVaryingNV;
pfn_glGetTransformFeedbackVaryingNV fp_glGetTransformFeedbackVaryingNV;
pfn_glTransformFeedbackStreamAttribsNV fp_glTransformFeedbackStreamAttribsNV;
pfn_glBindTransformFeedbackNV fp_glBindTransformFeedbackNV;
pfn_glDeleteTransformFeedbacksNV fp_glDeleteTransformFeedbacksNV;
pfn_glGenTransformFeedbacksNV fp_glGenTransformFeedbacksNV;
pfn_glIsTransformFeedbackNV fp_glIsTransformFeedbackNV;
pfn_glPauseTransformFeedbackNV fp_glPauseTransformFeedbackNV;
pfn_glResumeTransformFeedbackNV fp_glResumeTransformFeedbackNV;
pfn_glDrawTransformFeedbackNV fp_glDrawTransformFeedbackNV;
pfn_glVDPAUInitNV fp_glVDPAUInitNV;
pfn_glVDPAUFiniNV fp_glVDPAUFiniNV;
pfn_glVDPAURegisterVideoSurfaceNV fp_glVDPAURegisterVideoSurfaceNV;
pfn_glVDPAURegisterOutputSurfaceNV fp_glVDPAURegisterOutputSurfaceNV;
pfn_glVDPAUIsSurfaceNV fp_glVDPAUIsSurfaceNV;
pfn_glVDPAUUnregisterSurfaceNV fp_glVDPAUUnregisterSurfaceNV;
pfn_glVDPAUGetSurfaceivNV fp_glVDPAUGetSurfaceivNV;
pfn_glVDPAUSurfaceAccessNV fp_glVDPAUSurfaceAccessNV;
pfn_glVDPAUMapSurfacesNV fp_glVDPAUMapSurfacesNV;
pfn_glVDPAUUnmapSurfacesNV fp_glVDPAUUnmapSurfacesNV;
pfn_glVertexAttribL1i64NV fp_glVertexAttribL1i64NV;
pfn_glVertexAttribL2i64NV fp_glVertexAttribL2i64NV;
pfn_glVertexAttribL3i64NV fp_glVertexAttribL3i64NV;
pfn_glVertexAttribL4i64NV fp_glVertexAttribL4i64NV;
pfn_glVertexAttribL1i64vNV fp_glVertexAttribL1i64vNV;
pfn_glVertexAttribL2i64vNV fp_glVertexAttribL2i64vNV;
pfn_glVertexAttribL3i64vNV fp_glVertexAttribL3i64vNV;
pfn_glVertexAttribL4i64vNV fp_glVertexAttribL4i64vNV;
pfn_glVertexAttribL1ui64NV fp_glVertexAttribL1ui64NV;
pfn_glVertexAttribL2ui64NV fp_glVertexAttribL2ui64NV;
pfn_glVertexAttribL3ui64NV fp_glVertexAttribL3ui64NV;
pfn_glVertexAttribL4ui64NV fp_glVertexAttribL4ui64NV;
pfn_glVertexAttribL1ui64vNV fp_glVertexAttribL1ui64vNV;
pfn_glVertexAttribL2ui64vNV fp_glVertexAttribL2ui64vNV;
pfn_glVertexAttribL3ui64vNV fp_glVertexAttribL3ui64vNV;
pfn_glVertexAttribL4ui64vNV fp_glVertexAttribL4ui64vNV;
pfn_glGetVertexAttribLi64vNV fp_glGetVertexAttribLi64vNV;
pfn_glGetVertexAttribLui64vNV fp_glGetVertexAttribLui64vNV;
pfn_glVertexAttribLFormatNV fp_glVertexAttribLFormatNV;
pfn_glBufferAddressRangeNV fp_glBufferAddressRangeNV;
pfn_glVertexFormatNV fp_glVertexFormatNV;
pfn_glNormalFormatNV fp_glNormalFormatNV;
pfn_glColorFormatNV fp_glColorFormatNV;
pfn_glIndexFormatNV fp_glIndexFormatNV;
pfn_glTexCoordFormatNV fp_glTexCoordFormatNV;
pfn_glEdgeFlagFormatNV fp_glEdgeFlagFormatNV;
pfn_glSecondaryColorFormatNV fp_glSecondaryColorFormatNV;
pfn_glFogCoordFormatNV fp_glFogCoordFormatNV;
pfn_glVertexAttribFormatNV fp_glVertexAttribFormatNV;
pfn_glVertexAttribIFormatNV fp_glVertexAttribIFormatNV;
pfn_glGetIntegerui64i_vNV fp_glGetIntegerui64i_vNV;
pfn_glVertexAttribI1iEXT fp_glVertexAttribI1iEXT;
pfn_glVertexAttribI2iEXT fp_glVertexAttribI2iEXT;
pfn_glVertexAttribI3iEXT fp_glVertexAttribI3iEXT;
pfn_glVertexAttribI4iEXT fp_glVertexAttribI4iEXT;
pfn_glVertexAttribI1uiEXT fp_glVertexAttribI1uiEXT;
pfn_glVertexAttribI2uiEXT fp_glVertexAttribI2uiEXT;
pfn_glVertexAttribI3uiEXT fp_glVertexAttribI3uiEXT;
pfn_glVertexAttribI4uiEXT fp_glVertexAttribI4uiEXT;
pfn_glVertexAttribI1ivEXT fp_glVertexAttribI1ivEXT;
pfn_glVertexAttribI2ivEXT fp_glVertexAttribI2ivEXT;
pfn_glVertexAttribI3ivEXT fp_glVertexAttribI3ivEXT;
pfn_glVertexAttribI4ivEXT fp_glVertexAttribI4ivEXT;
pfn_glVertexAttribI1uivEXT fp_glVertexAttribI1uivEXT;
pfn_glVertexAttribI2uivEXT fp_glVertexAttribI2uivEXT;
pfn_glVertexAttribI3uivEXT fp_glVertexAttribI3uivEXT;
pfn_glVertexAttribI4uivEXT fp_glVertexAttribI4uivEXT;
pfn_glVertexAttribI4bvEXT fp_glVertexAttribI4bvEXT;
pfn_glVertexAttribI4svEXT fp_glVertexAttribI4svEXT;
pfn_glVertexAttribI4ubvEXT fp_glVertexAttribI4ubvEXT;
pfn_glVertexAttribI4usvEXT fp_glVertexAttribI4usvEXT;
pfn_glVertexAttribIPointerEXT fp_glVertexAttribIPointerEXT;
pfn_glGetVertexAttribIivEXT fp_glGetVertexAttribIivEXT;
pfn_glGetVertexAttribIuivEXT fp_glGetVertexAttribIuivEXT;
pfn_glBeginVideoCaptureNV fp_glBeginVideoCaptureNV;
pfn_glBindVideoCaptureStreamBufferNV fp_glBindVideoCaptureStreamBufferNV;
pfn_glBindVideoCaptureStreamTextureNV fp_glBindVideoCaptureStreamTextureNV;
pfn_glEndVideoCaptureNV fp_glEndVideoCaptureNV;
pfn_glGetVideoCaptureivNV fp_glGetVideoCaptureivNV;
pfn_glGetVideoCaptureStreamivNV fp_glGetVideoCaptureStreamivNV;
pfn_glGetVideoCaptureStreamfvNV fp_glGetVideoCaptureStreamfvNV;
pfn_glGetVideoCaptureStreamdvNV fp_glGetVideoCaptureStreamdvNV;
pfn_glVideoCaptureNV fp_glVideoCaptureNV;
pfn_glVideoCaptureStreamParameterivNV fp_glVideoCaptureStreamParameterivNV;
pfn_glVideoCaptureStreamParameterfvNV fp_glVideoCaptureStreamParameterfvNV;
pfn_glVideoCaptureStreamParameterdvNV fp_glVideoCaptureStreamParameterdvNV;
pfn_glViewportArrayvNV fp_glViewportArrayvNV;
pfn_glViewportIndexedfNV fp_glViewportIndexedfNV;
pfn_glViewportIndexedfvNV fp_glViewportIndexedfvNV;
pfn_glScissorArrayvNV fp_glScissorArrayvNV;
pfn_glScissorIndexedNV fp_glScissorIndexedNV;
pfn_glScissorIndexedvNV fp_glScissorIndexedvNV;
pfn_glDepthRangeArrayfvNV fp_glDepthRangeArrayfvNV;
pfn_glDepthRangeIndexedfNV fp_glDepthRangeIndexedfNV;
pfn_glGetFloati_vNV fp_glGetFloati_vNV;
pfn_glEnableiNV fp_glEnableiNV;
pfn_glDisableiNV fp_glDisableiNV;
pfn_glIsEnablediNV fp_glIsEnablediNV;
pfn_glBeginConditionalRenderNVX fp_glBeginConditionalRenderNVX;
pfn_glEndConditionalRenderNVX fp_glEndConditionalRenderNVX;
pfn_glFramebufferTextureMultiviewOVR fp_glFramebufferTextureMultiviewOVR;
pfn_glFramebufferTextureMultisampleMultiviewOVR fp_glFramebufferTextureMultisampleMultiviewOVR;
pfn_glAlphaFuncQCOM fp_glAlphaFuncQCOM;
pfn_glGetDriverControlsQCOM fp_glGetDriverControlsQCOM;
pfn_glGetDriverControlStringQCOM fp_glGetDriverControlStringQCOM;
pfn_glEnableDriverControlQCOM fp_glEnableDriverControlQCOM;
pfn_glDisableDriverControlQCOM fp_glDisableDriverControlQCOM;
pfn_glExtGetTexturesQCOM fp_glExtGetTexturesQCOM;
pfn_glExtGetBuffersQCOM fp_glExtGetBuffersQCOM;
pfn_glExtGetRenderbuffersQCOM fp_glExtGetRenderbuffersQCOM;
pfn_glExtGetFramebuffersQCOM fp_glExtGetFramebuffersQCOM;
pfn_glExtGetTexLevelParameterivQCOM fp_glExtGetTexLevelParameterivQCOM;
pfn_glExtTexObjectStateOverrideiQCOM fp_glExtTexObjectStateOverrideiQCOM;
pfn_glExtGetTexSubImageQCOM fp_glExtGetTexSubImageQCOM;
pfn_glExtGetBufferPointervQCOM fp_glExtGetBufferPointervQCOM;
pfn_glExtGetShadersQCOM fp_glExtGetShadersQCOM;
pfn_glExtGetProgramsQCOM fp_glExtGetProgramsQCOM;
pfn_glExtIsProgramBinaryQCOM fp_glExtIsProgramBinaryQCOM;
pfn_glExtGetProgramBinarySourceQCOM fp_glExtGetProgramBinarySourceQCOM;
pfn_glStartTilingQCOM fp_glStartTilingQCOM;
pfn_glEndTilingQCOM fp_glEndTilingQCOM;

GLboolean GLAD_VERSION_1_0 = GL_FALSE;
static void load_GL_VERSION_1_0(LOADER load) {
	if(!GLAD_VERSION_1_0) return;
	fp_glCullFace = (pfn_glCullFace)load("glCullFace");
	fp_glFrontFace = (pfn_glFrontFace)load("glFrontFace");
	fp_glHint = (pfn_glHint)load("glHint");
	fp_glLineWidth = (pfn_glLineWidth)load("glLineWidth");
	fp_glPointSize = (pfn_glPointSize)load("glPointSize");
	fp_glPolygonMode = (pfn_glPolygonMode)load("glPolygonMode");
	fp_glScissor = (pfn_glScissor)load("glScissor");
	fp_glTexParameterf = (pfn_glTexParameterf)load("glTexParameterf");
	fp_glTexParameterfv = (pfn_glTexParameterfv)load("glTexParameterfv");
	fp_glTexParameteri = (pfn_glTexParameteri)load("glTexParameteri");
	fp_glTexParameteriv = (pfn_glTexParameteriv)load("glTexParameteriv");
	fp_glTexImage1D = (pfn_glTexImage1D)load("glTexImage1D");
	fp_glTexImage2D = (pfn_glTexImage2D)load("glTexImage2D");
	fp_glDrawBuffer = (pfn_glDrawBuffer)load("glDrawBuffer");
	fp_glClear = (pfn_glClear)load("glClear");
	fp_glClearColor = (pfn_glClearColor)load("glClearColor");
	fp_glClearStencil = (pfn_glClearStencil)load("glClearStencil");
	fp_glClearDepth = (pfn_glClearDepth)load("glClearDepth");
	fp_glStencilMask = (pfn_glStencilMask)load("glStencilMask");
	fp_glColorMask = (pfn_glColorMask)load("glColorMask");
	fp_glDepthMask = (pfn_glDepthMask)load("glDepthMask");
	fp_glDisable = (pfn_glDisable)load("glDisable");
	fp_glEnable = (pfn_glEnable)load("glEnable");
	fp_glFinish = (pfn_glFinish)load("glFinish");
	fp_glFlush = (pfn_glFlush)load("glFlush");
	fp_glBlendFunc = (pfn_glBlendFunc)load("glBlendFunc");
	fp_glLogicOp = (pfn_glLogicOp)load("glLogicOp");
	fp_glStencilFunc = (pfn_glStencilFunc)load("glStencilFunc");
	fp_glStencilOp = (pfn_glStencilOp)load("glStencilOp");
	fp_glDepthFunc = (pfn_glDepthFunc)load("glDepthFunc");
	fp_glPixelStoref = (pfn_glPixelStoref)load("glPixelStoref");
	fp_glPixelStorei = (pfn_glPixelStorei)load("glPixelStorei");
	fp_glReadBuffer = (pfn_glReadBuffer)load("glReadBuffer");
	fp_glReadPixels = (pfn_glReadPixels)load("glReadPixels");
	fp_glGetBooleanv = (pfn_glGetBooleanv)load("glGetBooleanv");
	fp_glGetDoublev = (pfn_glGetDoublev)load("glGetDoublev");
	fp_glGetError = (pfn_glGetError)load("glGetError");
	fp_glGetFloatv = (pfn_glGetFloatv)load("glGetFloatv");
	fp_glGetIntegerv = (pfn_glGetIntegerv)load("glGetIntegerv");
	fp_glGetString = (pfn_glGetString)load("glGetString");
	fp_glGetTexImage = (pfn_glGetTexImage)load("glGetTexImage");
	fp_glGetTexParameterfv = (pfn_glGetTexParameterfv)load("glGetTexParameterfv");
	fp_glGetTexParameteriv = (pfn_glGetTexParameteriv)load("glGetTexParameteriv");
	fp_glGetTexLevelParameterfv = (pfn_glGetTexLevelParameterfv)load("glGetTexLevelParameterfv");
	fp_glGetTexLevelParameteriv = (pfn_glGetTexLevelParameteriv)load("glGetTexLevelParameteriv");
	fp_glIsEnabled = (pfn_glIsEnabled)load("glIsEnabled");
	fp_glDepthRange = (pfn_glDepthRange)load("glDepthRange");
	fp_glViewport = (pfn_glViewport)load("glViewport");
	fp_glNewList = (pfn_glNewList)load("glNewList");
	fp_glEndList = (pfn_glEndList)load("glEndList");
	fp_glCallList = (pfn_glCallList)load("glCallList");
	fp_glCallLists = (pfn_glCallLists)load("glCallLists");
	fp_glDeleteLists = (pfn_glDeleteLists)load("glDeleteLists");
	fp_glGenLists = (pfn_glGenLists)load("glGenLists");
	fp_glListBase = (pfn_glListBase)load("glListBase");
	fp_glBegin = (pfn_glBegin)load("glBegin");
	fp_glBitmap = (pfn_glBitmap)load("glBitmap");
	fp_glColor3b = (pfn_glColor3b)load("glColor3b");
	fp_glColor3bv = (pfn_glColor3bv)load("glColor3bv");
	fp_glColor3d = (pfn_glColor3d)load("glColor3d");
	fp_glColor3dv = (pfn_glColor3dv)load("glColor3dv");
	fp_glColor3f = (pfn_glColor3f)load("glColor3f");
	fp_glColor3fv = (pfn_glColor3fv)load("glColor3fv");
	fp_glColor3i = (pfn_glColor3i)load("glColor3i");
	fp_glColor3iv = (pfn_glColor3iv)load("glColor3iv");
	fp_glColor3s = (pfn_glColor3s)load("glColor3s");
	fp_glColor3sv = (pfn_glColor3sv)load("glColor3sv");
	fp_glColor3ub = (pfn_glColor3ub)load("glColor3ub");
	fp_glColor3ubv = (pfn_glColor3ubv)load("glColor3ubv");
	fp_glColor3ui = (pfn_glColor3ui)load("glColor3ui");
	fp_glColor3uiv = (pfn_glColor3uiv)load("glColor3uiv");
	fp_glColor3us = (pfn_glColor3us)load("glColor3us");
	fp_glColor3usv = (pfn_glColor3usv)load("glColor3usv");
	fp_glColor4b = (pfn_glColor4b)load("glColor4b");
	fp_glColor4bv = (pfn_glColor4bv)load("glColor4bv");
	fp_glColor4d = (pfn_glColor4d)load("glColor4d");
	fp_glColor4dv = (pfn_glColor4dv)load("glColor4dv");
	fp_glColor4f = (pfn_glColor4f)load("glColor4f");
	fp_glColor4fv = (pfn_glColor4fv)load("glColor4fv");
	fp_glColor4i = (pfn_glColor4i)load("glColor4i");
	fp_glColor4iv = (pfn_glColor4iv)load("glColor4iv");
	fp_glColor4s = (pfn_glColor4s)load("glColor4s");
	fp_glColor4sv = (pfn_glColor4sv)load("glColor4sv");
	fp_glColor4ub = (pfn_glColor4ub)load("glColor4ub");
	fp_glColor4ubv = (pfn_glColor4ubv)load("glColor4ubv");
	fp_glColor4ui = (pfn_glColor4ui)load("glColor4ui");
	fp_glColor4uiv = (pfn_glColor4uiv)load("glColor4uiv");
	fp_glColor4us = (pfn_glColor4us)load("glColor4us");
	fp_glColor4usv = (pfn_glColor4usv)load("glColor4usv");
	fp_glEdgeFlag = (pfn_glEdgeFlag)load("glEdgeFlag");
	fp_glEdgeFlagv = (pfn_glEdgeFlagv)load("glEdgeFlagv");
	fp_glEnd = (pfn_glEnd)load("glEnd");
	fp_glIndexd = (pfn_glIndexd)load("glIndexd");
	fp_glIndexdv = (pfn_glIndexdv)load("glIndexdv");
	fp_glIndexf = (pfn_glIndexf)load("glIndexf");
	fp_glIndexfv = (pfn_glIndexfv)load("glIndexfv");
	fp_glIndexi = (pfn_glIndexi)load("glIndexi");
	fp_glIndexiv = (pfn_glIndexiv)load("glIndexiv");
	fp_glIndexs = (pfn_glIndexs)load("glIndexs");
	fp_glIndexsv = (pfn_glIndexsv)load("glIndexsv");
	fp_glNormal3b = (pfn_glNormal3b)load("glNormal3b");
	fp_glNormal3bv = (pfn_glNormal3bv)load("glNormal3bv");
	fp_glNormal3d = (pfn_glNormal3d)load("glNormal3d");
	fp_glNormal3dv = (pfn_glNormal3dv)load("glNormal3dv");
	fp_glNormal3f = (pfn_glNormal3f)load("glNormal3f");
	fp_glNormal3fv = (pfn_glNormal3fv)load("glNormal3fv");
	fp_glNormal3i = (pfn_glNormal3i)load("glNormal3i");
	fp_glNormal3iv = (pfn_glNormal3iv)load("glNormal3iv");
	fp_glNormal3s = (pfn_glNormal3s)load("glNormal3s");
	fp_glNormal3sv = (pfn_glNormal3sv)load("glNormal3sv");
	fp_glRasterPos2d = (pfn_glRasterPos2d)load("glRasterPos2d");
	fp_glRasterPos2dv = (pfn_glRasterPos2dv)load("glRasterPos2dv");
	fp_glRasterPos2f = (pfn_glRasterPos2f)load("glRasterPos2f");
	fp_glRasterPos2fv = (pfn_glRasterPos2fv)load("glRasterPos2fv");
	fp_glRasterPos2i = (pfn_glRasterPos2i)load("glRasterPos2i");
	fp_glRasterPos2iv = (pfn_glRasterPos2iv)load("glRasterPos2iv");
	fp_glRasterPos2s = (pfn_glRasterPos2s)load("glRasterPos2s");
	fp_glRasterPos2sv = (pfn_glRasterPos2sv)load("glRasterPos2sv");
	fp_glRasterPos3d = (pfn_glRasterPos3d)load("glRasterPos3d");
	fp_glRasterPos3dv = (pfn_glRasterPos3dv)load("glRasterPos3dv");
	fp_glRasterPos3f = (pfn_glRasterPos3f)load("glRasterPos3f");
	fp_glRasterPos3fv = (pfn_glRasterPos3fv)load("glRasterPos3fv");
	fp_glRasterPos3i = (pfn_glRasterPos3i)load("glRasterPos3i");
	fp_glRasterPos3iv = (pfn_glRasterPos3iv)load("glRasterPos3iv");
	fp_glRasterPos3s = (pfn_glRasterPos3s)load("glRasterPos3s");
	fp_glRasterPos3sv = (pfn_glRasterPos3sv)load("glRasterPos3sv");
	fp_glRasterPos4d = (pfn_glRasterPos4d)load("glRasterPos4d");
	fp_glRasterPos4dv = (pfn_glRasterPos4dv)load("glRasterPos4dv");
	fp_glRasterPos4f = (pfn_glRasterPos4f)load("glRasterPos4f");
	fp_glRasterPos4fv = (pfn_glRasterPos4fv)load("glRasterPos4fv");
	fp_glRasterPos4i = (pfn_glRasterPos4i)load("glRasterPos4i");
	fp_glRasterPos4iv = (pfn_glRasterPos4iv)load("glRasterPos4iv");
	fp_glRasterPos4s = (pfn_glRasterPos4s)load("glRasterPos4s");
	fp_glRasterPos4sv = (pfn_glRasterPos4sv)load("glRasterPos4sv");
	fp_glRectd = (pfn_glRectd)load("glRectd");
	fp_glRectdv = (pfn_glRectdv)load("glRectdv");
	fp_glRectf = (pfn_glRectf)load("glRectf");
	fp_glRectfv = (pfn_glRectfv)load("glRectfv");
	fp_glRecti = (pfn_glRecti)load("glRecti");
	fp_glRectiv = (pfn_glRectiv)load("glRectiv");
	fp_glRects = (pfn_glRects)load("glRects");
	fp_glRectsv = (pfn_glRectsv)load("glRectsv");
	fp_glTexCoord1d = (pfn_glTexCoord1d)load("glTexCoord1d");
	fp_glTexCoord1dv = (pfn_glTexCoord1dv)load("glTexCoord1dv");
	fp_glTexCoord1f = (pfn_glTexCoord1f)load("glTexCoord1f");
	fp_glTexCoord1fv = (pfn_glTexCoord1fv)load("glTexCoord1fv");
	fp_glTexCoord1i = (pfn_glTexCoord1i)load("glTexCoord1i");
	fp_glTexCoord1iv = (pfn_glTexCoord1iv)load("glTexCoord1iv");
	fp_glTexCoord1s = (pfn_glTexCoord1s)load("glTexCoord1s");
	fp_glTexCoord1sv = (pfn_glTexCoord1sv)load("glTexCoord1sv");
	fp_glTexCoord2d = (pfn_glTexCoord2d)load("glTexCoord2d");
	fp_glTexCoord2dv = (pfn_glTexCoord2dv)load("glTexCoord2dv");
	fp_glTexCoord2f = (pfn_glTexCoord2f)load("glTexCoord2f");
	fp_glTexCoord2fv = (pfn_glTexCoord2fv)load("glTexCoord2fv");
	fp_glTexCoord2i = (pfn_glTexCoord2i)load("glTexCoord2i");
	fp_glTexCoord2iv = (pfn_glTexCoord2iv)load("glTexCoord2iv");
	fp_glTexCoord2s = (pfn_glTexCoord2s)load("glTexCoord2s");
	fp_glTexCoord2sv = (pfn_glTexCoord2sv)load("glTexCoord2sv");
	fp_glTexCoord3d = (pfn_glTexCoord3d)load("glTexCoord3d");
	fp_glTexCoord3dv = (pfn_glTexCoord3dv)load("glTexCoord3dv");
	fp_glTexCoord3f = (pfn_glTexCoord3f)load("glTexCoord3f");
	fp_glTexCoord3fv = (pfn_glTexCoord3fv)load("glTexCoord3fv");
	fp_glTexCoord3i = (pfn_glTexCoord3i)load("glTexCoord3i");
	fp_glTexCoord3iv = (pfn_glTexCoord3iv)load("glTexCoord3iv");
	fp_glTexCoord3s = (pfn_glTexCoord3s)load("glTexCoord3s");
	fp_glTexCoord3sv = (pfn_glTexCoord3sv)load("glTexCoord3sv");
	fp_glTexCoord4d = (pfn_glTexCoord4d)load("glTexCoord4d");
	fp_glTexCoord4dv = (pfn_glTexCoord4dv)load("glTexCoord4dv");
	fp_glTexCoord4f = (pfn_glTexCoord4f)load("glTexCoord4f");
	fp_glTexCoord4fv = (pfn_glTexCoord4fv)load("glTexCoord4fv");
	fp_glTexCoord4i = (pfn_glTexCoord4i)load("glTexCoord4i");
	fp_glTexCoord4iv = (pfn_glTexCoord4iv)load("glTexCoord4iv");
	fp_glTexCoord4s = (pfn_glTexCoord4s)load("glTexCoord4s");
	fp_glTexCoord4sv = (pfn_glTexCoord4sv)load("glTexCoord4sv");
	fp_glVertex2d = (pfn_glVertex2d)load("glVertex2d");
	fp_glVertex2dv = (pfn_glVertex2dv)load("glVertex2dv");
	fp_glVertex2f = (pfn_glVertex2f)load("glVertex2f");
	fp_glVertex2fv = (pfn_glVertex2fv)load("glVertex2fv");
	fp_glVertex2i = (pfn_glVertex2i)load("glVertex2i");
	fp_glVertex2iv = (pfn_glVertex2iv)load("glVertex2iv");
	fp_glVertex2s = (pfn_glVertex2s)load("glVertex2s");
	fp_glVertex2sv = (pfn_glVertex2sv)load("glVertex2sv");
	fp_glVertex3d = (pfn_glVertex3d)load("glVertex3d");
	fp_glVertex3dv = (pfn_glVertex3dv)load("glVertex3dv");
	fp_glVertex3f = (pfn_glVertex3f)load("glVertex3f");
	fp_glVertex3fv = (pfn_glVertex3fv)load("glVertex3fv");
	fp_glVertex3i = (pfn_glVertex3i)load("glVertex3i");
	fp_glVertex3iv = (pfn_glVertex3iv)load("glVertex3iv");
	fp_glVertex3s = (pfn_glVertex3s)load("glVertex3s");
	fp_glVertex3sv = (pfn_glVertex3sv)load("glVertex3sv");
	fp_glVertex4d = (pfn_glVertex4d)load("glVertex4d");
	fp_glVertex4dv = (pfn_glVertex4dv)load("glVertex4dv");
	fp_glVertex4f = (pfn_glVertex4f)load("glVertex4f");
	fp_glVertex4fv = (pfn_glVertex4fv)load("glVertex4fv");
	fp_glVertex4i = (pfn_glVertex4i)load("glVertex4i");
	fp_glVertex4iv = (pfn_glVertex4iv)load("glVertex4iv");
	fp_glVertex4s = (pfn_glVertex4s)load("glVertex4s");
	fp_glVertex4sv = (pfn_glVertex4sv)load("glVertex4sv");
	fp_glClipPlane = (pfn_glClipPlane)load("glClipPlane");
	fp_glColorMaterial = (pfn_glColorMaterial)load("glColorMaterial");
	fp_glFogf = (pfn_glFogf)load("glFogf");
	fp_glFogfv = (pfn_glFogfv)load("glFogfv");
	fp_glFogi = (pfn_glFogi)load("glFogi");
	fp_glFogiv = (pfn_glFogiv)load("glFogiv");
	fp_glLightf = (pfn_glLightf)load("glLightf");
	fp_glLightfv = (pfn_glLightfv)load("glLightfv");
	fp_glLighti = (pfn_glLighti)load("glLighti");
	fp_glLightiv = (pfn_glLightiv)load("glLightiv");
	fp_glLightModelf = (pfn_glLightModelf)load("glLightModelf");
	fp_glLightModelfv = (pfn_glLightModelfv)load("glLightModelfv");
	fp_glLightModeli = (pfn_glLightModeli)load("glLightModeli");
	fp_glLightModeliv = (pfn_glLightModeliv)load("glLightModeliv");
	fp_glLineStipple = (pfn_glLineStipple)load("glLineStipple");
	fp_glMaterialf = (pfn_glMaterialf)load("glMaterialf");
	fp_glMaterialfv = (pfn_glMaterialfv)load("glMaterialfv");
	fp_glMateriali = (pfn_glMateriali)load("glMateriali");
	fp_glMaterialiv = (pfn_glMaterialiv)load("glMaterialiv");
	fp_glPolygonStipple = (pfn_glPolygonStipple)load("glPolygonStipple");
	fp_glShadeModel = (pfn_glShadeModel)load("glShadeModel");
	fp_glTexEnvf = (pfn_glTexEnvf)load("glTexEnvf");
	fp_glTexEnvfv = (pfn_glTexEnvfv)load("glTexEnvfv");
	fp_glTexEnvi = (pfn_glTexEnvi)load("glTexEnvi");
	fp_glTexEnviv = (pfn_glTexEnviv)load("glTexEnviv");
	fp_glTexGend = (pfn_glTexGend)load("glTexGend");
	fp_glTexGendv = (pfn_glTexGendv)load("glTexGendv");
	fp_glTexGenf = (pfn_glTexGenf)load("glTexGenf");
	fp_glTexGenfv = (pfn_glTexGenfv)load("glTexGenfv");
	fp_glTexGeni = (pfn_glTexGeni)load("glTexGeni");
	fp_glTexGeniv = (pfn_glTexGeniv)load("glTexGeniv");
	fp_glFeedbackBuffer = (pfn_glFeedbackBuffer)load("glFeedbackBuffer");
	fp_glSelectBuffer = (pfn_glSelectBuffer)load("glSelectBuffer");
	fp_glRenderMode = (pfn_glRenderMode)load("glRenderMode");
	fp_glInitNames = (pfn_glInitNames)load("glInitNames");
	fp_glLoadName = (pfn_glLoadName)load("glLoadName");
	fp_glPassThrough = (pfn_glPassThrough)load("glPassThrough");
	fp_glPopName = (pfn_glPopName)load("glPopName");
	fp_glPushName = (pfn_glPushName)load("glPushName");
	fp_glClearAccum = (pfn_glClearAccum)load("glClearAccum");
	fp_glClearIndex = (pfn_glClearIndex)load("glClearIndex");
	fp_glIndexMask = (pfn_glIndexMask)load("glIndexMask");
	fp_glAccum = (pfn_glAccum)load("glAccum");
	fp_glPopAttrib = (pfn_glPopAttrib)load("glPopAttrib");
	fp_glPushAttrib = (pfn_glPushAttrib)load("glPushAttrib");
	fp_glMap1d = (pfn_glMap1d)load("glMap1d");
	fp_glMap1f = (pfn_glMap1f)load("glMap1f");
	fp_glMap2d = (pfn_glMap2d)load("glMap2d");
	fp_glMap2f = (pfn_glMap2f)load("glMap2f");
	fp_glMapGrid1d = (pfn_glMapGrid1d)load("glMapGrid1d");
	fp_glMapGrid1f = (pfn_glMapGrid1f)load("glMapGrid1f");
	fp_glMapGrid2d = (pfn_glMapGrid2d)load("glMapGrid2d");
	fp_glMapGrid2f = (pfn_glMapGrid2f)load("glMapGrid2f");
	fp_glEvalCoord1d = (pfn_glEvalCoord1d)load("glEvalCoord1d");
	fp_glEvalCoord1dv = (pfn_glEvalCoord1dv)load("glEvalCoord1dv");
	fp_glEvalCoord1f = (pfn_glEvalCoord1f)load("glEvalCoord1f");
	fp_glEvalCoord1fv = (pfn_glEvalCoord1fv)load("glEvalCoord1fv");
	fp_glEvalCoord2d = (pfn_glEvalCoord2d)load("glEvalCoord2d");
	fp_glEvalCoord2dv = (pfn_glEvalCoord2dv)load("glEvalCoord2dv");
	fp_glEvalCoord2f = (pfn_glEvalCoord2f)load("glEvalCoord2f");
	fp_glEvalCoord2fv = (pfn_glEvalCoord2fv)load("glEvalCoord2fv");
	fp_glEvalMesh1 = (pfn_glEvalMesh1)load("glEvalMesh1");
	fp_glEvalPoint1 = (pfn_glEvalPoint1)load("glEvalPoint1");
	fp_glEvalMesh2 = (pfn_glEvalMesh2)load("glEvalMesh2");
	fp_glEvalPoint2 = (pfn_glEvalPoint2)load("glEvalPoint2");
	fp_glAlphaFunc = (pfn_glAlphaFunc)load("glAlphaFunc");
	fp_glPixelZoom = (pfn_glPixelZoom)load("glPixelZoom");
	fp_glPixelTransferf = (pfn_glPixelTransferf)load("glPixelTransferf");
	fp_glPixelTransferi = (pfn_glPixelTransferi)load("glPixelTransferi");
	fp_glPixelMapfv = (pfn_glPixelMapfv)load("glPixelMapfv");
	fp_glPixelMapuiv = (pfn_glPixelMapuiv)load("glPixelMapuiv");
	fp_glPixelMapusv = (pfn_glPixelMapusv)load("glPixelMapusv");
	fp_glCopyPixels = (pfn_glCopyPixels)load("glCopyPixels");
	fp_glDrawPixels = (pfn_glDrawPixels)load("glDrawPixels");
	fp_glGetClipPlane = (pfn_glGetClipPlane)load("glGetClipPlane");
	fp_glGetLightfv = (pfn_glGetLightfv)load("glGetLightfv");
	fp_glGetLightiv = (pfn_glGetLightiv)load("glGetLightiv");
	fp_glGetMapdv = (pfn_glGetMapdv)load("glGetMapdv");
	fp_glGetMapfv = (pfn_glGetMapfv)load("glGetMapfv");
	fp_glGetMapiv = (pfn_glGetMapiv)load("glGetMapiv");
	fp_glGetMaterialfv = (pfn_glGetMaterialfv)load("glGetMaterialfv");
	fp_glGetMaterialiv = (pfn_glGetMaterialiv)load("glGetMaterialiv");
	fp_glGetPixelMapfv = (pfn_glGetPixelMapfv)load("glGetPixelMapfv");
	fp_glGetPixelMapuiv = (pfn_glGetPixelMapuiv)load("glGetPixelMapuiv");
	fp_glGetPixelMapusv = (pfn_glGetPixelMapusv)load("glGetPixelMapusv");
	fp_glGetPolygonStipple = (pfn_glGetPolygonStipple)load("glGetPolygonStipple");
	fp_glGetTexEnvfv = (pfn_glGetTexEnvfv)load("glGetTexEnvfv");
	fp_glGetTexEnviv = (pfn_glGetTexEnviv)load("glGetTexEnviv");
	fp_glGetTexGendv = (pfn_glGetTexGendv)load("glGetTexGendv");
	fp_glGetTexGenfv = (pfn_glGetTexGenfv)load("glGetTexGenfv");
	fp_glGetTexGeniv = (pfn_glGetTexGeniv)load("glGetTexGeniv");
	fp_glIsList = (pfn_glIsList)load("glIsList");
	fp_glFrustum = (pfn_glFrustum)load("glFrustum");
	fp_glLoadIdentity = (pfn_glLoadIdentity)load("glLoadIdentity");
	fp_glLoadMatrixf = (pfn_glLoadMatrixf)load("glLoadMatrixf");
	fp_glLoadMatrixd = (pfn_glLoadMatrixd)load("glLoadMatrixd");
	fp_glMatrixMode = (pfn_glMatrixMode)load("glMatrixMode");
	fp_glMultMatrixf = (pfn_glMultMatrixf)load("glMultMatrixf");
	fp_glMultMatrixd = (pfn_glMultMatrixd)load("glMultMatrixd");
	fp_glOrtho = (pfn_glOrtho)load("glOrtho");
	fp_glPopMatrix = (pfn_glPopMatrix)load("glPopMatrix");
	fp_glPushMatrix = (pfn_glPushMatrix)load("glPushMatrix");
	fp_glRotated = (pfn_glRotated)load("glRotated");
	fp_glRotatef = (pfn_glRotatef)load("glRotatef");
	fp_glScaled = (pfn_glScaled)load("glScaled");
	fp_glScalef = (pfn_glScalef)load("glScalef");
	fp_glTranslated = (pfn_glTranslated)load("glTranslated");
	fp_glTranslatef = (pfn_glTranslatef)load("glTranslatef");
}

GLboolean GLAD_VERSION_1_1 = GL_FALSE;
static void load_GL_VERSION_1_1(LOADER load) {
	if(!GLAD_VERSION_1_1) return;
	fp_glDrawArrays = (pfn_glDrawArrays)load("glDrawArrays");
	fp_glDrawElements = (pfn_glDrawElements)load("glDrawElements");
	fp_glGetPointerv = (pfn_glGetPointerv)load("glGetPointerv");
	fp_glPolygonOffset = (pfn_glPolygonOffset)load("glPolygonOffset");
	fp_glCopyTexImage1D = (pfn_glCopyTexImage1D)load("glCopyTexImage1D");
	fp_glCopyTexImage2D = (pfn_glCopyTexImage2D)load("glCopyTexImage2D");
	fp_glCopyTexSubImage1D = (pfn_glCopyTexSubImage1D)load("glCopyTexSubImage1D");
	fp_glCopyTexSubImage2D = (pfn_glCopyTexSubImage2D)load("glCopyTexSubImage2D");
	fp_glTexSubImage1D = (pfn_glTexSubImage1D)load("glTexSubImage1D");
	fp_glTexSubImage2D = (pfn_glTexSubImage2D)load("glTexSubImage2D");
	fp_glBindTexture = (pfn_glBindTexture)load("glBindTexture");
	fp_glDeleteTextures = (pfn_glDeleteTextures)load("glDeleteTextures");
	fp_glGenTextures = (pfn_glGenTextures)load("glGenTextures");
	fp_glIsTexture = (pfn_glIsTexture)load("glIsTexture");
	fp_glArrayElement = (pfn_glArrayElement)load("glArrayElement");
	fp_glColorPointer = (pfn_glColorPointer)load("glColorPointer");
	fp_glDisableClientState = (pfn_glDisableClientState)load("glDisableClientState");
	fp_glEdgeFlagPointer = (pfn_glEdgeFlagPointer)load("glEdgeFlagPointer");
	fp_glEnableClientState = (pfn_glEnableClientState)load("glEnableClientState");
	fp_glIndexPointer = (pfn_glIndexPointer)load("glIndexPointer");
	fp_glInterleavedArrays = (pfn_glInterleavedArrays)load("glInterleavedArrays");
	fp_glNormalPointer = (pfn_glNormalPointer)load("glNormalPointer");
	fp_glTexCoordPointer = (pfn_glTexCoordPointer)load("glTexCoordPointer");
	fp_glVertexPointer = (pfn_glVertexPointer)load("glVertexPointer");
	fp_glAreTexturesResident = (pfn_glAreTexturesResident)load("glAreTexturesResident");
	fp_glPrioritizeTextures = (pfn_glPrioritizeTextures)load("glPrioritizeTextures");
	fp_glIndexub = (pfn_glIndexub)load("glIndexub");
	fp_glIndexubv = (pfn_glIndexubv)load("glIndexubv");
	fp_glPopClientAttrib = (pfn_glPopClientAttrib)load("glPopClientAttrib");
	fp_glPushClientAttrib = (pfn_glPushClientAttrib)load("glPushClientAttrib");
}

GLboolean GLAD_VERSION_1_2 = GL_FALSE;
static void load_GL_VERSION_1_2(LOADER load) {
	if(!GLAD_VERSION_1_2) return;
	fp_glDrawRangeElements = (pfn_glDrawRangeElements)load("glDrawRangeElements");
	fp_glTexImage3D = (pfn_glTexImage3D)load("glTexImage3D");
	fp_glTexSubImage3D = (pfn_glTexSubImage3D)load("glTexSubImage3D");
	fp_glCopyTexSubImage3D = (pfn_glCopyTexSubImage3D)load("glCopyTexSubImage3D");
}

GLboolean GLAD_VERSION_1_3 = GL_FALSE;
static void load_GL_VERSION_1_3(LOADER load) {
	if(!GLAD_VERSION_1_3) return;
	fp_glActiveTexture = (pfn_glActiveTexture)load("glActiveTexture");
	fp_glSampleCoverage = (pfn_glSampleCoverage)load("glSampleCoverage");
	fp_glCompressedTexImage3D = (pfn_glCompressedTexImage3D)load("glCompressedTexImage3D");
	fp_glCompressedTexImage2D = (pfn_glCompressedTexImage2D)load("glCompressedTexImage2D");
	fp_glCompressedTexImage1D = (pfn_glCompressedTexImage1D)load("glCompressedTexImage1D");
	fp_glCompressedTexSubImage3D = (pfn_glCompressedTexSubImage3D)load("glCompressedTexSubImage3D");
	fp_glCompressedTexSubImage2D = (pfn_glCompressedTexSubImage2D)load("glCompressedTexSubImage2D");
	fp_glCompressedTexSubImage1D = (pfn_glCompressedTexSubImage1D)load("glCompressedTexSubImage1D");
	fp_glGetCompressedTexImage = (pfn_glGetCompressedTexImage)load("glGetCompressedTexImage");
	fp_glClientActiveTexture = (pfn_glClientActiveTexture)load("glClientActiveTexture");
	fp_glMultiTexCoord1d = (pfn_glMultiTexCoord1d)load("glMultiTexCoord1d");
	fp_glMultiTexCoord1dv = (pfn_glMultiTexCoord1dv)load("glMultiTexCoord1dv");
	fp_glMultiTexCoord1f = (pfn_glMultiTexCoord1f)load("glMultiTexCoord1f");
	fp_glMultiTexCoord1fv = (pfn_glMultiTexCoord1fv)load("glMultiTexCoord1fv");
	fp_glMultiTexCoord1i = (pfn_glMultiTexCoord1i)load("glMultiTexCoord1i");
	fp_glMultiTexCoord1iv = (pfn_glMultiTexCoord1iv)load("glMultiTexCoord1iv");
	fp_glMultiTexCoord1s = (pfn_glMultiTexCoord1s)load("glMultiTexCoord1s");
	fp_glMultiTexCoord1sv = (pfn_glMultiTexCoord1sv)load("glMultiTexCoord1sv");
	fp_glMultiTexCoord2d = (pfn_glMultiTexCoord2d)load("glMultiTexCoord2d");
	fp_glMultiTexCoord2dv = (pfn_glMultiTexCoord2dv)load("glMultiTexCoord2dv");
	fp_glMultiTexCoord2f = (pfn_glMultiTexCoord2f)load("glMultiTexCoord2f");
	fp_glMultiTexCoord2fv = (pfn_glMultiTexCoord2fv)load("glMultiTexCoord2fv");
	fp_glMultiTexCoord2i = (pfn_glMultiTexCoord2i)load("glMultiTexCoord2i");
	fp_glMultiTexCoord2iv = (pfn_glMultiTexCoord2iv)load("glMultiTexCoord2iv");
	fp_glMultiTexCoord2s = (pfn_glMultiTexCoord2s)load("glMultiTexCoord2s");
	fp_glMultiTexCoord2sv = (pfn_glMultiTexCoord2sv)load("glMultiTexCoord2sv");
	fp_glMultiTexCoord3d = (pfn_glMultiTexCoord3d)load("glMultiTexCoord3d");
	fp_glMultiTexCoord3dv = (pfn_glMultiTexCoord3dv)load("glMultiTexCoord3dv");
	fp_glMultiTexCoord3f = (pfn_glMultiTexCoord3f)load("glMultiTexCoord3f");
	fp_glMultiTexCoord3fv = (pfn_glMultiTexCoord3fv)load("glMultiTexCoord3fv");
	fp_glMultiTexCoord3i = (pfn_glMultiTexCoord3i)load("glMultiTexCoord3i");
	fp_glMultiTexCoord3iv = (pfn_glMultiTexCoord3iv)load("glMultiTexCoord3iv");
	fp_glMultiTexCoord3s = (pfn_glMultiTexCoord3s)load("glMultiTexCoord3s");
	fp_glMultiTexCoord3sv = (pfn_glMultiTexCoord3sv)load("glMultiTexCoord3sv");
	fp_glMultiTexCoord4d = (pfn_glMultiTexCoord4d)load("glMultiTexCoord4d");
	fp_glMultiTexCoord4dv = (pfn_glMultiTexCoord4dv)load("glMultiTexCoord4dv");
	fp_glMultiTexCoord4f = (pfn_glMultiTexCoord4f)load("glMultiTexCoord4f");
	fp_glMultiTexCoord4fv = (pfn_glMultiTexCoord4fv)load("glMultiTexCoord4fv");
	fp_glMultiTexCoord4i = (pfn_glMultiTexCoord4i)load("glMultiTexCoord4i");
	fp_glMultiTexCoord4iv = (pfn_glMultiTexCoord4iv)load("glMultiTexCoord4iv");
	fp_glMultiTexCoord4s = (pfn_glMultiTexCoord4s)load("glMultiTexCoord4s");
	fp_glMultiTexCoord4sv = (pfn_glMultiTexCoord4sv)load("glMultiTexCoord4sv");
	fp_glLoadTransposeMatrixf = (pfn_glLoadTransposeMatrixf)load("glLoadTransposeMatrixf");
	fp_glLoadTransposeMatrixd = (pfn_glLoadTransposeMatrixd)load("glLoadTransposeMatrixd");
	fp_glMultTransposeMatrixf = (pfn_glMultTransposeMatrixf)load("glMultTransposeMatrixf");
	fp_glMultTransposeMatrixd = (pfn_glMultTransposeMatrixd)load("glMultTransposeMatrixd");
}

GLboolean GLAD_VERSION_1_4 = GL_FALSE;
static void load_GL_VERSION_1_4(LOADER load) {
	if(!GLAD_VERSION_1_4) return;
	fp_glBlendFuncSeparate = (pfn_glBlendFuncSeparate)load("glBlendFuncSeparate");
	fp_glMultiDrawArrays = (pfn_glMultiDrawArrays)load("glMultiDrawArrays");
	fp_glMultiDrawElements = (pfn_glMultiDrawElements)load("glMultiDrawElements");
	fp_glPointParameterf = (pfn_glPointParameterf)load("glPointParameterf");
	fp_glPointParameterfv = (pfn_glPointParameterfv)load("glPointParameterfv");
	fp_glPointParameteri = (pfn_glPointParameteri)load("glPointParameteri");
	fp_glPointParameteriv = (pfn_glPointParameteriv)load("glPointParameteriv");
	fp_glFogCoordf = (pfn_glFogCoordf)load("glFogCoordf");
	fp_glFogCoordfv = (pfn_glFogCoordfv)load("glFogCoordfv");
	fp_glFogCoordd = (pfn_glFogCoordd)load("glFogCoordd");
	fp_glFogCoorddv = (pfn_glFogCoorddv)load("glFogCoorddv");
	fp_glFogCoordPointer = (pfn_glFogCoordPointer)load("glFogCoordPointer");
	fp_glSecondaryColor3b = (pfn_glSecondaryColor3b)load("glSecondaryColor3b");
	fp_glSecondaryColor3bv = (pfn_glSecondaryColor3bv)load("glSecondaryColor3bv");
	fp_glSecondaryColor3d = (pfn_glSecondaryColor3d)load("glSecondaryColor3d");
	fp_glSecondaryColor3dv = (pfn_glSecondaryColor3dv)load("glSecondaryColor3dv");
	fp_glSecondaryColor3f = (pfn_glSecondaryColor3f)load("glSecondaryColor3f");
	fp_glSecondaryColor3fv = (pfn_glSecondaryColor3fv)load("glSecondaryColor3fv");
	fp_glSecondaryColor3i = (pfn_glSecondaryColor3i)load("glSecondaryColor3i");
	fp_glSecondaryColor3iv = (pfn_glSecondaryColor3iv)load("glSecondaryColor3iv");
	fp_glSecondaryColor3s = (pfn_glSecondaryColor3s)load("glSecondaryColor3s");
	fp_glSecondaryColor3sv = (pfn_glSecondaryColor3sv)load("glSecondaryColor3sv");
	fp_glSecondaryColor3ub = (pfn_glSecondaryColor3ub)load("glSecondaryColor3ub");
	fp_glSecondaryColor3ubv = (pfn_glSecondaryColor3ubv)load("glSecondaryColor3ubv");
	fp_glSecondaryColor3ui = (pfn_glSecondaryColor3ui)load("glSecondaryColor3ui");
	fp_glSecondaryColor3uiv = (pfn_glSecondaryColor3uiv)load("glSecondaryColor3uiv");
	fp_glSecondaryColor3us = (pfn_glSecondaryColor3us)load("glSecondaryColor3us");
	fp_glSecondaryColor3usv = (pfn_glSecondaryColor3usv)load("glSecondaryColor3usv");
	fp_glSecondaryColorPointer = (pfn_glSecondaryColorPointer)load("glSecondaryColorPointer");
	fp_glWindowPos2d = (pfn_glWindowPos2d)load("glWindowPos2d");
	fp_glWindowPos2dv = (pfn_glWindowPos2dv)load("glWindowPos2dv");
	fp_glWindowPos2f = (pfn_glWindowPos2f)load("glWindowPos2f");
	fp_glWindowPos2fv = (pfn_glWindowPos2fv)load("glWindowPos2fv");
	fp_glWindowPos2i = (pfn_glWindowPos2i)load("glWindowPos2i");
	fp_glWindowPos2iv = (pfn_glWindowPos2iv)load("glWindowPos2iv");
	fp_glWindowPos2s = (pfn_glWindowPos2s)load("glWindowPos2s");
	fp_glWindowPos2sv = (pfn_glWindowPos2sv)load("glWindowPos2sv");
	fp_glWindowPos3d = (pfn_glWindowPos3d)load("glWindowPos3d");
	fp_glWindowPos3dv = (pfn_glWindowPos3dv)load("glWindowPos3dv");
	fp_glWindowPos3f = (pfn_glWindowPos3f)load("glWindowPos3f");
	fp_glWindowPos3fv = (pfn_glWindowPos3fv)load("glWindowPos3fv");
	fp_glWindowPos3i = (pfn_glWindowPos3i)load("glWindowPos3i");
	fp_glWindowPos3iv = (pfn_glWindowPos3iv)load("glWindowPos3iv");
	fp_glWindowPos3s = (pfn_glWindowPos3s)load("glWindowPos3s");
	fp_glWindowPos3sv = (pfn_glWindowPos3sv)load("glWindowPos3sv");
	fp_glBlendColor = (pfn_glBlendColor)load("glBlendColor");
	fp_glBlendEquation = (pfn_glBlendEquation)load("glBlendEquation");
}

GLboolean GLAD_VERSION_1_5 = GL_FALSE;
static void load_GL_VERSION_1_5(LOADER load) {
	if(!GLAD_VERSION_1_5) return;
	fp_glGenQueries = (pfn_glGenQueries)load("glGenQueries");
	fp_glDeleteQueries = (pfn_glDeleteQueries)load("glDeleteQueries");
	fp_glIsQuery = (pfn_glIsQuery)load("glIsQuery");
	fp_glBeginQuery = (pfn_glBeginQuery)load("glBeginQuery");
	fp_glEndQuery = (pfn_glEndQuery)load("glEndQuery");
	fp_glGetQueryiv = (pfn_glGetQueryiv)load("glGetQueryiv");
	fp_glGetQueryObjectiv = (pfn_glGetQueryObjectiv)load("glGetQueryObjectiv");
	fp_glGetQueryObjectuiv = (pfn_glGetQueryObjectuiv)load("glGetQueryObjectuiv");
	fp_glBindBuffer = (pfn_glBindBuffer)load("glBindBuffer");
	fp_glDeleteBuffers = (pfn_glDeleteBuffers)load("glDeleteBuffers");
	fp_glGenBuffers = (pfn_glGenBuffers)load("glGenBuffers");
	fp_glIsBuffer = (pfn_glIsBuffer)load("glIsBuffer");
	fp_glBufferData = (pfn_glBufferData)load("glBufferData");
	fp_glBufferSubData = (pfn_glBufferSubData)load("glBufferSubData");
	fp_glGetBufferSubData = (pfn_glGetBufferSubData)load("glGetBufferSubData");
	fp_glMapBuffer = (pfn_glMapBuffer)load("glMapBuffer");
	fp_glUnmapBuffer = (pfn_glUnmapBuffer)load("glUnmapBuffer");
	fp_glGetBufferParameteriv = (pfn_glGetBufferParameteriv)load("glGetBufferParameteriv");
	fp_glGetBufferPointerv = (pfn_glGetBufferPointerv)load("glGetBufferPointerv");
}

GLboolean GLAD_VERSION_2_0 = GL_FALSE;
static void load_GL_VERSION_2_0(LOADER load) {
	if(!GLAD_VERSION_2_0) return;
	fp_glBlendEquationSeparate = (pfn_glBlendEquationSeparate)load("glBlendEquationSeparate");
	fp_glDrawBuffers = (pfn_glDrawBuffers)load("glDrawBuffers");
	fp_glStencilOpSeparate = (pfn_glStencilOpSeparate)load("glStencilOpSeparate");
	fp_glStencilFuncSeparate = (pfn_glStencilFuncSeparate)load("glStencilFuncSeparate");
	fp_glStencilMaskSeparate = (pfn_glStencilMaskSeparate)load("glStencilMaskSeparate");
	fp_glAttachShader = (pfn_glAttachShader)load("glAttachShader");
	fp_glBindAttribLocation = (pfn_glBindAttribLocation)load("glBindAttribLocation");
	fp_glCompileShader = (pfn_glCompileShader)load("glCompileShader");
	fp_glCreateProgram = (pfn_glCreateProgram)load("glCreateProgram");
	fp_glCreateShader = (pfn_glCreateShader)load("glCreateShader");
	fp_glDeleteProgram = (pfn_glDeleteProgram)load("glDeleteProgram");
	fp_glDeleteShader = (pfn_glDeleteShader)load("glDeleteShader");
	fp_glDetachShader = (pfn_glDetachShader)load("glDetachShader");
	fp_glDisableVertexAttribArray = (pfn_glDisableVertexAttribArray)load("glDisableVertexAttribArray");
	fp_glEnableVertexAttribArray = (pfn_glEnableVertexAttribArray)load("glEnableVertexAttribArray");
	fp_glGetActiveAttrib = (pfn_glGetActiveAttrib)load("glGetActiveAttrib");
	fp_glGetActiveUniform = (pfn_glGetActiveUniform)load("glGetActiveUniform");
	fp_glGetAttachedShaders = (pfn_glGetAttachedShaders)load("glGetAttachedShaders");
	fp_glGetAttribLocation = (pfn_glGetAttribLocation)load("glGetAttribLocation");
	fp_glGetProgramiv = (pfn_glGetProgramiv)load("glGetProgramiv");
	fp_glGetProgramInfoLog = (pfn_glGetProgramInfoLog)load("glGetProgramInfoLog");
	fp_glGetShaderiv = (pfn_glGetShaderiv)load("glGetShaderiv");
	fp_glGetShaderInfoLog = (pfn_glGetShaderInfoLog)load("glGetShaderInfoLog");
	fp_glGetShaderSource = (pfn_glGetShaderSource)load("glGetShaderSource");
	fp_glGetUniformLocation = (pfn_glGetUniformLocation)load("glGetUniformLocation");
	fp_glGetUniformfv = (pfn_glGetUniformfv)load("glGetUniformfv");
	fp_glGetUniformiv = (pfn_glGetUniformiv)load("glGetUniformiv");
	fp_glGetVertexAttribdv = (pfn_glGetVertexAttribdv)load("glGetVertexAttribdv");
	fp_glGetVertexAttribfv = (pfn_glGetVertexAttribfv)load("glGetVertexAttribfv");
	fp_glGetVertexAttribiv = (pfn_glGetVertexAttribiv)load("glGetVertexAttribiv");
	fp_glGetVertexAttribPointerv = (pfn_glGetVertexAttribPointerv)load("glGetVertexAttribPointerv");
	fp_glIsProgram = (pfn_glIsProgram)load("glIsProgram");
	fp_glIsShader = (pfn_glIsShader)load("glIsShader");
	fp_glLinkProgram = (pfn_glLinkProgram)load("glLinkProgram");
	fp_glShaderSource = (pfn_glShaderSource)load("glShaderSource");
	fp_glUseProgram = (pfn_glUseProgram)load("glUseProgram");
	fp_glUniform1f = (pfn_glUniform1f)load("glUniform1f");
	fp_glUniform2f = (pfn_glUniform2f)load("glUniform2f");
	fp_glUniform3f = (pfn_glUniform3f)load("glUniform3f");
	fp_glUniform4f = (pfn_glUniform4f)load("glUniform4f");
	fp_glUniform1i = (pfn_glUniform1i)load("glUniform1i");
	fp_glUniform2i = (pfn_glUniform2i)load("glUniform2i");
	fp_glUniform3i = (pfn_glUniform3i)load("glUniform3i");
	fp_glUniform4i = (pfn_glUniform4i)load("glUniform4i");
	fp_glUniform1fv = (pfn_glUniform1fv)load("glUniform1fv");
	fp_glUniform2fv = (pfn_glUniform2fv)load("glUniform2fv");
	fp_glUniform3fv = (pfn_glUniform3fv)load("glUniform3fv");
	fp_glUniform4fv = (pfn_glUniform4fv)load("glUniform4fv");
	fp_glUniform1iv = (pfn_glUniform1iv)load("glUniform1iv");
	fp_glUniform2iv = (pfn_glUniform2iv)load("glUniform2iv");
	fp_glUniform3iv = (pfn_glUniform3iv)load("glUniform3iv");
	fp_glUniform4iv = (pfn_glUniform4iv)load("glUniform4iv");
	fp_glUniformMatrix2fv = (pfn_glUniformMatrix2fv)load("glUniformMatrix2fv");
	fp_glUniformMatrix3fv = (pfn_glUniformMatrix3fv)load("glUniformMatrix3fv");
	fp_glUniformMatrix4fv = (pfn_glUniformMatrix4fv)load("glUniformMatrix4fv");
	fp_glValidateProgram = (pfn_glValidateProgram)load("glValidateProgram");
	fp_glVertexAttrib1d = (pfn_glVertexAttrib1d)load("glVertexAttrib1d");
	fp_glVertexAttrib1dv = (pfn_glVertexAttrib1dv)load("glVertexAttrib1dv");
	fp_glVertexAttrib1f = (pfn_glVertexAttrib1f)load("glVertexAttrib1f");
	fp_glVertexAttrib1fv = (pfn_glVertexAttrib1fv)load("glVertexAttrib1fv");
	fp_glVertexAttrib1s = (pfn_glVertexAttrib1s)load("glVertexAttrib1s");
	fp_glVertexAttrib1sv = (pfn_glVertexAttrib1sv)load("glVertexAttrib1sv");
	fp_glVertexAttrib2d = (pfn_glVertexAttrib2d)load("glVertexAttrib2d");
	fp_glVertexAttrib2dv = (pfn_glVertexAttrib2dv)load("glVertexAttrib2dv");
	fp_glVertexAttrib2f = (pfn_glVertexAttrib2f)load("glVertexAttrib2f");
	fp_glVertexAttrib2fv = (pfn_glVertexAttrib2fv)load("glVertexAttrib2fv");
	fp_glVertexAttrib2s = (pfn_glVertexAttrib2s)load("glVertexAttrib2s");
	fp_glVertexAttrib2sv = (pfn_glVertexAttrib2sv)load("glVertexAttrib2sv");
	fp_glVertexAttrib3d = (pfn_glVertexAttrib3d)load("glVertexAttrib3d");
	fp_glVertexAttrib3dv = (pfn_glVertexAttrib3dv)load("glVertexAttrib3dv");
	fp_glVertexAttrib3f = (pfn_glVertexAttrib3f)load("glVertexAttrib3f");
	fp_glVertexAttrib3fv = (pfn_glVertexAttrib3fv)load("glVertexAttrib3fv");
	fp_glVertexAttrib3s = (pfn_glVertexAttrib3s)load("glVertexAttrib3s");
	fp_glVertexAttrib3sv = (pfn_glVertexAttrib3sv)load("glVertexAttrib3sv");
	fp_glVertexAttrib4Nbv = (pfn_glVertexAttrib4Nbv)load("glVertexAttrib4Nbv");
	fp_glVertexAttrib4Niv = (pfn_glVertexAttrib4Niv)load("glVertexAttrib4Niv");
	fp_glVertexAttrib4Nsv = (pfn_glVertexAttrib4Nsv)load("glVertexAttrib4Nsv");
	fp_glVertexAttrib4Nub = (pfn_glVertexAttrib4Nub)load("glVertexAttrib4Nub");
	fp_glVertexAttrib4Nubv = (pfn_glVertexAttrib4Nubv)load("glVertexAttrib4Nubv");
	fp_glVertexAttrib4Nuiv = (pfn_glVertexAttrib4Nuiv)load("glVertexAttrib4Nuiv");
	fp_glVertexAttrib4Nusv = (pfn_glVertexAttrib4Nusv)load("glVertexAttrib4Nusv");
	fp_glVertexAttrib4bv = (pfn_glVertexAttrib4bv)load("glVertexAttrib4bv");
	fp_glVertexAttrib4d = (pfn_glVertexAttrib4d)load("glVertexAttrib4d");
	fp_glVertexAttrib4dv = (pfn_glVertexAttrib4dv)load("glVertexAttrib4dv");
	fp_glVertexAttrib4f = (pfn_glVertexAttrib4f)load("glVertexAttrib4f");
	fp_glVertexAttrib4fv = (pfn_glVertexAttrib4fv)load("glVertexAttrib4fv");
	fp_glVertexAttrib4iv = (pfn_glVertexAttrib4iv)load("glVertexAttrib4iv");
	fp_glVertexAttrib4s = (pfn_glVertexAttrib4s)load("glVertexAttrib4s");
	fp_glVertexAttrib4sv = (pfn_glVertexAttrib4sv)load("glVertexAttrib4sv");
	fp_glVertexAttrib4ubv = (pfn_glVertexAttrib4ubv)load("glVertexAttrib4ubv");
	fp_glVertexAttrib4uiv = (pfn_glVertexAttrib4uiv)load("glVertexAttrib4uiv");
	fp_glVertexAttrib4usv = (pfn_glVertexAttrib4usv)load("glVertexAttrib4usv");
	fp_glVertexAttribPointer = (pfn_glVertexAttribPointer)load("glVertexAttribPointer");
}

GLboolean GLAD_VERSION_2_1 = GL_FALSE;
static void load_GL_VERSION_2_1(LOADER load) {
	if(!GLAD_VERSION_2_1) return;
	fp_glUniformMatrix2x3fv = (pfn_glUniformMatrix2x3fv)load("glUniformMatrix2x3fv");
	fp_glUniformMatrix3x2fv = (pfn_glUniformMatrix3x2fv)load("glUniformMatrix3x2fv");
	fp_glUniformMatrix2x4fv = (pfn_glUniformMatrix2x4fv)load("glUniformMatrix2x4fv");
	fp_glUniformMatrix4x2fv = (pfn_glUniformMatrix4x2fv)load("glUniformMatrix4x2fv");
	fp_glUniformMatrix3x4fv = (pfn_glUniformMatrix3x4fv)load("glUniformMatrix3x4fv");
	fp_glUniformMatrix4x3fv = (pfn_glUniformMatrix4x3fv)load("glUniformMatrix4x3fv");
}

GLboolean GLAD_VERSION_3_0 = GL_FALSE;
static void load_GL_VERSION_3_0(LOADER load) {
	if(!GLAD_VERSION_3_0) return;
	fp_glColorMaski = (pfn_glColorMaski)load("glColorMaski");
	fp_glGetBooleani_v = (pfn_glGetBooleani_v)load("glGetBooleani_v");
	fp_glGetIntegeri_v = (pfn_glGetIntegeri_v)load("glGetIntegeri_v");
	fp_glEnablei = (pfn_glEnablei)load("glEnablei");
	fp_glDisablei = (pfn_glDisablei)load("glDisablei");
	fp_glIsEnabledi = (pfn_glIsEnabledi)load("glIsEnabledi");
	fp_glBeginTransformFeedback = (pfn_glBeginTransformFeedback)load("glBeginTransformFeedback");
	fp_glEndTransformFeedback = (pfn_glEndTransformFeedback)load("glEndTransformFeedback");
	fp_glBindBufferRange = (pfn_glBindBufferRange)load("glBindBufferRange");
	fp_glBindBufferBase = (pfn_glBindBufferBase)load("glBindBufferBase");
	fp_glTransformFeedbackVaryings = (pfn_glTransformFeedbackVaryings)load("glTransformFeedbackVaryings");
	fp_glGetTransformFeedbackVarying = (pfn_glGetTransformFeedbackVarying)load("glGetTransformFeedbackVarying");
	fp_glClampColor = (pfn_glClampColor)load("glClampColor");
	fp_glBeginConditionalRender = (pfn_glBeginConditionalRender)load("glBeginConditionalRender");
	fp_glEndConditionalRender = (pfn_glEndConditionalRender)load("glEndConditionalRender");
	fp_glVertexAttribIPointer = (pfn_glVertexAttribIPointer)load("glVertexAttribIPointer");
	fp_glGetVertexAttribIiv = (pfn_glGetVertexAttribIiv)load("glGetVertexAttribIiv");
	fp_glGetVertexAttribIuiv = (pfn_glGetVertexAttribIuiv)load("glGetVertexAttribIuiv");
	fp_glVertexAttribI1i = (pfn_glVertexAttribI1i)load("glVertexAttribI1i");
	fp_glVertexAttribI2i = (pfn_glVertexAttribI2i)load("glVertexAttribI2i");
	fp_glVertexAttribI3i = (pfn_glVertexAttribI3i)load("glVertexAttribI3i");
	fp_glVertexAttribI4i = (pfn_glVertexAttribI4i)load("glVertexAttribI4i");
	fp_glVertexAttribI1ui = (pfn_glVertexAttribI1ui)load("glVertexAttribI1ui");
	fp_glVertexAttribI2ui = (pfn_glVertexAttribI2ui)load("glVertexAttribI2ui");
	fp_glVertexAttribI3ui = (pfn_glVertexAttribI3ui)load("glVertexAttribI3ui");
	fp_glVertexAttribI4ui = (pfn_glVertexAttribI4ui)load("glVertexAttribI4ui");
	fp_glVertexAttribI1iv = (pfn_glVertexAttribI1iv)load("glVertexAttribI1iv");
	fp_glVertexAttribI2iv = (pfn_glVertexAttribI2iv)load("glVertexAttribI2iv");
	fp_glVertexAttribI3iv = (pfn_glVertexAttribI3iv)load("glVertexAttribI3iv");
	fp_glVertexAttribI4iv = (pfn_glVertexAttribI4iv)load("glVertexAttribI4iv");
	fp_glVertexAttribI1uiv = (pfn_glVertexAttribI1uiv)load("glVertexAttribI1uiv");
	fp_glVertexAttribI2uiv = (pfn_glVertexAttribI2uiv)load("glVertexAttribI2uiv");
	fp_glVertexAttribI3uiv = (pfn_glVertexAttribI3uiv)load("glVertexAttribI3uiv");
	fp_glVertexAttribI4uiv = (pfn_glVertexAttribI4uiv)load("glVertexAttribI4uiv");
	fp_glVertexAttribI4bv = (pfn_glVertexAttribI4bv)load("glVertexAttribI4bv");
	fp_glVertexAttribI4sv = (pfn_glVertexAttribI4sv)load("glVertexAttribI4sv");
	fp_glVertexAttribI4ubv = (pfn_glVertexAttribI4ubv)load("glVertexAttribI4ubv");
	fp_glVertexAttribI4usv = (pfn_glVertexAttribI4usv)load("glVertexAttribI4usv");
	fp_glGetUniformuiv = (pfn_glGetUniformuiv)load("glGetUniformuiv");
	fp_glBindFragDataLocation = (pfn_glBindFragDataLocation)load("glBindFragDataLocation");
	fp_glGetFragDataLocation = (pfn_glGetFragDataLocation)load("glGetFragDataLocation");
	fp_glUniform1ui = (pfn_glUniform1ui)load("glUniform1ui");
	fp_glUniform2ui = (pfn_glUniform2ui)load("glUniform2ui");
	fp_glUniform3ui = (pfn_glUniform3ui)load("glUniform3ui");
	fp_glUniform4ui = (pfn_glUniform4ui)load("glUniform4ui");
	fp_glUniform1uiv = (pfn_glUniform1uiv)load("glUniform1uiv");
	fp_glUniform2uiv = (pfn_glUniform2uiv)load("glUniform2uiv");
	fp_glUniform3uiv = (pfn_glUniform3uiv)load("glUniform3uiv");
	fp_glUniform4uiv = (pfn_glUniform4uiv)load("glUniform4uiv");
	fp_glTexParameterIiv = (pfn_glTexParameterIiv)load("glTexParameterIiv");
	fp_glTexParameterIuiv = (pfn_glTexParameterIuiv)load("glTexParameterIuiv");
	fp_glGetTexParameterIiv = (pfn_glGetTexParameterIiv)load("glGetTexParameterIiv");
	fp_glGetTexParameterIuiv = (pfn_glGetTexParameterIuiv)load("glGetTexParameterIuiv");
	fp_glClearBufferiv = (pfn_glClearBufferiv)load("glClearBufferiv");
	fp_glClearBufferuiv = (pfn_glClearBufferuiv)load("glClearBufferuiv");
	fp_glClearBufferfv = (pfn_glClearBufferfv)load("glClearBufferfv");
	fp_glClearBufferfi = (pfn_glClearBufferfi)load("glClearBufferfi");
	fp_glGetStringi = (pfn_glGetStringi)load("glGetStringi");
	fp_glIsRenderbuffer = (pfn_glIsRenderbuffer)load("glIsRenderbuffer");
	fp_glBindRenderbuffer = (pfn_glBindRenderbuffer)load("glBindRenderbuffer");
	fp_glDeleteRenderbuffers = (pfn_glDeleteRenderbuffers)load("glDeleteRenderbuffers");
	fp_glGenRenderbuffers = (pfn_glGenRenderbuffers)load("glGenRenderbuffers");
	fp_glRenderbufferStorage = (pfn_glRenderbufferStorage)load("glRenderbufferStorage");
	fp_glGetRenderbufferParameteriv = (pfn_glGetRenderbufferParameteriv)load("glGetRenderbufferParameteriv");
	fp_glIsFramebuffer = (pfn_glIsFramebuffer)load("glIsFramebuffer");
	fp_glBindFramebuffer = (pfn_glBindFramebuffer)load("glBindFramebuffer");
	fp_glDeleteFramebuffers = (pfn_glDeleteFramebuffers)load("glDeleteFramebuffers");
	fp_glGenFramebuffers = (pfn_glGenFramebuffers)load("glGenFramebuffers");
	fp_glCheckFramebufferStatus = (pfn_glCheckFramebufferStatus)load("glCheckFramebufferStatus");
	fp_glFramebufferTexture1D = (pfn_glFramebufferTexture1D)load("glFramebufferTexture1D");
	fp_glFramebufferTexture2D = (pfn_glFramebufferTexture2D)load("glFramebufferTexture2D");
	fp_glFramebufferTexture3D = (pfn_glFramebufferTexture3D)load("glFramebufferTexture3D");
	fp_glFramebufferRenderbuffer = (pfn_glFramebufferRenderbuffer)load("glFramebufferRenderbuffer");
	fp_glGetFramebufferAttachmentParameteriv = (pfn_glGetFramebufferAttachmentParameteriv)load("glGetFramebufferAttachmentParameteriv");
	fp_glGenerateMipmap = (pfn_glGenerateMipmap)load("glGenerateMipmap");
	fp_glBlitFramebuffer = (pfn_glBlitFramebuffer)load("glBlitFramebuffer");
	fp_glRenderbufferStorageMultisample = (pfn_glRenderbufferStorageMultisample)load("glRenderbufferStorageMultisample");
	fp_glFramebufferTextureLayer = (pfn_glFramebufferTextureLayer)load("glFramebufferTextureLayer");
	fp_glMapBufferRange = (pfn_glMapBufferRange)load("glMapBufferRange");
	fp_glFlushMappedBufferRange = (pfn_glFlushMappedBufferRange)load("glFlushMappedBufferRange");
	fp_glBindVertexArray = (pfn_glBindVertexArray)load("glBindVertexArray");
	fp_glDeleteVertexArrays = (pfn_glDeleteVertexArrays)load("glDeleteVertexArrays");
	fp_glGenVertexArrays = (pfn_glGenVertexArrays)load("glGenVertexArrays");
	fp_glIsVertexArray = (pfn_glIsVertexArray)load("glIsVertexArray");
}

GLboolean GLAD_VERSION_3_1 = GL_FALSE;
static void load_GL_VERSION_3_1(LOADER load) {
	if(!GLAD_VERSION_3_1) return;
	fp_glDrawArraysInstanced = (pfn_glDrawArraysInstanced)load("glDrawArraysInstanced");
	fp_glDrawElementsInstanced = (pfn_glDrawElementsInstanced)load("glDrawElementsInstanced");
	fp_glTexBuffer = (pfn_glTexBuffer)load("glTexBuffer");
	fp_glPrimitiveRestartIndex = (pfn_glPrimitiveRestartIndex)load("glPrimitiveRestartIndex");
	fp_glCopyBufferSubData = (pfn_glCopyBufferSubData)load("glCopyBufferSubData");
	fp_glGetUniformIndices = (pfn_glGetUniformIndices)load("glGetUniformIndices");
	fp_glGetActiveUniformsiv = (pfn_glGetActiveUniformsiv)load("glGetActiveUniformsiv");
	fp_glGetActiveUniformName = (pfn_glGetActiveUniformName)load("glGetActiveUniformName");
	fp_glGetUniformBlockIndex = (pfn_glGetUniformBlockIndex)load("glGetUniformBlockIndex");
	fp_glGetActiveUniformBlockiv = (pfn_glGetActiveUniformBlockiv)load("glGetActiveUniformBlockiv");
	fp_glGetActiveUniformBlockName = (pfn_glGetActiveUniformBlockName)load("glGetActiveUniformBlockName");
	fp_glUniformBlockBinding = (pfn_glUniformBlockBinding)load("glUniformBlockBinding");
	fp_glBindBufferRange = (pfn_glBindBufferRange)load("glBindBufferRange");
	fp_glBindBufferBase = (pfn_glBindBufferBase)load("glBindBufferBase");
	fp_glGetIntegeri_v = (pfn_glGetIntegeri_v)load("glGetIntegeri_v");
}

GLboolean GLAD_VERSION_3_2 = GL_FALSE;
static void load_GL_VERSION_3_2(LOADER load) {
	if(!GLAD_VERSION_3_2) return;
	fp_glDrawElementsBaseVertex = (pfn_glDrawElementsBaseVertex)load("glDrawElementsBaseVertex");
	fp_glDrawRangeElementsBaseVertex = (pfn_glDrawRangeElementsBaseVertex)load("glDrawRangeElementsBaseVertex");
	fp_glDrawElementsInstancedBaseVertex = (pfn_glDrawElementsInstancedBaseVertex)load("glDrawElementsInstancedBaseVertex");
	fp_glMultiDrawElementsBaseVertex = (pfn_glMultiDrawElementsBaseVertex)load("glMultiDrawElementsBaseVertex");
	fp_glProvokingVertex = (pfn_glProvokingVertex)load("glProvokingVertex");
	fp_glFenceSync = (pfn_glFenceSync)load("glFenceSync");
	fp_glIsSync = (pfn_glIsSync)load("glIsSync");
	fp_glDeleteSync = (pfn_glDeleteSync)load("glDeleteSync");
	fp_glClientWaitSync = (pfn_glClientWaitSync)load("glClientWaitSync");
	fp_glWaitSync = (pfn_glWaitSync)load("glWaitSync");
	fp_glGetInteger64v = (pfn_glGetInteger64v)load("glGetInteger64v");
	fp_glGetSynciv = (pfn_glGetSynciv)load("glGetSynciv");
	fp_glGetInteger64i_v = (pfn_glGetInteger64i_v)load("glGetInteger64i_v");
	fp_glGetBufferParameteri64v = (pfn_glGetBufferParameteri64v)load("glGetBufferParameteri64v");
	fp_glFramebufferTexture = (pfn_glFramebufferTexture)load("glFramebufferTexture");
	fp_glTexImage2DMultisample = (pfn_glTexImage2DMultisample)load("glTexImage2DMultisample");
	fp_glTexImage3DMultisample = (pfn_glTexImage3DMultisample)load("glTexImage3DMultisample");
	fp_glGetMultisamplefv = (pfn_glGetMultisamplefv)load("glGetMultisamplefv");
	fp_glSampleMaski = (pfn_glSampleMaski)load("glSampleMaski");
}

GLboolean GLAD_VERSION_3_3 = GL_FALSE;
static void load_GL_VERSION_3_3(LOADER load) {
	if(!GLAD_VERSION_3_3) return;
	fp_glBindFragDataLocationIndexed = (pfn_glBindFragDataLocationIndexed)load("glBindFragDataLocationIndexed");
	fp_glGetFragDataIndex = (pfn_glGetFragDataIndex)load("glGetFragDataIndex");
	fp_glGenSamplers = (pfn_glGenSamplers)load("glGenSamplers");
	fp_glDeleteSamplers = (pfn_glDeleteSamplers)load("glDeleteSamplers");
	fp_glIsSampler = (pfn_glIsSampler)load("glIsSampler");
	fp_glBindSampler = (pfn_glBindSampler)load("glBindSampler");
	fp_glSamplerParameteri = (pfn_glSamplerParameteri)load("glSamplerParameteri");
	fp_glSamplerParameteriv = (pfn_glSamplerParameteriv)load("glSamplerParameteriv");
	fp_glSamplerParameterf = (pfn_glSamplerParameterf)load("glSamplerParameterf");
	fp_glSamplerParameterfv = (pfn_glSamplerParameterfv)load("glSamplerParameterfv");
	fp_glSamplerParameterIiv = (pfn_glSamplerParameterIiv)load("glSamplerParameterIiv");
	fp_glSamplerParameterIuiv = (pfn_glSamplerParameterIuiv)load("glSamplerParameterIuiv");
	fp_glGetSamplerParameteriv = (pfn_glGetSamplerParameteriv)load("glGetSamplerParameteriv");
	fp_glGetSamplerParameterIiv = (pfn_glGetSamplerParameterIiv)load("glGetSamplerParameterIiv");
	fp_glGetSamplerParameterfv = (pfn_glGetSamplerParameterfv)load("glGetSamplerParameterfv");
	fp_glGetSamplerParameterIuiv = (pfn_glGetSamplerParameterIuiv)load("glGetSamplerParameterIuiv");
	fp_glQueryCounter = (pfn_glQueryCounter)load("glQueryCounter");
	fp_glGetQueryObjecti64v = (pfn_glGetQueryObjecti64v)load("glGetQueryObjecti64v");
	fp_glGetQueryObjectui64v = (pfn_glGetQueryObjectui64v)load("glGetQueryObjectui64v");
	fp_glVertexAttribDivisor = (pfn_glVertexAttribDivisor)load("glVertexAttribDivisor");
	fp_glVertexAttribP1ui = (pfn_glVertexAttribP1ui)load("glVertexAttribP1ui");
	fp_glVertexAttribP1uiv = (pfn_glVertexAttribP1uiv)load("glVertexAttribP1uiv");
	fp_glVertexAttribP2ui = (pfn_glVertexAttribP2ui)load("glVertexAttribP2ui");
	fp_glVertexAttribP2uiv = (pfn_glVertexAttribP2uiv)load("glVertexAttribP2uiv");
	fp_glVertexAttribP3ui = (pfn_glVertexAttribP3ui)load("glVertexAttribP3ui");
	fp_glVertexAttribP3uiv = (pfn_glVertexAttribP3uiv)load("glVertexAttribP3uiv");
	fp_glVertexAttribP4ui = (pfn_glVertexAttribP4ui)load("glVertexAttribP4ui");
	fp_glVertexAttribP4uiv = (pfn_glVertexAttribP4uiv)load("glVertexAttribP4uiv");
	fp_glVertexP2ui = (pfn_glVertexP2ui)load("glVertexP2ui");
	fp_glVertexP2uiv = (pfn_glVertexP2uiv)load("glVertexP2uiv");
	fp_glVertexP3ui = (pfn_glVertexP3ui)load("glVertexP3ui");
	fp_glVertexP3uiv = (pfn_glVertexP3uiv)load("glVertexP3uiv");
	fp_glVertexP4ui = (pfn_glVertexP4ui)load("glVertexP4ui");
	fp_glVertexP4uiv = (pfn_glVertexP4uiv)load("glVertexP4uiv");
	fp_glTexCoordP1ui = (pfn_glTexCoordP1ui)load("glTexCoordP1ui");
	fp_glTexCoordP1uiv = (pfn_glTexCoordP1uiv)load("glTexCoordP1uiv");
	fp_glTexCoordP2ui = (pfn_glTexCoordP2ui)load("glTexCoordP2ui");
	fp_glTexCoordP2uiv = (pfn_glTexCoordP2uiv)load("glTexCoordP2uiv");
	fp_glTexCoordP3ui = (pfn_glTexCoordP3ui)load("glTexCoordP3ui");
	fp_glTexCoordP3uiv = (pfn_glTexCoordP3uiv)load("glTexCoordP3uiv");
	fp_glTexCoordP4ui = (pfn_glTexCoordP4ui)load("glTexCoordP4ui");
	fp_glTexCoordP4uiv = (pfn_glTexCoordP4uiv)load("glTexCoordP4uiv");
	fp_glMultiTexCoordP1ui = (pfn_glMultiTexCoordP1ui)load("glMultiTexCoordP1ui");
	fp_glMultiTexCoordP1uiv = (pfn_glMultiTexCoordP1uiv)load("glMultiTexCoordP1uiv");
	fp_glMultiTexCoordP2ui = (pfn_glMultiTexCoordP2ui)load("glMultiTexCoordP2ui");
	fp_glMultiTexCoordP2uiv = (pfn_glMultiTexCoordP2uiv)load("glMultiTexCoordP2uiv");
	fp_glMultiTexCoordP3ui = (pfn_glMultiTexCoordP3ui)load("glMultiTexCoordP3ui");
	fp_glMultiTexCoordP3uiv = (pfn_glMultiTexCoordP3uiv)load("glMultiTexCoordP3uiv");
	fp_glMultiTexCoordP4ui = (pfn_glMultiTexCoordP4ui)load("glMultiTexCoordP4ui");
	fp_glMultiTexCoordP4uiv = (pfn_glMultiTexCoordP4uiv)load("glMultiTexCoordP4uiv");
	fp_glNormalP3ui = (pfn_glNormalP3ui)load("glNormalP3ui");
	fp_glNormalP3uiv = (pfn_glNormalP3uiv)load("glNormalP3uiv");
	fp_glColorP3ui = (pfn_glColorP3ui)load("glColorP3ui");
	fp_glColorP3uiv = (pfn_glColorP3uiv)load("glColorP3uiv");
	fp_glColorP4ui = (pfn_glColorP4ui)load("glColorP4ui");
	fp_glColorP4uiv = (pfn_glColorP4uiv)load("glColorP4uiv");
	fp_glSecondaryColorP3ui = (pfn_glSecondaryColorP3ui)load("glSecondaryColorP3ui");
	fp_glSecondaryColorP3uiv = (pfn_glSecondaryColorP3uiv)load("glSecondaryColorP3uiv");
}

GLboolean GLAD_VERSION_4_0 = GL_FALSE;
static void load_GL_VERSION_4_0(LOADER load) {
	if(!GLAD_VERSION_4_0) return;
	fp_glMinSampleShading = (pfn_glMinSampleShading)load("glMinSampleShading");
	fp_glBlendEquationi = (pfn_glBlendEquationi)load("glBlendEquationi");
	fp_glBlendEquationSeparatei = (pfn_glBlendEquationSeparatei)load("glBlendEquationSeparatei");
	fp_glBlendFunci = (pfn_glBlendFunci)load("glBlendFunci");
	fp_glBlendFuncSeparatei = (pfn_glBlendFuncSeparatei)load("glBlendFuncSeparatei");
	fp_glDrawArraysIndirect = (pfn_glDrawArraysIndirect)load("glDrawArraysIndirect");
	fp_glDrawElementsIndirect = (pfn_glDrawElementsIndirect)load("glDrawElementsIndirect");
	fp_glUniform1d = (pfn_glUniform1d)load("glUniform1d");
	fp_glUniform2d = (pfn_glUniform2d)load("glUniform2d");
	fp_glUniform3d = (pfn_glUniform3d)load("glUniform3d");
	fp_glUniform4d = (pfn_glUniform4d)load("glUniform4d");
	fp_glUniform1dv = (pfn_glUniform1dv)load("glUniform1dv");
	fp_glUniform2dv = (pfn_glUniform2dv)load("glUniform2dv");
	fp_glUniform3dv = (pfn_glUniform3dv)load("glUniform3dv");
	fp_glUniform4dv = (pfn_glUniform4dv)load("glUniform4dv");
	fp_glUniformMatrix2dv = (pfn_glUniformMatrix2dv)load("glUniformMatrix2dv");
	fp_glUniformMatrix3dv = (pfn_glUniformMatrix3dv)load("glUniformMatrix3dv");
	fp_glUniformMatrix4dv = (pfn_glUniformMatrix4dv)load("glUniformMatrix4dv");
	fp_glUniformMatrix2x3dv = (pfn_glUniformMatrix2x3dv)load("glUniformMatrix2x3dv");
	fp_glUniformMatrix2x4dv = (pfn_glUniformMatrix2x4dv)load("glUniformMatrix2x4dv");
	fp_glUniformMatrix3x2dv = (pfn_glUniformMatrix3x2dv)load("glUniformMatrix3x2dv");
	fp_glUniformMatrix3x4dv = (pfn_glUniformMatrix3x4dv)load("glUniformMatrix3x4dv");
	fp_glUniformMatrix4x2dv = (pfn_glUniformMatrix4x2dv)load("glUniformMatrix4x2dv");
	fp_glUniformMatrix4x3dv = (pfn_glUniformMatrix4x3dv)load("glUniformMatrix4x3dv");
	fp_glGetUniformdv = (pfn_glGetUniformdv)load("glGetUniformdv");
	fp_glGetSubroutineUniformLocation = (pfn_glGetSubroutineUniformLocation)load("glGetSubroutineUniformLocation");
	fp_glGetSubroutineIndex = (pfn_glGetSubroutineIndex)load("glGetSubroutineIndex");
	fp_glGetActiveSubroutineUniformiv = (pfn_glGetActiveSubroutineUniformiv)load("glGetActiveSubroutineUniformiv");
	fp_glGetActiveSubroutineUniformName = (pfn_glGetActiveSubroutineUniformName)load("glGetActiveSubroutineUniformName");
	fp_glGetActiveSubroutineName = (pfn_glGetActiveSubroutineName)load("glGetActiveSubroutineName");
	fp_glUniformSubroutinesuiv = (pfn_glUniformSubroutinesuiv)load("glUniformSubroutinesuiv");
	fp_glGetUniformSubroutineuiv = (pfn_glGetUniformSubroutineuiv)load("glGetUniformSubroutineuiv");
	fp_glGetProgramStageiv = (pfn_glGetProgramStageiv)load("glGetProgramStageiv");
	fp_glPatchParameteri = (pfn_glPatchParameteri)load("glPatchParameteri");
	fp_glPatchParameterfv = (pfn_glPatchParameterfv)load("glPatchParameterfv");
	fp_glBindTransformFeedback = (pfn_glBindTransformFeedback)load("glBindTransformFeedback");
	fp_glDeleteTransformFeedbacks = (pfn_glDeleteTransformFeedbacks)load("glDeleteTransformFeedbacks");
	fp_glGenTransformFeedbacks = (pfn_glGenTransformFeedbacks)load("glGenTransformFeedbacks");
	fp_glIsTransformFeedback = (pfn_glIsTransformFeedback)load("glIsTransformFeedback");
	fp_glPauseTransformFeedback = (pfn_glPauseTransformFeedback)load("glPauseTransformFeedback");
	fp_glResumeTransformFeedback = (pfn_glResumeTransformFeedback)load("glResumeTransformFeedback");
	fp_glDrawTransformFeedback = (pfn_glDrawTransformFeedback)load("glDrawTransformFeedback");
	fp_glDrawTransformFeedbackStream = (pfn_glDrawTransformFeedbackStream)load("glDrawTransformFeedbackStream");
	fp_glBeginQueryIndexed = (pfn_glBeginQueryIndexed)load("glBeginQueryIndexed");
	fp_glEndQueryIndexed = (pfn_glEndQueryIndexed)load("glEndQueryIndexed");
	fp_glGetQueryIndexediv = (pfn_glGetQueryIndexediv)load("glGetQueryIndexediv");
}

GLboolean GLAD_VERSION_4_1 = GL_FALSE;
static void load_GL_VERSION_4_1(LOADER load) {
	if(!GLAD_VERSION_4_1) return;
	fp_glReleaseShaderCompiler = (pfn_glReleaseShaderCompiler)load("glReleaseShaderCompiler");
	fp_glShaderBinary = (pfn_glShaderBinary)load("glShaderBinary");
	fp_glGetShaderPrecisionFormat = (pfn_glGetShaderPrecisionFormat)load("glGetShaderPrecisionFormat");
	fp_glDepthRangef = (pfn_glDepthRangef)load("glDepthRangef");
	fp_glClearDepthf = (pfn_glClearDepthf)load("glClearDepthf");
	fp_glGetProgramBinary = (pfn_glGetProgramBinary)load("glGetProgramBinary");
	fp_glProgramBinary = (pfn_glProgramBinary)load("glProgramBinary");
	fp_glProgramParameteri = (pfn_glProgramParameteri)load("glProgramParameteri");
	fp_glUseProgramStages = (pfn_glUseProgramStages)load("glUseProgramStages");
	fp_glActiveShaderProgram = (pfn_glActiveShaderProgram)load("glActiveShaderProgram");
	fp_glCreateShaderProgramv = (pfn_glCreateShaderProgramv)load("glCreateShaderProgramv");
	fp_glBindProgramPipeline = (pfn_glBindProgramPipeline)load("glBindProgramPipeline");
	fp_glDeleteProgramPipelines = (pfn_glDeleteProgramPipelines)load("glDeleteProgramPipelines");
	fp_glGenProgramPipelines = (pfn_glGenProgramPipelines)load("glGenProgramPipelines");
	fp_glIsProgramPipeline = (pfn_glIsProgramPipeline)load("glIsProgramPipeline");
	fp_glGetProgramPipelineiv = (pfn_glGetProgramPipelineiv)load("glGetProgramPipelineiv");
	fp_glProgramUniform1i = (pfn_glProgramUniform1i)load("glProgramUniform1i");
	fp_glProgramUniform1iv = (pfn_glProgramUniform1iv)load("glProgramUniform1iv");
	fp_glProgramUniform1f = (pfn_glProgramUniform1f)load("glProgramUniform1f");
	fp_glProgramUniform1fv = (pfn_glProgramUniform1fv)load("glProgramUniform1fv");
	fp_glProgramUniform1d = (pfn_glProgramUniform1d)load("glProgramUniform1d");
	fp_glProgramUniform1dv = (pfn_glProgramUniform1dv)load("glProgramUniform1dv");
	fp_glProgramUniform1ui = (pfn_glProgramUniform1ui)load("glProgramUniform1ui");
	fp_glProgramUniform1uiv = (pfn_glProgramUniform1uiv)load("glProgramUniform1uiv");
	fp_glProgramUniform2i = (pfn_glProgramUniform2i)load("glProgramUniform2i");
	fp_glProgramUniform2iv = (pfn_glProgramUniform2iv)load("glProgramUniform2iv");
	fp_glProgramUniform2f = (pfn_glProgramUniform2f)load("glProgramUniform2f");
	fp_glProgramUniform2fv = (pfn_glProgramUniform2fv)load("glProgramUniform2fv");
	fp_glProgramUniform2d = (pfn_glProgramUniform2d)load("glProgramUniform2d");
	fp_glProgramUniform2dv = (pfn_glProgramUniform2dv)load("glProgramUniform2dv");
	fp_glProgramUniform2ui = (pfn_glProgramUniform2ui)load("glProgramUniform2ui");
	fp_glProgramUniform2uiv = (pfn_glProgramUniform2uiv)load("glProgramUniform2uiv");
	fp_glProgramUniform3i = (pfn_glProgramUniform3i)load("glProgramUniform3i");
	fp_glProgramUniform3iv = (pfn_glProgramUniform3iv)load("glProgramUniform3iv");
	fp_glProgramUniform3f = (pfn_glProgramUniform3f)load("glProgramUniform3f");
	fp_glProgramUniform3fv = (pfn_glProgramUniform3fv)load("glProgramUniform3fv");
	fp_glProgramUniform3d = (pfn_glProgramUniform3d)load("glProgramUniform3d");
	fp_glProgramUniform3dv = (pfn_glProgramUniform3dv)load("glProgramUniform3dv");
	fp_glProgramUniform3ui = (pfn_glProgramUniform3ui)load("glProgramUniform3ui");
	fp_glProgramUniform3uiv = (pfn_glProgramUniform3uiv)load("glProgramUniform3uiv");
	fp_glProgramUniform4i = (pfn_glProgramUniform4i)load("glProgramUniform4i");
	fp_glProgramUniform4iv = (pfn_glProgramUniform4iv)load("glProgramUniform4iv");
	fp_glProgramUniform4f = (pfn_glProgramUniform4f)load("glProgramUniform4f");
	fp_glProgramUniform4fv = (pfn_glProgramUniform4fv)load("glProgramUniform4fv");
	fp_glProgramUniform4d = (pfn_glProgramUniform4d)load("glProgramUniform4d");
	fp_glProgramUniform4dv = (pfn_glProgramUniform4dv)load("glProgramUniform4dv");
	fp_glProgramUniform4ui = (pfn_glProgramUniform4ui)load("glProgramUniform4ui");
	fp_glProgramUniform4uiv = (pfn_glProgramUniform4uiv)load("glProgramUniform4uiv");
	fp_glProgramUniformMatrix2fv = (pfn_glProgramUniformMatrix2fv)load("glProgramUniformMatrix2fv");
	fp_glProgramUniformMatrix3fv = (pfn_glProgramUniformMatrix3fv)load("glProgramUniformMatrix3fv");
	fp_glProgramUniformMatrix4fv = (pfn_glProgramUniformMatrix4fv)load("glProgramUniformMatrix4fv");
	fp_glProgramUniformMatrix2dv = (pfn_glProgramUniformMatrix2dv)load("glProgramUniformMatrix2dv");
	fp_glProgramUniformMatrix3dv = (pfn_glProgramUniformMatrix3dv)load("glProgramUniformMatrix3dv");
	fp_glProgramUniformMatrix4dv = (pfn_glProgramUniformMatrix4dv)load("glProgramUniformMatrix4dv");
	fp_glProgramUniformMatrix2x3fv = (pfn_glProgramUniformMatrix2x3fv)load("glProgramUniformMatrix2x3fv");
	fp_glProgramUniformMatrix3x2fv = (pfn_glProgramUniformMatrix3x2fv)load("glProgramUniformMatrix3x2fv");
	fp_glProgramUniformMatrix2x4fv = (pfn_glProgramUniformMatrix2x4fv)load("glProgramUniformMatrix2x4fv");
	fp_glProgramUniformMatrix4x2fv = (pfn_glProgramUniformMatrix4x2fv)load("glProgramUniformMatrix4x2fv");
	fp_glProgramUniformMatrix3x4fv = (pfn_glProgramUniformMatrix3x4fv)load("glProgramUniformMatrix3x4fv");
	fp_glProgramUniformMatrix4x3fv = (pfn_glProgramUniformMatrix4x3fv)load("glProgramUniformMatrix4x3fv");
	fp_glProgramUniformMatrix2x3dv = (pfn_glProgramUniformMatrix2x3dv)load("glProgramUniformMatrix2x3dv");
	fp_glProgramUniformMatrix3x2dv = (pfn_glProgramUniformMatrix3x2dv)load("glProgramUniformMatrix3x2dv");
	fp_glProgramUniformMatrix2x4dv = (pfn_glProgramUniformMatrix2x4dv)load("glProgramUniformMatrix2x4dv");
	fp_glProgramUniformMatrix4x2dv = (pfn_glProgramUniformMatrix4x2dv)load("glProgramUniformMatrix4x2dv");
	fp_glProgramUniformMatrix3x4dv = (pfn_glProgramUniformMatrix3x4dv)load("glProgramUniformMatrix3x4dv");
	fp_glProgramUniformMatrix4x3dv = (pfn_glProgramUniformMatrix4x3dv)load("glProgramUniformMatrix4x3dv");
	fp_glValidateProgramPipeline = (pfn_glValidateProgramPipeline)load("glValidateProgramPipeline");
	fp_glGetProgramPipelineInfoLog = (pfn_glGetProgramPipelineInfoLog)load("glGetProgramPipelineInfoLog");
	fp_glVertexAttribL1d = (pfn_glVertexAttribL1d)load("glVertexAttribL1d");
	fp_glVertexAttribL2d = (pfn_glVertexAttribL2d)load("glVertexAttribL2d");
	fp_glVertexAttribL3d = (pfn_glVertexAttribL3d)load("glVertexAttribL3d");
	fp_glVertexAttribL4d = (pfn_glVertexAttribL4d)load("glVertexAttribL4d");
	fp_glVertexAttribL1dv = (pfn_glVertexAttribL1dv)load("glVertexAttribL1dv");
	fp_glVertexAttribL2dv = (pfn_glVertexAttribL2dv)load("glVertexAttribL2dv");
	fp_glVertexAttribL3dv = (pfn_glVertexAttribL3dv)load("glVertexAttribL3dv");
	fp_glVertexAttribL4dv = (pfn_glVertexAttribL4dv)load("glVertexAttribL4dv");
	fp_glVertexAttribLPointer = (pfn_glVertexAttribLPointer)load("glVertexAttribLPointer");
	fp_glGetVertexAttribLdv = (pfn_glGetVertexAttribLdv)load("glGetVertexAttribLdv");
	fp_glViewportArrayv = (pfn_glViewportArrayv)load("glViewportArrayv");
	fp_glViewportIndexedf = (pfn_glViewportIndexedf)load("glViewportIndexedf");
	fp_glViewportIndexedfv = (pfn_glViewportIndexedfv)load("glViewportIndexedfv");
	fp_glScissorArrayv = (pfn_glScissorArrayv)load("glScissorArrayv");
	fp_glScissorIndexed = (pfn_glScissorIndexed)load("glScissorIndexed");
	fp_glScissorIndexedv = (pfn_glScissorIndexedv)load("glScissorIndexedv");
	fp_glDepthRangeArrayv = (pfn_glDepthRangeArrayv)load("glDepthRangeArrayv");
	fp_glDepthRangeIndexed = (pfn_glDepthRangeIndexed)load("glDepthRangeIndexed");
	fp_glGetFloati_v = (pfn_glGetFloati_v)load("glGetFloati_v");
	fp_glGetDoublei_v = (pfn_glGetDoublei_v)load("glGetDoublei_v");
}

GLboolean GLAD_VERSION_4_2 = GL_FALSE;
static void load_GL_VERSION_4_2(LOADER load) {
	if(!GLAD_VERSION_4_2) return;
	fp_glDrawArraysInstancedBaseInstance = (pfn_glDrawArraysInstancedBaseInstance)load("glDrawArraysInstancedBaseInstance");
	fp_glDrawElementsInstancedBaseInstance = (pfn_glDrawElementsInstancedBaseInstance)load("glDrawElementsInstancedBaseInstance");
	fp_glDrawElementsInstancedBaseVertexBaseInstance = (pfn_glDrawElementsInstancedBaseVertexBaseInstance)load("glDrawElementsInstancedBaseVertexBaseInstance");
	fp_glGetInternalformativ = (pfn_glGetInternalformativ)load("glGetInternalformativ");
	fp_glGetActiveAtomicCounterBufferiv = (pfn_glGetActiveAtomicCounterBufferiv)load("glGetActiveAtomicCounterBufferiv");
	fp_glBindImageTexture = (pfn_glBindImageTexture)load("glBindImageTexture");
	fp_glMemoryBarrier = (pfn_glMemoryBarrier)load("glMemoryBarrier");
	fp_glTexStorage1D = (pfn_glTexStorage1D)load("glTexStorage1D");
	fp_glTexStorage2D = (pfn_glTexStorage2D)load("glTexStorage2D");
	fp_glTexStorage3D = (pfn_glTexStorage3D)load("glTexStorage3D");
	fp_glDrawTransformFeedbackInstanced = (pfn_glDrawTransformFeedbackInstanced)load("glDrawTransformFeedbackInstanced");
	fp_glDrawTransformFeedbackStreamInstanced = (pfn_glDrawTransformFeedbackStreamInstanced)load("glDrawTransformFeedbackStreamInstanced");
}

GLboolean GLAD_VERSION_4_3 = GL_FALSE;
static void load_GL_VERSION_4_3(LOADER load) {
	if(!GLAD_VERSION_4_3) return;
	fp_glClearBufferData = (pfn_glClearBufferData)load("glClearBufferData");
	fp_glClearBufferSubData = (pfn_glClearBufferSubData)load("glClearBufferSubData");
	fp_glDispatchCompute = (pfn_glDispatchCompute)load("glDispatchCompute");
	fp_glDispatchComputeIndirect = (pfn_glDispatchComputeIndirect)load("glDispatchComputeIndirect");
	fp_glCopyImageSubData = (pfn_glCopyImageSubData)load("glCopyImageSubData");
	fp_glFramebufferParameteri = (pfn_glFramebufferParameteri)load("glFramebufferParameteri");
	fp_glGetFramebufferParameteriv = (pfn_glGetFramebufferParameteriv)load("glGetFramebufferParameteriv");
	fp_glGetInternalformati64v = (pfn_glGetInternalformati64v)load("glGetInternalformati64v");
	fp_glInvalidateTexSubImage = (pfn_glInvalidateTexSubImage)load("glInvalidateTexSubImage");
	fp_glInvalidateTexImage = (pfn_glInvalidateTexImage)load("glInvalidateTexImage");
	fp_glInvalidateBufferSubData = (pfn_glInvalidateBufferSubData)load("glInvalidateBufferSubData");
	fp_glInvalidateBufferData = (pfn_glInvalidateBufferData)load("glInvalidateBufferData");
	fp_glInvalidateFramebuffer = (pfn_glInvalidateFramebuffer)load("glInvalidateFramebuffer");
	fp_glInvalidateSubFramebuffer = (pfn_glInvalidateSubFramebuffer)load("glInvalidateSubFramebuffer");
	fp_glMultiDrawArraysIndirect = (pfn_glMultiDrawArraysIndirect)load("glMultiDrawArraysIndirect");
	fp_glMultiDrawElementsIndirect = (pfn_glMultiDrawElementsIndirect)load("glMultiDrawElementsIndirect");
	fp_glGetProgramInterfaceiv = (pfn_glGetProgramInterfaceiv)load("glGetProgramInterfaceiv");
	fp_glGetProgramResourceIndex = (pfn_glGetProgramResourceIndex)load("glGetProgramResourceIndex");
	fp_glGetProgramResourceName = (pfn_glGetProgramResourceName)load("glGetProgramResourceName");
	fp_glGetProgramResourceiv = (pfn_glGetProgramResourceiv)load("glGetProgramResourceiv");
	fp_glGetProgramResourceLocation = (pfn_glGetProgramResourceLocation)load("glGetProgramResourceLocation");
	fp_glGetProgramResourceLocationIndex = (pfn_glGetProgramResourceLocationIndex)load("glGetProgramResourceLocationIndex");
	fp_glShaderStorageBlockBinding = (pfn_glShaderStorageBlockBinding)load("glShaderStorageBlockBinding");
	fp_glTexBufferRange = (pfn_glTexBufferRange)load("glTexBufferRange");
	fp_glTexStorage2DMultisample = (pfn_glTexStorage2DMultisample)load("glTexStorage2DMultisample");
	fp_glTexStorage3DMultisample = (pfn_glTexStorage3DMultisample)load("glTexStorage3DMultisample");
	fp_glTextureView = (pfn_glTextureView)load("glTextureView");
	fp_glBindVertexBuffer = (pfn_glBindVertexBuffer)load("glBindVertexBuffer");
	fp_glVertexAttribFormat = (pfn_glVertexAttribFormat)load("glVertexAttribFormat");
	fp_glVertexAttribIFormat = (pfn_glVertexAttribIFormat)load("glVertexAttribIFormat");
	fp_glVertexAttribLFormat = (pfn_glVertexAttribLFormat)load("glVertexAttribLFormat");
	fp_glVertexAttribBinding = (pfn_glVertexAttribBinding)load("glVertexAttribBinding");
	fp_glVertexBindingDivisor = (pfn_glVertexBindingDivisor)load("glVertexBindingDivisor");
	fp_glDebugMessageControl = (pfn_glDebugMessageControl)load("glDebugMessageControl");
	fp_glDebugMessageInsert = (pfn_glDebugMessageInsert)load("glDebugMessageInsert");
	fp_glDebugMessageCallback = (pfn_glDebugMessageCallback)load("glDebugMessageCallback");
	fp_glGetDebugMessageLog = (pfn_glGetDebugMessageLog)load("glGetDebugMessageLog");
	fp_glPushDebugGroup = (pfn_glPushDebugGroup)load("glPushDebugGroup");
	fp_glPopDebugGroup = (pfn_glPopDebugGroup)load("glPopDebugGroup");
	fp_glObjectLabel = (pfn_glObjectLabel)load("glObjectLabel");
	fp_glGetObjectLabel = (pfn_glGetObjectLabel)load("glGetObjectLabel");
	fp_glObjectPtrLabel = (pfn_glObjectPtrLabel)load("glObjectPtrLabel");
	fp_glGetObjectPtrLabel = (pfn_glGetObjectPtrLabel)load("glGetObjectPtrLabel");
	fp_glGetPointerv = (pfn_glGetPointerv)load("glGetPointerv");
	fp_glGetPointerv = (pfn_glGetPointerv)load("glGetPointerv");
}

GLboolean GLAD_VERSION_4_4 = GL_FALSE;
static void load_GL_VERSION_4_4(LOADER load) {
	if(!GLAD_VERSION_4_4) return;
	fp_glBufferStorage = (pfn_glBufferStorage)load("glBufferStorage");
	fp_glClearTexImage = (pfn_glClearTexImage)load("glClearTexImage");
	fp_glClearTexSubImage = (pfn_glClearTexSubImage)load("glClearTexSubImage");
	fp_glBindBuffersBase = (pfn_glBindBuffersBase)load("glBindBuffersBase");
	fp_glBindBuffersRange = (pfn_glBindBuffersRange)load("glBindBuffersRange");
	fp_glBindTextures = (pfn_glBindTextures)load("glBindTextures");
	fp_glBindSamplers = (pfn_glBindSamplers)load("glBindSamplers");
	fp_glBindImageTextures = (pfn_glBindImageTextures)load("glBindImageTextures");
	fp_glBindVertexBuffers = (pfn_glBindVertexBuffers)load("glBindVertexBuffers");
}

GLboolean GLAD_VERSION_4_5 = GL_FALSE;
static void load_GL_VERSION_4_5(LOADER load) {
	if(!GLAD_VERSION_4_5) return;
	fp_glClipControl = (pfn_glClipControl)load("glClipControl");
	fp_glCreateTransformFeedbacks = (pfn_glCreateTransformFeedbacks)load("glCreateTransformFeedbacks");
	fp_glTransformFeedbackBufferBase = (pfn_glTransformFeedbackBufferBase)load("glTransformFeedbackBufferBase");
	fp_glTransformFeedbackBufferRange = (pfn_glTransformFeedbackBufferRange)load("glTransformFeedbackBufferRange");
	fp_glGetTransformFeedbackiv = (pfn_glGetTransformFeedbackiv)load("glGetTransformFeedbackiv");
	fp_glGetTransformFeedbacki_v = (pfn_glGetTransformFeedbacki_v)load("glGetTransformFeedbacki_v");
	fp_glGetTransformFeedbacki64_v = (pfn_glGetTransformFeedbacki64_v)load("glGetTransformFeedbacki64_v");
	fp_glCreateBuffers = (pfn_glCreateBuffers)load("glCreateBuffers");
	fp_glNamedBufferStorage = (pfn_glNamedBufferStorage)load("glNamedBufferStorage");
	fp_glNamedBufferData = (pfn_glNamedBufferData)load("glNamedBufferData");
	fp_glNamedBufferSubData = (pfn_glNamedBufferSubData)load("glNamedBufferSubData");
	fp_glCopyNamedBufferSubData = (pfn_glCopyNamedBufferSubData)load("glCopyNamedBufferSubData");
	fp_glClearNamedBufferData = (pfn_glClearNamedBufferData)load("glClearNamedBufferData");
	fp_glClearNamedBufferSubData = (pfn_glClearNamedBufferSubData)load("glClearNamedBufferSubData");
	fp_glMapNamedBuffer = (pfn_glMapNamedBuffer)load("glMapNamedBuffer");
	fp_glMapNamedBufferRange = (pfn_glMapNamedBufferRange)load("glMapNamedBufferRange");
	fp_glUnmapNamedBuffer = (pfn_glUnmapNamedBuffer)load("glUnmapNamedBuffer");
	fp_glFlushMappedNamedBufferRange = (pfn_glFlushMappedNamedBufferRange)load("glFlushMappedNamedBufferRange");
	fp_glGetNamedBufferParameteriv = (pfn_glGetNamedBufferParameteriv)load("glGetNamedBufferParameteriv");
	fp_glGetNamedBufferParameteri64v = (pfn_glGetNamedBufferParameteri64v)load("glGetNamedBufferParameteri64v");
	fp_glGetNamedBufferPointerv = (pfn_glGetNamedBufferPointerv)load("glGetNamedBufferPointerv");
	fp_glGetNamedBufferSubData = (pfn_glGetNamedBufferSubData)load("glGetNamedBufferSubData");
	fp_glCreateFramebuffers = (pfn_glCreateFramebuffers)load("glCreateFramebuffers");
	fp_glNamedFramebufferRenderbuffer = (pfn_glNamedFramebufferRenderbuffer)load("glNamedFramebufferRenderbuffer");
	fp_glNamedFramebufferParameteri = (pfn_glNamedFramebufferParameteri)load("glNamedFramebufferParameteri");
	fp_glNamedFramebufferTexture = (pfn_glNamedFramebufferTexture)load("glNamedFramebufferTexture");
	fp_glNamedFramebufferTextureLayer = (pfn_glNamedFramebufferTextureLayer)load("glNamedFramebufferTextureLayer");
	fp_glNamedFramebufferDrawBuffer = (pfn_glNamedFramebufferDrawBuffer)load("glNamedFramebufferDrawBuffer");
	fp_glNamedFramebufferDrawBuffers = (pfn_glNamedFramebufferDrawBuffers)load("glNamedFramebufferDrawBuffers");
	fp_glNamedFramebufferReadBuffer = (pfn_glNamedFramebufferReadBuffer)load("glNamedFramebufferReadBuffer");
	fp_glInvalidateNamedFramebufferData = (pfn_glInvalidateNamedFramebufferData)load("glInvalidateNamedFramebufferData");
	fp_glInvalidateNamedFramebufferSubData = (pfn_glInvalidateNamedFramebufferSubData)load("glInvalidateNamedFramebufferSubData");
	fp_glClearNamedFramebufferiv = (pfn_glClearNamedFramebufferiv)load("glClearNamedFramebufferiv");
	fp_glClearNamedFramebufferuiv = (pfn_glClearNamedFramebufferuiv)load("glClearNamedFramebufferuiv");
	fp_glClearNamedFramebufferfv = (pfn_glClearNamedFramebufferfv)load("glClearNamedFramebufferfv");
	fp_glClearNamedFramebufferfi = (pfn_glClearNamedFramebufferfi)load("glClearNamedFramebufferfi");
	fp_glBlitNamedFramebuffer = (pfn_glBlitNamedFramebuffer)load("glBlitNamedFramebuffer");
	fp_glCheckNamedFramebufferStatus = (pfn_glCheckNamedFramebufferStatus)load("glCheckNamedFramebufferStatus");
	fp_glGetNamedFramebufferParameteriv = (pfn_glGetNamedFramebufferParameteriv)load("glGetNamedFramebufferParameteriv");
	fp_glGetNamedFramebufferAttachmentParameteriv = (pfn_glGetNamedFramebufferAttachmentParameteriv)load("glGetNamedFramebufferAttachmentParameteriv");
	fp_glCreateRenderbuffers = (pfn_glCreateRenderbuffers)load("glCreateRenderbuffers");
	fp_glNamedRenderbufferStorage = (pfn_glNamedRenderbufferStorage)load("glNamedRenderbufferStorage");
	fp_glNamedRenderbufferStorageMultisample = (pfn_glNamedRenderbufferStorageMultisample)load("glNamedRenderbufferStorageMultisample");
	fp_glGetNamedRenderbufferParameteriv = (pfn_glGetNamedRenderbufferParameteriv)load("glGetNamedRenderbufferParameteriv");
	fp_glCreateTextures = (pfn_glCreateTextures)load("glCreateTextures");
	fp_glTextureBuffer = (pfn_glTextureBuffer)load("glTextureBuffer");
	fp_glTextureBufferRange = (pfn_glTextureBufferRange)load("glTextureBufferRange");
	fp_glTextureStorage1D = (pfn_glTextureStorage1D)load("glTextureStorage1D");
	fp_glTextureStorage2D = (pfn_glTextureStorage2D)load("glTextureStorage2D");
	fp_glTextureStorage3D = (pfn_glTextureStorage3D)load("glTextureStorage3D");
	fp_glTextureStorage2DMultisample = (pfn_glTextureStorage2DMultisample)load("glTextureStorage2DMultisample");
	fp_glTextureStorage3DMultisample = (pfn_glTextureStorage3DMultisample)load("glTextureStorage3DMultisample");
	fp_glTextureSubImage1D = (pfn_glTextureSubImage1D)load("glTextureSubImage1D");
	fp_glTextureSubImage2D = (pfn_glTextureSubImage2D)load("glTextureSubImage2D");
	fp_glTextureSubImage3D = (pfn_glTextureSubImage3D)load("glTextureSubImage3D");
	fp_glCompressedTextureSubImage1D = (pfn_glCompressedTextureSubImage1D)load("glCompressedTextureSubImage1D");
	fp_glCompressedTextureSubImage2D = (pfn_glCompressedTextureSubImage2D)load("glCompressedTextureSubImage2D");
	fp_glCompressedTextureSubImage3D = (pfn_glCompressedTextureSubImage3D)load("glCompressedTextureSubImage3D");
	fp_glCopyTextureSubImage1D = (pfn_glCopyTextureSubImage1D)load("glCopyTextureSubImage1D");
	fp_glCopyTextureSubImage2D = (pfn_glCopyTextureSubImage2D)load("glCopyTextureSubImage2D");
	fp_glCopyTextureSubImage3D = (pfn_glCopyTextureSubImage3D)load("glCopyTextureSubImage3D");
	fp_glTextureParameterf = (pfn_glTextureParameterf)load("glTextureParameterf");
	fp_glTextureParameterfv = (pfn_glTextureParameterfv)load("glTextureParameterfv");
	fp_glTextureParameteri = (pfn_glTextureParameteri)load("glTextureParameteri");
	fp_glTextureParameterIiv = (pfn_glTextureParameterIiv)load("glTextureParameterIiv");
	fp_glTextureParameterIuiv = (pfn_glTextureParameterIuiv)load("glTextureParameterIuiv");
	fp_glTextureParameteriv = (pfn_glTextureParameteriv)load("glTextureParameteriv");
	fp_glGenerateTextureMipmap = (pfn_glGenerateTextureMipmap)load("glGenerateTextureMipmap");
	fp_glBindTextureUnit = (pfn_glBindTextureUnit)load("glBindTextureUnit");
	fp_glGetTextureImage = (pfn_glGetTextureImage)load("glGetTextureImage");
	fp_glGetCompressedTextureImage = (pfn_glGetCompressedTextureImage)load("glGetCompressedTextureImage");
	fp_glGetTextureLevelParameterfv = (pfn_glGetTextureLevelParameterfv)load("glGetTextureLevelParameterfv");
	fp_glGetTextureLevelParameteriv = (pfn_glGetTextureLevelParameteriv)load("glGetTextureLevelParameteriv");
	fp_glGetTextureParameterfv = (pfn_glGetTextureParameterfv)load("glGetTextureParameterfv");
	fp_glGetTextureParameterIiv = (pfn_glGetTextureParameterIiv)load("glGetTextureParameterIiv");
	fp_glGetTextureParameterIuiv = (pfn_glGetTextureParameterIuiv)load("glGetTextureParameterIuiv");
	fp_glGetTextureParameteriv = (pfn_glGetTextureParameteriv)load("glGetTextureParameteriv");
	fp_glCreateVertexArrays = (pfn_glCreateVertexArrays)load("glCreateVertexArrays");
	fp_glDisableVertexArrayAttrib = (pfn_glDisableVertexArrayAttrib)load("glDisableVertexArrayAttrib");
	fp_glEnableVertexArrayAttrib = (pfn_glEnableVertexArrayAttrib)load("glEnableVertexArrayAttrib");
	fp_glVertexArrayElementBuffer = (pfn_glVertexArrayElementBuffer)load("glVertexArrayElementBuffer");
	fp_glVertexArrayVertexBuffer = (pfn_glVertexArrayVertexBuffer)load("glVertexArrayVertexBuffer");
	fp_glVertexArrayVertexBuffers = (pfn_glVertexArrayVertexBuffers)load("glVertexArrayVertexBuffers");
	fp_glVertexArrayAttribBinding = (pfn_glVertexArrayAttribBinding)load("glVertexArrayAttribBinding");
	fp_glVertexArrayAttribFormat = (pfn_glVertexArrayAttribFormat)load("glVertexArrayAttribFormat");
	fp_glVertexArrayAttribIFormat = (pfn_glVertexArrayAttribIFormat)load("glVertexArrayAttribIFormat");
	fp_glVertexArrayAttribLFormat = (pfn_glVertexArrayAttribLFormat)load("glVertexArrayAttribLFormat");
	fp_glVertexArrayBindingDivisor = (pfn_glVertexArrayBindingDivisor)load("glVertexArrayBindingDivisor");
	fp_glGetVertexArrayiv = (pfn_glGetVertexArrayiv)load("glGetVertexArrayiv");
	fp_glGetVertexArrayIndexediv = (pfn_glGetVertexArrayIndexediv)load("glGetVertexArrayIndexediv");
	fp_glGetVertexArrayIndexed64iv = (pfn_glGetVertexArrayIndexed64iv)load("glGetVertexArrayIndexed64iv");
	fp_glCreateSamplers = (pfn_glCreateSamplers)load("glCreateSamplers");
	fp_glCreateProgramPipelines = (pfn_glCreateProgramPipelines)load("glCreateProgramPipelines");
	fp_glCreateQueries = (pfn_glCreateQueries)load("glCreateQueries");
	fp_glGetQueryBufferObjecti64v = (pfn_glGetQueryBufferObjecti64v)load("glGetQueryBufferObjecti64v");
	fp_glGetQueryBufferObjectiv = (pfn_glGetQueryBufferObjectiv)load("glGetQueryBufferObjectiv");
	fp_glGetQueryBufferObjectui64v = (pfn_glGetQueryBufferObjectui64v)load("glGetQueryBufferObjectui64v");
	fp_glGetQueryBufferObjectuiv = (pfn_glGetQueryBufferObjectuiv)load("glGetQueryBufferObjectuiv");
	fp_glMemoryBarrierByRegion = (pfn_glMemoryBarrierByRegion)load("glMemoryBarrierByRegion");
	fp_glGetTextureSubImage = (pfn_glGetTextureSubImage)load("glGetTextureSubImage");
	fp_glGetCompressedTextureSubImage = (pfn_glGetCompressedTextureSubImage)load("glGetCompressedTextureSubImage");
	fp_glGetGraphicsResetStatus = (pfn_glGetGraphicsResetStatus)load("glGetGraphicsResetStatus");
	fp_glGetnCompressedTexImage = (pfn_glGetnCompressedTexImage)load("glGetnCompressedTexImage");
	fp_glGetnTexImage = (pfn_glGetnTexImage)load("glGetnTexImage");
	fp_glGetnUniformdv = (pfn_glGetnUniformdv)load("glGetnUniformdv");
	fp_glGetnUniformfv = (pfn_glGetnUniformfv)load("glGetnUniformfv");
	fp_glGetnUniformiv = (pfn_glGetnUniformiv)load("glGetnUniformiv");
	fp_glGetnUniformuiv = (pfn_glGetnUniformuiv)load("glGetnUniformuiv");
	fp_glReadnPixels = (pfn_glReadnPixels)load("glReadnPixels");
	fp_glGetnMapdv = (pfn_glGetnMapdv)load("glGetnMapdv");
	fp_glGetnMapfv = (pfn_glGetnMapfv)load("glGetnMapfv");
	fp_glGetnMapiv = (pfn_glGetnMapiv)load("glGetnMapiv");
	fp_glGetnPixelMapfv = (pfn_glGetnPixelMapfv)load("glGetnPixelMapfv");
	fp_glGetnPixelMapuiv = (pfn_glGetnPixelMapuiv)load("glGetnPixelMapuiv");
	fp_glGetnPixelMapusv = (pfn_glGetnPixelMapusv)load("glGetnPixelMapusv");
	fp_glGetnPolygonStipple = (pfn_glGetnPolygonStipple)load("glGetnPolygonStipple");
	fp_glGetnColorTable = (pfn_glGetnColorTable)load("glGetnColorTable");
	fp_glGetnConvolutionFilter = (pfn_glGetnConvolutionFilter)load("glGetnConvolutionFilter");
	fp_glGetnSeparableFilter = (pfn_glGetnSeparableFilter)load("glGetnSeparableFilter");
	fp_glGetnHistogram = (pfn_glGetnHistogram)load("glGetnHistogram");
	fp_glGetnMinmax = (pfn_glGetnMinmax)load("glGetnMinmax");
	fp_glTextureBarrier = (pfn_glTextureBarrier)load("glTextureBarrier");
}

GLboolean GLAD_ES_VERSION_2_0 = GL_FALSE;
static void load_GL_ES_VERSION_2_0(LOADER load) {
	if(!GLAD_ES_VERSION_2_0) return;
	fp_glActiveTexture = (pfn_glActiveTexture)load("glActiveTexture");
	fp_glAttachShader = (pfn_glAttachShader)load("glAttachShader");
	fp_glBindAttribLocation = (pfn_glBindAttribLocation)load("glBindAttribLocation");
	fp_glBindBuffer = (pfn_glBindBuffer)load("glBindBuffer");
	fp_glBindFramebuffer = (pfn_glBindFramebuffer)load("glBindFramebuffer");
	fp_glBindRenderbuffer = (pfn_glBindRenderbuffer)load("glBindRenderbuffer");
	fp_glBindTexture = (pfn_glBindTexture)load("glBindTexture");
	fp_glBlendColor = (pfn_glBlendColor)load("glBlendColor");
	fp_glBlendEquation = (pfn_glBlendEquation)load("glBlendEquation");
	fp_glBlendEquationSeparate = (pfn_glBlendEquationSeparate)load("glBlendEquationSeparate");
	fp_glBlendFunc = (pfn_glBlendFunc)load("glBlendFunc");
	fp_glBlendFuncSeparate = (pfn_glBlendFuncSeparate)load("glBlendFuncSeparate");
	fp_glBufferData = (pfn_glBufferData)load("glBufferData");
	fp_glBufferSubData = (pfn_glBufferSubData)load("glBufferSubData");
	fp_glCheckFramebufferStatus = (pfn_glCheckFramebufferStatus)load("glCheckFramebufferStatus");
	fp_glClear = (pfn_glClear)load("glClear");
	fp_glClearColor = (pfn_glClearColor)load("glClearColor");
	fp_glClearDepthf = (pfn_glClearDepthf)load("glClearDepthf");
	fp_glClearStencil = (pfn_glClearStencil)load("glClearStencil");
	fp_glColorMask = (pfn_glColorMask)load("glColorMask");
	fp_glCompileShader = (pfn_glCompileShader)load("glCompileShader");
	fp_glCompressedTexImage2D = (pfn_glCompressedTexImage2D)load("glCompressedTexImage2D");
	fp_glCompressedTexSubImage2D = (pfn_glCompressedTexSubImage2D)load("glCompressedTexSubImage2D");
	fp_glCopyTexImage2D = (pfn_glCopyTexImage2D)load("glCopyTexImage2D");
	fp_glCopyTexSubImage2D = (pfn_glCopyTexSubImage2D)load("glCopyTexSubImage2D");
	fp_glCreateProgram = (pfn_glCreateProgram)load("glCreateProgram");
	fp_glCreateShader = (pfn_glCreateShader)load("glCreateShader");
	fp_glCullFace = (pfn_glCullFace)load("glCullFace");
	fp_glDeleteBuffers = (pfn_glDeleteBuffers)load("glDeleteBuffers");
	fp_glDeleteFramebuffers = (pfn_glDeleteFramebuffers)load("glDeleteFramebuffers");
	fp_glDeleteProgram = (pfn_glDeleteProgram)load("glDeleteProgram");
	fp_glDeleteRenderbuffers = (pfn_glDeleteRenderbuffers)load("glDeleteRenderbuffers");
	fp_glDeleteShader = (pfn_glDeleteShader)load("glDeleteShader");
	fp_glDeleteTextures = (pfn_glDeleteTextures)load("glDeleteTextures");
	fp_glDepthFunc = (pfn_glDepthFunc)load("glDepthFunc");
	fp_glDepthMask = (pfn_glDepthMask)load("glDepthMask");
	fp_glDepthRangef = (pfn_glDepthRangef)load("glDepthRangef");
	fp_glDetachShader = (pfn_glDetachShader)load("glDetachShader");
	fp_glDisable = (pfn_glDisable)load("glDisable");
	fp_glDisableVertexAttribArray = (pfn_glDisableVertexAttribArray)load("glDisableVertexAttribArray");
	fp_glDrawArrays = (pfn_glDrawArrays)load("glDrawArrays");
	fp_glDrawElements = (pfn_glDrawElements)load("glDrawElements");
	fp_glEnable = (pfn_glEnable)load("glEnable");
	fp_glEnableVertexAttribArray = (pfn_glEnableVertexAttribArray)load("glEnableVertexAttribArray");
	fp_glFinish = (pfn_glFinish)load("glFinish");
	fp_glFlush = (pfn_glFlush)load("glFlush");
	fp_glFramebufferRenderbuffer = (pfn_glFramebufferRenderbuffer)load("glFramebufferRenderbuffer");
	fp_glFramebufferTexture2D = (pfn_glFramebufferTexture2D)load("glFramebufferTexture2D");
	fp_glFrontFace = (pfn_glFrontFace)load("glFrontFace");
	fp_glGenBuffers = (pfn_glGenBuffers)load("glGenBuffers");
	fp_glGenerateMipmap = (pfn_glGenerateMipmap)load("glGenerateMipmap");
	fp_glGenFramebuffers = (pfn_glGenFramebuffers)load("glGenFramebuffers");
	fp_glGenRenderbuffers = (pfn_glGenRenderbuffers)load("glGenRenderbuffers");
	fp_glGenTextures = (pfn_glGenTextures)load("glGenTextures");
	fp_glGetActiveAttrib = (pfn_glGetActiveAttrib)load("glGetActiveAttrib");
	fp_glGetActiveUniform = (pfn_glGetActiveUniform)load("glGetActiveUniform");
	fp_glGetAttachedShaders = (pfn_glGetAttachedShaders)load("glGetAttachedShaders");
	fp_glGetAttribLocation = (pfn_glGetAttribLocation)load("glGetAttribLocation");
	fp_glGetBooleanv = (pfn_glGetBooleanv)load("glGetBooleanv");
	fp_glGetBufferParameteriv = (pfn_glGetBufferParameteriv)load("glGetBufferParameteriv");
	fp_glGetError = (pfn_glGetError)load("glGetError");
	fp_glGetFloatv = (pfn_glGetFloatv)load("glGetFloatv");
	fp_glGetFramebufferAttachmentParameteriv = (pfn_glGetFramebufferAttachmentParameteriv)load("glGetFramebufferAttachmentParameteriv");
	fp_glGetIntegerv = (pfn_glGetIntegerv)load("glGetIntegerv");
	fp_glGetProgramiv = (pfn_glGetProgramiv)load("glGetProgramiv");
	fp_glGetProgramInfoLog = (pfn_glGetProgramInfoLog)load("glGetProgramInfoLog");
	fp_glGetRenderbufferParameteriv = (pfn_glGetRenderbufferParameteriv)load("glGetRenderbufferParameteriv");
	fp_glGetShaderiv = (pfn_glGetShaderiv)load("glGetShaderiv");
	fp_glGetShaderInfoLog = (pfn_glGetShaderInfoLog)load("glGetShaderInfoLog");
	fp_glGetShaderPrecisionFormat = (pfn_glGetShaderPrecisionFormat)load("glGetShaderPrecisionFormat");
	fp_glGetShaderSource = (pfn_glGetShaderSource)load("glGetShaderSource");
	fp_glGetString = (pfn_glGetString)load("glGetString");
	fp_glGetTexParameterfv = (pfn_glGetTexParameterfv)load("glGetTexParameterfv");
	fp_glGetTexParameteriv = (pfn_glGetTexParameteriv)load("glGetTexParameteriv");
	fp_glGetUniformfv = (pfn_glGetUniformfv)load("glGetUniformfv");
	fp_glGetUniformiv = (pfn_glGetUniformiv)load("glGetUniformiv");
	fp_glGetUniformLocation = (pfn_glGetUniformLocation)load("glGetUniformLocation");
	fp_glGetVertexAttribfv = (pfn_glGetVertexAttribfv)load("glGetVertexAttribfv");
	fp_glGetVertexAttribiv = (pfn_glGetVertexAttribiv)load("glGetVertexAttribiv");
	fp_glGetVertexAttribPointerv = (pfn_glGetVertexAttribPointerv)load("glGetVertexAttribPointerv");
	fp_glHint = (pfn_glHint)load("glHint");
	fp_glIsBuffer = (pfn_glIsBuffer)load("glIsBuffer");
	fp_glIsEnabled = (pfn_glIsEnabled)load("glIsEnabled");
	fp_glIsFramebuffer = (pfn_glIsFramebuffer)load("glIsFramebuffer");
	fp_glIsProgram = (pfn_glIsProgram)load("glIsProgram");
	fp_glIsRenderbuffer = (pfn_glIsRenderbuffer)load("glIsRenderbuffer");
	fp_glIsShader = (pfn_glIsShader)load("glIsShader");
	fp_glIsTexture = (pfn_glIsTexture)load("glIsTexture");
	fp_glLineWidth = (pfn_glLineWidth)load("glLineWidth");
	fp_glLinkProgram = (pfn_glLinkProgram)load("glLinkProgram");
	fp_glPixelStorei = (pfn_glPixelStorei)load("glPixelStorei");
	fp_glPolygonOffset = (pfn_glPolygonOffset)load("glPolygonOffset");
	fp_glReadPixels = (pfn_glReadPixels)load("glReadPixels");
	fp_glReleaseShaderCompiler = (pfn_glReleaseShaderCompiler)load("glReleaseShaderCompiler");
	fp_glRenderbufferStorage = (pfn_glRenderbufferStorage)load("glRenderbufferStorage");
	fp_glSampleCoverage = (pfn_glSampleCoverage)load("glSampleCoverage");
	fp_glScissor = (pfn_glScissor)load("glScissor");
	fp_glShaderBinary = (pfn_glShaderBinary)load("glShaderBinary");
	fp_glShaderSource = (pfn_glShaderSource)load("glShaderSource");
	fp_glStencilFunc = (pfn_glStencilFunc)load("glStencilFunc");
	fp_glStencilFuncSeparate = (pfn_glStencilFuncSeparate)load("glStencilFuncSeparate");
	fp_glStencilMask = (pfn_glStencilMask)load("glStencilMask");
	fp_glStencilMaskSeparate = (pfn_glStencilMaskSeparate)load("glStencilMaskSeparate");
	fp_glStencilOp = (pfn_glStencilOp)load("glStencilOp");
	fp_glStencilOpSeparate = (pfn_glStencilOpSeparate)load("glStencilOpSeparate");
	fp_glTexImage2D = (pfn_glTexImage2D)load("glTexImage2D");
	fp_glTexParameterf = (pfn_glTexParameterf)load("glTexParameterf");
	fp_glTexParameterfv = (pfn_glTexParameterfv)load("glTexParameterfv");
	fp_glTexParameteri = (pfn_glTexParameteri)load("glTexParameteri");
	fp_glTexParameteriv = (pfn_glTexParameteriv)load("glTexParameteriv");
	fp_glTexSubImage2D = (pfn_glTexSubImage2D)load("glTexSubImage2D");
	fp_glUniform1f = (pfn_glUniform1f)load("glUniform1f");
	fp_glUniform1fv = (pfn_glUniform1fv)load("glUniform1fv");
	fp_glUniform1i = (pfn_glUniform1i)load("glUniform1i");
	fp_glUniform1iv = (pfn_glUniform1iv)load("glUniform1iv");
	fp_glUniform2f = (pfn_glUniform2f)load("glUniform2f");
	fp_glUniform2fv = (pfn_glUniform2fv)load("glUniform2fv");
	fp_glUniform2i = (pfn_glUniform2i)load("glUniform2i");
	fp_glUniform2iv = (pfn_glUniform2iv)load("glUniform2iv");
	fp_glUniform3f = (pfn_glUniform3f)load("glUniform3f");
	fp_glUniform3fv = (pfn_glUniform3fv)load("glUniform3fv");
	fp_glUniform3i = (pfn_glUniform3i)load("glUniform3i");
	fp_glUniform3iv = (pfn_glUniform3iv)load("glUniform3iv");
	fp_glUniform4f = (pfn_glUniform4f)load("glUniform4f");
	fp_glUniform4fv = (pfn_glUniform4fv)load("glUniform4fv");
	fp_glUniform4i = (pfn_glUniform4i)load("glUniform4i");
	fp_glUniform4iv = (pfn_glUniform4iv)load("glUniform4iv");
	fp_glUniformMatrix2fv = (pfn_glUniformMatrix2fv)load("glUniformMatrix2fv");
	fp_glUniformMatrix3fv = (pfn_glUniformMatrix3fv)load("glUniformMatrix3fv");
	fp_glUniformMatrix4fv = (pfn_glUniformMatrix4fv)load("glUniformMatrix4fv");
	fp_glUseProgram = (pfn_glUseProgram)load("glUseProgram");
	fp_glValidateProgram = (pfn_glValidateProgram)load("glValidateProgram");
	fp_glVertexAttrib1f = (pfn_glVertexAttrib1f)load("glVertexAttrib1f");
	fp_glVertexAttrib1fv = (pfn_glVertexAttrib1fv)load("glVertexAttrib1fv");
	fp_glVertexAttrib2f = (pfn_glVertexAttrib2f)load("glVertexAttrib2f");
	fp_glVertexAttrib2fv = (pfn_glVertexAttrib2fv)load("glVertexAttrib2fv");
	fp_glVertexAttrib3f = (pfn_glVertexAttrib3f)load("glVertexAttrib3f");
	fp_glVertexAttrib3fv = (pfn_glVertexAttrib3fv)load("glVertexAttrib3fv");
	fp_glVertexAttrib4f = (pfn_glVertexAttrib4f)load("glVertexAttrib4f");
	fp_glVertexAttrib4fv = (pfn_glVertexAttrib4fv)load("glVertexAttrib4fv");
	fp_glVertexAttribPointer = (pfn_glVertexAttribPointer)load("glVertexAttribPointer");
	fp_glViewport = (pfn_glViewport)load("glViewport");
}

GLboolean GLAD_ES_VERSION_3_0 = GL_FALSE;
static void load_GL_ES_VERSION_3_0(LOADER load) {
	if(!GLAD_ES_VERSION_3_0) return;
	fp_glReadBuffer = (pfn_glReadBuffer)load("glReadBuffer");
	fp_glDrawRangeElements = (pfn_glDrawRangeElements)load("glDrawRangeElements");
	fp_glTexImage3D = (pfn_glTexImage3D)load("glTexImage3D");
	fp_glTexSubImage3D = (pfn_glTexSubImage3D)load("glTexSubImage3D");
	fp_glCopyTexSubImage3D = (pfn_glCopyTexSubImage3D)load("glCopyTexSubImage3D");
	fp_glCompressedTexImage3D = (pfn_glCompressedTexImage3D)load("glCompressedTexImage3D");
	fp_glCompressedTexSubImage3D = (pfn_glCompressedTexSubImage3D)load("glCompressedTexSubImage3D");
	fp_glGenQueries = (pfn_glGenQueries)load("glGenQueries");
	fp_glDeleteQueries = (pfn_glDeleteQueries)load("glDeleteQueries");
	fp_glIsQuery = (pfn_glIsQuery)load("glIsQuery");
	fp_glBeginQuery = (pfn_glBeginQuery)load("glBeginQuery");
	fp_glEndQuery = (pfn_glEndQuery)load("glEndQuery");
	fp_glGetQueryiv = (pfn_glGetQueryiv)load("glGetQueryiv");
	fp_glGetQueryObjectuiv = (pfn_glGetQueryObjectuiv)load("glGetQueryObjectuiv");
	fp_glUnmapBuffer = (pfn_glUnmapBuffer)load("glUnmapBuffer");
	fp_glGetBufferPointerv = (pfn_glGetBufferPointerv)load("glGetBufferPointerv");
	fp_glDrawBuffers = (pfn_glDrawBuffers)load("glDrawBuffers");
	fp_glUniformMatrix2x3fv = (pfn_glUniformMatrix2x3fv)load("glUniformMatrix2x3fv");
	fp_glUniformMatrix3x2fv = (pfn_glUniformMatrix3x2fv)load("glUniformMatrix3x2fv");
	fp_glUniformMatrix2x4fv = (pfn_glUniformMatrix2x4fv)load("glUniformMatrix2x4fv");
	fp_glUniformMatrix4x2fv = (pfn_glUniformMatrix4x2fv)load("glUniformMatrix4x2fv");
	fp_glUniformMatrix3x4fv = (pfn_glUniformMatrix3x4fv)load("glUniformMatrix3x4fv");
	fp_glUniformMatrix4x3fv = (pfn_glUniformMatrix4x3fv)load("glUniformMatrix4x3fv");
	fp_glBlitFramebuffer = (pfn_glBlitFramebuffer)load("glBlitFramebuffer");
	fp_glRenderbufferStorageMultisample = (pfn_glRenderbufferStorageMultisample)load("glRenderbufferStorageMultisample");
	fp_glFramebufferTextureLayer = (pfn_glFramebufferTextureLayer)load("glFramebufferTextureLayer");
	fp_glMapBufferRange = (pfn_glMapBufferRange)load("glMapBufferRange");
	fp_glFlushMappedBufferRange = (pfn_glFlushMappedBufferRange)load("glFlushMappedBufferRange");
	fp_glBindVertexArray = (pfn_glBindVertexArray)load("glBindVertexArray");
	fp_glDeleteVertexArrays = (pfn_glDeleteVertexArrays)load("glDeleteVertexArrays");
	fp_glGenVertexArrays = (pfn_glGenVertexArrays)load("glGenVertexArrays");
	fp_glIsVertexArray = (pfn_glIsVertexArray)load("glIsVertexArray");
	fp_glGetIntegeri_v = (pfn_glGetIntegeri_v)load("glGetIntegeri_v");
	fp_glBeginTransformFeedback = (pfn_glBeginTransformFeedback)load("glBeginTransformFeedback");
	fp_glEndTransformFeedback = (pfn_glEndTransformFeedback)load("glEndTransformFeedback");
	fp_glBindBufferRange = (pfn_glBindBufferRange)load("glBindBufferRange");
	fp_glBindBufferBase = (pfn_glBindBufferBase)load("glBindBufferBase");
	fp_glTransformFeedbackVaryings = (pfn_glTransformFeedbackVaryings)load("glTransformFeedbackVaryings");
	fp_glGetTransformFeedbackVarying = (pfn_glGetTransformFeedbackVarying)load("glGetTransformFeedbackVarying");
	fp_glVertexAttribIPointer = (pfn_glVertexAttribIPointer)load("glVertexAttribIPointer");
	fp_glGetVertexAttribIiv = (pfn_glGetVertexAttribIiv)load("glGetVertexAttribIiv");
	fp_glGetVertexAttribIuiv = (pfn_glGetVertexAttribIuiv)load("glGetVertexAttribIuiv");
	fp_glVertexAttribI4i = (pfn_glVertexAttribI4i)load("glVertexAttribI4i");
	fp_glVertexAttribI4ui = (pfn_glVertexAttribI4ui)load("glVertexAttribI4ui");
	fp_glVertexAttribI4iv = (pfn_glVertexAttribI4iv)load("glVertexAttribI4iv");
	fp_glVertexAttribI4uiv = (pfn_glVertexAttribI4uiv)load("glVertexAttribI4uiv");
	fp_glGetUniformuiv = (pfn_glGetUniformuiv)load("glGetUniformuiv");
	fp_glGetFragDataLocation = (pfn_glGetFragDataLocation)load("glGetFragDataLocation");
	fp_glUniform1ui = (pfn_glUniform1ui)load("glUniform1ui");
	fp_glUniform2ui = (pfn_glUniform2ui)load("glUniform2ui");
	fp_glUniform3ui = (pfn_glUniform3ui)load("glUniform3ui");
	fp_glUniform4ui = (pfn_glUniform4ui)load("glUniform4ui");
	fp_glUniform1uiv = (pfn_glUniform1uiv)load("glUniform1uiv");
	fp_glUniform2uiv = (pfn_glUniform2uiv)load("glUniform2uiv");
	fp_glUniform3uiv = (pfn_glUniform3uiv)load("glUniform3uiv");
	fp_glUniform4uiv = (pfn_glUniform4uiv)load("glUniform4uiv");
	fp_glClearBufferiv = (pfn_glClearBufferiv)load("glClearBufferiv");
	fp_glClearBufferuiv = (pfn_glClearBufferuiv)load("glClearBufferuiv");
	fp_glClearBufferfv = (pfn_glClearBufferfv)load("glClearBufferfv");
	fp_glClearBufferfi = (pfn_glClearBufferfi)load("glClearBufferfi");
	fp_glGetStringi = (pfn_glGetStringi)load("glGetStringi");
	fp_glCopyBufferSubData = (pfn_glCopyBufferSubData)load("glCopyBufferSubData");
	fp_glGetUniformIndices = (pfn_glGetUniformIndices)load("glGetUniformIndices");
	fp_glGetActiveUniformsiv = (pfn_glGetActiveUniformsiv)load("glGetActiveUniformsiv");
	fp_glGetUniformBlockIndex = (pfn_glGetUniformBlockIndex)load("glGetUniformBlockIndex");
	fp_glGetActiveUniformBlockiv = (pfn_glGetActiveUniformBlockiv)load("glGetActiveUniformBlockiv");
	fp_glGetActiveUniformBlockName = (pfn_glGetActiveUniformBlockName)load("glGetActiveUniformBlockName");
	fp_glUniformBlockBinding = (pfn_glUniformBlockBinding)load("glUniformBlockBinding");
	fp_glDrawArraysInstanced = (pfn_glDrawArraysInstanced)load("glDrawArraysInstanced");
	fp_glDrawElementsInstanced = (pfn_glDrawElementsInstanced)load("glDrawElementsInstanced");
	fp_glFenceSync = (pfn_glFenceSync)load("glFenceSync");
	fp_glIsSync = (pfn_glIsSync)load("glIsSync");
	fp_glDeleteSync = (pfn_glDeleteSync)load("glDeleteSync");
	fp_glClientWaitSync = (pfn_glClientWaitSync)load("glClientWaitSync");
	fp_glWaitSync = (pfn_glWaitSync)load("glWaitSync");
	fp_glGetInteger64v = (pfn_glGetInteger64v)load("glGetInteger64v");
	fp_glGetSynciv = (pfn_glGetSynciv)load("glGetSynciv");
	fp_glGetInteger64i_v = (pfn_glGetInteger64i_v)load("glGetInteger64i_v");
	fp_glGetBufferParameteri64v = (pfn_glGetBufferParameteri64v)load("glGetBufferParameteri64v");
	fp_glGenSamplers = (pfn_glGenSamplers)load("glGenSamplers");
	fp_glDeleteSamplers = (pfn_glDeleteSamplers)load("glDeleteSamplers");
	fp_glIsSampler = (pfn_glIsSampler)load("glIsSampler");
	fp_glBindSampler = (pfn_glBindSampler)load("glBindSampler");
	fp_glSamplerParameteri = (pfn_glSamplerParameteri)load("glSamplerParameteri");
	fp_glSamplerParameteriv = (pfn_glSamplerParameteriv)load("glSamplerParameteriv");
	fp_glSamplerParameterf = (pfn_glSamplerParameterf)load("glSamplerParameterf");
	fp_glSamplerParameterfv = (pfn_glSamplerParameterfv)load("glSamplerParameterfv");
	fp_glGetSamplerParameteriv = (pfn_glGetSamplerParameteriv)load("glGetSamplerParameteriv");
	fp_glGetSamplerParameterfv = (pfn_glGetSamplerParameterfv)load("glGetSamplerParameterfv");
	fp_glVertexAttribDivisor = (pfn_glVertexAttribDivisor)load("glVertexAttribDivisor");
	fp_glBindTransformFeedback = (pfn_glBindTransformFeedback)load("glBindTransformFeedback");
	fp_glDeleteTransformFeedbacks = (pfn_glDeleteTransformFeedbacks)load("glDeleteTransformFeedbacks");
	fp_glGenTransformFeedbacks = (pfn_glGenTransformFeedbacks)load("glGenTransformFeedbacks");
	fp_glIsTransformFeedback = (pfn_glIsTransformFeedback)load("glIsTransformFeedback");
	fp_glPauseTransformFeedback = (pfn_glPauseTransformFeedback)load("glPauseTransformFeedback");
	fp_glResumeTransformFeedback = (pfn_glResumeTransformFeedback)load("glResumeTransformFeedback");
	fp_glGetProgramBinary = (pfn_glGetProgramBinary)load("glGetProgramBinary");
	fp_glProgramBinary = (pfn_glProgramBinary)load("glProgramBinary");
	fp_glProgramParameteri = (pfn_glProgramParameteri)load("glProgramParameteri");
	fp_glInvalidateFramebuffer = (pfn_glInvalidateFramebuffer)load("glInvalidateFramebuffer");
	fp_glInvalidateSubFramebuffer = (pfn_glInvalidateSubFramebuffer)load("glInvalidateSubFramebuffer");
	fp_glTexStorage2D = (pfn_glTexStorage2D)load("glTexStorage2D");
	fp_glTexStorage3D = (pfn_glTexStorage3D)load("glTexStorage3D");
	fp_glGetInternalformativ = (pfn_glGetInternalformativ)load("glGetInternalformativ");
}

GLboolean GLAD_ES_VERSION_3_1 = GL_FALSE;
static void load_GL_ES_VERSION_3_1(LOADER load) {
	if(!GLAD_ES_VERSION_3_1) return;
	fp_glDispatchCompute = (pfn_glDispatchCompute)load("glDispatchCompute");
	fp_glDispatchComputeIndirect = (pfn_glDispatchComputeIndirect)load("glDispatchComputeIndirect");
	fp_glDrawArraysIndirect = (pfn_glDrawArraysIndirect)load("glDrawArraysIndirect");
	fp_glDrawElementsIndirect = (pfn_glDrawElementsIndirect)load("glDrawElementsIndirect");
	fp_glFramebufferParameteri = (pfn_glFramebufferParameteri)load("glFramebufferParameteri");
	fp_glGetFramebufferParameteriv = (pfn_glGetFramebufferParameteriv)load("glGetFramebufferParameteriv");
	fp_glGetProgramInterfaceiv = (pfn_glGetProgramInterfaceiv)load("glGetProgramInterfaceiv");
	fp_glGetProgramResourceIndex = (pfn_glGetProgramResourceIndex)load("glGetProgramResourceIndex");
	fp_glGetProgramResourceName = (pfn_glGetProgramResourceName)load("glGetProgramResourceName");
	fp_glGetProgramResourceiv = (pfn_glGetProgramResourceiv)load("glGetProgramResourceiv");
	fp_glGetProgramResourceLocation = (pfn_glGetProgramResourceLocation)load("glGetProgramResourceLocation");
	fp_glUseProgramStages = (pfn_glUseProgramStages)load("glUseProgramStages");
	fp_glActiveShaderProgram = (pfn_glActiveShaderProgram)load("glActiveShaderProgram");
	fp_glCreateShaderProgramv = (pfn_glCreateShaderProgramv)load("glCreateShaderProgramv");
	fp_glBindProgramPipeline = (pfn_glBindProgramPipeline)load("glBindProgramPipeline");
	fp_glDeleteProgramPipelines = (pfn_glDeleteProgramPipelines)load("glDeleteProgramPipelines");
	fp_glGenProgramPipelines = (pfn_glGenProgramPipelines)load("glGenProgramPipelines");
	fp_glIsProgramPipeline = (pfn_glIsProgramPipeline)load("glIsProgramPipeline");
	fp_glGetProgramPipelineiv = (pfn_glGetProgramPipelineiv)load("glGetProgramPipelineiv");
	fp_glProgramUniform1i = (pfn_glProgramUniform1i)load("glProgramUniform1i");
	fp_glProgramUniform2i = (pfn_glProgramUniform2i)load("glProgramUniform2i");
	fp_glProgramUniform3i = (pfn_glProgramUniform3i)load("glProgramUniform3i");
	fp_glProgramUniform4i = (pfn_glProgramUniform4i)load("glProgramUniform4i");
	fp_glProgramUniform1ui = (pfn_glProgramUniform1ui)load("glProgramUniform1ui");
	fp_glProgramUniform2ui = (pfn_glProgramUniform2ui)load("glProgramUniform2ui");
	fp_glProgramUniform3ui = (pfn_glProgramUniform3ui)load("glProgramUniform3ui");
	fp_glProgramUniform4ui = (pfn_glProgramUniform4ui)load("glProgramUniform4ui");
	fp_glProgramUniform1f = (pfn_glProgramUniform1f)load("glProgramUniform1f");
	fp_glProgramUniform2f = (pfn_glProgramUniform2f)load("glProgramUniform2f");
	fp_glProgramUniform3f = (pfn_glProgramUniform3f)load("glProgramUniform3f");
	fp_glProgramUniform4f = (pfn_glProgramUniform4f)load("glProgramUniform4f");
	fp_glProgramUniform1iv = (pfn_glProgramUniform1iv)load("glProgramUniform1iv");
	fp_glProgramUniform2iv = (pfn_glProgramUniform2iv)load("glProgramUniform2iv");
	fp_glProgramUniform3iv = (pfn_glProgramUniform3iv)load("glProgramUniform3iv");
	fp_glProgramUniform4iv = (pfn_glProgramUniform4iv)load("glProgramUniform4iv");
	fp_glProgramUniform1uiv = (pfn_glProgramUniform1uiv)load("glProgramUniform1uiv");
	fp_glProgramUniform2uiv = (pfn_glProgramUniform2uiv)load("glProgramUniform2uiv");
	fp_glProgramUniform3uiv = (pfn_glProgramUniform3uiv)load("glProgramUniform3uiv");
	fp_glProgramUniform4uiv = (pfn_glProgramUniform4uiv)load("glProgramUniform4uiv");
	fp_glProgramUniform1fv = (pfn_glProgramUniform1fv)load("glProgramUniform1fv");
	fp_glProgramUniform2fv = (pfn_glProgramUniform2fv)load("glProgramUniform2fv");
	fp_glProgramUniform3fv = (pfn_glProgramUniform3fv)load("glProgramUniform3fv");
	fp_glProgramUniform4fv = (pfn_glProgramUniform4fv)load("glProgramUniform4fv");
	fp_glProgramUniformMatrix2fv = (pfn_glProgramUniformMatrix2fv)load("glProgramUniformMatrix2fv");
	fp_glProgramUniformMatrix3fv = (pfn_glProgramUniformMatrix3fv)load("glProgramUniformMatrix3fv");
	fp_glProgramUniformMatrix4fv = (pfn_glProgramUniformMatrix4fv)load("glProgramUniformMatrix4fv");
	fp_glProgramUniformMatrix2x3fv = (pfn_glProgramUniformMatrix2x3fv)load("glProgramUniformMatrix2x3fv");
	fp_glProgramUniformMatrix3x2fv = (pfn_glProgramUniformMatrix3x2fv)load("glProgramUniformMatrix3x2fv");
	fp_glProgramUniformMatrix2x4fv = (pfn_glProgramUniformMatrix2x4fv)load("glProgramUniformMatrix2x4fv");
	fp_glProgramUniformMatrix4x2fv = (pfn_glProgramUniformMatrix4x2fv)load("glProgramUniformMatrix4x2fv");
	fp_glProgramUniformMatrix3x4fv = (pfn_glProgramUniformMatrix3x4fv)load("glProgramUniformMatrix3x4fv");
	fp_glProgramUniformMatrix4x3fv = (pfn_glProgramUniformMatrix4x3fv)load("glProgramUniformMatrix4x3fv");
	fp_glValidateProgramPipeline = (pfn_glValidateProgramPipeline)load("glValidateProgramPipeline");
	fp_glGetProgramPipelineInfoLog = (pfn_glGetProgramPipelineInfoLog)load("glGetProgramPipelineInfoLog");
	fp_glBindImageTexture = (pfn_glBindImageTexture)load("glBindImageTexture");
	fp_glGetBooleani_v = (pfn_glGetBooleani_v)load("glGetBooleani_v");
	fp_glMemoryBarrier = (pfn_glMemoryBarrier)load("glMemoryBarrier");
	fp_glMemoryBarrierByRegion = (pfn_glMemoryBarrierByRegion)load("glMemoryBarrierByRegion");
	fp_glTexStorage2DMultisample = (pfn_glTexStorage2DMultisample)load("glTexStorage2DMultisample");
	fp_glGetMultisamplefv = (pfn_glGetMultisamplefv)load("glGetMultisamplefv");
	fp_glSampleMaski = (pfn_glSampleMaski)load("glSampleMaski");
	fp_glGetTexLevelParameteriv = (pfn_glGetTexLevelParameteriv)load("glGetTexLevelParameteriv");
	fp_glGetTexLevelParameterfv = (pfn_glGetTexLevelParameterfv)load("glGetTexLevelParameterfv");
	fp_glBindVertexBuffer = (pfn_glBindVertexBuffer)load("glBindVertexBuffer");
	fp_glVertexAttribFormat = (pfn_glVertexAttribFormat)load("glVertexAttribFormat");
	fp_glVertexAttribIFormat = (pfn_glVertexAttribIFormat)load("glVertexAttribIFormat");
	fp_glVertexAttribBinding = (pfn_glVertexAttribBinding)load("glVertexAttribBinding");
	fp_glVertexBindingDivisor = (pfn_glVertexBindingDivisor)load("glVertexBindingDivisor");
}

GLboolean GLAD_ES_VERSION_3_2 = GL_FALSE;
static void load_GL_ES_VERSION_3_2(LOADER load) {
	if(!GLAD_ES_VERSION_3_2) return;
	fp_glBlendBarrier = (pfn_glBlendBarrier)load("glBlendBarrier");
	fp_glCopyImageSubData = (pfn_glCopyImageSubData)load("glCopyImageSubData");
	fp_glDebugMessageControl = (pfn_glDebugMessageControl)load("glDebugMessageControl");
	fp_glDebugMessageInsert = (pfn_glDebugMessageInsert)load("glDebugMessageInsert");
	fp_glDebugMessageCallback = (pfn_glDebugMessageCallback)load("glDebugMessageCallback");
	fp_glGetDebugMessageLog = (pfn_glGetDebugMessageLog)load("glGetDebugMessageLog");
	fp_glPushDebugGroup = (pfn_glPushDebugGroup)load("glPushDebugGroup");
	fp_glPopDebugGroup = (pfn_glPopDebugGroup)load("glPopDebugGroup");
	fp_glObjectLabel = (pfn_glObjectLabel)load("glObjectLabel");
	fp_glGetObjectLabel = (pfn_glGetObjectLabel)load("glGetObjectLabel");
	fp_glObjectPtrLabel = (pfn_glObjectPtrLabel)load("glObjectPtrLabel");
	fp_glGetObjectPtrLabel = (pfn_glGetObjectPtrLabel)load("glGetObjectPtrLabel");
	fp_glGetPointerv = (pfn_glGetPointerv)load("glGetPointerv");
	fp_glEnablei = (pfn_glEnablei)load("glEnablei");
	fp_glDisablei = (pfn_glDisablei)load("glDisablei");
	fp_glBlendEquationi = (pfn_glBlendEquationi)load("glBlendEquationi");
	fp_glBlendEquationSeparatei = (pfn_glBlendEquationSeparatei)load("glBlendEquationSeparatei");
	fp_glBlendFunci = (pfn_glBlendFunci)load("glBlendFunci");
	fp_glBlendFuncSeparatei = (pfn_glBlendFuncSeparatei)load("glBlendFuncSeparatei");
	fp_glColorMaski = (pfn_glColorMaski)load("glColorMaski");
	fp_glIsEnabledi = (pfn_glIsEnabledi)load("glIsEnabledi");
	fp_glDrawElementsBaseVertex = (pfn_glDrawElementsBaseVertex)load("glDrawElementsBaseVertex");
	fp_glDrawRangeElementsBaseVertex = (pfn_glDrawRangeElementsBaseVertex)load("glDrawRangeElementsBaseVertex");
	fp_glDrawElementsInstancedBaseVertex = (pfn_glDrawElementsInstancedBaseVertex)load("glDrawElementsInstancedBaseVertex");
	fp_glFramebufferTexture = (pfn_glFramebufferTexture)load("glFramebufferTexture");
	fp_glPrimitiveBoundingBox = (pfn_glPrimitiveBoundingBox)load("glPrimitiveBoundingBox");
	fp_glGetGraphicsResetStatus = (pfn_glGetGraphicsResetStatus)load("glGetGraphicsResetStatus");
	fp_glReadnPixels = (pfn_glReadnPixels)load("glReadnPixels");
	fp_glGetnUniformfv = (pfn_glGetnUniformfv)load("glGetnUniformfv");
	fp_glGetnUniformiv = (pfn_glGetnUniformiv)load("glGetnUniformiv");
	fp_glGetnUniformuiv = (pfn_glGetnUniformuiv)load("glGetnUniformuiv");
	fp_glMinSampleShading = (pfn_glMinSampleShading)load("glMinSampleShading");
	fp_glPatchParameteri = (pfn_glPatchParameteri)load("glPatchParameteri");
	fp_glTexParameterIiv = (pfn_glTexParameterIiv)load("glTexParameterIiv");
	fp_glTexParameterIuiv = (pfn_glTexParameterIuiv)load("glTexParameterIuiv");
	fp_glGetTexParameterIiv = (pfn_glGetTexParameterIiv)load("glGetTexParameterIiv");
	fp_glGetTexParameterIuiv = (pfn_glGetTexParameterIuiv)load("glGetTexParameterIuiv");
	fp_glSamplerParameterIiv = (pfn_glSamplerParameterIiv)load("glSamplerParameterIiv");
	fp_glSamplerParameterIuiv = (pfn_glSamplerParameterIuiv)load("glSamplerParameterIuiv");
	fp_glGetSamplerParameterIiv = (pfn_glGetSamplerParameterIiv)load("glGetSamplerParameterIiv");
	fp_glGetSamplerParameterIuiv = (pfn_glGetSamplerParameterIuiv)load("glGetSamplerParameterIuiv");
	fp_glTexBuffer = (pfn_glTexBuffer)load("glTexBuffer");
	fp_glTexBufferRange = (pfn_glTexBufferRange)load("glTexBufferRange");
	fp_glTexStorage3DMultisample = (pfn_glTexStorage3DMultisample)load("glTexStorage3DMultisample");
}

GLboolean GLAD_KHR_blend_equation_advanced = GL_FALSE;
static void load_GL_KHR_blend_equation_advanced(LOADER load) {
	if(!GLAD_KHR_blend_equation_advanced) return;
	fp_glBlendBarrierKHR = (pfn_glBlendBarrierKHR)load("glBlendBarrierKHR");
}

GLboolean GLAD_KHR_blend_equation_advanced_coherent = GL_FALSE;
GLboolean GLAD_KHR_context_flush_control = GL_FALSE;
GLboolean GLAD_KHR_debug = GL_FALSE;
static void load_GL_KHR_debug(LOADER load) {
	if(!GLAD_KHR_debug) return;
	fp_glDebugMessageControl = (pfn_glDebugMessageControl)load("glDebugMessageControl");
	fp_glDebugMessageInsert = (pfn_glDebugMessageInsert)load("glDebugMessageInsert");
	fp_glDebugMessageCallback = (pfn_glDebugMessageCallback)load("glDebugMessageCallback");
	fp_glGetDebugMessageLog = (pfn_glGetDebugMessageLog)load("glGetDebugMessageLog");
	fp_glPushDebugGroup = (pfn_glPushDebugGroup)load("glPushDebugGroup");
	fp_glPopDebugGroup = (pfn_glPopDebugGroup)load("glPopDebugGroup");
	fp_glObjectLabel = (pfn_glObjectLabel)load("glObjectLabel");
	fp_glGetObjectLabel = (pfn_glGetObjectLabel)load("glGetObjectLabel");
	fp_glObjectPtrLabel = (pfn_glObjectPtrLabel)load("glObjectPtrLabel");
	fp_glGetObjectPtrLabel = (pfn_glGetObjectPtrLabel)load("glGetObjectPtrLabel");
	fp_glGetPointerv = (pfn_glGetPointerv)load("glGetPointerv");
	fp_glDebugMessageControlKHR = (pfn_glDebugMessageControlKHR)load("glDebugMessageControlKHR");
	fp_glDebugMessageInsertKHR = (pfn_glDebugMessageInsertKHR)load("glDebugMessageInsertKHR");
	fp_glDebugMessageCallbackKHR = (pfn_glDebugMessageCallbackKHR)load("glDebugMessageCallbackKHR");
	fp_glGetDebugMessageLogKHR = (pfn_glGetDebugMessageLogKHR)load("glGetDebugMessageLogKHR");
	fp_glPushDebugGroupKHR = (pfn_glPushDebugGroupKHR)load("glPushDebugGroupKHR");
	fp_glPopDebugGroupKHR = (pfn_glPopDebugGroupKHR)load("glPopDebugGroupKHR");
	fp_glObjectLabelKHR = (pfn_glObjectLabelKHR)load("glObjectLabelKHR");
	fp_glGetObjectLabelKHR = (pfn_glGetObjectLabelKHR)load("glGetObjectLabelKHR");
	fp_glObjectPtrLabelKHR = (pfn_glObjectPtrLabelKHR)load("glObjectPtrLabelKHR");
	fp_glGetObjectPtrLabelKHR = (pfn_glGetObjectPtrLabelKHR)load("glGetObjectPtrLabelKHR");
	fp_glGetPointervKHR = (pfn_glGetPointervKHR)load("glGetPointervKHR");
}

GLboolean GLAD_KHR_no_error = GL_FALSE;
GLboolean GLAD_KHR_robust_buffer_access_behavior = GL_FALSE;
GLboolean GLAD_KHR_robustness = GL_FALSE;
static void load_GL_KHR_robustness(LOADER load) {
	if(!GLAD_KHR_robustness) return;
	fp_glGetGraphicsResetStatus = (pfn_glGetGraphicsResetStatus)load("glGetGraphicsResetStatus");
	fp_glReadnPixels = (pfn_glReadnPixels)load("glReadnPixels");
	fp_glGetnUniformfv = (pfn_glGetnUniformfv)load("glGetnUniformfv");
	fp_glGetnUniformiv = (pfn_glGetnUniformiv)load("glGetnUniformiv");
	fp_glGetnUniformuiv = (pfn_glGetnUniformuiv)load("glGetnUniformuiv");
	fp_glGetGraphicsResetStatusKHR = (pfn_glGetGraphicsResetStatusKHR)load("glGetGraphicsResetStatusKHR");
	fp_glReadnPixelsKHR = (pfn_glReadnPixelsKHR)load("glReadnPixelsKHR");
	fp_glGetnUniformfvKHR = (pfn_glGetnUniformfvKHR)load("glGetnUniformfvKHR");
	fp_glGetnUniformivKHR = (pfn_glGetnUniformivKHR)load("glGetnUniformivKHR");
	fp_glGetnUniformuivKHR = (pfn_glGetnUniformuivKHR)load("glGetnUniformuivKHR");
}

GLboolean GLAD_KHR_texture_compression_astc_hdr = GL_FALSE;
GLboolean GLAD_KHR_texture_compression_astc_ldr = GL_FALSE;
GLboolean GLAD_KHR_texture_compression_astc_sliced_3d = GL_FALSE;
GLboolean GLAD_ARB_arrays_of_arrays = GL_FALSE;
GLboolean GLAD_ARB_base_instance = GL_FALSE;
static void load_GL_ARB_base_instance(LOADER load) {
	if(!GLAD_ARB_base_instance) return;
	fp_glDrawArraysInstancedBaseInstance = (pfn_glDrawArraysInstancedBaseInstance)load("glDrawArraysInstancedBaseInstance");
	fp_glDrawElementsInstancedBaseInstance = (pfn_glDrawElementsInstancedBaseInstance)load("glDrawElementsInstancedBaseInstance");
	fp_glDrawElementsInstancedBaseVertexBaseInstance = (pfn_glDrawElementsInstancedBaseVertexBaseInstance)load("glDrawElementsInstancedBaseVertexBaseInstance");
}

GLboolean GLAD_ARB_bindless_texture = GL_FALSE;
static void load_GL_ARB_bindless_texture(LOADER load) {
	if(!GLAD_ARB_bindless_texture) return;
	fp_glGetTextureHandleARB = (pfn_glGetTextureHandleARB)load("glGetTextureHandleARB");
	fp_glGetTextureSamplerHandleARB = (pfn_glGetTextureSamplerHandleARB)load("glGetTextureSamplerHandleARB");
	fp_glMakeTextureHandleResidentARB = (pfn_glMakeTextureHandleResidentARB)load("glMakeTextureHandleResidentARB");
	fp_glMakeTextureHandleNonResidentARB = (pfn_glMakeTextureHandleNonResidentARB)load("glMakeTextureHandleNonResidentARB");
	fp_glGetImageHandleARB = (pfn_glGetImageHandleARB)load("glGetImageHandleARB");
	fp_glMakeImageHandleResidentARB = (pfn_glMakeImageHandleResidentARB)load("glMakeImageHandleResidentARB");
	fp_glMakeImageHandleNonResidentARB = (pfn_glMakeImageHandleNonResidentARB)load("glMakeImageHandleNonResidentARB");
	fp_glUniformHandleui64ARB = (pfn_glUniformHandleui64ARB)load("glUniformHandleui64ARB");
	fp_glUniformHandleui64vARB = (pfn_glUniformHandleui64vARB)load("glUniformHandleui64vARB");
	fp_glProgramUniformHandleui64ARB = (pfn_glProgramUniformHandleui64ARB)load("glProgramUniformHandleui64ARB");
	fp_glProgramUniformHandleui64vARB = (pfn_glProgramUniformHandleui64vARB)load("glProgramUniformHandleui64vARB");
	fp_glIsTextureHandleResidentARB = (pfn_glIsTextureHandleResidentARB)load("glIsTextureHandleResidentARB");
	fp_glIsImageHandleResidentARB = (pfn_glIsImageHandleResidentARB)load("glIsImageHandleResidentARB");
	fp_glVertexAttribL1ui64ARB = (pfn_glVertexAttribL1ui64ARB)load("glVertexAttribL1ui64ARB");
	fp_glVertexAttribL1ui64vARB = (pfn_glVertexAttribL1ui64vARB)load("glVertexAttribL1ui64vARB");
	fp_glGetVertexAttribLui64vARB = (pfn_glGetVertexAttribLui64vARB)load("glGetVertexAttribLui64vARB");
}

GLboolean GLAD_ARB_blend_func_extended = GL_FALSE;
static void load_GL_ARB_blend_func_extended(LOADER load) {
	if(!GLAD_ARB_blend_func_extended) return;
	fp_glBindFragDataLocationIndexed = (pfn_glBindFragDataLocationIndexed)load("glBindFragDataLocationIndexed");
	fp_glGetFragDataIndex = (pfn_glGetFragDataIndex)load("glGetFragDataIndex");
}

GLboolean GLAD_ARB_buffer_storage = GL_FALSE;
static void load_GL_ARB_buffer_storage(LOADER load) {
	if(!GLAD_ARB_buffer_storage) return;
	fp_glBufferStorage = (pfn_glBufferStorage)load("glBufferStorage");
}

GLboolean GLAD_ARB_cl_event = GL_FALSE;
static void load_GL_ARB_cl_event(LOADER load) {
	if(!GLAD_ARB_cl_event) return;
	fp_glCreateSyncFromCLeventARB = (pfn_glCreateSyncFromCLeventARB)load("glCreateSyncFromCLeventARB");
}

GLboolean GLAD_ARB_clear_buffer_object = GL_FALSE;
static void load_GL_ARB_clear_buffer_object(LOADER load) {
	if(!GLAD_ARB_clear_buffer_object) return;
	fp_glClearBufferData = (pfn_glClearBufferData)load("glClearBufferData");
	fp_glClearBufferSubData = (pfn_glClearBufferSubData)load("glClearBufferSubData");
}

GLboolean GLAD_ARB_clear_texture = GL_FALSE;
static void load_GL_ARB_clear_texture(LOADER load) {
	if(!GLAD_ARB_clear_texture) return;
	fp_glClearTexImage = (pfn_glClearTexImage)load("glClearTexImage");
	fp_glClearTexSubImage = (pfn_glClearTexSubImage)load("glClearTexSubImage");
}

GLboolean GLAD_ARB_clip_control = GL_FALSE;
static void load_GL_ARB_clip_control(LOADER load) {
	if(!GLAD_ARB_clip_control) return;
	fp_glClipControl = (pfn_glClipControl)load("glClipControl");
}

GLboolean GLAD_ARB_color_buffer_float = GL_FALSE;
static void load_GL_ARB_color_buffer_float(LOADER load) {
	if(!GLAD_ARB_color_buffer_float) return;
	fp_glClampColorARB = (pfn_glClampColorARB)load("glClampColorARB");
}

GLboolean GLAD_ARB_compatibility = GL_FALSE;
GLboolean GLAD_ARB_compressed_texture_pixel_storage = GL_FALSE;
GLboolean GLAD_ARB_compute_shader = GL_FALSE;
static void load_GL_ARB_compute_shader(LOADER load) {
	if(!GLAD_ARB_compute_shader) return;
	fp_glDispatchCompute = (pfn_glDispatchCompute)load("glDispatchCompute");
	fp_glDispatchComputeIndirect = (pfn_glDispatchComputeIndirect)load("glDispatchComputeIndirect");
}

GLboolean GLAD_ARB_compute_variable_group_size = GL_FALSE;
static void load_GL_ARB_compute_variable_group_size(LOADER load) {
	if(!GLAD_ARB_compute_variable_group_size) return;
	fp_glDispatchComputeGroupSizeARB = (pfn_glDispatchComputeGroupSizeARB)load("glDispatchComputeGroupSizeARB");
}

GLboolean GLAD_ARB_conditional_render_inverted = GL_FALSE;
GLboolean GLAD_ARB_conservative_depth = GL_FALSE;
GLboolean GLAD_ARB_copy_buffer = GL_FALSE;
static void load_GL_ARB_copy_buffer(LOADER load) {
	if(!GLAD_ARB_copy_buffer) return;
	fp_glCopyBufferSubData = (pfn_glCopyBufferSubData)load("glCopyBufferSubData");
}

GLboolean GLAD_ARB_copy_image = GL_FALSE;
static void load_GL_ARB_copy_image(LOADER load) {
	if(!GLAD_ARB_copy_image) return;
	fp_glCopyImageSubData = (pfn_glCopyImageSubData)load("glCopyImageSubData");
}

GLboolean GLAD_ARB_cull_distance = GL_FALSE;
GLboolean GLAD_ARB_debug_output = GL_FALSE;
static void load_GL_ARB_debug_output(LOADER load) {
	if(!GLAD_ARB_debug_output) return;
	fp_glDebugMessageControlARB = (pfn_glDebugMessageControlARB)load("glDebugMessageControlARB");
	fp_glDebugMessageInsertARB = (pfn_glDebugMessageInsertARB)load("glDebugMessageInsertARB");
	fp_glDebugMessageCallbackARB = (pfn_glDebugMessageCallbackARB)load("glDebugMessageCallbackARB");
	fp_glGetDebugMessageLogARB = (pfn_glGetDebugMessageLogARB)load("glGetDebugMessageLogARB");
}

GLboolean GLAD_ARB_depth_buffer_float = GL_FALSE;
GLboolean GLAD_ARB_depth_clamp = GL_FALSE;
GLboolean GLAD_ARB_derivative_control = GL_FALSE;
GLboolean GLAD_ARB_direct_state_access = GL_FALSE;
static void load_GL_ARB_direct_state_access(LOADER load) {
	if(!GLAD_ARB_direct_state_access) return;
	fp_glCreateTransformFeedbacks = (pfn_glCreateTransformFeedbacks)load("glCreateTransformFeedbacks");
	fp_glTransformFeedbackBufferBase = (pfn_glTransformFeedbackBufferBase)load("glTransformFeedbackBufferBase");
	fp_glTransformFeedbackBufferRange = (pfn_glTransformFeedbackBufferRange)load("glTransformFeedbackBufferRange");
	fp_glGetTransformFeedbackiv = (pfn_glGetTransformFeedbackiv)load("glGetTransformFeedbackiv");
	fp_glGetTransformFeedbacki_v = (pfn_glGetTransformFeedbacki_v)load("glGetTransformFeedbacki_v");
	fp_glGetTransformFeedbacki64_v = (pfn_glGetTransformFeedbacki64_v)load("glGetTransformFeedbacki64_v");
	fp_glCreateBuffers = (pfn_glCreateBuffers)load("glCreateBuffers");
	fp_glNamedBufferStorage = (pfn_glNamedBufferStorage)load("glNamedBufferStorage");
	fp_glNamedBufferData = (pfn_glNamedBufferData)load("glNamedBufferData");
	fp_glNamedBufferSubData = (pfn_glNamedBufferSubData)load("glNamedBufferSubData");
	fp_glCopyNamedBufferSubData = (pfn_glCopyNamedBufferSubData)load("glCopyNamedBufferSubData");
	fp_glClearNamedBufferData = (pfn_glClearNamedBufferData)load("glClearNamedBufferData");
	fp_glClearNamedBufferSubData = (pfn_glClearNamedBufferSubData)load("glClearNamedBufferSubData");
	fp_glMapNamedBuffer = (pfn_glMapNamedBuffer)load("glMapNamedBuffer");
	fp_glMapNamedBufferRange = (pfn_glMapNamedBufferRange)load("glMapNamedBufferRange");
	fp_glUnmapNamedBuffer = (pfn_glUnmapNamedBuffer)load("glUnmapNamedBuffer");
	fp_glFlushMappedNamedBufferRange = (pfn_glFlushMappedNamedBufferRange)load("glFlushMappedNamedBufferRange");
	fp_glGetNamedBufferParameteriv = (pfn_glGetNamedBufferParameteriv)load("glGetNamedBufferParameteriv");
	fp_glGetNamedBufferParameteri64v = (pfn_glGetNamedBufferParameteri64v)load("glGetNamedBufferParameteri64v");
	fp_glGetNamedBufferPointerv = (pfn_glGetNamedBufferPointerv)load("glGetNamedBufferPointerv");
	fp_glGetNamedBufferSubData = (pfn_glGetNamedBufferSubData)load("glGetNamedBufferSubData");
	fp_glCreateFramebuffers = (pfn_glCreateFramebuffers)load("glCreateFramebuffers");
	fp_glNamedFramebufferRenderbuffer = (pfn_glNamedFramebufferRenderbuffer)load("glNamedFramebufferRenderbuffer");
	fp_glNamedFramebufferParameteri = (pfn_glNamedFramebufferParameteri)load("glNamedFramebufferParameteri");
	fp_glNamedFramebufferTexture = (pfn_glNamedFramebufferTexture)load("glNamedFramebufferTexture");
	fp_glNamedFramebufferTextureLayer = (pfn_glNamedFramebufferTextureLayer)load("glNamedFramebufferTextureLayer");
	fp_glNamedFramebufferDrawBuffer = (pfn_glNamedFramebufferDrawBuffer)load("glNamedFramebufferDrawBuffer");
	fp_glNamedFramebufferDrawBuffers = (pfn_glNamedFramebufferDrawBuffers)load("glNamedFramebufferDrawBuffers");
	fp_glNamedFramebufferReadBuffer = (pfn_glNamedFramebufferReadBuffer)load("glNamedFramebufferReadBuffer");
	fp_glInvalidateNamedFramebufferData = (pfn_glInvalidateNamedFramebufferData)load("glInvalidateNamedFramebufferData");
	fp_glInvalidateNamedFramebufferSubData = (pfn_glInvalidateNamedFramebufferSubData)load("glInvalidateNamedFramebufferSubData");
	fp_glClearNamedFramebufferiv = (pfn_glClearNamedFramebufferiv)load("glClearNamedFramebufferiv");
	fp_glClearNamedFramebufferuiv = (pfn_glClearNamedFramebufferuiv)load("glClearNamedFramebufferuiv");
	fp_glClearNamedFramebufferfv = (pfn_glClearNamedFramebufferfv)load("glClearNamedFramebufferfv");
	fp_glClearNamedFramebufferfi = (pfn_glClearNamedFramebufferfi)load("glClearNamedFramebufferfi");
	fp_glBlitNamedFramebuffer = (pfn_glBlitNamedFramebuffer)load("glBlitNamedFramebuffer");
	fp_glCheckNamedFramebufferStatus = (pfn_glCheckNamedFramebufferStatus)load("glCheckNamedFramebufferStatus");
	fp_glGetNamedFramebufferParameteriv = (pfn_glGetNamedFramebufferParameteriv)load("glGetNamedFramebufferParameteriv");
	fp_glGetNamedFramebufferAttachmentParameteriv = (pfn_glGetNamedFramebufferAttachmentParameteriv)load("glGetNamedFramebufferAttachmentParameteriv");
	fp_glCreateRenderbuffers = (pfn_glCreateRenderbuffers)load("glCreateRenderbuffers");
	fp_glNamedRenderbufferStorage = (pfn_glNamedRenderbufferStorage)load("glNamedRenderbufferStorage");
	fp_glNamedRenderbufferStorageMultisample = (pfn_glNamedRenderbufferStorageMultisample)load("glNamedRenderbufferStorageMultisample");
	fp_glGetNamedRenderbufferParameteriv = (pfn_glGetNamedRenderbufferParameteriv)load("glGetNamedRenderbufferParameteriv");
	fp_glCreateTextures = (pfn_glCreateTextures)load("glCreateTextures");
	fp_glTextureBuffer = (pfn_glTextureBuffer)load("glTextureBuffer");
	fp_glTextureBufferRange = (pfn_glTextureBufferRange)load("glTextureBufferRange");
	fp_glTextureStorage1D = (pfn_glTextureStorage1D)load("glTextureStorage1D");
	fp_glTextureStorage2D = (pfn_glTextureStorage2D)load("glTextureStorage2D");
	fp_glTextureStorage3D = (pfn_glTextureStorage3D)load("glTextureStorage3D");
	fp_glTextureStorage2DMultisample = (pfn_glTextureStorage2DMultisample)load("glTextureStorage2DMultisample");
	fp_glTextureStorage3DMultisample = (pfn_glTextureStorage3DMultisample)load("glTextureStorage3DMultisample");
	fp_glTextureSubImage1D = (pfn_glTextureSubImage1D)load("glTextureSubImage1D");
	fp_glTextureSubImage2D = (pfn_glTextureSubImage2D)load("glTextureSubImage2D");
	fp_glTextureSubImage3D = (pfn_glTextureSubImage3D)load("glTextureSubImage3D");
	fp_glCompressedTextureSubImage1D = (pfn_glCompressedTextureSubImage1D)load("glCompressedTextureSubImage1D");
	fp_glCompressedTextureSubImage2D = (pfn_glCompressedTextureSubImage2D)load("glCompressedTextureSubImage2D");
	fp_glCompressedTextureSubImage3D = (pfn_glCompressedTextureSubImage3D)load("glCompressedTextureSubImage3D");
	fp_glCopyTextureSubImage1D = (pfn_glCopyTextureSubImage1D)load("glCopyTextureSubImage1D");
	fp_glCopyTextureSubImage2D = (pfn_glCopyTextureSubImage2D)load("glCopyTextureSubImage2D");
	fp_glCopyTextureSubImage3D = (pfn_glCopyTextureSubImage3D)load("glCopyTextureSubImage3D");
	fp_glTextureParameterf = (pfn_glTextureParameterf)load("glTextureParameterf");
	fp_glTextureParameterfv = (pfn_glTextureParameterfv)load("glTextureParameterfv");
	fp_glTextureParameteri = (pfn_glTextureParameteri)load("glTextureParameteri");
	fp_glTextureParameterIiv = (pfn_glTextureParameterIiv)load("glTextureParameterIiv");
	fp_glTextureParameterIuiv = (pfn_glTextureParameterIuiv)load("glTextureParameterIuiv");
	fp_glTextureParameteriv = (pfn_glTextureParameteriv)load("glTextureParameteriv");
	fp_glGenerateTextureMipmap = (pfn_glGenerateTextureMipmap)load("glGenerateTextureMipmap");
	fp_glBindTextureUnit = (pfn_glBindTextureUnit)load("glBindTextureUnit");
	fp_glGetTextureImage = (pfn_glGetTextureImage)load("glGetTextureImage");
	fp_glGetCompressedTextureImage = (pfn_glGetCompressedTextureImage)load("glGetCompressedTextureImage");
	fp_glGetTextureLevelParameterfv = (pfn_glGetTextureLevelParameterfv)load("glGetTextureLevelParameterfv");
	fp_glGetTextureLevelParameteriv = (pfn_glGetTextureLevelParameteriv)load("glGetTextureLevelParameteriv");
	fp_glGetTextureParameterfv = (pfn_glGetTextureParameterfv)load("glGetTextureParameterfv");
	fp_glGetTextureParameterIiv = (pfn_glGetTextureParameterIiv)load("glGetTextureParameterIiv");
	fp_glGetTextureParameterIuiv = (pfn_glGetTextureParameterIuiv)load("glGetTextureParameterIuiv");
	fp_glGetTextureParameteriv = (pfn_glGetTextureParameteriv)load("glGetTextureParameteriv");
	fp_glCreateVertexArrays = (pfn_glCreateVertexArrays)load("glCreateVertexArrays");
	fp_glDisableVertexArrayAttrib = (pfn_glDisableVertexArrayAttrib)load("glDisableVertexArrayAttrib");
	fp_glEnableVertexArrayAttrib = (pfn_glEnableVertexArrayAttrib)load("glEnableVertexArrayAttrib");
	fp_glVertexArrayElementBuffer = (pfn_glVertexArrayElementBuffer)load("glVertexArrayElementBuffer");
	fp_glVertexArrayVertexBuffer = (pfn_glVertexArrayVertexBuffer)load("glVertexArrayVertexBuffer");
	fp_glVertexArrayVertexBuffers = (pfn_glVertexArrayVertexBuffers)load("glVertexArrayVertexBuffers");
	fp_glVertexArrayAttribBinding = (pfn_glVertexArrayAttribBinding)load("glVertexArrayAttribBinding");
	fp_glVertexArrayAttribFormat = (pfn_glVertexArrayAttribFormat)load("glVertexArrayAttribFormat");
	fp_glVertexArrayAttribIFormat = (pfn_glVertexArrayAttribIFormat)load("glVertexArrayAttribIFormat");
	fp_glVertexArrayAttribLFormat = (pfn_glVertexArrayAttribLFormat)load("glVertexArrayAttribLFormat");
	fp_glVertexArrayBindingDivisor = (pfn_glVertexArrayBindingDivisor)load("glVertexArrayBindingDivisor");
	fp_glGetVertexArrayiv = (pfn_glGetVertexArrayiv)load("glGetVertexArrayiv");
	fp_glGetVertexArrayIndexediv = (pfn_glGetVertexArrayIndexediv)load("glGetVertexArrayIndexediv");
	fp_glGetVertexArrayIndexed64iv = (pfn_glGetVertexArrayIndexed64iv)load("glGetVertexArrayIndexed64iv");
	fp_glCreateSamplers = (pfn_glCreateSamplers)load("glCreateSamplers");
	fp_glCreateProgramPipelines = (pfn_glCreateProgramPipelines)load("glCreateProgramPipelines");
	fp_glCreateQueries = (pfn_glCreateQueries)load("glCreateQueries");
	fp_glGetQueryBufferObjecti64v = (pfn_glGetQueryBufferObjecti64v)load("glGetQueryBufferObjecti64v");
	fp_glGetQueryBufferObjectiv = (pfn_glGetQueryBufferObjectiv)load("glGetQueryBufferObjectiv");
	fp_glGetQueryBufferObjectui64v = (pfn_glGetQueryBufferObjectui64v)load("glGetQueryBufferObjectui64v");
	fp_glGetQueryBufferObjectuiv = (pfn_glGetQueryBufferObjectuiv)load("glGetQueryBufferObjectuiv");
}

GLboolean GLAD_ARB_draw_buffers_blend = GL_FALSE;
static void load_GL_ARB_draw_buffers_blend(LOADER load) {
	if(!GLAD_ARB_draw_buffers_blend) return;
	fp_glBlendEquationiARB = (pfn_glBlendEquationiARB)load("glBlendEquationiARB");
	fp_glBlendEquationSeparateiARB = (pfn_glBlendEquationSeparateiARB)load("glBlendEquationSeparateiARB");
	fp_glBlendFunciARB = (pfn_glBlendFunciARB)load("glBlendFunciARB");
	fp_glBlendFuncSeparateiARB = (pfn_glBlendFuncSeparateiARB)load("glBlendFuncSeparateiARB");
}

GLboolean GLAD_ARB_draw_elements_base_vertex = GL_FALSE;
static void load_GL_ARB_draw_elements_base_vertex(LOADER load) {
	if(!GLAD_ARB_draw_elements_base_vertex) return;
	fp_glDrawElementsBaseVertex = (pfn_glDrawElementsBaseVertex)load("glDrawElementsBaseVertex");
	fp_glDrawRangeElementsBaseVertex = (pfn_glDrawRangeElementsBaseVertex)load("glDrawRangeElementsBaseVertex");
	fp_glDrawElementsInstancedBaseVertex = (pfn_glDrawElementsInstancedBaseVertex)load("glDrawElementsInstancedBaseVertex");
	fp_glMultiDrawElementsBaseVertex = (pfn_glMultiDrawElementsBaseVertex)load("glMultiDrawElementsBaseVertex");
}

GLboolean GLAD_ARB_draw_indirect = GL_FALSE;
static void load_GL_ARB_draw_indirect(LOADER load) {
	if(!GLAD_ARB_draw_indirect) return;
	fp_glDrawArraysIndirect = (pfn_glDrawArraysIndirect)load("glDrawArraysIndirect");
	fp_glDrawElementsIndirect = (pfn_glDrawElementsIndirect)load("glDrawElementsIndirect");
}

GLboolean GLAD_ARB_draw_instanced = GL_FALSE;
static void load_GL_ARB_draw_instanced(LOADER load) {
	if(!GLAD_ARB_draw_instanced) return;
	fp_glDrawArraysInstancedARB = (pfn_glDrawArraysInstancedARB)load("glDrawArraysInstancedARB");
	fp_glDrawElementsInstancedARB = (pfn_glDrawElementsInstancedARB)load("glDrawElementsInstancedARB");
}

GLboolean GLAD_ARB_enhanced_layouts = GL_FALSE;
GLboolean GLAD_ARB_ES2_compatibility = GL_FALSE;
static void load_GL_ARB_ES2_compatibility(LOADER load) {
	if(!GLAD_ARB_ES2_compatibility) return;
	fp_glReleaseShaderCompiler = (pfn_glReleaseShaderCompiler)load("glReleaseShaderCompiler");
	fp_glShaderBinary = (pfn_glShaderBinary)load("glShaderBinary");
	fp_glGetShaderPrecisionFormat = (pfn_glGetShaderPrecisionFormat)load("glGetShaderPrecisionFormat");
	fp_glDepthRangef = (pfn_glDepthRangef)load("glDepthRangef");
	fp_glClearDepthf = (pfn_glClearDepthf)load("glClearDepthf");
}

GLboolean GLAD_ARB_ES3_1_compatibility = GL_FALSE;
static void load_GL_ARB_ES3_1_compatibility(LOADER load) {
	if(!GLAD_ARB_ES3_1_compatibility) return;
	fp_glMemoryBarrierByRegion = (pfn_glMemoryBarrierByRegion)load("glMemoryBarrierByRegion");
}

GLboolean GLAD_ARB_ES3_2_compatibility = GL_FALSE;
static void load_GL_ARB_ES3_2_compatibility(LOADER load) {
	if(!GLAD_ARB_ES3_2_compatibility) return;
	fp_glPrimitiveBoundingBoxARB = (pfn_glPrimitiveBoundingBoxARB)load("glPrimitiveBoundingBoxARB");
}

GLboolean GLAD_ARB_ES3_compatibility = GL_FALSE;
GLboolean GLAD_ARB_explicit_attrib_location = GL_FALSE;
GLboolean GLAD_ARB_explicit_uniform_location = GL_FALSE;
GLboolean GLAD_ARB_fragment_coord_conventions = GL_FALSE;
GLboolean GLAD_ARB_fragment_layer_viewport = GL_FALSE;
GLboolean GLAD_ARB_fragment_shader_interlock = GL_FALSE;
GLboolean GLAD_ARB_framebuffer_no_attachments = GL_FALSE;
static void load_GL_ARB_framebuffer_no_attachments(LOADER load) {
	if(!GLAD_ARB_framebuffer_no_attachments) return;
	fp_glFramebufferParameteri = (pfn_glFramebufferParameteri)load("glFramebufferParameteri");
	fp_glGetFramebufferParameteriv = (pfn_glGetFramebufferParameteriv)load("glGetFramebufferParameteriv");
}

GLboolean GLAD_ARB_framebuffer_object = GL_FALSE;
static void load_GL_ARB_framebuffer_object(LOADER load) {
	if(!GLAD_ARB_framebuffer_object) return;
	fp_glIsRenderbuffer = (pfn_glIsRenderbuffer)load("glIsRenderbuffer");
	fp_glBindRenderbuffer = (pfn_glBindRenderbuffer)load("glBindRenderbuffer");
	fp_glDeleteRenderbuffers = (pfn_glDeleteRenderbuffers)load("glDeleteRenderbuffers");
	fp_glGenRenderbuffers = (pfn_glGenRenderbuffers)load("glGenRenderbuffers");
	fp_glRenderbufferStorage = (pfn_glRenderbufferStorage)load("glRenderbufferStorage");
	fp_glGetRenderbufferParameteriv = (pfn_glGetRenderbufferParameteriv)load("glGetRenderbufferParameteriv");
	fp_glIsFramebuffer = (pfn_glIsFramebuffer)load("glIsFramebuffer");
	fp_glBindFramebuffer = (pfn_glBindFramebuffer)load("glBindFramebuffer");
	fp_glDeleteFramebuffers = (pfn_glDeleteFramebuffers)load("glDeleteFramebuffers");
	fp_glGenFramebuffers = (pfn_glGenFramebuffers)load("glGenFramebuffers");
	fp_glCheckFramebufferStatus = (pfn_glCheckFramebufferStatus)load("glCheckFramebufferStatus");
	fp_glFramebufferTexture1D = (pfn_glFramebufferTexture1D)load("glFramebufferTexture1D");
	fp_glFramebufferTexture2D = (pfn_glFramebufferTexture2D)load("glFramebufferTexture2D");
	fp_glFramebufferTexture3D = (pfn_glFramebufferTexture3D)load("glFramebufferTexture3D");
	fp_glFramebufferRenderbuffer = (pfn_glFramebufferRenderbuffer)load("glFramebufferRenderbuffer");
	fp_glGetFramebufferAttachmentParameteriv = (pfn_glGetFramebufferAttachmentParameteriv)load("glGetFramebufferAttachmentParameteriv");
	fp_glGenerateMipmap = (pfn_glGenerateMipmap)load("glGenerateMipmap");
	fp_glBlitFramebuffer = (pfn_glBlitFramebuffer)load("glBlitFramebuffer");
	fp_glRenderbufferStorageMultisample = (pfn_glRenderbufferStorageMultisample)load("glRenderbufferStorageMultisample");
	fp_glFramebufferTextureLayer = (pfn_glFramebufferTextureLayer)load("glFramebufferTextureLayer");
}

GLboolean GLAD_ARB_framebuffer_sRGB = GL_FALSE;
GLboolean GLAD_ARB_geometry_shader4 = GL_FALSE;
static void load_GL_ARB_geometry_shader4(LOADER load) {
	if(!GLAD_ARB_geometry_shader4) return;
	fp_glProgramParameteriARB = (pfn_glProgramParameteriARB)load("glProgramParameteriARB");
	fp_glFramebufferTextureARB = (pfn_glFramebufferTextureARB)load("glFramebufferTextureARB");
	fp_glFramebufferTextureLayerARB = (pfn_glFramebufferTextureLayerARB)load("glFramebufferTextureLayerARB");
	fp_glFramebufferTextureFaceARB = (pfn_glFramebufferTextureFaceARB)load("glFramebufferTextureFaceARB");
}

GLboolean GLAD_ARB_get_program_binary = GL_FALSE;
static void load_GL_ARB_get_program_binary(LOADER load) {
	if(!GLAD_ARB_get_program_binary) return;
	fp_glGetProgramBinary = (pfn_glGetProgramBinary)load("glGetProgramBinary");
	fp_glProgramBinary = (pfn_glProgramBinary)load("glProgramBinary");
	fp_glProgramParameteri = (pfn_glProgramParameteri)load("glProgramParameteri");
}

GLboolean GLAD_ARB_get_texture_sub_image = GL_FALSE;
static void load_GL_ARB_get_texture_sub_image(LOADER load) {
	if(!GLAD_ARB_get_texture_sub_image) return;
	fp_glGetTextureSubImage = (pfn_glGetTextureSubImage)load("glGetTextureSubImage");
	fp_glGetCompressedTextureSubImage = (pfn_glGetCompressedTextureSubImage)load("glGetCompressedTextureSubImage");
}

GLboolean GLAD_ARB_gpu_shader5 = GL_FALSE;
GLboolean GLAD_ARB_gpu_shader_fp64 = GL_FALSE;
static void load_GL_ARB_gpu_shader_fp64(LOADER load) {
	if(!GLAD_ARB_gpu_shader_fp64) return;
	fp_glUniform1d = (pfn_glUniform1d)load("glUniform1d");
	fp_glUniform2d = (pfn_glUniform2d)load("glUniform2d");
	fp_glUniform3d = (pfn_glUniform3d)load("glUniform3d");
	fp_glUniform4d = (pfn_glUniform4d)load("glUniform4d");
	fp_glUniform1dv = (pfn_glUniform1dv)load("glUniform1dv");
	fp_glUniform2dv = (pfn_glUniform2dv)load("glUniform2dv");
	fp_glUniform3dv = (pfn_glUniform3dv)load("glUniform3dv");
	fp_glUniform4dv = (pfn_glUniform4dv)load("glUniform4dv");
	fp_glUniformMatrix2dv = (pfn_glUniformMatrix2dv)load("glUniformMatrix2dv");
	fp_glUniformMatrix3dv = (pfn_glUniformMatrix3dv)load("glUniformMatrix3dv");
	fp_glUniformMatrix4dv = (pfn_glUniformMatrix4dv)load("glUniformMatrix4dv");
	fp_glUniformMatrix2x3dv = (pfn_glUniformMatrix2x3dv)load("glUniformMatrix2x3dv");
	fp_glUniformMatrix2x4dv = (pfn_glUniformMatrix2x4dv)load("glUniformMatrix2x4dv");
	fp_glUniformMatrix3x2dv = (pfn_glUniformMatrix3x2dv)load("glUniformMatrix3x2dv");
	fp_glUniformMatrix3x4dv = (pfn_glUniformMatrix3x4dv)load("glUniformMatrix3x4dv");
	fp_glUniformMatrix4x2dv = (pfn_glUniformMatrix4x2dv)load("glUniformMatrix4x2dv");
	fp_glUniformMatrix4x3dv = (pfn_glUniformMatrix4x3dv)load("glUniformMatrix4x3dv");
	fp_glGetUniformdv = (pfn_glGetUniformdv)load("glGetUniformdv");
}

GLboolean GLAD_ARB_gpu_shader_int64 = GL_FALSE;
static void load_GL_ARB_gpu_shader_int64(LOADER load) {
	if(!GLAD_ARB_gpu_shader_int64) return;
	fp_glUniform1i64ARB = (pfn_glUniform1i64ARB)load("glUniform1i64ARB");
	fp_glUniform2i64ARB = (pfn_glUniform2i64ARB)load("glUniform2i64ARB");
	fp_glUniform3i64ARB = (pfn_glUniform3i64ARB)load("glUniform3i64ARB");
	fp_glUniform4i64ARB = (pfn_glUniform4i64ARB)load("glUniform4i64ARB");
	fp_glUniform1i64vARB = (pfn_glUniform1i64vARB)load("glUniform1i64vARB");
	fp_glUniform2i64vARB = (pfn_glUniform2i64vARB)load("glUniform2i64vARB");
	fp_glUniform3i64vARB = (pfn_glUniform3i64vARB)load("glUniform3i64vARB");
	fp_glUniform4i64vARB = (pfn_glUniform4i64vARB)load("glUniform4i64vARB");
	fp_glUniform1ui64ARB = (pfn_glUniform1ui64ARB)load("glUniform1ui64ARB");
	fp_glUniform2ui64ARB = (pfn_glUniform2ui64ARB)load("glUniform2ui64ARB");
	fp_glUniform3ui64ARB = (pfn_glUniform3ui64ARB)load("glUniform3ui64ARB");
	fp_glUniform4ui64ARB = (pfn_glUniform4ui64ARB)load("glUniform4ui64ARB");
	fp_glUniform1ui64vARB = (pfn_glUniform1ui64vARB)load("glUniform1ui64vARB");
	fp_glUniform2ui64vARB = (pfn_glUniform2ui64vARB)load("glUniform2ui64vARB");
	fp_glUniform3ui64vARB = (pfn_glUniform3ui64vARB)load("glUniform3ui64vARB");
	fp_glUniform4ui64vARB = (pfn_glUniform4ui64vARB)load("glUniform4ui64vARB");
	fp_glGetUniformi64vARB = (pfn_glGetUniformi64vARB)load("glGetUniformi64vARB");
	fp_glGetUniformui64vARB = (pfn_glGetUniformui64vARB)load("glGetUniformui64vARB");
	fp_glGetnUniformi64vARB = (pfn_glGetnUniformi64vARB)load("glGetnUniformi64vARB");
	fp_glGetnUniformui64vARB = (pfn_glGetnUniformui64vARB)load("glGetnUniformui64vARB");
	fp_glProgramUniform1i64ARB = (pfn_glProgramUniform1i64ARB)load("glProgramUniform1i64ARB");
	fp_glProgramUniform2i64ARB = (pfn_glProgramUniform2i64ARB)load("glProgramUniform2i64ARB");
	fp_glProgramUniform3i64ARB = (pfn_glProgramUniform3i64ARB)load("glProgramUniform3i64ARB");
	fp_glProgramUniform4i64ARB = (pfn_glProgramUniform4i64ARB)load("glProgramUniform4i64ARB");
	fp_glProgramUniform1i64vARB = (pfn_glProgramUniform1i64vARB)load("glProgramUniform1i64vARB");
	fp_glProgramUniform2i64vARB = (pfn_glProgramUniform2i64vARB)load("glProgramUniform2i64vARB");
	fp_glProgramUniform3i64vARB = (pfn_glProgramUniform3i64vARB)load("glProgramUniform3i64vARB");
	fp_glProgramUniform4i64vARB = (pfn_glProgramUniform4i64vARB)load("glProgramUniform4i64vARB");
	fp_glProgramUniform1ui64ARB = (pfn_glProgramUniform1ui64ARB)load("glProgramUniform1ui64ARB");
	fp_glProgramUniform2ui64ARB = (pfn_glProgramUniform2ui64ARB)load("glProgramUniform2ui64ARB");
	fp_glProgramUniform3ui64ARB = (pfn_glProgramUniform3ui64ARB)load("glProgramUniform3ui64ARB");
	fp_glProgramUniform4ui64ARB = (pfn_glProgramUniform4ui64ARB)load("glProgramUniform4ui64ARB");
	fp_glProgramUniform1ui64vARB = (pfn_glProgramUniform1ui64vARB)load("glProgramUniform1ui64vARB");
	fp_glProgramUniform2ui64vARB = (pfn_glProgramUniform2ui64vARB)load("glProgramUniform2ui64vARB");
	fp_glProgramUniform3ui64vARB = (pfn_glProgramUniform3ui64vARB)load("glProgramUniform3ui64vARB");
	fp_glProgramUniform4ui64vARB = (pfn_glProgramUniform4ui64vARB)load("glProgramUniform4ui64vARB");
}

GLboolean GLAD_ARB_half_float_pixel = GL_FALSE;
GLboolean GLAD_ARB_half_float_vertex = GL_FALSE;
GLboolean GLAD_ARB_indirect_parameters = GL_FALSE;
static void load_GL_ARB_indirect_parameters(LOADER load) {
	if(!GLAD_ARB_indirect_parameters) return;
	fp_glMultiDrawArraysIndirectCountARB = (pfn_glMultiDrawArraysIndirectCountARB)load("glMultiDrawArraysIndirectCountARB");
	fp_glMultiDrawElementsIndirectCountARB = (pfn_glMultiDrawElementsIndirectCountARB)load("glMultiDrawElementsIndirectCountARB");
}

GLboolean GLAD_ARB_instanced_arrays = GL_FALSE;
static void load_GL_ARB_instanced_arrays(LOADER load) {
	if(!GLAD_ARB_instanced_arrays) return;
	fp_glVertexAttribDivisorARB = (pfn_glVertexAttribDivisorARB)load("glVertexAttribDivisorARB");
}

GLboolean GLAD_ARB_internalformat_query = GL_FALSE;
static void load_GL_ARB_internalformat_query(LOADER load) {
	if(!GLAD_ARB_internalformat_query) return;
	fp_glGetInternalformativ = (pfn_glGetInternalformativ)load("glGetInternalformativ");
}

GLboolean GLAD_ARB_internalformat_query2 = GL_FALSE;
static void load_GL_ARB_internalformat_query2(LOADER load) {
	if(!GLAD_ARB_internalformat_query2) return;
	fp_glGetInternalformati64v = (pfn_glGetInternalformati64v)load("glGetInternalformati64v");
}

GLboolean GLAD_ARB_invalidate_subdata = GL_FALSE;
static void load_GL_ARB_invalidate_subdata(LOADER load) {
	if(!GLAD_ARB_invalidate_subdata) return;
	fp_glInvalidateTexSubImage = (pfn_glInvalidateTexSubImage)load("glInvalidateTexSubImage");
	fp_glInvalidateTexImage = (pfn_glInvalidateTexImage)load("glInvalidateTexImage");
	fp_glInvalidateBufferSubData = (pfn_glInvalidateBufferSubData)load("glInvalidateBufferSubData");
	fp_glInvalidateBufferData = (pfn_glInvalidateBufferData)load("glInvalidateBufferData");
	fp_glInvalidateFramebuffer = (pfn_glInvalidateFramebuffer)load("glInvalidateFramebuffer");
	fp_glInvalidateSubFramebuffer = (pfn_glInvalidateSubFramebuffer)load("glInvalidateSubFramebuffer");
}

GLboolean GLAD_ARB_map_buffer_alignment = GL_FALSE;
GLboolean GLAD_ARB_map_buffer_range = GL_FALSE;
static void load_GL_ARB_map_buffer_range(LOADER load) {
	if(!GLAD_ARB_map_buffer_range) return;
	fp_glMapBufferRange = (pfn_glMapBufferRange)load("glMapBufferRange");
	fp_glFlushMappedBufferRange = (pfn_glFlushMappedBufferRange)load("glFlushMappedBufferRange");
}

GLboolean GLAD_ARB_multi_bind = GL_FALSE;
static void load_GL_ARB_multi_bind(LOADER load) {
	if(!GLAD_ARB_multi_bind) return;
	fp_glBindBuffersBase = (pfn_glBindBuffersBase)load("glBindBuffersBase");
	fp_glBindBuffersRange = (pfn_glBindBuffersRange)load("glBindBuffersRange");
	fp_glBindTextures = (pfn_glBindTextures)load("glBindTextures");
	fp_glBindSamplers = (pfn_glBindSamplers)load("glBindSamplers");
	fp_glBindImageTextures = (pfn_glBindImageTextures)load("glBindImageTextures");
	fp_glBindVertexBuffers = (pfn_glBindVertexBuffers)load("glBindVertexBuffers");
}

GLboolean GLAD_ARB_multi_draw_indirect = GL_FALSE;
static void load_GL_ARB_multi_draw_indirect(LOADER load) {
	if(!GLAD_ARB_multi_draw_indirect) return;
	fp_glMultiDrawArraysIndirect = (pfn_glMultiDrawArraysIndirect)load("glMultiDrawArraysIndirect");
	fp_glMultiDrawElementsIndirect = (pfn_glMultiDrawElementsIndirect)load("glMultiDrawElementsIndirect");
}

GLboolean GLAD_ARB_occlusion_query2 = GL_FALSE;
GLboolean GLAD_ARB_parallel_shader_compile = GL_FALSE;
static void load_GL_ARB_parallel_shader_compile(LOADER load) {
	if(!GLAD_ARB_parallel_shader_compile) return;
	fp_glMaxShaderCompilerThreadsARB = (pfn_glMaxShaderCompilerThreadsARB)load("glMaxShaderCompilerThreadsARB");
}

GLboolean GLAD_ARB_pipeline_statistics_query = GL_FALSE;
GLboolean GLAD_ARB_pixel_buffer_object = GL_FALSE;
GLboolean GLAD_ARB_post_depth_coverage = GL_FALSE;
GLboolean GLAD_ARB_program_interface_query = GL_FALSE;
static void load_GL_ARB_program_interface_query(LOADER load) {
	if(!GLAD_ARB_program_interface_query) return;
	fp_glGetProgramInterfaceiv = (pfn_glGetProgramInterfaceiv)load("glGetProgramInterfaceiv");
	fp_glGetProgramResourceIndex = (pfn_glGetProgramResourceIndex)load("glGetProgramResourceIndex");
	fp_glGetProgramResourceName = (pfn_glGetProgramResourceName)load("glGetProgramResourceName");
	fp_glGetProgramResourceiv = (pfn_glGetProgramResourceiv)load("glGetProgramResourceiv");
	fp_glGetProgramResourceLocation = (pfn_glGetProgramResourceLocation)load("glGetProgramResourceLocation");
	fp_glGetProgramResourceLocationIndex = (pfn_glGetProgramResourceLocationIndex)load("glGetProgramResourceLocationIndex");
}

GLboolean GLAD_ARB_provoking_vertex = GL_FALSE;
static void load_GL_ARB_provoking_vertex(LOADER load) {
	if(!GLAD_ARB_provoking_vertex) return;
	fp_glProvokingVertex = (pfn_glProvokingVertex)load("glProvokingVertex");
}

GLboolean GLAD_ARB_query_buffer_object = GL_FALSE;
GLboolean GLAD_ARB_robust_buffer_access_behavior = GL_FALSE;
GLboolean GLAD_ARB_robustness = GL_FALSE;
static void load_GL_ARB_robustness(LOADER load) {
	if(!GLAD_ARB_robustness) return;
	fp_glGetGraphicsResetStatusARB = (pfn_glGetGraphicsResetStatusARB)load("glGetGraphicsResetStatusARB");
	fp_glGetnTexImageARB = (pfn_glGetnTexImageARB)load("glGetnTexImageARB");
	fp_glReadnPixelsARB = (pfn_glReadnPixelsARB)load("glReadnPixelsARB");
	fp_glGetnCompressedTexImageARB = (pfn_glGetnCompressedTexImageARB)load("glGetnCompressedTexImageARB");
	fp_glGetnUniformfvARB = (pfn_glGetnUniformfvARB)load("glGetnUniformfvARB");
	fp_glGetnUniformivARB = (pfn_glGetnUniformivARB)load("glGetnUniformivARB");
	fp_glGetnUniformuivARB = (pfn_glGetnUniformuivARB)load("glGetnUniformuivARB");
	fp_glGetnUniformdvARB = (pfn_glGetnUniformdvARB)load("glGetnUniformdvARB");
	fp_glGetnMapdvARB = (pfn_glGetnMapdvARB)load("glGetnMapdvARB");
	fp_glGetnMapfvARB = (pfn_glGetnMapfvARB)load("glGetnMapfvARB");
	fp_glGetnMapivARB = (pfn_glGetnMapivARB)load("glGetnMapivARB");
	fp_glGetnPixelMapfvARB = (pfn_glGetnPixelMapfvARB)load("glGetnPixelMapfvARB");
	fp_glGetnPixelMapuivARB = (pfn_glGetnPixelMapuivARB)load("glGetnPixelMapuivARB");
	fp_glGetnPixelMapusvARB = (pfn_glGetnPixelMapusvARB)load("glGetnPixelMapusvARB");
	fp_glGetnPolygonStippleARB = (pfn_glGetnPolygonStippleARB)load("glGetnPolygonStippleARB");
	fp_glGetnColorTableARB = (pfn_glGetnColorTableARB)load("glGetnColorTableARB");
	fp_glGetnConvolutionFilterARB = (pfn_glGetnConvolutionFilterARB)load("glGetnConvolutionFilterARB");
	fp_glGetnSeparableFilterARB = (pfn_glGetnSeparableFilterARB)load("glGetnSeparableFilterARB");
	fp_glGetnHistogramARB = (pfn_glGetnHistogramARB)load("glGetnHistogramARB");
	fp_glGetnMinmaxARB = (pfn_glGetnMinmaxARB)load("glGetnMinmaxARB");
}

GLboolean GLAD_ARB_robustness_isolation = GL_FALSE;
GLboolean GLAD_ARB_sample_locations = GL_FALSE;
static void load_GL_ARB_sample_locations(LOADER load) {
	if(!GLAD_ARB_sample_locations) return;
	fp_glFramebufferSampleLocationsfvARB = (pfn_glFramebufferSampleLocationsfvARB)load("glFramebufferSampleLocationsfvARB");
	fp_glNamedFramebufferSampleLocationsfvARB = (pfn_glNamedFramebufferSampleLocationsfvARB)load("glNamedFramebufferSampleLocationsfvARB");
	fp_glEvaluateDepthValuesARB = (pfn_glEvaluateDepthValuesARB)load("glEvaluateDepthValuesARB");
}

GLboolean GLAD_ARB_sample_shading = GL_FALSE;
static void load_GL_ARB_sample_shading(LOADER load) {
	if(!GLAD_ARB_sample_shading) return;
	fp_glMinSampleShadingARB = (pfn_glMinSampleShadingARB)load("glMinSampleShadingARB");
}

GLboolean GLAD_ARB_sampler_objects = GL_FALSE;
static void load_GL_ARB_sampler_objects(LOADER load) {
	if(!GLAD_ARB_sampler_objects) return;
	fp_glGenSamplers = (pfn_glGenSamplers)load("glGenSamplers");
	fp_glDeleteSamplers = (pfn_glDeleteSamplers)load("glDeleteSamplers");
	fp_glIsSampler = (pfn_glIsSampler)load("glIsSampler");
	fp_glBindSampler = (pfn_glBindSampler)load("glBindSampler");
	fp_glSamplerParameteri = (pfn_glSamplerParameteri)load("glSamplerParameteri");
	fp_glSamplerParameteriv = (pfn_glSamplerParameteriv)load("glSamplerParameteriv");
	fp_glSamplerParameterf = (pfn_glSamplerParameterf)load("glSamplerParameterf");
	fp_glSamplerParameterfv = (pfn_glSamplerParameterfv)load("glSamplerParameterfv");
	fp_glSamplerParameterIiv = (pfn_glSamplerParameterIiv)load("glSamplerParameterIiv");
	fp_glSamplerParameterIuiv = (pfn_glSamplerParameterIuiv)load("glSamplerParameterIuiv");
	fp_glGetSamplerParameteriv = (pfn_glGetSamplerParameteriv)load("glGetSamplerParameteriv");
	fp_glGetSamplerParameterIiv = (pfn_glGetSamplerParameterIiv)load("glGetSamplerParameterIiv");
	fp_glGetSamplerParameterfv = (pfn_glGetSamplerParameterfv)load("glGetSamplerParameterfv");
	fp_glGetSamplerParameterIuiv = (pfn_glGetSamplerParameterIuiv)load("glGetSamplerParameterIuiv");
}

GLboolean GLAD_ARB_seamless_cube_map = GL_FALSE;
GLboolean GLAD_ARB_seamless_cubemap_per_texture = GL_FALSE;
GLboolean GLAD_ARB_separate_shader_objects = GL_FALSE;
static void load_GL_ARB_separate_shader_objects(LOADER load) {
	if(!GLAD_ARB_separate_shader_objects) return;
	fp_glUseProgramStages = (pfn_glUseProgramStages)load("glUseProgramStages");
	fp_glActiveShaderProgram = (pfn_glActiveShaderProgram)load("glActiveShaderProgram");
	fp_glCreateShaderProgramv = (pfn_glCreateShaderProgramv)load("glCreateShaderProgramv");
	fp_glBindProgramPipeline = (pfn_glBindProgramPipeline)load("glBindProgramPipeline");
	fp_glDeleteProgramPipelines = (pfn_glDeleteProgramPipelines)load("glDeleteProgramPipelines");
	fp_glGenProgramPipelines = (pfn_glGenProgramPipelines)load("glGenProgramPipelines");
	fp_glIsProgramPipeline = (pfn_glIsProgramPipeline)load("glIsProgramPipeline");
	fp_glGetProgramPipelineiv = (pfn_glGetProgramPipelineiv)load("glGetProgramPipelineiv");
	fp_glProgramUniform1i = (pfn_glProgramUniform1i)load("glProgramUniform1i");
	fp_glProgramUniform1iv = (pfn_glProgramUniform1iv)load("glProgramUniform1iv");
	fp_glProgramUniform1f = (pfn_glProgramUniform1f)load("glProgramUniform1f");
	fp_glProgramUniform1fv = (pfn_glProgramUniform1fv)load("glProgramUniform1fv");
	fp_glProgramUniform1d = (pfn_glProgramUniform1d)load("glProgramUniform1d");
	fp_glProgramUniform1dv = (pfn_glProgramUniform1dv)load("glProgramUniform1dv");
	fp_glProgramUniform1ui = (pfn_glProgramUniform1ui)load("glProgramUniform1ui");
	fp_glProgramUniform1uiv = (pfn_glProgramUniform1uiv)load("glProgramUniform1uiv");
	fp_glProgramUniform2i = (pfn_glProgramUniform2i)load("glProgramUniform2i");
	fp_glProgramUniform2iv = (pfn_glProgramUniform2iv)load("glProgramUniform2iv");
	fp_glProgramUniform2f = (pfn_glProgramUniform2f)load("glProgramUniform2f");
	fp_glProgramUniform2fv = (pfn_glProgramUniform2fv)load("glProgramUniform2fv");
	fp_glProgramUniform2d = (pfn_glProgramUniform2d)load("glProgramUniform2d");
	fp_glProgramUniform2dv = (pfn_glProgramUniform2dv)load("glProgramUniform2dv");
	fp_glProgramUniform2ui = (pfn_glProgramUniform2ui)load("glProgramUniform2ui");
	fp_glProgramUniform2uiv = (pfn_glProgramUniform2uiv)load("glProgramUniform2uiv");
	fp_glProgramUniform3i = (pfn_glProgramUniform3i)load("glProgramUniform3i");
	fp_glProgramUniform3iv = (pfn_glProgramUniform3iv)load("glProgramUniform3iv");
	fp_glProgramUniform3f = (pfn_glProgramUniform3f)load("glProgramUniform3f");
	fp_glProgramUniform3fv = (pfn_glProgramUniform3fv)load("glProgramUniform3fv");
	fp_glProgramUniform3d = (pfn_glProgramUniform3d)load("glProgramUniform3d");
	fp_glProgramUniform3dv = (pfn_glProgramUniform3dv)load("glProgramUniform3dv");
	fp_glProgramUniform3ui = (pfn_glProgramUniform3ui)load("glProgramUniform3ui");
	fp_glProgramUniform3uiv = (pfn_glProgramUniform3uiv)load("glProgramUniform3uiv");
	fp_glProgramUniform4i = (pfn_glProgramUniform4i)load("glProgramUniform4i");
	fp_glProgramUniform4iv = (pfn_glProgramUniform4iv)load("glProgramUniform4iv");
	fp_glProgramUniform4f = (pfn_glProgramUniform4f)load("glProgramUniform4f");
	fp_glProgramUniform4fv = (pfn_glProgramUniform4fv)load("glProgramUniform4fv");
	fp_glProgramUniform4d = (pfn_glProgramUniform4d)load("glProgramUniform4d");
	fp_glProgramUniform4dv = (pfn_glProgramUniform4dv)load("glProgramUniform4dv");
	fp_glProgramUniform4ui = (pfn_glProgramUniform4ui)load("glProgramUniform4ui");
	fp_glProgramUniform4uiv = (pfn_glProgramUniform4uiv)load("glProgramUniform4uiv");
	fp_glProgramUniformMatrix2fv = (pfn_glProgramUniformMatrix2fv)load("glProgramUniformMatrix2fv");
	fp_glProgramUniformMatrix3fv = (pfn_glProgramUniformMatrix3fv)load("glProgramUniformMatrix3fv");
	fp_glProgramUniformMatrix4fv = (pfn_glProgramUniformMatrix4fv)load("glProgramUniformMatrix4fv");
	fp_glProgramUniformMatrix2dv = (pfn_glProgramUniformMatrix2dv)load("glProgramUniformMatrix2dv");
	fp_glProgramUniformMatrix3dv = (pfn_glProgramUniformMatrix3dv)load("glProgramUniformMatrix3dv");
	fp_glProgramUniformMatrix4dv = (pfn_glProgramUniformMatrix4dv)load("glProgramUniformMatrix4dv");
	fp_glProgramUniformMatrix2x3fv = (pfn_glProgramUniformMatrix2x3fv)load("glProgramUniformMatrix2x3fv");
	fp_glProgramUniformMatrix3x2fv = (pfn_glProgramUniformMatrix3x2fv)load("glProgramUniformMatrix3x2fv");
	fp_glProgramUniformMatrix2x4fv = (pfn_glProgramUniformMatrix2x4fv)load("glProgramUniformMatrix2x4fv");
	fp_glProgramUniformMatrix4x2fv = (pfn_glProgramUniformMatrix4x2fv)load("glProgramUniformMatrix4x2fv");
	fp_glProgramUniformMatrix3x4fv = (pfn_glProgramUniformMatrix3x4fv)load("glProgramUniformMatrix3x4fv");
	fp_glProgramUniformMatrix4x3fv = (pfn_glProgramUniformMatrix4x3fv)load("glProgramUniformMatrix4x3fv");
	fp_glProgramUniformMatrix2x3dv = (pfn_glProgramUniformMatrix2x3dv)load("glProgramUniformMatrix2x3dv");
	fp_glProgramUniformMatrix3x2dv = (pfn_glProgramUniformMatrix3x2dv)load("glProgramUniformMatrix3x2dv");
	fp_glProgramUniformMatrix2x4dv = (pfn_glProgramUniformMatrix2x4dv)load("glProgramUniformMatrix2x4dv");
	fp_glProgramUniformMatrix4x2dv = (pfn_glProgramUniformMatrix4x2dv)load("glProgramUniformMatrix4x2dv");
	fp_glProgramUniformMatrix3x4dv = (pfn_glProgramUniformMatrix3x4dv)load("glProgramUniformMatrix3x4dv");
	fp_glProgramUniformMatrix4x3dv = (pfn_glProgramUniformMatrix4x3dv)load("glProgramUniformMatrix4x3dv");
	fp_glValidateProgramPipeline = (pfn_glValidateProgramPipeline)load("glValidateProgramPipeline");
	fp_glGetProgramPipelineInfoLog = (pfn_glGetProgramPipelineInfoLog)load("glGetProgramPipelineInfoLog");
}

GLboolean GLAD_ARB_shader_atomic_counter_ops = GL_FALSE;
GLboolean GLAD_ARB_shader_atomic_counters = GL_FALSE;
static void load_GL_ARB_shader_atomic_counters(LOADER load) {
	if(!GLAD_ARB_shader_atomic_counters) return;
	fp_glGetActiveAtomicCounterBufferiv = (pfn_glGetActiveAtomicCounterBufferiv)load("glGetActiveAtomicCounterBufferiv");
}

GLboolean GLAD_ARB_shader_ballot = GL_FALSE;
GLboolean GLAD_ARB_shader_bit_encoding = GL_FALSE;
GLboolean GLAD_ARB_shader_clock = GL_FALSE;
GLboolean GLAD_ARB_shader_draw_parameters = GL_FALSE;
GLboolean GLAD_ARB_shader_group_vote = GL_FALSE;
GLboolean GLAD_ARB_shader_image_load_store = GL_FALSE;
static void load_GL_ARB_shader_image_load_store(LOADER load) {
	if(!GLAD_ARB_shader_image_load_store) return;
	fp_glBindImageTexture = (pfn_glBindImageTexture)load("glBindImageTexture");
	fp_glMemoryBarrier = (pfn_glMemoryBarrier)load("glMemoryBarrier");
}

GLboolean GLAD_ARB_shader_image_size = GL_FALSE;
GLboolean GLAD_ARB_shader_precision = GL_FALSE;
GLboolean GLAD_ARB_shader_stencil_export = GL_FALSE;
GLboolean GLAD_ARB_shader_storage_buffer_object = GL_FALSE;
static void load_GL_ARB_shader_storage_buffer_object(LOADER load) {
	if(!GLAD_ARB_shader_storage_buffer_object) return;
	fp_glShaderStorageBlockBinding = (pfn_glShaderStorageBlockBinding)load("glShaderStorageBlockBinding");
}

GLboolean GLAD_ARB_shader_subroutine = GL_FALSE;
static void load_GL_ARB_shader_subroutine(LOADER load) {
	if(!GLAD_ARB_shader_subroutine) return;
	fp_glGetSubroutineUniformLocation = (pfn_glGetSubroutineUniformLocation)load("glGetSubroutineUniformLocation");
	fp_glGetSubroutineIndex = (pfn_glGetSubroutineIndex)load("glGetSubroutineIndex");
	fp_glGetActiveSubroutineUniformiv = (pfn_glGetActiveSubroutineUniformiv)load("glGetActiveSubroutineUniformiv");
	fp_glGetActiveSubroutineUniformName = (pfn_glGetActiveSubroutineUniformName)load("glGetActiveSubroutineUniformName");
	fp_glGetActiveSubroutineName = (pfn_glGetActiveSubroutineName)load("glGetActiveSubroutineName");
	fp_glUniformSubroutinesuiv = (pfn_glUniformSubroutinesuiv)load("glUniformSubroutinesuiv");
	fp_glGetUniformSubroutineuiv = (pfn_glGetUniformSubroutineuiv)load("glGetUniformSubroutineuiv");
	fp_glGetProgramStageiv = (pfn_glGetProgramStageiv)load("glGetProgramStageiv");
}

GLboolean GLAD_ARB_shader_texture_image_samples = GL_FALSE;
GLboolean GLAD_ARB_shader_texture_lod = GL_FALSE;
GLboolean GLAD_ARB_shader_viewport_layer_array = GL_FALSE;
GLboolean GLAD_ARB_shading_language_420pack = GL_FALSE;
GLboolean GLAD_ARB_shading_language_include = GL_FALSE;
static void load_GL_ARB_shading_language_include(LOADER load) {
	if(!GLAD_ARB_shading_language_include) return;
	fp_glNamedStringARB = (pfn_glNamedStringARB)load("glNamedStringARB");
	fp_glDeleteNamedStringARB = (pfn_glDeleteNamedStringARB)load("glDeleteNamedStringARB");
	fp_glCompileShaderIncludeARB = (pfn_glCompileShaderIncludeARB)load("glCompileShaderIncludeARB");
	fp_glIsNamedStringARB = (pfn_glIsNamedStringARB)load("glIsNamedStringARB");
	fp_glGetNamedStringARB = (pfn_glGetNamedStringARB)load("glGetNamedStringARB");
	fp_glGetNamedStringivARB = (pfn_glGetNamedStringivARB)load("glGetNamedStringivARB");
}

GLboolean GLAD_ARB_shading_language_packing = GL_FALSE;
GLboolean GLAD_ARB_sparse_buffer = GL_FALSE;
static void load_GL_ARB_sparse_buffer(LOADER load) {
	if(!GLAD_ARB_sparse_buffer) return;
	fp_glBufferPageCommitmentARB = (pfn_glBufferPageCommitmentARB)load("glBufferPageCommitmentARB");
	fp_glNamedBufferPageCommitmentEXT = (pfn_glNamedBufferPageCommitmentEXT)load("glNamedBufferPageCommitmentEXT");
	fp_glNamedBufferPageCommitmentARB = (pfn_glNamedBufferPageCommitmentARB)load("glNamedBufferPageCommitmentARB");
}

GLboolean GLAD_ARB_sparse_texture = GL_FALSE;
static void load_GL_ARB_sparse_texture(LOADER load) {
	if(!GLAD_ARB_sparse_texture) return;
	fp_glTexPageCommitmentARB = (pfn_glTexPageCommitmentARB)load("glTexPageCommitmentARB");
}

GLboolean GLAD_ARB_sparse_texture2 = GL_FALSE;
GLboolean GLAD_ARB_sparse_texture_clamp = GL_FALSE;
GLboolean GLAD_ARB_stencil_texturing = GL_FALSE;
GLboolean GLAD_ARB_sync = GL_FALSE;
static void load_GL_ARB_sync(LOADER load) {
	if(!GLAD_ARB_sync) return;
	fp_glFenceSync = (pfn_glFenceSync)load("glFenceSync");
	fp_glIsSync = (pfn_glIsSync)load("glIsSync");
	fp_glDeleteSync = (pfn_glDeleteSync)load("glDeleteSync");
	fp_glClientWaitSync = (pfn_glClientWaitSync)load("glClientWaitSync");
	fp_glWaitSync = (pfn_glWaitSync)load("glWaitSync");
	fp_glGetInteger64v = (pfn_glGetInteger64v)load("glGetInteger64v");
	fp_glGetSynciv = (pfn_glGetSynciv)load("glGetSynciv");
}

GLboolean GLAD_ARB_tessellation_shader = GL_FALSE;
static void load_GL_ARB_tessellation_shader(LOADER load) {
	if(!GLAD_ARB_tessellation_shader) return;
	fp_glPatchParameteri = (pfn_glPatchParameteri)load("glPatchParameteri");
	fp_glPatchParameterfv = (pfn_glPatchParameterfv)load("glPatchParameterfv");
}

GLboolean GLAD_ARB_texture_barrier = GL_FALSE;
static void load_GL_ARB_texture_barrier(LOADER load) {
	if(!GLAD_ARB_texture_barrier) return;
	fp_glTextureBarrier = (pfn_glTextureBarrier)load("glTextureBarrier");
}

GLboolean GLAD_ARB_texture_buffer_object = GL_FALSE;
static void load_GL_ARB_texture_buffer_object(LOADER load) {
	if(!GLAD_ARB_texture_buffer_object) return;
	fp_glTexBufferARB = (pfn_glTexBufferARB)load("glTexBufferARB");
}

GLboolean GLAD_ARB_texture_buffer_object_rgb32 = GL_FALSE;
GLboolean GLAD_ARB_texture_buffer_range = GL_FALSE;
static void load_GL_ARB_texture_buffer_range(LOADER load) {
	if(!GLAD_ARB_texture_buffer_range) return;
	fp_glTexBufferRange = (pfn_glTexBufferRange)load("glTexBufferRange");
}

GLboolean GLAD_ARB_texture_compression_bptc = GL_FALSE;
GLboolean GLAD_ARB_texture_compression_rgtc = GL_FALSE;
GLboolean GLAD_ARB_texture_cube_map_array = GL_FALSE;
GLboolean GLAD_ARB_texture_filter_minmax = GL_FALSE;
GLboolean GLAD_ARB_texture_float = GL_FALSE;
GLboolean GLAD_ARB_texture_gather = GL_FALSE;
GLboolean GLAD_ARB_texture_mirror_clamp_to_edge = GL_FALSE;
GLboolean GLAD_ARB_texture_multisample = GL_FALSE;
static void load_GL_ARB_texture_multisample(LOADER load) {
	if(!GLAD_ARB_texture_multisample) return;
	fp_glTexImage2DMultisample = (pfn_glTexImage2DMultisample)load("glTexImage2DMultisample");
	fp_glTexImage3DMultisample = (pfn_glTexImage3DMultisample)load("glTexImage3DMultisample");
	fp_glGetMultisamplefv = (pfn_glGetMultisamplefv)load("glGetMultisamplefv");
	fp_glSampleMaski = (pfn_glSampleMaski)load("glSampleMaski");
}

GLboolean GLAD_ARB_texture_query_levels = GL_FALSE;
GLboolean GLAD_ARB_texture_query_lod = GL_FALSE;
GLboolean GLAD_ARB_texture_rectangle = GL_FALSE;
GLboolean GLAD_ARB_texture_rg = GL_FALSE;
GLboolean GLAD_ARB_texture_rgb10_a2ui = GL_FALSE;
GLboolean GLAD_ARB_texture_stencil8 = GL_FALSE;
GLboolean GLAD_ARB_texture_storage = GL_FALSE;
static void load_GL_ARB_texture_storage(LOADER load) {
	if(!GLAD_ARB_texture_storage) return;
	fp_glTexStorage1D = (pfn_glTexStorage1D)load("glTexStorage1D");
	fp_glTexStorage2D = (pfn_glTexStorage2D)load("glTexStorage2D");
	fp_glTexStorage3D = (pfn_glTexStorage3D)load("glTexStorage3D");
}

GLboolean GLAD_ARB_texture_storage_multisample = GL_FALSE;
static void load_GL_ARB_texture_storage_multisample(LOADER load) {
	if(!GLAD_ARB_texture_storage_multisample) return;
	fp_glTexStorage2DMultisample = (pfn_glTexStorage2DMultisample)load("glTexStorage2DMultisample");
	fp_glTexStorage3DMultisample = (pfn_glTexStorage3DMultisample)load("glTexStorage3DMultisample");
}

GLboolean GLAD_ARB_texture_swizzle = GL_FALSE;
GLboolean GLAD_ARB_texture_view = GL_FALSE;
static void load_GL_ARB_texture_view(LOADER load) {
	if(!GLAD_ARB_texture_view) return;
	fp_glTextureView = (pfn_glTextureView)load("glTextureView");
}

GLboolean GLAD_ARB_timer_query = GL_FALSE;
static void load_GL_ARB_timer_query(LOADER load) {
	if(!GLAD_ARB_timer_query) return;
	fp_glQueryCounter = (pfn_glQueryCounter)load("glQueryCounter");
	fp_glGetQueryObjecti64v = (pfn_glGetQueryObjecti64v)load("glGetQueryObjecti64v");
	fp_glGetQueryObjectui64v = (pfn_glGetQueryObjectui64v)load("glGetQueryObjectui64v");
}

GLboolean GLAD_ARB_transform_feedback2 = GL_FALSE;
static void load_GL_ARB_transform_feedback2(LOADER load) {
	if(!GLAD_ARB_transform_feedback2) return;
	fp_glBindTransformFeedback = (pfn_glBindTransformFeedback)load("glBindTransformFeedback");
	fp_glDeleteTransformFeedbacks = (pfn_glDeleteTransformFeedbacks)load("glDeleteTransformFeedbacks");
	fp_glGenTransformFeedbacks = (pfn_glGenTransformFeedbacks)load("glGenTransformFeedbacks");
	fp_glIsTransformFeedback = (pfn_glIsTransformFeedback)load("glIsTransformFeedback");
	fp_glPauseTransformFeedback = (pfn_glPauseTransformFeedback)load("glPauseTransformFeedback");
	fp_glResumeTransformFeedback = (pfn_glResumeTransformFeedback)load("glResumeTransformFeedback");
	fp_glDrawTransformFeedback = (pfn_glDrawTransformFeedback)load("glDrawTransformFeedback");
}

GLboolean GLAD_ARB_transform_feedback3 = GL_FALSE;
static void load_GL_ARB_transform_feedback3(LOADER load) {
	if(!GLAD_ARB_transform_feedback3) return;
	fp_glDrawTransformFeedbackStream = (pfn_glDrawTransformFeedbackStream)load("glDrawTransformFeedbackStream");
	fp_glBeginQueryIndexed = (pfn_glBeginQueryIndexed)load("glBeginQueryIndexed");
	fp_glEndQueryIndexed = (pfn_glEndQueryIndexed)load("glEndQueryIndexed");
	fp_glGetQueryIndexediv = (pfn_glGetQueryIndexediv)load("glGetQueryIndexediv");
}

GLboolean GLAD_ARB_transform_feedback_instanced = GL_FALSE;
static void load_GL_ARB_transform_feedback_instanced(LOADER load) {
	if(!GLAD_ARB_transform_feedback_instanced) return;
	fp_glDrawTransformFeedbackInstanced = (pfn_glDrawTransformFeedbackInstanced)load("glDrawTransformFeedbackInstanced");
	fp_glDrawTransformFeedbackStreamInstanced = (pfn_glDrawTransformFeedbackStreamInstanced)load("glDrawTransformFeedbackStreamInstanced");
}

GLboolean GLAD_ARB_transform_feedback_overflow_query = GL_FALSE;
GLboolean GLAD_ARB_uniform_buffer_object = GL_FALSE;
static void load_GL_ARB_uniform_buffer_object(LOADER load) {
	if(!GLAD_ARB_uniform_buffer_object) return;
	fp_glGetUniformIndices = (pfn_glGetUniformIndices)load("glGetUniformIndices");
	fp_glGetActiveUniformsiv = (pfn_glGetActiveUniformsiv)load("glGetActiveUniformsiv");
	fp_glGetActiveUniformName = (pfn_glGetActiveUniformName)load("glGetActiveUniformName");
	fp_glGetUniformBlockIndex = (pfn_glGetUniformBlockIndex)load("glGetUniformBlockIndex");
	fp_glGetActiveUniformBlockiv = (pfn_glGetActiveUniformBlockiv)load("glGetActiveUniformBlockiv");
	fp_glGetActiveUniformBlockName = (pfn_glGetActiveUniformBlockName)load("glGetActiveUniformBlockName");
	fp_glUniformBlockBinding = (pfn_glUniformBlockBinding)load("glUniformBlockBinding");
	fp_glBindBufferRange = (pfn_glBindBufferRange)load("glBindBufferRange");
	fp_glBindBufferBase = (pfn_glBindBufferBase)load("glBindBufferBase");
	fp_glGetIntegeri_v = (pfn_glGetIntegeri_v)load("glGetIntegeri_v");
}

GLboolean GLAD_ARB_vertex_array_bgra = GL_FALSE;
GLboolean GLAD_ARB_vertex_array_object = GL_FALSE;
static void load_GL_ARB_vertex_array_object(LOADER load) {
	if(!GLAD_ARB_vertex_array_object) return;
	fp_glBindVertexArray = (pfn_glBindVertexArray)load("glBindVertexArray");
	fp_glDeleteVertexArrays = (pfn_glDeleteVertexArrays)load("glDeleteVertexArrays");
	fp_glGenVertexArrays = (pfn_glGenVertexArrays)load("glGenVertexArrays");
	fp_glIsVertexArray = (pfn_glIsVertexArray)load("glIsVertexArray");
}

GLboolean GLAD_ARB_vertex_attrib_64bit = GL_FALSE;
static void load_GL_ARB_vertex_attrib_64bit(LOADER load) {
	if(!GLAD_ARB_vertex_attrib_64bit) return;
	fp_glVertexAttribL1d = (pfn_glVertexAttribL1d)load("glVertexAttribL1d");
	fp_glVertexAttribL2d = (pfn_glVertexAttribL2d)load("glVertexAttribL2d");
	fp_glVertexAttribL3d = (pfn_glVertexAttribL3d)load("glVertexAttribL3d");
	fp_glVertexAttribL4d = (pfn_glVertexAttribL4d)load("glVertexAttribL4d");
	fp_glVertexAttribL1dv = (pfn_glVertexAttribL1dv)load("glVertexAttribL1dv");
	fp_glVertexAttribL2dv = (pfn_glVertexAttribL2dv)load("glVertexAttribL2dv");
	fp_glVertexAttribL3dv = (pfn_glVertexAttribL3dv)load("glVertexAttribL3dv");
	fp_glVertexAttribL4dv = (pfn_glVertexAttribL4dv)load("glVertexAttribL4dv");
	fp_glVertexAttribLPointer = (pfn_glVertexAttribLPointer)load("glVertexAttribLPointer");
	fp_glGetVertexAttribLdv = (pfn_glGetVertexAttribLdv)load("glGetVertexAttribLdv");
}

GLboolean GLAD_ARB_vertex_attrib_binding = GL_FALSE;
static void load_GL_ARB_vertex_attrib_binding(LOADER load) {
	if(!GLAD_ARB_vertex_attrib_binding) return;
	fp_glBindVertexBuffer = (pfn_glBindVertexBuffer)load("glBindVertexBuffer");
	fp_glVertexAttribFormat = (pfn_glVertexAttribFormat)load("glVertexAttribFormat");
	fp_glVertexAttribIFormat = (pfn_glVertexAttribIFormat)load("glVertexAttribIFormat");
	fp_glVertexAttribLFormat = (pfn_glVertexAttribLFormat)load("glVertexAttribLFormat");
	fp_glVertexAttribBinding = (pfn_glVertexAttribBinding)load("glVertexAttribBinding");
	fp_glVertexBindingDivisor = (pfn_glVertexBindingDivisor)load("glVertexBindingDivisor");
}

GLboolean GLAD_ARB_vertex_type_10f_11f_11f_rev = GL_FALSE;
GLboolean GLAD_ARB_vertex_type_2_10_10_10_rev = GL_FALSE;
static void load_GL_ARB_vertex_type_2_10_10_10_rev(LOADER load) {
	if(!GLAD_ARB_vertex_type_2_10_10_10_rev) return;
	fp_glVertexAttribP1ui = (pfn_glVertexAttribP1ui)load("glVertexAttribP1ui");
	fp_glVertexAttribP1uiv = (pfn_glVertexAttribP1uiv)load("glVertexAttribP1uiv");
	fp_glVertexAttribP2ui = (pfn_glVertexAttribP2ui)load("glVertexAttribP2ui");
	fp_glVertexAttribP2uiv = (pfn_glVertexAttribP2uiv)load("glVertexAttribP2uiv");
	fp_glVertexAttribP3ui = (pfn_glVertexAttribP3ui)load("glVertexAttribP3ui");
	fp_glVertexAttribP3uiv = (pfn_glVertexAttribP3uiv)load("glVertexAttribP3uiv");
	fp_glVertexAttribP4ui = (pfn_glVertexAttribP4ui)load("glVertexAttribP4ui");
	fp_glVertexAttribP4uiv = (pfn_glVertexAttribP4uiv)load("glVertexAttribP4uiv");
	fp_glVertexP2ui = (pfn_glVertexP2ui)load("glVertexP2ui");
	fp_glVertexP2uiv = (pfn_glVertexP2uiv)load("glVertexP2uiv");
	fp_glVertexP3ui = (pfn_glVertexP3ui)load("glVertexP3ui");
	fp_glVertexP3uiv = (pfn_glVertexP3uiv)load("glVertexP3uiv");
	fp_glVertexP4ui = (pfn_glVertexP4ui)load("glVertexP4ui");
	fp_glVertexP4uiv = (pfn_glVertexP4uiv)load("glVertexP4uiv");
	fp_glTexCoordP1ui = (pfn_glTexCoordP1ui)load("glTexCoordP1ui");
	fp_glTexCoordP1uiv = (pfn_glTexCoordP1uiv)load("glTexCoordP1uiv");
	fp_glTexCoordP2ui = (pfn_glTexCoordP2ui)load("glTexCoordP2ui");
	fp_glTexCoordP2uiv = (pfn_glTexCoordP2uiv)load("glTexCoordP2uiv");
	fp_glTexCoordP3ui = (pfn_glTexCoordP3ui)load("glTexCoordP3ui");
	fp_glTexCoordP3uiv = (pfn_glTexCoordP3uiv)load("glTexCoordP3uiv");
	fp_glTexCoordP4ui = (pfn_glTexCoordP4ui)load("glTexCoordP4ui");
	fp_glTexCoordP4uiv = (pfn_glTexCoordP4uiv)load("glTexCoordP4uiv");
	fp_glMultiTexCoordP1ui = (pfn_glMultiTexCoordP1ui)load("glMultiTexCoordP1ui");
	fp_glMultiTexCoordP1uiv = (pfn_glMultiTexCoordP1uiv)load("glMultiTexCoordP1uiv");
	fp_glMultiTexCoordP2ui = (pfn_glMultiTexCoordP2ui)load("glMultiTexCoordP2ui");
	fp_glMultiTexCoordP2uiv = (pfn_glMultiTexCoordP2uiv)load("glMultiTexCoordP2uiv");
	fp_glMultiTexCoordP3ui = (pfn_glMultiTexCoordP3ui)load("glMultiTexCoordP3ui");
	fp_glMultiTexCoordP3uiv = (pfn_glMultiTexCoordP3uiv)load("glMultiTexCoordP3uiv");
	fp_glMultiTexCoordP4ui = (pfn_glMultiTexCoordP4ui)load("glMultiTexCoordP4ui");
	fp_glMultiTexCoordP4uiv = (pfn_glMultiTexCoordP4uiv)load("glMultiTexCoordP4uiv");
	fp_glNormalP3ui = (pfn_glNormalP3ui)load("glNormalP3ui");
	fp_glNormalP3uiv = (pfn_glNormalP3uiv)load("glNormalP3uiv");
	fp_glColorP3ui = (pfn_glColorP3ui)load("glColorP3ui");
	fp_glColorP3uiv = (pfn_glColorP3uiv)load("glColorP3uiv");
	fp_glColorP4ui = (pfn_glColorP4ui)load("glColorP4ui");
	fp_glColorP4uiv = (pfn_glColorP4uiv)load("glColorP4uiv");
	fp_glSecondaryColorP3ui = (pfn_glSecondaryColorP3ui)load("glSecondaryColorP3ui");
	fp_glSecondaryColorP3uiv = (pfn_glSecondaryColorP3uiv)load("glSecondaryColorP3uiv");
}

GLboolean GLAD_ARB_viewport_array = GL_FALSE;
static void load_GL_ARB_viewport_array(LOADER load) {
	if(!GLAD_ARB_viewport_array) return;
	fp_glViewportArrayv = (pfn_glViewportArrayv)load("glViewportArrayv");
	fp_glViewportIndexedf = (pfn_glViewportIndexedf)load("glViewportIndexedf");
	fp_glViewportIndexedfv = (pfn_glViewportIndexedfv)load("glViewportIndexedfv");
	fp_glScissorArrayv = (pfn_glScissorArrayv)load("glScissorArrayv");
	fp_glScissorIndexed = (pfn_glScissorIndexed)load("glScissorIndexed");
	fp_glScissorIndexedv = (pfn_glScissorIndexedv)load("glScissorIndexedv");
	fp_glDepthRangeArrayv = (pfn_glDepthRangeArrayv)load("glDepthRangeArrayv");
	fp_glDepthRangeIndexed = (pfn_glDepthRangeIndexed)load("glDepthRangeIndexed");
	fp_glGetFloati_v = (pfn_glGetFloati_v)load("glGetFloati_v");
	fp_glGetDoublei_v = (pfn_glGetDoublei_v)load("glGetDoublei_v");
}

GLboolean GLAD_EXT_base_instance = GL_FALSE;
static void load_GL_EXT_base_instance(LOADER load) {
	if(!GLAD_EXT_base_instance) return;
	fp_glDrawArraysInstancedBaseInstanceEXT = (pfn_glDrawArraysInstancedBaseInstanceEXT)load("glDrawArraysInstancedBaseInstanceEXT");
	fp_glDrawElementsInstancedBaseInstanceEXT = (pfn_glDrawElementsInstancedBaseInstanceEXT)load("glDrawElementsInstancedBaseInstanceEXT");
	fp_glDrawElementsInstancedBaseVertexBaseInstanceEXT = (pfn_glDrawElementsInstancedBaseVertexBaseInstanceEXT)load("glDrawElementsInstancedBaseVertexBaseInstanceEXT");
}

GLboolean GLAD_EXT_bgra = GL_FALSE;
GLboolean GLAD_EXT_bindable_uniform = GL_FALSE;
static void load_GL_EXT_bindable_uniform(LOADER load) {
	if(!GLAD_EXT_bindable_uniform) return;
	fp_glUniformBufferEXT = (pfn_glUniformBufferEXT)load("glUniformBufferEXT");
	fp_glGetUniformBufferSizeEXT = (pfn_glGetUniformBufferSizeEXT)load("glGetUniformBufferSizeEXT");
	fp_glGetUniformOffsetEXT = (pfn_glGetUniformOffsetEXT)load("glGetUniformOffsetEXT");
}

GLboolean GLAD_EXT_blend_func_extended = GL_FALSE;
static void load_GL_EXT_blend_func_extended(LOADER load) {
	if(!GLAD_EXT_blend_func_extended) return;
	fp_glBindFragDataLocationIndexedEXT = (pfn_glBindFragDataLocationIndexedEXT)load("glBindFragDataLocationIndexedEXT");
	fp_glBindFragDataLocationEXT = (pfn_glBindFragDataLocationEXT)load("glBindFragDataLocationEXT");
	fp_glGetProgramResourceLocationIndexEXT = (pfn_glGetProgramResourceLocationIndexEXT)load("glGetProgramResourceLocationIndexEXT");
	fp_glGetFragDataIndexEXT = (pfn_glGetFragDataIndexEXT)load("glGetFragDataIndexEXT");
}

GLboolean GLAD_EXT_blend_minmax = GL_FALSE;
static void load_GL_EXT_blend_minmax(LOADER load) {
	if(!GLAD_EXT_blend_minmax) return;
	fp_glBlendEquationEXT = (pfn_glBlendEquationEXT)load("glBlendEquationEXT");
}

GLboolean GLAD_EXT_buffer_storage = GL_FALSE;
static void load_GL_EXT_buffer_storage(LOADER load) {
	if(!GLAD_EXT_buffer_storage) return;
	fp_glBufferStorageEXT = (pfn_glBufferStorageEXT)load("glBufferStorageEXT");
}

GLboolean GLAD_EXT_color_buffer_float = GL_FALSE;
GLboolean GLAD_EXT_color_buffer_half_float = GL_FALSE;
GLboolean GLAD_EXT_copy_image = GL_FALSE;
static void load_GL_EXT_copy_image(LOADER load) {
	if(!GLAD_EXT_copy_image) return;
	fp_glCopyImageSubDataEXT = (pfn_glCopyImageSubDataEXT)load("glCopyImageSubDataEXT");
}

GLboolean GLAD_EXT_debug_label = GL_FALSE;
static void load_GL_EXT_debug_label(LOADER load) {
	if(!GLAD_EXT_debug_label) return;
	fp_glLabelObjectEXT = (pfn_glLabelObjectEXT)load("glLabelObjectEXT");
	fp_glGetObjectLabelEXT = (pfn_glGetObjectLabelEXT)load("glGetObjectLabelEXT");
}

GLboolean GLAD_EXT_debug_marker = GL_FALSE;
static void load_GL_EXT_debug_marker(LOADER load) {
	if(!GLAD_EXT_debug_marker) return;
	fp_glInsertEventMarkerEXT = (pfn_glInsertEventMarkerEXT)load("glInsertEventMarkerEXT");
	fp_glPushGroupMarkerEXT = (pfn_glPushGroupMarkerEXT)load("glPushGroupMarkerEXT");
	fp_glPopGroupMarkerEXT = (pfn_glPopGroupMarkerEXT)load("glPopGroupMarkerEXT");
}

GLboolean GLAD_EXT_direct_state_access = GL_FALSE;
static void load_GL_EXT_direct_state_access(LOADER load) {
	if(!GLAD_EXT_direct_state_access) return;
	fp_glMatrixLoadfEXT = (pfn_glMatrixLoadfEXT)load("glMatrixLoadfEXT");
	fp_glMatrixLoaddEXT = (pfn_glMatrixLoaddEXT)load("glMatrixLoaddEXT");
	fp_glMatrixMultfEXT = (pfn_glMatrixMultfEXT)load("glMatrixMultfEXT");
	fp_glMatrixMultdEXT = (pfn_glMatrixMultdEXT)load("glMatrixMultdEXT");
	fp_glMatrixLoadIdentityEXT = (pfn_glMatrixLoadIdentityEXT)load("glMatrixLoadIdentityEXT");
	fp_glMatrixRotatefEXT = (pfn_glMatrixRotatefEXT)load("glMatrixRotatefEXT");
	fp_glMatrixRotatedEXT = (pfn_glMatrixRotatedEXT)load("glMatrixRotatedEXT");
	fp_glMatrixScalefEXT = (pfn_glMatrixScalefEXT)load("glMatrixScalefEXT");
	fp_glMatrixScaledEXT = (pfn_glMatrixScaledEXT)load("glMatrixScaledEXT");
	fp_glMatrixTranslatefEXT = (pfn_glMatrixTranslatefEXT)load("glMatrixTranslatefEXT");
	fp_glMatrixTranslatedEXT = (pfn_glMatrixTranslatedEXT)load("glMatrixTranslatedEXT");
	fp_glMatrixFrustumEXT = (pfn_glMatrixFrustumEXT)load("glMatrixFrustumEXT");
	fp_glMatrixOrthoEXT = (pfn_glMatrixOrthoEXT)load("glMatrixOrthoEXT");
	fp_glMatrixPopEXT = (pfn_glMatrixPopEXT)load("glMatrixPopEXT");
	fp_glMatrixPushEXT = (pfn_glMatrixPushEXT)load("glMatrixPushEXT");
	fp_glClientAttribDefaultEXT = (pfn_glClientAttribDefaultEXT)load("glClientAttribDefaultEXT");
	fp_glPushClientAttribDefaultEXT = (pfn_glPushClientAttribDefaultEXT)load("glPushClientAttribDefaultEXT");
	fp_glTextureParameterfEXT = (pfn_glTextureParameterfEXT)load("glTextureParameterfEXT");
	fp_glTextureParameterfvEXT = (pfn_glTextureParameterfvEXT)load("glTextureParameterfvEXT");
	fp_glTextureParameteriEXT = (pfn_glTextureParameteriEXT)load("glTextureParameteriEXT");
	fp_glTextureParameterivEXT = (pfn_glTextureParameterivEXT)load("glTextureParameterivEXT");
	fp_glTextureImage1DEXT = (pfn_glTextureImage1DEXT)load("glTextureImage1DEXT");
	fp_glTextureImage2DEXT = (pfn_glTextureImage2DEXT)load("glTextureImage2DEXT");
	fp_glTextureSubImage1DEXT = (pfn_glTextureSubImage1DEXT)load("glTextureSubImage1DEXT");
	fp_glTextureSubImage2DEXT = (pfn_glTextureSubImage2DEXT)load("glTextureSubImage2DEXT");
	fp_glCopyTextureImage1DEXT = (pfn_glCopyTextureImage1DEXT)load("glCopyTextureImage1DEXT");
	fp_glCopyTextureImage2DEXT = (pfn_glCopyTextureImage2DEXT)load("glCopyTextureImage2DEXT");
	fp_glCopyTextureSubImage1DEXT = (pfn_glCopyTextureSubImage1DEXT)load("glCopyTextureSubImage1DEXT");
	fp_glCopyTextureSubImage2DEXT = (pfn_glCopyTextureSubImage2DEXT)load("glCopyTextureSubImage2DEXT");
	fp_glGetTextureImageEXT = (pfn_glGetTextureImageEXT)load("glGetTextureImageEXT");
	fp_glGetTextureParameterfvEXT = (pfn_glGetTextureParameterfvEXT)load("glGetTextureParameterfvEXT");
	fp_glGetTextureParameterivEXT = (pfn_glGetTextureParameterivEXT)load("glGetTextureParameterivEXT");
	fp_glGetTextureLevelParameterfvEXT = (pfn_glGetTextureLevelParameterfvEXT)load("glGetTextureLevelParameterfvEXT");
	fp_glGetTextureLevelParameterivEXT = (pfn_glGetTextureLevelParameterivEXT)load("glGetTextureLevelParameterivEXT");
	fp_glTextureImage3DEXT = (pfn_glTextureImage3DEXT)load("glTextureImage3DEXT");
	fp_glTextureSubImage3DEXT = (pfn_glTextureSubImage3DEXT)load("glTextureSubImage3DEXT");
	fp_glCopyTextureSubImage3DEXT = (pfn_glCopyTextureSubImage3DEXT)load("glCopyTextureSubImage3DEXT");
	fp_glBindMultiTextureEXT = (pfn_glBindMultiTextureEXT)load("glBindMultiTextureEXT");
	fp_glMultiTexCoordPointerEXT = (pfn_glMultiTexCoordPointerEXT)load("glMultiTexCoordPointerEXT");
	fp_glMultiTexEnvfEXT = (pfn_glMultiTexEnvfEXT)load("glMultiTexEnvfEXT");
	fp_glMultiTexEnvfvEXT = (pfn_glMultiTexEnvfvEXT)load("glMultiTexEnvfvEXT");
	fp_glMultiTexEnviEXT = (pfn_glMultiTexEnviEXT)load("glMultiTexEnviEXT");
	fp_glMultiTexEnvivEXT = (pfn_glMultiTexEnvivEXT)load("glMultiTexEnvivEXT");
	fp_glMultiTexGendEXT = (pfn_glMultiTexGendEXT)load("glMultiTexGendEXT");
	fp_glMultiTexGendvEXT = (pfn_glMultiTexGendvEXT)load("glMultiTexGendvEXT");
	fp_glMultiTexGenfEXT = (pfn_glMultiTexGenfEXT)load("glMultiTexGenfEXT");
	fp_glMultiTexGenfvEXT = (pfn_glMultiTexGenfvEXT)load("glMultiTexGenfvEXT");
	fp_glMultiTexGeniEXT = (pfn_glMultiTexGeniEXT)load("glMultiTexGeniEXT");
	fp_glMultiTexGenivEXT = (pfn_glMultiTexGenivEXT)load("glMultiTexGenivEXT");
	fp_glGetMultiTexEnvfvEXT = (pfn_glGetMultiTexEnvfvEXT)load("glGetMultiTexEnvfvEXT");
	fp_glGetMultiTexEnvivEXT = (pfn_glGetMultiTexEnvivEXT)load("glGetMultiTexEnvivEXT");
	fp_glGetMultiTexGendvEXT = (pfn_glGetMultiTexGendvEXT)load("glGetMultiTexGendvEXT");
	fp_glGetMultiTexGenfvEXT = (pfn_glGetMultiTexGenfvEXT)load("glGetMultiTexGenfvEXT");
	fp_glGetMultiTexGenivEXT = (pfn_glGetMultiTexGenivEXT)load("glGetMultiTexGenivEXT");
	fp_glMultiTexParameteriEXT = (pfn_glMultiTexParameteriEXT)load("glMultiTexParameteriEXT");
	fp_glMultiTexParameterivEXT = (pfn_glMultiTexParameterivEXT)load("glMultiTexParameterivEXT");
	fp_glMultiTexParameterfEXT = (pfn_glMultiTexParameterfEXT)load("glMultiTexParameterfEXT");
	fp_glMultiTexParameterfvEXT = (pfn_glMultiTexParameterfvEXT)load("glMultiTexParameterfvEXT");
	fp_glMultiTexImage1DEXT = (pfn_glMultiTexImage1DEXT)load("glMultiTexImage1DEXT");
	fp_glMultiTexImage2DEXT = (pfn_glMultiTexImage2DEXT)load("glMultiTexImage2DEXT");
	fp_glMultiTexSubImage1DEXT = (pfn_glMultiTexSubImage1DEXT)load("glMultiTexSubImage1DEXT");
	fp_glMultiTexSubImage2DEXT = (pfn_glMultiTexSubImage2DEXT)load("glMultiTexSubImage2DEXT");
	fp_glCopyMultiTexImage1DEXT = (pfn_glCopyMultiTexImage1DEXT)load("glCopyMultiTexImage1DEXT");
	fp_glCopyMultiTexImage2DEXT = (pfn_glCopyMultiTexImage2DEXT)load("glCopyMultiTexImage2DEXT");
	fp_glCopyMultiTexSubImage1DEXT = (pfn_glCopyMultiTexSubImage1DEXT)load("glCopyMultiTexSubImage1DEXT");
	fp_glCopyMultiTexSubImage2DEXT = (pfn_glCopyMultiTexSubImage2DEXT)load("glCopyMultiTexSubImage2DEXT");
	fp_glGetMultiTexImageEXT = (pfn_glGetMultiTexImageEXT)load("glGetMultiTexImageEXT");
	fp_glGetMultiTexParameterfvEXT = (pfn_glGetMultiTexParameterfvEXT)load("glGetMultiTexParameterfvEXT");
	fp_glGetMultiTexParameterivEXT = (pfn_glGetMultiTexParameterivEXT)load("glGetMultiTexParameterivEXT");
	fp_glGetMultiTexLevelParameterfvEXT = (pfn_glGetMultiTexLevelParameterfvEXT)load("glGetMultiTexLevelParameterfvEXT");
	fp_glGetMultiTexLevelParameterivEXT = (pfn_glGetMultiTexLevelParameterivEXT)load("glGetMultiTexLevelParameterivEXT");
	fp_glMultiTexImage3DEXT = (pfn_glMultiTexImage3DEXT)load("glMultiTexImage3DEXT");
	fp_glMultiTexSubImage3DEXT = (pfn_glMultiTexSubImage3DEXT)load("glMultiTexSubImage3DEXT");
	fp_glCopyMultiTexSubImage3DEXT = (pfn_glCopyMultiTexSubImage3DEXT)load("glCopyMultiTexSubImage3DEXT");
	fp_glEnableClientStateIndexedEXT = (pfn_glEnableClientStateIndexedEXT)load("glEnableClientStateIndexedEXT");
	fp_glDisableClientStateIndexedEXT = (pfn_glDisableClientStateIndexedEXT)load("glDisableClientStateIndexedEXT");
	fp_glGetFloatIndexedvEXT = (pfn_glGetFloatIndexedvEXT)load("glGetFloatIndexedvEXT");
	fp_glGetDoubleIndexedvEXT = (pfn_glGetDoubleIndexedvEXT)load("glGetDoubleIndexedvEXT");
	fp_glGetPointerIndexedvEXT = (pfn_glGetPointerIndexedvEXT)load("glGetPointerIndexedvEXT");
	fp_glEnableIndexedEXT = (pfn_glEnableIndexedEXT)load("glEnableIndexedEXT");
	fp_glDisableIndexedEXT = (pfn_glDisableIndexedEXT)load("glDisableIndexedEXT");
	fp_glIsEnabledIndexedEXT = (pfn_glIsEnabledIndexedEXT)load("glIsEnabledIndexedEXT");
	fp_glGetIntegerIndexedvEXT = (pfn_glGetIntegerIndexedvEXT)load("glGetIntegerIndexedvEXT");
	fp_glGetBooleanIndexedvEXT = (pfn_glGetBooleanIndexedvEXT)load("glGetBooleanIndexedvEXT");
	fp_glCompressedTextureImage3DEXT = (pfn_glCompressedTextureImage3DEXT)load("glCompressedTextureImage3DEXT");
	fp_glCompressedTextureImage2DEXT = (pfn_glCompressedTextureImage2DEXT)load("glCompressedTextureImage2DEXT");
	fp_glCompressedTextureImage1DEXT = (pfn_glCompressedTextureImage1DEXT)load("glCompressedTextureImage1DEXT");
	fp_glCompressedTextureSubImage3DEXT = (pfn_glCompressedTextureSubImage3DEXT)load("glCompressedTextureSubImage3DEXT");
	fp_glCompressedTextureSubImage2DEXT = (pfn_glCompressedTextureSubImage2DEXT)load("glCompressedTextureSubImage2DEXT");
	fp_glCompressedTextureSubImage1DEXT = (pfn_glCompressedTextureSubImage1DEXT)load("glCompressedTextureSubImage1DEXT");
	fp_glGetCompressedTextureImageEXT = (pfn_glGetCompressedTextureImageEXT)load("glGetCompressedTextureImageEXT");
	fp_glCompressedMultiTexImage3DEXT = (pfn_glCompressedMultiTexImage3DEXT)load("glCompressedMultiTexImage3DEXT");
	fp_glCompressedMultiTexImage2DEXT = (pfn_glCompressedMultiTexImage2DEXT)load("glCompressedMultiTexImage2DEXT");
	fp_glCompressedMultiTexImage1DEXT = (pfn_glCompressedMultiTexImage1DEXT)load("glCompressedMultiTexImage1DEXT");
	fp_glCompressedMultiTexSubImage3DEXT = (pfn_glCompressedMultiTexSubImage3DEXT)load("glCompressedMultiTexSubImage3DEXT");
	fp_glCompressedMultiTexSubImage2DEXT = (pfn_glCompressedMultiTexSubImage2DEXT)load("glCompressedMultiTexSubImage2DEXT");
	fp_glCompressedMultiTexSubImage1DEXT = (pfn_glCompressedMultiTexSubImage1DEXT)load("glCompressedMultiTexSubImage1DEXT");
	fp_glGetCompressedMultiTexImageEXT = (pfn_glGetCompressedMultiTexImageEXT)load("glGetCompressedMultiTexImageEXT");
	fp_glMatrixLoadTransposefEXT = (pfn_glMatrixLoadTransposefEXT)load("glMatrixLoadTransposefEXT");
	fp_glMatrixLoadTransposedEXT = (pfn_glMatrixLoadTransposedEXT)load("glMatrixLoadTransposedEXT");
	fp_glMatrixMultTransposefEXT = (pfn_glMatrixMultTransposefEXT)load("glMatrixMultTransposefEXT");
	fp_glMatrixMultTransposedEXT = (pfn_glMatrixMultTransposedEXT)load("glMatrixMultTransposedEXT");
	fp_glNamedBufferDataEXT = (pfn_glNamedBufferDataEXT)load("glNamedBufferDataEXT");
	fp_glNamedBufferSubDataEXT = (pfn_glNamedBufferSubDataEXT)load("glNamedBufferSubDataEXT");
	fp_glMapNamedBufferEXT = (pfn_glMapNamedBufferEXT)load("glMapNamedBufferEXT");
	fp_glUnmapNamedBufferEXT = (pfn_glUnmapNamedBufferEXT)load("glUnmapNamedBufferEXT");
	fp_glGetNamedBufferParameterivEXT = (pfn_glGetNamedBufferParameterivEXT)load("glGetNamedBufferParameterivEXT");
	fp_glGetNamedBufferPointervEXT = (pfn_glGetNamedBufferPointervEXT)load("glGetNamedBufferPointervEXT");
	fp_glGetNamedBufferSubDataEXT = (pfn_glGetNamedBufferSubDataEXT)load("glGetNamedBufferSubDataEXT");
	fp_glProgramUniform1fEXT = (pfn_glProgramUniform1fEXT)load("glProgramUniform1fEXT");
	fp_glProgramUniform2fEXT = (pfn_glProgramUniform2fEXT)load("glProgramUniform2fEXT");
	fp_glProgramUniform3fEXT = (pfn_glProgramUniform3fEXT)load("glProgramUniform3fEXT");
	fp_glProgramUniform4fEXT = (pfn_glProgramUniform4fEXT)load("glProgramUniform4fEXT");
	fp_glProgramUniform1iEXT = (pfn_glProgramUniform1iEXT)load("glProgramUniform1iEXT");
	fp_glProgramUniform2iEXT = (pfn_glProgramUniform2iEXT)load("glProgramUniform2iEXT");
	fp_glProgramUniform3iEXT = (pfn_glProgramUniform3iEXT)load("glProgramUniform3iEXT");
	fp_glProgramUniform4iEXT = (pfn_glProgramUniform4iEXT)load("glProgramUniform4iEXT");
	fp_glProgramUniform1fvEXT = (pfn_glProgramUniform1fvEXT)load("glProgramUniform1fvEXT");
	fp_glProgramUniform2fvEXT = (pfn_glProgramUniform2fvEXT)load("glProgramUniform2fvEXT");
	fp_glProgramUniform3fvEXT = (pfn_glProgramUniform3fvEXT)load("glProgramUniform3fvEXT");
	fp_glProgramUniform4fvEXT = (pfn_glProgramUniform4fvEXT)load("glProgramUniform4fvEXT");
	fp_glProgramUniform1ivEXT = (pfn_glProgramUniform1ivEXT)load("glProgramUniform1ivEXT");
	fp_glProgramUniform2ivEXT = (pfn_glProgramUniform2ivEXT)load("glProgramUniform2ivEXT");
	fp_glProgramUniform3ivEXT = (pfn_glProgramUniform3ivEXT)load("glProgramUniform3ivEXT");
	fp_glProgramUniform4ivEXT = (pfn_glProgramUniform4ivEXT)load("glProgramUniform4ivEXT");
	fp_glProgramUniformMatrix2fvEXT = (pfn_glProgramUniformMatrix2fvEXT)load("glProgramUniformMatrix2fvEXT");
	fp_glProgramUniformMatrix3fvEXT = (pfn_glProgramUniformMatrix3fvEXT)load("glProgramUniformMatrix3fvEXT");
	fp_glProgramUniformMatrix4fvEXT = (pfn_glProgramUniformMatrix4fvEXT)load("glProgramUniformMatrix4fvEXT");
	fp_glProgramUniformMatrix2x3fvEXT = (pfn_glProgramUniformMatrix2x3fvEXT)load("glProgramUniformMatrix2x3fvEXT");
	fp_glProgramUniformMatrix3x2fvEXT = (pfn_glProgramUniformMatrix3x2fvEXT)load("glProgramUniformMatrix3x2fvEXT");
	fp_glProgramUniformMatrix2x4fvEXT = (pfn_glProgramUniformMatrix2x4fvEXT)load("glProgramUniformMatrix2x4fvEXT");
	fp_glProgramUniformMatrix4x2fvEXT = (pfn_glProgramUniformMatrix4x2fvEXT)load("glProgramUniformMatrix4x2fvEXT");
	fp_glProgramUniformMatrix3x4fvEXT = (pfn_glProgramUniformMatrix3x4fvEXT)load("glProgramUniformMatrix3x4fvEXT");
	fp_glProgramUniformMatrix4x3fvEXT = (pfn_glProgramUniformMatrix4x3fvEXT)load("glProgramUniformMatrix4x3fvEXT");
	fp_glTextureBufferEXT = (pfn_glTextureBufferEXT)load("glTextureBufferEXT");
	fp_glMultiTexBufferEXT = (pfn_glMultiTexBufferEXT)load("glMultiTexBufferEXT");
	fp_glTextureParameterIivEXT = (pfn_glTextureParameterIivEXT)load("glTextureParameterIivEXT");
	fp_glTextureParameterIuivEXT = (pfn_glTextureParameterIuivEXT)load("glTextureParameterIuivEXT");
	fp_glGetTextureParameterIivEXT = (pfn_glGetTextureParameterIivEXT)load("glGetTextureParameterIivEXT");
	fp_glGetTextureParameterIuivEXT = (pfn_glGetTextureParameterIuivEXT)load("glGetTextureParameterIuivEXT");
	fp_glMultiTexParameterIivEXT = (pfn_glMultiTexParameterIivEXT)load("glMultiTexParameterIivEXT");
	fp_glMultiTexParameterIuivEXT = (pfn_glMultiTexParameterIuivEXT)load("glMultiTexParameterIuivEXT");
	fp_glGetMultiTexParameterIivEXT = (pfn_glGetMultiTexParameterIivEXT)load("glGetMultiTexParameterIivEXT");
	fp_glGetMultiTexParameterIuivEXT = (pfn_glGetMultiTexParameterIuivEXT)load("glGetMultiTexParameterIuivEXT");
	fp_glProgramUniform1uiEXT = (pfn_glProgramUniform1uiEXT)load("glProgramUniform1uiEXT");
	fp_glProgramUniform2uiEXT = (pfn_glProgramUniform2uiEXT)load("glProgramUniform2uiEXT");
	fp_glProgramUniform3uiEXT = (pfn_glProgramUniform3uiEXT)load("glProgramUniform3uiEXT");
	fp_glProgramUniform4uiEXT = (pfn_glProgramUniform4uiEXT)load("glProgramUniform4uiEXT");
	fp_glProgramUniform1uivEXT = (pfn_glProgramUniform1uivEXT)load("glProgramUniform1uivEXT");
	fp_glProgramUniform2uivEXT = (pfn_glProgramUniform2uivEXT)load("glProgramUniform2uivEXT");
	fp_glProgramUniform3uivEXT = (pfn_glProgramUniform3uivEXT)load("glProgramUniform3uivEXT");
	fp_glProgramUniform4uivEXT = (pfn_glProgramUniform4uivEXT)load("glProgramUniform4uivEXT");
	fp_glNamedProgramLocalParameters4fvEXT = (pfn_glNamedProgramLocalParameters4fvEXT)load("glNamedProgramLocalParameters4fvEXT");
	fp_glNamedProgramLocalParameterI4iEXT = (pfn_glNamedProgramLocalParameterI4iEXT)load("glNamedProgramLocalParameterI4iEXT");
	fp_glNamedProgramLocalParameterI4ivEXT = (pfn_glNamedProgramLocalParameterI4ivEXT)load("glNamedProgramLocalParameterI4ivEXT");
	fp_glNamedProgramLocalParametersI4ivEXT = (pfn_glNamedProgramLocalParametersI4ivEXT)load("glNamedProgramLocalParametersI4ivEXT");
	fp_glNamedProgramLocalParameterI4uiEXT = (pfn_glNamedProgramLocalParameterI4uiEXT)load("glNamedProgramLocalParameterI4uiEXT");
	fp_glNamedProgramLocalParameterI4uivEXT = (pfn_glNamedProgramLocalParameterI4uivEXT)load("glNamedProgramLocalParameterI4uivEXT");
	fp_glNamedProgramLocalParametersI4uivEXT = (pfn_glNamedProgramLocalParametersI4uivEXT)load("glNamedProgramLocalParametersI4uivEXT");
	fp_glGetNamedProgramLocalParameterIivEXT = (pfn_glGetNamedProgramLocalParameterIivEXT)load("glGetNamedProgramLocalParameterIivEXT");
	fp_glGetNamedProgramLocalParameterIuivEXT = (pfn_glGetNamedProgramLocalParameterIuivEXT)load("glGetNamedProgramLocalParameterIuivEXT");
	fp_glEnableClientStateiEXT = (pfn_glEnableClientStateiEXT)load("glEnableClientStateiEXT");
	fp_glDisableClientStateiEXT = (pfn_glDisableClientStateiEXT)load("glDisableClientStateiEXT");
	fp_glGetFloati_vEXT = (pfn_glGetFloati_vEXT)load("glGetFloati_vEXT");
	fp_glGetDoublei_vEXT = (pfn_glGetDoublei_vEXT)load("glGetDoublei_vEXT");
	fp_glGetPointeri_vEXT = (pfn_glGetPointeri_vEXT)load("glGetPointeri_vEXT");
	fp_glNamedProgramStringEXT = (pfn_glNamedProgramStringEXT)load("glNamedProgramStringEXT");
	fp_glNamedProgramLocalParameter4dEXT = (pfn_glNamedProgramLocalParameter4dEXT)load("glNamedProgramLocalParameter4dEXT");
	fp_glNamedProgramLocalParameter4dvEXT = (pfn_glNamedProgramLocalParameter4dvEXT)load("glNamedProgramLocalParameter4dvEXT");
	fp_glNamedProgramLocalParameter4fEXT = (pfn_glNamedProgramLocalParameter4fEXT)load("glNamedProgramLocalParameter4fEXT");
	fp_glNamedProgramLocalParameter4fvEXT = (pfn_glNamedProgramLocalParameter4fvEXT)load("glNamedProgramLocalParameter4fvEXT");
	fp_glGetNamedProgramLocalParameterdvEXT = (pfn_glGetNamedProgramLocalParameterdvEXT)load("glGetNamedProgramLocalParameterdvEXT");
	fp_glGetNamedProgramLocalParameterfvEXT = (pfn_glGetNamedProgramLocalParameterfvEXT)load("glGetNamedProgramLocalParameterfvEXT");
	fp_glGetNamedProgramivEXT = (pfn_glGetNamedProgramivEXT)load("glGetNamedProgramivEXT");
	fp_glGetNamedProgramStringEXT = (pfn_glGetNamedProgramStringEXT)load("glGetNamedProgramStringEXT");
	fp_glNamedRenderbufferStorageEXT = (pfn_glNamedRenderbufferStorageEXT)load("glNamedRenderbufferStorageEXT");
	fp_glGetNamedRenderbufferParameterivEXT = (pfn_glGetNamedRenderbufferParameterivEXT)load("glGetNamedRenderbufferParameterivEXT");
	fp_glNamedRenderbufferStorageMultisampleEXT = (pfn_glNamedRenderbufferStorageMultisampleEXT)load("glNamedRenderbufferStorageMultisampleEXT");
	fp_glNamedRenderbufferStorageMultisampleCoverageEXT = (pfn_glNamedRenderbufferStorageMultisampleCoverageEXT)load("glNamedRenderbufferStorageMultisampleCoverageEXT");
	fp_glCheckNamedFramebufferStatusEXT = (pfn_glCheckNamedFramebufferStatusEXT)load("glCheckNamedFramebufferStatusEXT");
	fp_glNamedFramebufferTexture1DEXT = (pfn_glNamedFramebufferTexture1DEXT)load("glNamedFramebufferTexture1DEXT");
	fp_glNamedFramebufferTexture2DEXT = (pfn_glNamedFramebufferTexture2DEXT)load("glNamedFramebufferTexture2DEXT");
	fp_glNamedFramebufferTexture3DEXT = (pfn_glNamedFramebufferTexture3DEXT)load("glNamedFramebufferTexture3DEXT");
	fp_glNamedFramebufferRenderbufferEXT = (pfn_glNamedFramebufferRenderbufferEXT)load("glNamedFramebufferRenderbufferEXT");
	fp_glGetNamedFramebufferAttachmentParameterivEXT = (pfn_glGetNamedFramebufferAttachmentParameterivEXT)load("glGetNamedFramebufferAttachmentParameterivEXT");
	fp_glGenerateTextureMipmapEXT = (pfn_glGenerateTextureMipmapEXT)load("glGenerateTextureMipmapEXT");
	fp_glGenerateMultiTexMipmapEXT = (pfn_glGenerateMultiTexMipmapEXT)load("glGenerateMultiTexMipmapEXT");
	fp_glFramebufferDrawBufferEXT = (pfn_glFramebufferDrawBufferEXT)load("glFramebufferDrawBufferEXT");
	fp_glFramebufferDrawBuffersEXT = (pfn_glFramebufferDrawBuffersEXT)load("glFramebufferDrawBuffersEXT");
	fp_glFramebufferReadBufferEXT = (pfn_glFramebufferReadBufferEXT)load("glFramebufferReadBufferEXT");
	fp_glGetFramebufferParameterivEXT = (pfn_glGetFramebufferParameterivEXT)load("glGetFramebufferParameterivEXT");
	fp_glNamedCopyBufferSubDataEXT = (pfn_glNamedCopyBufferSubDataEXT)load("glNamedCopyBufferSubDataEXT");
	fp_glNamedFramebufferTextureEXT = (pfn_glNamedFramebufferTextureEXT)load("glNamedFramebufferTextureEXT");
	fp_glNamedFramebufferTextureLayerEXT = (pfn_glNamedFramebufferTextureLayerEXT)load("glNamedFramebufferTextureLayerEXT");
	fp_glNamedFramebufferTextureFaceEXT = (pfn_glNamedFramebufferTextureFaceEXT)load("glNamedFramebufferTextureFaceEXT");
	fp_glTextureRenderbufferEXT = (pfn_glTextureRenderbufferEXT)load("glTextureRenderbufferEXT");
	fp_glMultiTexRenderbufferEXT = (pfn_glMultiTexRenderbufferEXT)load("glMultiTexRenderbufferEXT");
	fp_glVertexArrayVertexOffsetEXT = (pfn_glVertexArrayVertexOffsetEXT)load("glVertexArrayVertexOffsetEXT");
	fp_glVertexArrayColorOffsetEXT = (pfn_glVertexArrayColorOffsetEXT)load("glVertexArrayColorOffsetEXT");
	fp_glVertexArrayEdgeFlagOffsetEXT = (pfn_glVertexArrayEdgeFlagOffsetEXT)load("glVertexArrayEdgeFlagOffsetEXT");
	fp_glVertexArrayIndexOffsetEXT = (pfn_glVertexArrayIndexOffsetEXT)load("glVertexArrayIndexOffsetEXT");
	fp_glVertexArrayNormalOffsetEXT = (pfn_glVertexArrayNormalOffsetEXT)load("glVertexArrayNormalOffsetEXT");
	fp_glVertexArrayTexCoordOffsetEXT = (pfn_glVertexArrayTexCoordOffsetEXT)load("glVertexArrayTexCoordOffsetEXT");
	fp_glVertexArrayMultiTexCoordOffsetEXT = (pfn_glVertexArrayMultiTexCoordOffsetEXT)load("glVertexArrayMultiTexCoordOffsetEXT");
	fp_glVertexArrayFogCoordOffsetEXT = (pfn_glVertexArrayFogCoordOffsetEXT)load("glVertexArrayFogCoordOffsetEXT");
	fp_glVertexArraySecondaryColorOffsetEXT = (pfn_glVertexArraySecondaryColorOffsetEXT)load("glVertexArraySecondaryColorOffsetEXT");
	fp_glVertexArrayVertexAttribOffsetEXT = (pfn_glVertexArrayVertexAttribOffsetEXT)load("glVertexArrayVertexAttribOffsetEXT");
	fp_glVertexArrayVertexAttribIOffsetEXT = (pfn_glVertexArrayVertexAttribIOffsetEXT)load("glVertexArrayVertexAttribIOffsetEXT");
	fp_glEnableVertexArrayEXT = (pfn_glEnableVertexArrayEXT)load("glEnableVertexArrayEXT");
	fp_glDisableVertexArrayEXT = (pfn_glDisableVertexArrayEXT)load("glDisableVertexArrayEXT");
	fp_glEnableVertexArrayAttribEXT = (pfn_glEnableVertexArrayAttribEXT)load("glEnableVertexArrayAttribEXT");
	fp_glDisableVertexArrayAttribEXT = (pfn_glDisableVertexArrayAttribEXT)load("glDisableVertexArrayAttribEXT");
	fp_glGetVertexArrayIntegervEXT = (pfn_glGetVertexArrayIntegervEXT)load("glGetVertexArrayIntegervEXT");
	fp_glGetVertexArrayPointervEXT = (pfn_glGetVertexArrayPointervEXT)load("glGetVertexArrayPointervEXT");
	fp_glGetVertexArrayIntegeri_vEXT = (pfn_glGetVertexArrayIntegeri_vEXT)load("glGetVertexArrayIntegeri_vEXT");
	fp_glGetVertexArrayPointeri_vEXT = (pfn_glGetVertexArrayPointeri_vEXT)load("glGetVertexArrayPointeri_vEXT");
	fp_glMapNamedBufferRangeEXT = (pfn_glMapNamedBufferRangeEXT)load("glMapNamedBufferRangeEXT");
	fp_glFlushMappedNamedBufferRangeEXT = (pfn_glFlushMappedNamedBufferRangeEXT)load("glFlushMappedNamedBufferRangeEXT");
	fp_glNamedBufferStorageEXT = (pfn_glNamedBufferStorageEXT)load("glNamedBufferStorageEXT");
	fp_glClearNamedBufferDataEXT = (pfn_glClearNamedBufferDataEXT)load("glClearNamedBufferDataEXT");
	fp_glClearNamedBufferSubDataEXT = (pfn_glClearNamedBufferSubDataEXT)load("glClearNamedBufferSubDataEXT");
	fp_glNamedFramebufferParameteriEXT = (pfn_glNamedFramebufferParameteriEXT)load("glNamedFramebufferParameteriEXT");
	fp_glGetNamedFramebufferParameterivEXT = (pfn_glGetNamedFramebufferParameterivEXT)load("glGetNamedFramebufferParameterivEXT");
	fp_glProgramUniform1dEXT = (pfn_glProgramUniform1dEXT)load("glProgramUniform1dEXT");
	fp_glProgramUniform2dEXT = (pfn_glProgramUniform2dEXT)load("glProgramUniform2dEXT");
	fp_glProgramUniform3dEXT = (pfn_glProgramUniform3dEXT)load("glProgramUniform3dEXT");
	fp_glProgramUniform4dEXT = (pfn_glProgramUniform4dEXT)load("glProgramUniform4dEXT");
	fp_glProgramUniform1dvEXT = (pfn_glProgramUniform1dvEXT)load("glProgramUniform1dvEXT");
	fp_glProgramUniform2dvEXT = (pfn_glProgramUniform2dvEXT)load("glProgramUniform2dvEXT");
	fp_glProgramUniform3dvEXT = (pfn_glProgramUniform3dvEXT)load("glProgramUniform3dvEXT");
	fp_glProgramUniform4dvEXT = (pfn_glProgramUniform4dvEXT)load("glProgramUniform4dvEXT");
	fp_glProgramUniformMatrix2dvEXT = (pfn_glProgramUniformMatrix2dvEXT)load("glProgramUniformMatrix2dvEXT");
	fp_glProgramUniformMatrix3dvEXT = (pfn_glProgramUniformMatrix3dvEXT)load("glProgramUniformMatrix3dvEXT");
	fp_glProgramUniformMatrix4dvEXT = (pfn_glProgramUniformMatrix4dvEXT)load("glProgramUniformMatrix4dvEXT");
	fp_glProgramUniformMatrix2x3dvEXT = (pfn_glProgramUniformMatrix2x3dvEXT)load("glProgramUniformMatrix2x3dvEXT");
	fp_glProgramUniformMatrix2x4dvEXT = (pfn_glProgramUniformMatrix2x4dvEXT)load("glProgramUniformMatrix2x4dvEXT");
	fp_glProgramUniformMatrix3x2dvEXT = (pfn_glProgramUniformMatrix3x2dvEXT)load("glProgramUniformMatrix3x2dvEXT");
	fp_glProgramUniformMatrix3x4dvEXT = (pfn_glProgramUniformMatrix3x4dvEXT)load("glProgramUniformMatrix3x4dvEXT");
	fp_glProgramUniformMatrix4x2dvEXT = (pfn_glProgramUniformMatrix4x2dvEXT)load("glProgramUniformMatrix4x2dvEXT");
	fp_glProgramUniformMatrix4x3dvEXT = (pfn_glProgramUniformMatrix4x3dvEXT)load("glProgramUniformMatrix4x3dvEXT");
	fp_glTextureBufferRangeEXT = (pfn_glTextureBufferRangeEXT)load("glTextureBufferRangeEXT");
	fp_glTextureStorage1DEXT = (pfn_glTextureStorage1DEXT)load("glTextureStorage1DEXT");
	fp_glTextureStorage2DEXT = (pfn_glTextureStorage2DEXT)load("glTextureStorage2DEXT");
	fp_glTextureStorage3DEXT = (pfn_glTextureStorage3DEXT)load("glTextureStorage3DEXT");
	fp_glTextureStorage2DMultisampleEXT = (pfn_glTextureStorage2DMultisampleEXT)load("glTextureStorage2DMultisampleEXT");
	fp_glTextureStorage3DMultisampleEXT = (pfn_glTextureStorage3DMultisampleEXT)load("glTextureStorage3DMultisampleEXT");
	fp_glVertexArrayBindVertexBufferEXT = (pfn_glVertexArrayBindVertexBufferEXT)load("glVertexArrayBindVertexBufferEXT");
	fp_glVertexArrayVertexAttribFormatEXT = (pfn_glVertexArrayVertexAttribFormatEXT)load("glVertexArrayVertexAttribFormatEXT");
	fp_glVertexArrayVertexAttribIFormatEXT = (pfn_glVertexArrayVertexAttribIFormatEXT)load("glVertexArrayVertexAttribIFormatEXT");
	fp_glVertexArrayVertexAttribLFormatEXT = (pfn_glVertexArrayVertexAttribLFormatEXT)load("glVertexArrayVertexAttribLFormatEXT");
	fp_glVertexArrayVertexAttribBindingEXT = (pfn_glVertexArrayVertexAttribBindingEXT)load("glVertexArrayVertexAttribBindingEXT");
	fp_glVertexArrayVertexBindingDivisorEXT = (pfn_glVertexArrayVertexBindingDivisorEXT)load("glVertexArrayVertexBindingDivisorEXT");
	fp_glVertexArrayVertexAttribLOffsetEXT = (pfn_glVertexArrayVertexAttribLOffsetEXT)load("glVertexArrayVertexAttribLOffsetEXT");
	fp_glTexturePageCommitmentEXT = (pfn_glTexturePageCommitmentEXT)load("glTexturePageCommitmentEXT");
	fp_glVertexArrayVertexAttribDivisorEXT = (pfn_glVertexArrayVertexAttribDivisorEXT)load("glVertexArrayVertexAttribDivisorEXT");
}

GLboolean GLAD_EXT_discard_framebuffer = GL_FALSE;
static void load_GL_EXT_discard_framebuffer(LOADER load) {
	if(!GLAD_EXT_discard_framebuffer) return;
	fp_glDiscardFramebufferEXT = (pfn_glDiscardFramebufferEXT)load("glDiscardFramebufferEXT");
}

GLboolean GLAD_EXT_disjoint_timer_query = GL_FALSE;
static void load_GL_EXT_disjoint_timer_query(LOADER load) {
	if(!GLAD_EXT_disjoint_timer_query) return;
	fp_glGenQueriesEXT = (pfn_glGenQueriesEXT)load("glGenQueriesEXT");
	fp_glDeleteQueriesEXT = (pfn_glDeleteQueriesEXT)load("glDeleteQueriesEXT");
	fp_glIsQueryEXT = (pfn_glIsQueryEXT)load("glIsQueryEXT");
	fp_glBeginQueryEXT = (pfn_glBeginQueryEXT)load("glBeginQueryEXT");
	fp_glEndQueryEXT = (pfn_glEndQueryEXT)load("glEndQueryEXT");
	fp_glQueryCounterEXT = (pfn_glQueryCounterEXT)load("glQueryCounterEXT");
	fp_glGetQueryivEXT = (pfn_glGetQueryivEXT)load("glGetQueryivEXT");
	fp_glGetQueryObjectivEXT = (pfn_glGetQueryObjectivEXT)load("glGetQueryObjectivEXT");
	fp_glGetQueryObjectuivEXT = (pfn_glGetQueryObjectuivEXT)load("glGetQueryObjectuivEXT");
	fp_glGetQueryObjecti64vEXT = (pfn_glGetQueryObjecti64vEXT)load("glGetQueryObjecti64vEXT");
	fp_glGetQueryObjectui64vEXT = (pfn_glGetQueryObjectui64vEXT)load("glGetQueryObjectui64vEXT");
}

GLboolean GLAD_EXT_draw_buffers = GL_FALSE;
static void load_GL_EXT_draw_buffers(LOADER load) {
	if(!GLAD_EXT_draw_buffers) return;
	fp_glDrawBuffersEXT = (pfn_glDrawBuffersEXT)load("glDrawBuffersEXT");
}

GLboolean GLAD_EXT_draw_buffers2 = GL_FALSE;
static void load_GL_EXT_draw_buffers2(LOADER load) {
	if(!GLAD_EXT_draw_buffers2) return;
	fp_glColorMaskIndexedEXT = (pfn_glColorMaskIndexedEXT)load("glColorMaskIndexedEXT");
	fp_glGetBooleanIndexedvEXT = (pfn_glGetBooleanIndexedvEXT)load("glGetBooleanIndexedvEXT");
	fp_glGetIntegerIndexedvEXT = (pfn_glGetIntegerIndexedvEXT)load("glGetIntegerIndexedvEXT");
	fp_glEnableIndexedEXT = (pfn_glEnableIndexedEXT)load("glEnableIndexedEXT");
	fp_glDisableIndexedEXT = (pfn_glDisableIndexedEXT)load("glDisableIndexedEXT");
	fp_glIsEnabledIndexedEXT = (pfn_glIsEnabledIndexedEXT)load("glIsEnabledIndexedEXT");
}

GLboolean GLAD_EXT_draw_buffers_indexed = GL_FALSE;
static void load_GL_EXT_draw_buffers_indexed(LOADER load) {
	if(!GLAD_EXT_draw_buffers_indexed) return;
	fp_glEnableiEXT = (pfn_glEnableiEXT)load("glEnableiEXT");
	fp_glDisableiEXT = (pfn_glDisableiEXT)load("glDisableiEXT");
	fp_glBlendEquationiEXT = (pfn_glBlendEquationiEXT)load("glBlendEquationiEXT");
	fp_glBlendEquationSeparateiEXT = (pfn_glBlendEquationSeparateiEXT)load("glBlendEquationSeparateiEXT");
	fp_glBlendFunciEXT = (pfn_glBlendFunciEXT)load("glBlendFunciEXT");
	fp_glBlendFuncSeparateiEXT = (pfn_glBlendFuncSeparateiEXT)load("glBlendFuncSeparateiEXT");
	fp_glColorMaskiEXT = (pfn_glColorMaskiEXT)load("glColorMaskiEXT");
	fp_glIsEnablediEXT = (pfn_glIsEnablediEXT)load("glIsEnablediEXT");
}

GLboolean GLAD_EXT_draw_elements_base_vertex = GL_FALSE;
static void load_GL_EXT_draw_elements_base_vertex(LOADER load) {
	if(!GLAD_EXT_draw_elements_base_vertex) return;
	fp_glDrawElementsBaseVertexEXT = (pfn_glDrawElementsBaseVertexEXT)load("glDrawElementsBaseVertexEXT");
	fp_glDrawRangeElementsBaseVertexEXT = (pfn_glDrawRangeElementsBaseVertexEXT)load("glDrawRangeElementsBaseVertexEXT");
	fp_glDrawElementsInstancedBaseVertexEXT = (pfn_glDrawElementsInstancedBaseVertexEXT)load("glDrawElementsInstancedBaseVertexEXT");
	fp_glMultiDrawElementsBaseVertexEXT = (pfn_glMultiDrawElementsBaseVertexEXT)load("glMultiDrawElementsBaseVertexEXT");
}

GLboolean GLAD_EXT_draw_instanced = GL_FALSE;
static void load_GL_EXT_draw_instanced(LOADER load) {
	if(!GLAD_EXT_draw_instanced) return;
	fp_glDrawArraysInstancedEXT = (pfn_glDrawArraysInstancedEXT)load("glDrawArraysInstancedEXT");
	fp_glDrawElementsInstancedEXT = (pfn_glDrawElementsInstancedEXT)load("glDrawElementsInstancedEXT");
}

GLboolean GLAD_EXT_float_blend = GL_FALSE;
GLboolean GLAD_EXT_framebuffer_blit = GL_FALSE;
static void load_GL_EXT_framebuffer_blit(LOADER load) {
	if(!GLAD_EXT_framebuffer_blit) return;
	fp_glBlitFramebufferEXT = (pfn_glBlitFramebufferEXT)load("glBlitFramebufferEXT");
}

GLboolean GLAD_EXT_framebuffer_multisample = GL_FALSE;
static void load_GL_EXT_framebuffer_multisample(LOADER load) {
	if(!GLAD_EXT_framebuffer_multisample) return;
	fp_glRenderbufferStorageMultisampleEXT = (pfn_glRenderbufferStorageMultisampleEXT)load("glRenderbufferStorageMultisampleEXT");
}

GLboolean GLAD_EXT_framebuffer_multisample_blit_scaled = GL_FALSE;
GLboolean GLAD_EXT_framebuffer_object = GL_FALSE;
static void load_GL_EXT_framebuffer_object(LOADER load) {
	if(!GLAD_EXT_framebuffer_object) return;
	fp_glIsRenderbufferEXT = (pfn_glIsRenderbufferEXT)load("glIsRenderbufferEXT");
	fp_glBindRenderbufferEXT = (pfn_glBindRenderbufferEXT)load("glBindRenderbufferEXT");
	fp_glDeleteRenderbuffersEXT = (pfn_glDeleteRenderbuffersEXT)load("glDeleteRenderbuffersEXT");
	fp_glGenRenderbuffersEXT = (pfn_glGenRenderbuffersEXT)load("glGenRenderbuffersEXT");
	fp_glRenderbufferStorageEXT = (pfn_glRenderbufferStorageEXT)load("glRenderbufferStorageEXT");
	fp_glGetRenderbufferParameterivEXT = (pfn_glGetRenderbufferParameterivEXT)load("glGetRenderbufferParameterivEXT");
	fp_glIsFramebufferEXT = (pfn_glIsFramebufferEXT)load("glIsFramebufferEXT");
	fp_glBindFramebufferEXT = (pfn_glBindFramebufferEXT)load("glBindFramebufferEXT");
	fp_glDeleteFramebuffersEXT = (pfn_glDeleteFramebuffersEXT)load("glDeleteFramebuffersEXT");
	fp_glGenFramebuffersEXT = (pfn_glGenFramebuffersEXT)load("glGenFramebuffersEXT");
	fp_glCheckFramebufferStatusEXT = (pfn_glCheckFramebufferStatusEXT)load("glCheckFramebufferStatusEXT");
	fp_glFramebufferTexture1DEXT = (pfn_glFramebufferTexture1DEXT)load("glFramebufferTexture1DEXT");
	fp_glFramebufferTexture2DEXT = (pfn_glFramebufferTexture2DEXT)load("glFramebufferTexture2DEXT");
	fp_glFramebufferTexture3DEXT = (pfn_glFramebufferTexture3DEXT)load("glFramebufferTexture3DEXT");
	fp_glFramebufferRenderbufferEXT = (pfn_glFramebufferRenderbufferEXT)load("glFramebufferRenderbufferEXT");
	fp_glGetFramebufferAttachmentParameterivEXT = (pfn_glGetFramebufferAttachmentParameterivEXT)load("glGetFramebufferAttachmentParameterivEXT");
	fp_glGenerateMipmapEXT = (pfn_glGenerateMipmapEXT)load("glGenerateMipmapEXT");
}

GLboolean GLAD_EXT_framebuffer_sRGB = GL_FALSE;
GLboolean GLAD_EXT_geometry_point_size = GL_FALSE;
GLboolean GLAD_EXT_geometry_shader = GL_FALSE;
static void load_GL_EXT_geometry_shader(LOADER load) {
	if(!GLAD_EXT_geometry_shader) return;
	fp_glFramebufferTextureEXT = (pfn_glFramebufferTextureEXT)load("glFramebufferTextureEXT");
}

GLboolean GLAD_EXT_geometry_shader4 = GL_FALSE;
static void load_GL_EXT_geometry_shader4(LOADER load) {
	if(!GLAD_EXT_geometry_shader4) return;
	fp_glProgramParameteriEXT = (pfn_glProgramParameteriEXT)load("glProgramParameteriEXT");
}

GLboolean GLAD_EXT_gpu_program_parameters = GL_FALSE;
static void load_GL_EXT_gpu_program_parameters(LOADER load) {
	if(!GLAD_EXT_gpu_program_parameters) return;
	fp_glProgramEnvParameters4fvEXT = (pfn_glProgramEnvParameters4fvEXT)load("glProgramEnvParameters4fvEXT");
	fp_glProgramLocalParameters4fvEXT = (pfn_glProgramLocalParameters4fvEXT)load("glProgramLocalParameters4fvEXT");
}

GLboolean GLAD_EXT_gpu_shader4 = GL_FALSE;
static void load_GL_EXT_gpu_shader4(LOADER load) {
	if(!GLAD_EXT_gpu_shader4) return;
	fp_glGetUniformuivEXT = (pfn_glGetUniformuivEXT)load("glGetUniformuivEXT");
	fp_glBindFragDataLocationEXT = (pfn_glBindFragDataLocationEXT)load("glBindFragDataLocationEXT");
	fp_glGetFragDataLocationEXT = (pfn_glGetFragDataLocationEXT)load("glGetFragDataLocationEXT");
	fp_glUniform1uiEXT = (pfn_glUniform1uiEXT)load("glUniform1uiEXT");
	fp_glUniform2uiEXT = (pfn_glUniform2uiEXT)load("glUniform2uiEXT");
	fp_glUniform3uiEXT = (pfn_glUniform3uiEXT)load("glUniform3uiEXT");
	fp_glUniform4uiEXT = (pfn_glUniform4uiEXT)load("glUniform4uiEXT");
	fp_glUniform1uivEXT = (pfn_glUniform1uivEXT)load("glUniform1uivEXT");
	fp_glUniform2uivEXT = (pfn_glUniform2uivEXT)load("glUniform2uivEXT");
	fp_glUniform3uivEXT = (pfn_glUniform3uivEXT)load("glUniform3uivEXT");
	fp_glUniform4uivEXT = (pfn_glUniform4uivEXT)load("glUniform4uivEXT");
}

GLboolean GLAD_EXT_gpu_shader5 = GL_FALSE;
GLboolean GLAD_EXT_instanced_arrays = GL_FALSE;
static void load_GL_EXT_instanced_arrays(LOADER load) {
	if(!GLAD_EXT_instanced_arrays) return;
	fp_glDrawArraysInstancedEXT = (pfn_glDrawArraysInstancedEXT)load("glDrawArraysInstancedEXT");
	fp_glDrawElementsInstancedEXT = (pfn_glDrawElementsInstancedEXT)load("glDrawElementsInstancedEXT");
	fp_glVertexAttribDivisorEXT = (pfn_glVertexAttribDivisorEXT)load("glVertexAttribDivisorEXT");
}

GLboolean GLAD_EXT_map_buffer_range = GL_FALSE;
static void load_GL_EXT_map_buffer_range(LOADER load) {
	if(!GLAD_EXT_map_buffer_range) return;
	fp_glMapBufferRangeEXT = (pfn_glMapBufferRangeEXT)load("glMapBufferRangeEXT");
	fp_glFlushMappedBufferRangeEXT = (pfn_glFlushMappedBufferRangeEXT)load("glFlushMappedBufferRangeEXT");
}

GLboolean GLAD_EXT_multi_draw_indirect = GL_FALSE;
static void load_GL_EXT_multi_draw_indirect(LOADER load) {
	if(!GLAD_EXT_multi_draw_indirect) return;
	fp_glMultiDrawArraysIndirectEXT = (pfn_glMultiDrawArraysIndirectEXT)load("glMultiDrawArraysIndirectEXT");
	fp_glMultiDrawElementsIndirectEXT = (pfn_glMultiDrawElementsIndirectEXT)load("glMultiDrawElementsIndirectEXT");
}

GLboolean GLAD_EXT_multisampled_compatibility = GL_FALSE;
GLboolean GLAD_EXT_multisampled_render_to_texture = GL_FALSE;
static void load_GL_EXT_multisampled_render_to_texture(LOADER load) {
	if(!GLAD_EXT_multisampled_render_to_texture) return;
	fp_glRenderbufferStorageMultisampleEXT = (pfn_glRenderbufferStorageMultisampleEXT)load("glRenderbufferStorageMultisampleEXT");
	fp_glFramebufferTexture2DMultisampleEXT = (pfn_glFramebufferTexture2DMultisampleEXT)load("glFramebufferTexture2DMultisampleEXT");
}

GLboolean GLAD_EXT_multiview_draw_buffers = GL_FALSE;
static void load_GL_EXT_multiview_draw_buffers(LOADER load) {
	if(!GLAD_EXT_multiview_draw_buffers) return;
	fp_glReadBufferIndexedEXT = (pfn_glReadBufferIndexedEXT)load("glReadBufferIndexedEXT");
	fp_glDrawBuffersIndexedEXT = (pfn_glDrawBuffersIndexedEXT)load("glDrawBuffersIndexedEXT");
	fp_glGetIntegeri_vEXT = (pfn_glGetIntegeri_vEXT)load("glGetIntegeri_vEXT");
}

GLboolean GLAD_EXT_occlusion_query_boolean = GL_FALSE;
static void load_GL_EXT_occlusion_query_boolean(LOADER load) {
	if(!GLAD_EXT_occlusion_query_boolean) return;
	fp_glGenQueriesEXT = (pfn_glGenQueriesEXT)load("glGenQueriesEXT");
	fp_glDeleteQueriesEXT = (pfn_glDeleteQueriesEXT)load("glDeleteQueriesEXT");
	fp_glIsQueryEXT = (pfn_glIsQueryEXT)load("glIsQueryEXT");
	fp_glBeginQueryEXT = (pfn_glBeginQueryEXT)load("glBeginQueryEXT");
	fp_glEndQueryEXT = (pfn_glEndQueryEXT)load("glEndQueryEXT");
	fp_glGetQueryivEXT = (pfn_glGetQueryivEXT)load("glGetQueryivEXT");
	fp_glGetQueryObjectuivEXT = (pfn_glGetQueryObjectuivEXT)load("glGetQueryObjectuivEXT");
}

GLboolean GLAD_EXT_packed_depth_stencil = GL_FALSE;
GLboolean GLAD_EXT_packed_float = GL_FALSE;
GLboolean GLAD_EXT_pixel_buffer_object = GL_FALSE;
GLboolean GLAD_EXT_polygon_offset_clamp = GL_FALSE;
static void load_GL_EXT_polygon_offset_clamp(LOADER load) {
	if(!GLAD_EXT_polygon_offset_clamp) return;
	fp_glPolygonOffsetClampEXT = (pfn_glPolygonOffsetClampEXT)load("glPolygonOffsetClampEXT");
}

GLboolean GLAD_EXT_post_depth_coverage = GL_FALSE;
GLboolean GLAD_EXT_primitive_bounding_box = GL_FALSE;
static void load_GL_EXT_primitive_bounding_box(LOADER load) {
	if(!GLAD_EXT_primitive_bounding_box) return;
	fp_glPrimitiveBoundingBoxEXT = (pfn_glPrimitiveBoundingBoxEXT)load("glPrimitiveBoundingBoxEXT");
}

GLboolean GLAD_EXT_provoking_vertex = GL_FALSE;
static void load_GL_EXT_provoking_vertex(LOADER load) {
	if(!GLAD_EXT_provoking_vertex) return;
	fp_glProvokingVertexEXT = (pfn_glProvokingVertexEXT)load("glProvokingVertexEXT");
}

GLboolean GLAD_EXT_pvrtc_sRGB = GL_FALSE;
GLboolean GLAD_EXT_raster_multisample = GL_FALSE;
static void load_GL_EXT_raster_multisample(LOADER load) {
	if(!GLAD_EXT_raster_multisample) return;
	fp_glRasterSamplesEXT = (pfn_glRasterSamplesEXT)load("glRasterSamplesEXT");
}

GLboolean GLAD_EXT_read_format_bgra = GL_FALSE;
GLboolean GLAD_EXT_render_snorm = GL_FALSE;
GLboolean GLAD_EXT_robustness = GL_FALSE;
static void load_GL_EXT_robustness(LOADER load) {
	if(!GLAD_EXT_robustness) return;
	fp_glGetGraphicsResetStatusEXT = (pfn_glGetGraphicsResetStatusEXT)load("glGetGraphicsResetStatusEXT");
	fp_glReadnPixelsEXT = (pfn_glReadnPixelsEXT)load("glReadnPixelsEXT");
	fp_glGetnUniformfvEXT = (pfn_glGetnUniformfvEXT)load("glGetnUniformfvEXT");
	fp_glGetnUniformivEXT = (pfn_glGetnUniformivEXT)load("glGetnUniformivEXT");
}

GLboolean GLAD_EXT_separate_shader_objects = GL_FALSE;
static void load_GL_EXT_separate_shader_objects(LOADER load) {
	if(!GLAD_EXT_separate_shader_objects) return;
	fp_glUseShaderProgramEXT = (pfn_glUseShaderProgramEXT)load("glUseShaderProgramEXT");
	fp_glActiveProgramEXT = (pfn_glActiveProgramEXT)load("glActiveProgramEXT");
	fp_glCreateShaderProgramEXT = (pfn_glCreateShaderProgramEXT)load("glCreateShaderProgramEXT");
	fp_glActiveShaderProgramEXT = (pfn_glActiveShaderProgramEXT)load("glActiveShaderProgramEXT");
	fp_glBindProgramPipelineEXT = (pfn_glBindProgramPipelineEXT)load("glBindProgramPipelineEXT");
	fp_glCreateShaderProgramvEXT = (pfn_glCreateShaderProgramvEXT)load("glCreateShaderProgramvEXT");
	fp_glDeleteProgramPipelinesEXT = (pfn_glDeleteProgramPipelinesEXT)load("glDeleteProgramPipelinesEXT");
	fp_glGenProgramPipelinesEXT = (pfn_glGenProgramPipelinesEXT)load("glGenProgramPipelinesEXT");
	fp_glGetProgramPipelineInfoLogEXT = (pfn_glGetProgramPipelineInfoLogEXT)load("glGetProgramPipelineInfoLogEXT");
	fp_glGetProgramPipelineivEXT = (pfn_glGetProgramPipelineivEXT)load("glGetProgramPipelineivEXT");
	fp_glIsProgramPipelineEXT = (pfn_glIsProgramPipelineEXT)load("glIsProgramPipelineEXT");
	fp_glProgramParameteriEXT = (pfn_glProgramParameteriEXT)load("glProgramParameteriEXT");
	fp_glProgramUniform1fEXT = (pfn_glProgramUniform1fEXT)load("glProgramUniform1fEXT");
	fp_glProgramUniform1fvEXT = (pfn_glProgramUniform1fvEXT)load("glProgramUniform1fvEXT");
	fp_glProgramUniform1iEXT = (pfn_glProgramUniform1iEXT)load("glProgramUniform1iEXT");
	fp_glProgramUniform1ivEXT = (pfn_glProgramUniform1ivEXT)load("glProgramUniform1ivEXT");
	fp_glProgramUniform2fEXT = (pfn_glProgramUniform2fEXT)load("glProgramUniform2fEXT");
	fp_glProgramUniform2fvEXT = (pfn_glProgramUniform2fvEXT)load("glProgramUniform2fvEXT");
	fp_glProgramUniform2iEXT = (pfn_glProgramUniform2iEXT)load("glProgramUniform2iEXT");
	fp_glProgramUniform2ivEXT = (pfn_glProgramUniform2ivEXT)load("glProgramUniform2ivEXT");
	fp_glProgramUniform3fEXT = (pfn_glProgramUniform3fEXT)load("glProgramUniform3fEXT");
	fp_glProgramUniform3fvEXT = (pfn_glProgramUniform3fvEXT)load("glProgramUniform3fvEXT");
	fp_glProgramUniform3iEXT = (pfn_glProgramUniform3iEXT)load("glProgramUniform3iEXT");
	fp_glProgramUniform3ivEXT = (pfn_glProgramUniform3ivEXT)load("glProgramUniform3ivEXT");
	fp_glProgramUniform4fEXT = (pfn_glProgramUniform4fEXT)load("glProgramUniform4fEXT");
	fp_glProgramUniform4fvEXT = (pfn_glProgramUniform4fvEXT)load("glProgramUniform4fvEXT");
	fp_glProgramUniform4iEXT = (pfn_glProgramUniform4iEXT)load("glProgramUniform4iEXT");
	fp_glProgramUniform4ivEXT = (pfn_glProgramUniform4ivEXT)load("glProgramUniform4ivEXT");
	fp_glProgramUniformMatrix2fvEXT = (pfn_glProgramUniformMatrix2fvEXT)load("glProgramUniformMatrix2fvEXT");
	fp_glProgramUniformMatrix3fvEXT = (pfn_glProgramUniformMatrix3fvEXT)load("glProgramUniformMatrix3fvEXT");
	fp_glProgramUniformMatrix4fvEXT = (pfn_glProgramUniformMatrix4fvEXT)load("glProgramUniformMatrix4fvEXT");
	fp_glUseProgramStagesEXT = (pfn_glUseProgramStagesEXT)load("glUseProgramStagesEXT");
	fp_glValidateProgramPipelineEXT = (pfn_glValidateProgramPipelineEXT)load("glValidateProgramPipelineEXT");
	fp_glProgramUniform1uiEXT = (pfn_glProgramUniform1uiEXT)load("glProgramUniform1uiEXT");
	fp_glProgramUniform2uiEXT = (pfn_glProgramUniform2uiEXT)load("glProgramUniform2uiEXT");
	fp_glProgramUniform3uiEXT = (pfn_glProgramUniform3uiEXT)load("glProgramUniform3uiEXT");
	fp_glProgramUniform4uiEXT = (pfn_glProgramUniform4uiEXT)load("glProgramUniform4uiEXT");
	fp_glProgramUniform1uivEXT = (pfn_glProgramUniform1uivEXT)load("glProgramUniform1uivEXT");
	fp_glProgramUniform2uivEXT = (pfn_glProgramUniform2uivEXT)load("glProgramUniform2uivEXT");
	fp_glProgramUniform3uivEXT = (pfn_glProgramUniform3uivEXT)load("glProgramUniform3uivEXT");
	fp_glProgramUniform4uivEXT = (pfn_glProgramUniform4uivEXT)load("glProgramUniform4uivEXT");
	fp_glProgramUniformMatrix4fvEXT = (pfn_glProgramUniformMatrix4fvEXT)load("glProgramUniformMatrix4fvEXT");
	fp_glProgramUniformMatrix2x3fvEXT = (pfn_glProgramUniformMatrix2x3fvEXT)load("glProgramUniformMatrix2x3fvEXT");
	fp_glProgramUniformMatrix3x2fvEXT = (pfn_glProgramUniformMatrix3x2fvEXT)load("glProgramUniformMatrix3x2fvEXT");
	fp_glProgramUniformMatrix2x4fvEXT = (pfn_glProgramUniformMatrix2x4fvEXT)load("glProgramUniformMatrix2x4fvEXT");
	fp_glProgramUniformMatrix4x2fvEXT = (pfn_glProgramUniformMatrix4x2fvEXT)load("glProgramUniformMatrix4x2fvEXT");
	fp_glProgramUniformMatrix3x4fvEXT = (pfn_glProgramUniformMatrix3x4fvEXT)load("glProgramUniformMatrix3x4fvEXT");
	fp_glProgramUniformMatrix4x3fvEXT = (pfn_glProgramUniformMatrix4x3fvEXT)load("glProgramUniformMatrix4x3fvEXT");
}

GLboolean GLAD_EXT_shader_framebuffer_fetch = GL_FALSE;
GLboolean GLAD_EXT_shader_image_load_formatted = GL_FALSE;
GLboolean GLAD_EXT_shader_image_load_store = GL_FALSE;
static void load_GL_EXT_shader_image_load_store(LOADER load) {
	if(!GLAD_EXT_shader_image_load_store) return;
	fp_glBindImageTextureEXT = (pfn_glBindImageTextureEXT)load("glBindImageTextureEXT");
	fp_glMemoryBarrierEXT = (pfn_glMemoryBarrierEXT)load("glMemoryBarrierEXT");
}

GLboolean GLAD_EXT_shader_implicit_conversions = GL_FALSE;
GLboolean GLAD_EXT_shader_integer_mix = GL_FALSE;
GLboolean GLAD_EXT_shader_io_blocks = GL_FALSE;
GLboolean GLAD_EXT_shader_pixel_local_storage = GL_FALSE;
GLboolean GLAD_EXT_shader_texture_lod = GL_FALSE;
GLboolean GLAD_EXT_shadow_samplers = GL_FALSE;
GLboolean GLAD_EXT_sparse_texture = GL_FALSE;
static void load_GL_EXT_sparse_texture(LOADER load) {
	if(!GLAD_EXT_sparse_texture) return;
	fp_glTexPageCommitmentEXT = (pfn_glTexPageCommitmentEXT)load("glTexPageCommitmentEXT");
}

GLboolean GLAD_EXT_sparse_texture2 = GL_FALSE;
GLboolean GLAD_EXT_sRGB = GL_FALSE;
GLboolean GLAD_EXT_sRGB_write_control = GL_FALSE;
GLboolean GLAD_EXT_stencil_clear_tag = GL_FALSE;
static void load_GL_EXT_stencil_clear_tag(LOADER load) {
	if(!GLAD_EXT_stencil_clear_tag) return;
	fp_glStencilClearTagEXT = (pfn_glStencilClearTagEXT)load("glStencilClearTagEXT");
}

GLboolean GLAD_EXT_tessellation_point_size = GL_FALSE;
GLboolean GLAD_EXT_tessellation_shader = GL_FALSE;
static void load_GL_EXT_tessellation_shader(LOADER load) {
	if(!GLAD_EXT_tessellation_shader) return;
	fp_glPatchParameteriEXT = (pfn_glPatchParameteriEXT)load("glPatchParameteriEXT");
}

GLboolean GLAD_EXT_texture_array = GL_FALSE;
static void load_GL_EXT_texture_array(LOADER load) {
	if(!GLAD_EXT_texture_array) return;
	fp_glFramebufferTextureLayerEXT = (pfn_glFramebufferTextureLayerEXT)load("glFramebufferTextureLayerEXT");
}

GLboolean GLAD_EXT_texture_border_clamp = GL_FALSE;
static void load_GL_EXT_texture_border_clamp(LOADER load) {
	if(!GLAD_EXT_texture_border_clamp) return;
	fp_glTexParameterIivEXT = (pfn_glTexParameterIivEXT)load("glTexParameterIivEXT");
	fp_glTexParameterIuivEXT = (pfn_glTexParameterIuivEXT)load("glTexParameterIuivEXT");
	fp_glGetTexParameterIivEXT = (pfn_glGetTexParameterIivEXT)load("glGetTexParameterIivEXT");
	fp_glGetTexParameterIuivEXT = (pfn_glGetTexParameterIuivEXT)load("glGetTexParameterIuivEXT");
	fp_glSamplerParameterIivEXT = (pfn_glSamplerParameterIivEXT)load("glSamplerParameterIivEXT");
	fp_glSamplerParameterIuivEXT = (pfn_glSamplerParameterIuivEXT)load("glSamplerParameterIuivEXT");
	fp_glGetSamplerParameterIivEXT = (pfn_glGetSamplerParameterIivEXT)load("glGetSamplerParameterIivEXT");
	fp_glGetSamplerParameterIuivEXT = (pfn_glGetSamplerParameterIuivEXT)load("glGetSamplerParameterIuivEXT");
}

GLboolean GLAD_EXT_texture_buffer = GL_FALSE;
static void load_GL_EXT_texture_buffer(LOADER load) {
	if(!GLAD_EXT_texture_buffer) return;
	fp_glTexBufferEXT = (pfn_glTexBufferEXT)load("glTexBufferEXT");
	fp_glTexBufferRangeEXT = (pfn_glTexBufferRangeEXT)load("glTexBufferRangeEXT");
}

GLboolean GLAD_EXT_texture_buffer_object = GL_FALSE;
static void load_GL_EXT_texture_buffer_object(LOADER load) {
	if(!GLAD_EXT_texture_buffer_object) return;
	fp_glTexBufferEXT = (pfn_glTexBufferEXT)load("glTexBufferEXT");
}

GLboolean GLAD_EXT_texture_compression_dxt1 = GL_FALSE;
GLboolean GLAD_EXT_texture_compression_latc = GL_FALSE;
GLboolean GLAD_EXT_texture_compression_rgtc = GL_FALSE;
GLboolean GLAD_EXT_texture_compression_s3tc = GL_FALSE;
GLboolean GLAD_EXT_texture_cube_map = GL_FALSE;
GLboolean GLAD_EXT_texture_cube_map_array = GL_FALSE;
GLboolean GLAD_EXT_texture_filter_anisotropic = GL_FALSE;
GLboolean GLAD_EXT_texture_filter_minmax = GL_FALSE;
static void load_GL_EXT_texture_filter_minmax(LOADER load) {
	if(!GLAD_EXT_texture_filter_minmax) return;
	fp_glRasterSamplesEXT = (pfn_glRasterSamplesEXT)load("glRasterSamplesEXT");
}

GLboolean GLAD_EXT_texture_format_BGRA8888 = GL_FALSE;
GLboolean GLAD_EXT_texture_integer = GL_FALSE;
static void load_GL_EXT_texture_integer(LOADER load) {
	if(!GLAD_EXT_texture_integer) return;
	fp_glTexParameterIivEXT = (pfn_glTexParameterIivEXT)load("glTexParameterIivEXT");
	fp_glTexParameterIuivEXT = (pfn_glTexParameterIuivEXT)load("glTexParameterIuivEXT");
	fp_glGetTexParameterIivEXT = (pfn_glGetTexParameterIivEXT)load("glGetTexParameterIivEXT");
	fp_glGetTexParameterIuivEXT = (pfn_glGetTexParameterIuivEXT)load("glGetTexParameterIuivEXT");
	fp_glClearColorIiEXT = (pfn_glClearColorIiEXT)load("glClearColorIiEXT");
	fp_glClearColorIuiEXT = (pfn_glClearColorIuiEXT)load("glClearColorIuiEXT");
}

GLboolean GLAD_EXT_texture_norm16 = GL_FALSE;
GLboolean GLAD_EXT_texture_rg = GL_FALSE;
GLboolean GLAD_EXT_texture_shared_exponent = GL_FALSE;
GLboolean GLAD_EXT_texture_snorm = GL_FALSE;
GLboolean GLAD_EXT_texture_sRGB = GL_FALSE;
GLboolean GLAD_EXT_texture_sRGB_decode = GL_FALSE;
GLboolean GLAD_EXT_texture_sRGB_R8 = GL_FALSE;
GLboolean GLAD_EXT_texture_sRGB_RG8 = GL_FALSE;
GLboolean GLAD_EXT_texture_storage = GL_FALSE;
static void load_GL_EXT_texture_storage(LOADER load) {
	if(!GLAD_EXT_texture_storage) return;
	fp_glTexStorage1DEXT = (pfn_glTexStorage1DEXT)load("glTexStorage1DEXT");
	fp_glTexStorage2DEXT = (pfn_glTexStorage2DEXT)load("glTexStorage2DEXT");
	fp_glTexStorage3DEXT = (pfn_glTexStorage3DEXT)load("glTexStorage3DEXT");
	fp_glTextureStorage1DEXT = (pfn_glTextureStorage1DEXT)load("glTextureStorage1DEXT");
	fp_glTextureStorage2DEXT = (pfn_glTextureStorage2DEXT)load("glTextureStorage2DEXT");
	fp_glTextureStorage3DEXT = (pfn_glTextureStorage3DEXT)load("glTextureStorage3DEXT");
}

GLboolean GLAD_EXT_texture_swizzle = GL_FALSE;
GLboolean GLAD_EXT_texture_type_2_10_10_10_REV = GL_FALSE;
GLboolean GLAD_EXT_texture_view = GL_FALSE;
static void load_GL_EXT_texture_view(LOADER load) {
	if(!GLAD_EXT_texture_view) return;
	fp_glTextureViewEXT = (pfn_glTextureViewEXT)load("glTextureViewEXT");
}

GLboolean GLAD_EXT_timer_query = GL_FALSE;
static void load_GL_EXT_timer_query(LOADER load) {
	if(!GLAD_EXT_timer_query) return;
	fp_glGetQueryObjecti64vEXT = (pfn_glGetQueryObjecti64vEXT)load("glGetQueryObjecti64vEXT");
	fp_glGetQueryObjectui64vEXT = (pfn_glGetQueryObjectui64vEXT)load("glGetQueryObjectui64vEXT");
}

GLboolean GLAD_EXT_transform_feedback = GL_FALSE;
static void load_GL_EXT_transform_feedback(LOADER load) {
	if(!GLAD_EXT_transform_feedback) return;
	fp_glBeginTransformFeedbackEXT = (pfn_glBeginTransformFeedbackEXT)load("glBeginTransformFeedbackEXT");
	fp_glEndTransformFeedbackEXT = (pfn_glEndTransformFeedbackEXT)load("glEndTransformFeedbackEXT");
	fp_glBindBufferRangeEXT = (pfn_glBindBufferRangeEXT)load("glBindBufferRangeEXT");
	fp_glBindBufferOffsetEXT = (pfn_glBindBufferOffsetEXT)load("glBindBufferOffsetEXT");
	fp_glBindBufferBaseEXT = (pfn_glBindBufferBaseEXT)load("glBindBufferBaseEXT");
	fp_glTransformFeedbackVaryingsEXT = (pfn_glTransformFeedbackVaryingsEXT)load("glTransformFeedbackVaryingsEXT");
	fp_glGetTransformFeedbackVaryingEXT = (pfn_glGetTransformFeedbackVaryingEXT)load("glGetTransformFeedbackVaryingEXT");
}

GLboolean GLAD_EXT_unpack_subimage = GL_FALSE;
GLboolean GLAD_EXT_vertex_array_bgra = GL_FALSE;
GLboolean GLAD_EXT_vertex_attrib_64bit = GL_FALSE;
static void load_GL_EXT_vertex_attrib_64bit(LOADER load) {
	if(!GLAD_EXT_vertex_attrib_64bit) return;
	fp_glVertexAttribL1dEXT = (pfn_glVertexAttribL1dEXT)load("glVertexAttribL1dEXT");
	fp_glVertexAttribL2dEXT = (pfn_glVertexAttribL2dEXT)load("glVertexAttribL2dEXT");
	fp_glVertexAttribL3dEXT = (pfn_glVertexAttribL3dEXT)load("glVertexAttribL3dEXT");
	fp_glVertexAttribL4dEXT = (pfn_glVertexAttribL4dEXT)load("glVertexAttribL4dEXT");
	fp_glVertexAttribL1dvEXT = (pfn_glVertexAttribL1dvEXT)load("glVertexAttribL1dvEXT");
	fp_glVertexAttribL2dvEXT = (pfn_glVertexAttribL2dvEXT)load("glVertexAttribL2dvEXT");
	fp_glVertexAttribL3dvEXT = (pfn_glVertexAttribL3dvEXT)load("glVertexAttribL3dvEXT");
	fp_glVertexAttribL4dvEXT = (pfn_glVertexAttribL4dvEXT)load("glVertexAttribL4dvEXT");
	fp_glVertexAttribLPointerEXT = (pfn_glVertexAttribLPointerEXT)load("glVertexAttribLPointerEXT");
	fp_glGetVertexAttribLdvEXT = (pfn_glGetVertexAttribLdvEXT)load("glGetVertexAttribLdvEXT");
}

GLboolean GLAD_EXT_x11_sync_object = GL_FALSE;
static void load_GL_EXT_x11_sync_object(LOADER load) {
	if(!GLAD_EXT_x11_sync_object) return;
	fp_glImportSyncEXT = (pfn_glImportSyncEXT)load("glImportSyncEXT");
}

GLboolean GLAD_EXT_YUV_target = GL_FALSE;
GLboolean GLAD_OES_compressed_ETC1_RGB8_sub_texture = GL_FALSE;
GLboolean GLAD_OES_compressed_ETC1_RGB8_texture = GL_FALSE;
GLboolean GLAD_OES_copy_image = GL_FALSE;
static void load_GL_OES_copy_image(LOADER load) {
	if(!GLAD_OES_copy_image) return;
	fp_glCopyImageSubDataOES = (pfn_glCopyImageSubDataOES)load("glCopyImageSubDataOES");
}

GLboolean GLAD_OES_depth24 = GL_FALSE;
GLboolean GLAD_OES_depth32 = GL_FALSE;
GLboolean GLAD_OES_depth_texture = GL_FALSE;
GLboolean GLAD_OES_draw_buffers_indexed = GL_FALSE;
static void load_GL_OES_draw_buffers_indexed(LOADER load) {
	if(!GLAD_OES_draw_buffers_indexed) return;
	fp_glEnableiOES = (pfn_glEnableiOES)load("glEnableiOES");
	fp_glDisableiOES = (pfn_glDisableiOES)load("glDisableiOES");
	fp_glBlendEquationiOES = (pfn_glBlendEquationiOES)load("glBlendEquationiOES");
	fp_glBlendEquationSeparateiOES = (pfn_glBlendEquationSeparateiOES)load("glBlendEquationSeparateiOES");
	fp_glBlendFunciOES = (pfn_glBlendFunciOES)load("glBlendFunciOES");
	fp_glBlendFuncSeparateiOES = (pfn_glBlendFuncSeparateiOES)load("glBlendFuncSeparateiOES");
	fp_glColorMaskiOES = (pfn_glColorMaskiOES)load("glColorMaskiOES");
	fp_glIsEnablediOES = (pfn_glIsEnablediOES)load("glIsEnablediOES");
}

GLboolean GLAD_OES_draw_elements_base_vertex = GL_FALSE;
static void load_GL_OES_draw_elements_base_vertex(LOADER load) {
	if(!GLAD_OES_draw_elements_base_vertex) return;
	fp_glDrawElementsBaseVertexOES = (pfn_glDrawElementsBaseVertexOES)load("glDrawElementsBaseVertexOES");
	fp_glDrawRangeElementsBaseVertexOES = (pfn_glDrawRangeElementsBaseVertexOES)load("glDrawRangeElementsBaseVertexOES");
	fp_glDrawElementsInstancedBaseVertexOES = (pfn_glDrawElementsInstancedBaseVertexOES)load("glDrawElementsInstancedBaseVertexOES");
	fp_glMultiDrawElementsBaseVertexOES = (pfn_glMultiDrawElementsBaseVertexOES)load("glMultiDrawElementsBaseVertexOES");
}

GLboolean GLAD_OES_EGL_image = GL_FALSE;
static void load_GL_OES_EGL_image(LOADER load) {
	if(!GLAD_OES_EGL_image) return;
	fp_glEGLImageTargetTexture2DOES = (pfn_glEGLImageTargetTexture2DOES)load("glEGLImageTargetTexture2DOES");
	fp_glEGLImageTargetRenderbufferStorageOES = (pfn_glEGLImageTargetRenderbufferStorageOES)load("glEGLImageTargetRenderbufferStorageOES");
}

GLboolean GLAD_OES_EGL_image_external = GL_FALSE;
GLboolean GLAD_OES_EGL_image_external_essl3 = GL_FALSE;
GLboolean GLAD_OES_element_index_uint = GL_FALSE;
GLboolean GLAD_OES_fbo_render_mipmap = GL_FALSE;
GLboolean GLAD_OES_fragment_precision_high = GL_FALSE;
GLboolean GLAD_OES_geometry_point_size = GL_FALSE;
GLboolean GLAD_OES_geometry_shader = GL_FALSE;
static void load_GL_OES_geometry_shader(LOADER load) {
	if(!GLAD_OES_geometry_shader) return;
	fp_glFramebufferTextureOES = (pfn_glFramebufferTextureOES)load("glFramebufferTextureOES");
}

GLboolean GLAD_OES_get_program_binary = GL_FALSE;
static void load_GL_OES_get_program_binary(LOADER load) {
	if(!GLAD_OES_get_program_binary) return;
	fp_glGetProgramBinaryOES = (pfn_glGetProgramBinaryOES)load("glGetProgramBinaryOES");
	fp_glProgramBinaryOES = (pfn_glProgramBinaryOES)load("glProgramBinaryOES");
}

GLboolean GLAD_OES_gpu_shader5 = GL_FALSE;
GLboolean GLAD_OES_mapbuffer = GL_FALSE;
static void load_GL_OES_mapbuffer(LOADER load) {
	if(!GLAD_OES_mapbuffer) return;
	fp_glMapBufferOES = (pfn_glMapBufferOES)load("glMapBufferOES");
	fp_glUnmapBufferOES = (pfn_glUnmapBufferOES)load("glUnmapBufferOES");
	fp_glGetBufferPointervOES = (pfn_glGetBufferPointervOES)load("glGetBufferPointervOES");
}

GLboolean GLAD_OES_packed_depth_stencil = GL_FALSE;
GLboolean GLAD_OES_primitive_bounding_box = GL_FALSE;
static void load_GL_OES_primitive_bounding_box(LOADER load) {
	if(!GLAD_OES_primitive_bounding_box) return;
	fp_glPrimitiveBoundingBoxOES = (pfn_glPrimitiveBoundingBoxOES)load("glPrimitiveBoundingBoxOES");
}

GLboolean GLAD_OES_required_internalformat = GL_FALSE;
GLboolean GLAD_OES_rgb8_rgba8 = GL_FALSE;
GLboolean GLAD_OES_sample_shading = GL_FALSE;
static void load_GL_OES_sample_shading(LOADER load) {
	if(!GLAD_OES_sample_shading) return;
	fp_glMinSampleShadingOES = (pfn_glMinSampleShadingOES)load("glMinSampleShadingOES");
}

GLboolean GLAD_OES_sample_variables = GL_FALSE;
GLboolean GLAD_OES_shader_image_atomic = GL_FALSE;
GLboolean GLAD_OES_shader_io_blocks = GL_FALSE;
GLboolean GLAD_OES_shader_multisample_interpolation = GL_FALSE;
GLboolean GLAD_OES_standard_derivatives = GL_FALSE;
GLboolean GLAD_OES_stencil1 = GL_FALSE;
GLboolean GLAD_OES_stencil4 = GL_FALSE;
GLboolean GLAD_OES_surfaceless_context = GL_FALSE;
GLboolean GLAD_OES_tessellation_point_size = GL_FALSE;
GLboolean GLAD_OES_tessellation_shader = GL_FALSE;
static void load_GL_OES_tessellation_shader(LOADER load) {
	if(!GLAD_OES_tessellation_shader) return;
	fp_glPatchParameteriOES = (pfn_glPatchParameteriOES)load("glPatchParameteriOES");
}

GLboolean GLAD_OES_texture_3D = GL_FALSE;
static void load_GL_OES_texture_3D(LOADER load) {
	if(!GLAD_OES_texture_3D) return;
	fp_glTexImage3DOES = (pfn_glTexImage3DOES)load("glTexImage3DOES");
	fp_glTexSubImage3DOES = (pfn_glTexSubImage3DOES)load("glTexSubImage3DOES");
	fp_glCopyTexSubImage3DOES = (pfn_glCopyTexSubImage3DOES)load("glCopyTexSubImage3DOES");
	fp_glCompressedTexImage3DOES = (pfn_glCompressedTexImage3DOES)load("glCompressedTexImage3DOES");
	fp_glCompressedTexSubImage3DOES = (pfn_glCompressedTexSubImage3DOES)load("glCompressedTexSubImage3DOES");
	fp_glFramebufferTexture3DOES = (pfn_glFramebufferTexture3DOES)load("glFramebufferTexture3DOES");
}

GLboolean GLAD_OES_texture_border_clamp = GL_FALSE;
static void load_GL_OES_texture_border_clamp(LOADER load) {
	if(!GLAD_OES_texture_border_clamp) return;
	fp_glTexParameterIivOES = (pfn_glTexParameterIivOES)load("glTexParameterIivOES");
	fp_glTexParameterIuivOES = (pfn_glTexParameterIuivOES)load("glTexParameterIuivOES");
	fp_glGetTexParameterIivOES = (pfn_glGetTexParameterIivOES)load("glGetTexParameterIivOES");
	fp_glGetTexParameterIuivOES = (pfn_glGetTexParameterIuivOES)load("glGetTexParameterIuivOES");
	fp_glSamplerParameterIivOES = (pfn_glSamplerParameterIivOES)load("glSamplerParameterIivOES");
	fp_glSamplerParameterIuivOES = (pfn_glSamplerParameterIuivOES)load("glSamplerParameterIuivOES");
	fp_glGetSamplerParameterIivOES = (pfn_glGetSamplerParameterIivOES)load("glGetSamplerParameterIivOES");
	fp_glGetSamplerParameterIuivOES = (pfn_glGetSamplerParameterIuivOES)load("glGetSamplerParameterIuivOES");
}

GLboolean GLAD_OES_texture_buffer = GL_FALSE;
static void load_GL_OES_texture_buffer(LOADER load) {
	if(!GLAD_OES_texture_buffer) return;
	fp_glTexBufferOES = (pfn_glTexBufferOES)load("glTexBufferOES");
	fp_glTexBufferRangeOES = (pfn_glTexBufferRangeOES)load("glTexBufferRangeOES");
}

GLboolean GLAD_OES_texture_compression_astc = GL_FALSE;
GLboolean GLAD_OES_texture_cube_map_array = GL_FALSE;
GLboolean GLAD_OES_texture_float = GL_FALSE;
GLboolean GLAD_OES_texture_float_linear = GL_FALSE;
GLboolean GLAD_OES_texture_half_float = GL_FALSE;
GLboolean GLAD_OES_texture_half_float_linear = GL_FALSE;
GLboolean GLAD_OES_texture_npot = GL_FALSE;
GLboolean GLAD_OES_texture_stencil8 = GL_FALSE;
GLboolean GLAD_OES_texture_storage_multisample_2d_array = GL_FALSE;
static void load_GL_OES_texture_storage_multisample_2d_array(LOADER load) {
	if(!GLAD_OES_texture_storage_multisample_2d_array) return;
	fp_glTexStorage3DMultisampleOES = (pfn_glTexStorage3DMultisampleOES)load("glTexStorage3DMultisampleOES");
}

GLboolean GLAD_OES_texture_view = GL_FALSE;
static void load_GL_OES_texture_view(LOADER load) {
	if(!GLAD_OES_texture_view) return;
	fp_glTextureViewOES = (pfn_glTextureViewOES)load("glTextureViewOES");
}

GLboolean GLAD_OES_vertex_array_object = GL_FALSE;
static void load_GL_OES_vertex_array_object(LOADER load) {
	if(!GLAD_OES_vertex_array_object) return;
	fp_glBindVertexArrayOES = (pfn_glBindVertexArrayOES)load("glBindVertexArrayOES");
	fp_glDeleteVertexArraysOES = (pfn_glDeleteVertexArraysOES)load("glDeleteVertexArraysOES");
	fp_glGenVertexArraysOES = (pfn_glGenVertexArraysOES)load("glGenVertexArraysOES");
	fp_glIsVertexArrayOES = (pfn_glIsVertexArrayOES)load("glIsVertexArrayOES");
}

GLboolean GLAD_OES_vertex_half_float = GL_FALSE;
GLboolean GLAD_OES_vertex_type_10_10_10_2 = GL_FALSE;
GLboolean GLAD_AMD_blend_minmax_factor = GL_FALSE;
GLboolean GLAD_AMD_compressed_3DC_texture = GL_FALSE;
GLboolean GLAD_AMD_compressed_ATC_texture = GL_FALSE;
GLboolean GLAD_AMD_conservative_depth = GL_FALSE;
GLboolean GLAD_AMD_debug_output = GL_FALSE;
static void load_GL_AMD_debug_output(LOADER load) {
	if(!GLAD_AMD_debug_output) return;
	fp_glDebugMessageEnableAMD = (pfn_glDebugMessageEnableAMD)load("glDebugMessageEnableAMD");
	fp_glDebugMessageInsertAMD = (pfn_glDebugMessageInsertAMD)load("glDebugMessageInsertAMD");
	fp_glDebugMessageCallbackAMD = (pfn_glDebugMessageCallbackAMD)load("glDebugMessageCallbackAMD");
	fp_glGetDebugMessageLogAMD = (pfn_glGetDebugMessageLogAMD)load("glGetDebugMessageLogAMD");
}

GLboolean GLAD_AMD_depth_clamp_separate = GL_FALSE;
GLboolean GLAD_AMD_draw_buffers_blend = GL_FALSE;
static void load_GL_AMD_draw_buffers_blend(LOADER load) {
	if(!GLAD_AMD_draw_buffers_blend) return;
	fp_glBlendFuncIndexedAMD = (pfn_glBlendFuncIndexedAMD)load("glBlendFuncIndexedAMD");
	fp_glBlendFuncSeparateIndexedAMD = (pfn_glBlendFuncSeparateIndexedAMD)load("glBlendFuncSeparateIndexedAMD");
	fp_glBlendEquationIndexedAMD = (pfn_glBlendEquationIndexedAMD)load("glBlendEquationIndexedAMD");
	fp_glBlendEquationSeparateIndexedAMD = (pfn_glBlendEquationSeparateIndexedAMD)load("glBlendEquationSeparateIndexedAMD");
}

GLboolean GLAD_AMD_gcn_shader = GL_FALSE;
GLboolean GLAD_AMD_gpu_shader_int64 = GL_FALSE;
static void load_GL_AMD_gpu_shader_int64(LOADER load) {
	if(!GLAD_AMD_gpu_shader_int64) return;
	fp_glUniform1i64NV = (pfn_glUniform1i64NV)load("glUniform1i64NV");
	fp_glUniform2i64NV = (pfn_glUniform2i64NV)load("glUniform2i64NV");
	fp_glUniform3i64NV = (pfn_glUniform3i64NV)load("glUniform3i64NV");
	fp_glUniform4i64NV = (pfn_glUniform4i64NV)load("glUniform4i64NV");
	fp_glUniform1i64vNV = (pfn_glUniform1i64vNV)load("glUniform1i64vNV");
	fp_glUniform2i64vNV = (pfn_glUniform2i64vNV)load("glUniform2i64vNV");
	fp_glUniform3i64vNV = (pfn_glUniform3i64vNV)load("glUniform3i64vNV");
	fp_glUniform4i64vNV = (pfn_glUniform4i64vNV)load("glUniform4i64vNV");
	fp_glUniform1ui64NV = (pfn_glUniform1ui64NV)load("glUniform1ui64NV");
	fp_glUniform2ui64NV = (pfn_glUniform2ui64NV)load("glUniform2ui64NV");
	fp_glUniform3ui64NV = (pfn_glUniform3ui64NV)load("glUniform3ui64NV");
	fp_glUniform4ui64NV = (pfn_glUniform4ui64NV)load("glUniform4ui64NV");
	fp_glUniform1ui64vNV = (pfn_glUniform1ui64vNV)load("glUniform1ui64vNV");
	fp_glUniform2ui64vNV = (pfn_glUniform2ui64vNV)load("glUniform2ui64vNV");
	fp_glUniform3ui64vNV = (pfn_glUniform3ui64vNV)load("glUniform3ui64vNV");
	fp_glUniform4ui64vNV = (pfn_glUniform4ui64vNV)load("glUniform4ui64vNV");
	fp_glGetUniformi64vNV = (pfn_glGetUniformi64vNV)load("glGetUniformi64vNV");
	fp_glGetUniformui64vNV = (pfn_glGetUniformui64vNV)load("glGetUniformui64vNV");
	fp_glProgramUniform1i64NV = (pfn_glProgramUniform1i64NV)load("glProgramUniform1i64NV");
	fp_glProgramUniform2i64NV = (pfn_glProgramUniform2i64NV)load("glProgramUniform2i64NV");
	fp_glProgramUniform3i64NV = (pfn_glProgramUniform3i64NV)load("glProgramUniform3i64NV");
	fp_glProgramUniform4i64NV = (pfn_glProgramUniform4i64NV)load("glProgramUniform4i64NV");
	fp_glProgramUniform1i64vNV = (pfn_glProgramUniform1i64vNV)load("glProgramUniform1i64vNV");
	fp_glProgramUniform2i64vNV = (pfn_glProgramUniform2i64vNV)load("glProgramUniform2i64vNV");
	fp_glProgramUniform3i64vNV = (pfn_glProgramUniform3i64vNV)load("glProgramUniform3i64vNV");
	fp_glProgramUniform4i64vNV = (pfn_glProgramUniform4i64vNV)load("glProgramUniform4i64vNV");
	fp_glProgramUniform1ui64NV = (pfn_glProgramUniform1ui64NV)load("glProgramUniform1ui64NV");
	fp_glProgramUniform2ui64NV = (pfn_glProgramUniform2ui64NV)load("glProgramUniform2ui64NV");
	fp_glProgramUniform3ui64NV = (pfn_glProgramUniform3ui64NV)load("glProgramUniform3ui64NV");
	fp_glProgramUniform4ui64NV = (pfn_glProgramUniform4ui64NV)load("glProgramUniform4ui64NV");
	fp_glProgramUniform1ui64vNV = (pfn_glProgramUniform1ui64vNV)load("glProgramUniform1ui64vNV");
	fp_glProgramUniform2ui64vNV = (pfn_glProgramUniform2ui64vNV)load("glProgramUniform2ui64vNV");
	fp_glProgramUniform3ui64vNV = (pfn_glProgramUniform3ui64vNV)load("glProgramUniform3ui64vNV");
	fp_glProgramUniform4ui64vNV = (pfn_glProgramUniform4ui64vNV)load("glProgramUniform4ui64vNV");
}

GLboolean GLAD_AMD_interleaved_elements = GL_FALSE;
static void load_GL_AMD_interleaved_elements(LOADER load) {
	if(!GLAD_AMD_interleaved_elements) return;
	fp_glVertexAttribParameteriAMD = (pfn_glVertexAttribParameteriAMD)load("glVertexAttribParameteriAMD");
}

GLboolean GLAD_AMD_multi_draw_indirect = GL_FALSE;
static void load_GL_AMD_multi_draw_indirect(LOADER load) {
	if(!GLAD_AMD_multi_draw_indirect) return;
	fp_glMultiDrawArraysIndirectAMD = (pfn_glMultiDrawArraysIndirectAMD)load("glMultiDrawArraysIndirectAMD");
	fp_glMultiDrawElementsIndirectAMD = (pfn_glMultiDrawElementsIndirectAMD)load("glMultiDrawElementsIndirectAMD");
}

GLboolean GLAD_AMD_name_gen_delete = GL_FALSE;
static void load_GL_AMD_name_gen_delete(LOADER load) {
	if(!GLAD_AMD_name_gen_delete) return;
	fp_glGenNamesAMD = (pfn_glGenNamesAMD)load("glGenNamesAMD");
	fp_glDeleteNamesAMD = (pfn_glDeleteNamesAMD)load("glDeleteNamesAMD");
	fp_glIsNameAMD = (pfn_glIsNameAMD)load("glIsNameAMD");
}

GLboolean GLAD_AMD_occlusion_query_event = GL_FALSE;
static void load_GL_AMD_occlusion_query_event(LOADER load) {
	if(!GLAD_AMD_occlusion_query_event) return;
	fp_glQueryObjectParameteruiAMD = (pfn_glQueryObjectParameteruiAMD)load("glQueryObjectParameteruiAMD");
}

GLboolean GLAD_AMD_performance_monitor = GL_FALSE;
static void load_GL_AMD_performance_monitor(LOADER load) {
	if(!GLAD_AMD_performance_monitor) return;
	fp_glGetPerfMonitorGroupsAMD = (pfn_glGetPerfMonitorGroupsAMD)load("glGetPerfMonitorGroupsAMD");
	fp_glGetPerfMonitorCountersAMD = (pfn_glGetPerfMonitorCountersAMD)load("glGetPerfMonitorCountersAMD");
	fp_glGetPerfMonitorGroupStringAMD = (pfn_glGetPerfMonitorGroupStringAMD)load("glGetPerfMonitorGroupStringAMD");
	fp_glGetPerfMonitorCounterStringAMD = (pfn_glGetPerfMonitorCounterStringAMD)load("glGetPerfMonitorCounterStringAMD");
	fp_glGetPerfMonitorCounterInfoAMD = (pfn_glGetPerfMonitorCounterInfoAMD)load("glGetPerfMonitorCounterInfoAMD");
	fp_glGenPerfMonitorsAMD = (pfn_glGenPerfMonitorsAMD)load("glGenPerfMonitorsAMD");
	fp_glDeletePerfMonitorsAMD = (pfn_glDeletePerfMonitorsAMD)load("glDeletePerfMonitorsAMD");
	fp_glSelectPerfMonitorCountersAMD = (pfn_glSelectPerfMonitorCountersAMD)load("glSelectPerfMonitorCountersAMD");
	fp_glBeginPerfMonitorAMD = (pfn_glBeginPerfMonitorAMD)load("glBeginPerfMonitorAMD");
	fp_glEndPerfMonitorAMD = (pfn_glEndPerfMonitorAMD)load("glEndPerfMonitorAMD");
	fp_glGetPerfMonitorCounterDataAMD = (pfn_glGetPerfMonitorCounterDataAMD)load("glGetPerfMonitorCounterDataAMD");
}

GLboolean GLAD_AMD_pinned_memory = GL_FALSE;
GLboolean GLAD_AMD_program_binary_Z400 = GL_FALSE;
GLboolean GLAD_AMD_query_buffer_object = GL_FALSE;
GLboolean GLAD_AMD_sample_positions = GL_FALSE;
static void load_GL_AMD_sample_positions(LOADER load) {
	if(!GLAD_AMD_sample_positions) return;
	fp_glSetMultisamplefvAMD = (pfn_glSetMultisamplefvAMD)load("glSetMultisamplefvAMD");
}

GLboolean GLAD_AMD_seamless_cubemap_per_texture = GL_FALSE;
GLboolean GLAD_AMD_shader_atomic_counter_ops = GL_FALSE;
GLboolean GLAD_AMD_shader_stencil_export = GL_FALSE;
GLboolean GLAD_AMD_shader_trinary_minmax = GL_FALSE;
GLboolean GLAD_AMD_sparse_texture = GL_FALSE;
static void load_GL_AMD_sparse_texture(LOADER load) {
	if(!GLAD_AMD_sparse_texture) return;
	fp_glTexStorageSparseAMD = (pfn_glTexStorageSparseAMD)load("glTexStorageSparseAMD");
	fp_glTextureStorageSparseAMD = (pfn_glTextureStorageSparseAMD)load("glTextureStorageSparseAMD");
}

GLboolean GLAD_AMD_stencil_operation_extended = GL_FALSE;
static void load_GL_AMD_stencil_operation_extended(LOADER load) {
	if(!GLAD_AMD_stencil_operation_extended) return;
	fp_glStencilOpValueAMD = (pfn_glStencilOpValueAMD)load("glStencilOpValueAMD");
}

GLboolean GLAD_AMD_texture_texture4 = GL_FALSE;
GLboolean GLAD_AMD_transform_feedback3_lines_triangles = GL_FALSE;
GLboolean GLAD_AMD_transform_feedback4 = GL_FALSE;
GLboolean GLAD_AMD_vertex_shader_layer = GL_FALSE;
GLboolean GLAD_AMD_vertex_shader_tessellator = GL_FALSE;
static void load_GL_AMD_vertex_shader_tessellator(LOADER load) {
	if(!GLAD_AMD_vertex_shader_tessellator) return;
	fp_glTessellationFactorAMD = (pfn_glTessellationFactorAMD)load("glTessellationFactorAMD");
	fp_glTessellationModeAMD = (pfn_glTessellationModeAMD)load("glTessellationModeAMD");
}

GLboolean GLAD_AMD_vertex_shader_viewport_index = GL_FALSE;
GLboolean GLAD_ANDROID_extension_pack_es31a = GL_FALSE;
GLboolean GLAD_ANGLE_depth_texture = GL_FALSE;
GLboolean GLAD_ANGLE_framebuffer_blit = GL_FALSE;
static void load_GL_ANGLE_framebuffer_blit(LOADER load) {
	if(!GLAD_ANGLE_framebuffer_blit) return;
	fp_glBlitFramebufferANGLE = (pfn_glBlitFramebufferANGLE)load("glBlitFramebufferANGLE");
}

GLboolean GLAD_ANGLE_framebuffer_multisample = GL_FALSE;
static void load_GL_ANGLE_framebuffer_multisample(LOADER load) {
	if(!GLAD_ANGLE_framebuffer_multisample) return;
	fp_glRenderbufferStorageMultisampleANGLE = (pfn_glRenderbufferStorageMultisampleANGLE)load("glRenderbufferStorageMultisampleANGLE");
}

GLboolean GLAD_ANGLE_instanced_arrays = GL_FALSE;
static void load_GL_ANGLE_instanced_arrays(LOADER load) {
	if(!GLAD_ANGLE_instanced_arrays) return;
	fp_glDrawArraysInstancedANGLE = (pfn_glDrawArraysInstancedANGLE)load("glDrawArraysInstancedANGLE");
	fp_glDrawElementsInstancedANGLE = (pfn_glDrawElementsInstancedANGLE)load("glDrawElementsInstancedANGLE");
	fp_glVertexAttribDivisorANGLE = (pfn_glVertexAttribDivisorANGLE)load("glVertexAttribDivisorANGLE");
}

GLboolean GLAD_ANGLE_pack_reverse_row_order = GL_FALSE;
GLboolean GLAD_ANGLE_program_binary = GL_FALSE;
GLboolean GLAD_ANGLE_texture_compression_dxt3 = GL_FALSE;
GLboolean GLAD_ANGLE_texture_compression_dxt5 = GL_FALSE;
GLboolean GLAD_ANGLE_texture_usage = GL_FALSE;
GLboolean GLAD_ANGLE_translated_shader_source = GL_FALSE;
static void load_GL_ANGLE_translated_shader_source(LOADER load) {
	if(!GLAD_ANGLE_translated_shader_source) return;
	fp_glGetTranslatedShaderSourceANGLE = (pfn_glGetTranslatedShaderSourceANGLE)load("glGetTranslatedShaderSourceANGLE");
}

GLboolean GLAD_APPLE_aux_depth_stencil = GL_FALSE;
GLboolean GLAD_APPLE_client_storage = GL_FALSE;
GLboolean GLAD_APPLE_clip_distance = GL_FALSE;
GLboolean GLAD_APPLE_color_buffer_packed_float = GL_FALSE;
GLboolean GLAD_APPLE_copy_texture_levels = GL_FALSE;
static void load_GL_APPLE_copy_texture_levels(LOADER load) {
	if(!GLAD_APPLE_copy_texture_levels) return;
	fp_glCopyTextureLevelsAPPLE = (pfn_glCopyTextureLevelsAPPLE)load("glCopyTextureLevelsAPPLE");
}

GLboolean GLAD_APPLE_element_array = GL_FALSE;
static void load_GL_APPLE_element_array(LOADER load) {
	if(!GLAD_APPLE_element_array) return;
	fp_glElementPointerAPPLE = (pfn_glElementPointerAPPLE)load("glElementPointerAPPLE");
	fp_glDrawElementArrayAPPLE = (pfn_glDrawElementArrayAPPLE)load("glDrawElementArrayAPPLE");
	fp_glDrawRangeElementArrayAPPLE = (pfn_glDrawRangeElementArrayAPPLE)load("glDrawRangeElementArrayAPPLE");
	fp_glMultiDrawElementArrayAPPLE = (pfn_glMultiDrawElementArrayAPPLE)load("glMultiDrawElementArrayAPPLE");
	fp_glMultiDrawRangeElementArrayAPPLE = (pfn_glMultiDrawRangeElementArrayAPPLE)load("glMultiDrawRangeElementArrayAPPLE");
}

GLboolean GLAD_APPLE_fence = GL_FALSE;
static void load_GL_APPLE_fence(LOADER load) {
	if(!GLAD_APPLE_fence) return;
	fp_glGenFencesAPPLE = (pfn_glGenFencesAPPLE)load("glGenFencesAPPLE");
	fp_glDeleteFencesAPPLE = (pfn_glDeleteFencesAPPLE)load("glDeleteFencesAPPLE");
	fp_glSetFenceAPPLE = (pfn_glSetFenceAPPLE)load("glSetFenceAPPLE");
	fp_glIsFenceAPPLE = (pfn_glIsFenceAPPLE)load("glIsFenceAPPLE");
	fp_glTestFenceAPPLE = (pfn_glTestFenceAPPLE)load("glTestFenceAPPLE");
	fp_glFinishFenceAPPLE = (pfn_glFinishFenceAPPLE)load("glFinishFenceAPPLE");
	fp_glTestObjectAPPLE = (pfn_glTestObjectAPPLE)load("glTestObjectAPPLE");
	fp_glFinishObjectAPPLE = (pfn_glFinishObjectAPPLE)load("glFinishObjectAPPLE");
}

GLboolean GLAD_APPLE_float_pixels = GL_FALSE;
GLboolean GLAD_APPLE_flush_buffer_range = GL_FALSE;
static void load_GL_APPLE_flush_buffer_range(LOADER load) {
	if(!GLAD_APPLE_flush_buffer_range) return;
	fp_glBufferParameteriAPPLE = (pfn_glBufferParameteriAPPLE)load("glBufferParameteriAPPLE");
	fp_glFlushMappedBufferRangeAPPLE = (pfn_glFlushMappedBufferRangeAPPLE)load("glFlushMappedBufferRangeAPPLE");
}

GLboolean GLAD_APPLE_framebuffer_multisample = GL_FALSE;
static void load_GL_APPLE_framebuffer_multisample(LOADER load) {
	if(!GLAD_APPLE_framebuffer_multisample) return;
	fp_glRenderbufferStorageMultisampleAPPLE = (pfn_glRenderbufferStorageMultisampleAPPLE)load("glRenderbufferStorageMultisampleAPPLE");
	fp_glResolveMultisampleFramebufferAPPLE = (pfn_glResolveMultisampleFramebufferAPPLE)load("glResolveMultisampleFramebufferAPPLE");
}

GLboolean GLAD_APPLE_object_purgeable = GL_FALSE;
static void load_GL_APPLE_object_purgeable(LOADER load) {
	if(!GLAD_APPLE_object_purgeable) return;
	fp_glObjectPurgeableAPPLE = (pfn_glObjectPurgeableAPPLE)load("glObjectPurgeableAPPLE");
	fp_glObjectUnpurgeableAPPLE = (pfn_glObjectUnpurgeableAPPLE)load("glObjectUnpurgeableAPPLE");
	fp_glGetObjectParameterivAPPLE = (pfn_glGetObjectParameterivAPPLE)load("glGetObjectParameterivAPPLE");
}

GLboolean GLAD_APPLE_rgb_422 = GL_FALSE;
GLboolean GLAD_APPLE_row_bytes = GL_FALSE;
GLboolean GLAD_APPLE_sync = GL_FALSE;
static void load_GL_APPLE_sync(LOADER load) {
	if(!GLAD_APPLE_sync) return;
	fp_glFenceSyncAPPLE = (pfn_glFenceSyncAPPLE)load("glFenceSyncAPPLE");
	fp_glIsSyncAPPLE = (pfn_glIsSyncAPPLE)load("glIsSyncAPPLE");
	fp_glDeleteSyncAPPLE = (pfn_glDeleteSyncAPPLE)load("glDeleteSyncAPPLE");
	fp_glClientWaitSyncAPPLE = (pfn_glClientWaitSyncAPPLE)load("glClientWaitSyncAPPLE");
	fp_glWaitSyncAPPLE = (pfn_glWaitSyncAPPLE)load("glWaitSyncAPPLE");
	fp_glGetInteger64vAPPLE = (pfn_glGetInteger64vAPPLE)load("glGetInteger64vAPPLE");
	fp_glGetSyncivAPPLE = (pfn_glGetSyncivAPPLE)load("glGetSyncivAPPLE");
}

GLboolean GLAD_APPLE_texture_format_BGRA8888 = GL_FALSE;
GLboolean GLAD_APPLE_texture_max_level = GL_FALSE;
GLboolean GLAD_APPLE_texture_packed_float = GL_FALSE;
GLboolean GLAD_APPLE_texture_range = GL_FALSE;
static void load_GL_APPLE_texture_range(LOADER load) {
	if(!GLAD_APPLE_texture_range) return;
	fp_glTextureRangeAPPLE = (pfn_glTextureRangeAPPLE)load("glTextureRangeAPPLE");
	fp_glGetTexParameterPointervAPPLE = (pfn_glGetTexParameterPointervAPPLE)load("glGetTexParameterPointervAPPLE");
}

GLboolean GLAD_APPLE_vertex_array_object = GL_FALSE;
static void load_GL_APPLE_vertex_array_object(LOADER load) {
	if(!GLAD_APPLE_vertex_array_object) return;
	fp_glBindVertexArrayAPPLE = (pfn_glBindVertexArrayAPPLE)load("glBindVertexArrayAPPLE");
	fp_glDeleteVertexArraysAPPLE = (pfn_glDeleteVertexArraysAPPLE)load("glDeleteVertexArraysAPPLE");
	fp_glGenVertexArraysAPPLE = (pfn_glGenVertexArraysAPPLE)load("glGenVertexArraysAPPLE");
	fp_glIsVertexArrayAPPLE = (pfn_glIsVertexArrayAPPLE)load("glIsVertexArrayAPPLE");
}

GLboolean GLAD_APPLE_vertex_array_range = GL_FALSE;
static void load_GL_APPLE_vertex_array_range(LOADER load) {
	if(!GLAD_APPLE_vertex_array_range) return;
	fp_glVertexArrayRangeAPPLE = (pfn_glVertexArrayRangeAPPLE)load("glVertexArrayRangeAPPLE");
	fp_glFlushVertexArrayRangeAPPLE = (pfn_glFlushVertexArrayRangeAPPLE)load("glFlushVertexArrayRangeAPPLE");
	fp_glVertexArrayParameteriAPPLE = (pfn_glVertexArrayParameteriAPPLE)load("glVertexArrayParameteriAPPLE");
}

GLboolean GLAD_APPLE_vertex_program_evaluators = GL_FALSE;
static void load_GL_APPLE_vertex_program_evaluators(LOADER load) {
	if(!GLAD_APPLE_vertex_program_evaluators) return;
	fp_glEnableVertexAttribAPPLE = (pfn_glEnableVertexAttribAPPLE)load("glEnableVertexAttribAPPLE");
	fp_glDisableVertexAttribAPPLE = (pfn_glDisableVertexAttribAPPLE)load("glDisableVertexAttribAPPLE");
	fp_glIsVertexAttribEnabledAPPLE = (pfn_glIsVertexAttribEnabledAPPLE)load("glIsVertexAttribEnabledAPPLE");
	fp_glMapVertexAttrib1dAPPLE = (pfn_glMapVertexAttrib1dAPPLE)load("glMapVertexAttrib1dAPPLE");
	fp_glMapVertexAttrib1fAPPLE = (pfn_glMapVertexAttrib1fAPPLE)load("glMapVertexAttrib1fAPPLE");
	fp_glMapVertexAttrib2dAPPLE = (pfn_glMapVertexAttrib2dAPPLE)load("glMapVertexAttrib2dAPPLE");
	fp_glMapVertexAttrib2fAPPLE = (pfn_glMapVertexAttrib2fAPPLE)load("glMapVertexAttrib2fAPPLE");
}

GLboolean GLAD_APPLE_ycbcr_422 = GL_FALSE;
GLboolean GLAD_ARM_mali_program_binary = GL_FALSE;
GLboolean GLAD_ARM_mali_shader_binary = GL_FALSE;
GLboolean GLAD_ARM_rgba8 = GL_FALSE;
GLboolean GLAD_ARM_shader_framebuffer_fetch = GL_FALSE;
GLboolean GLAD_ARM_shader_framebuffer_fetch_depth_stencil = GL_FALSE;
GLboolean GLAD_ATI_meminfo = GL_FALSE;
GLboolean GLAD_ATI_pixel_format_float = GL_FALSE;
GLboolean GLAD_DMP_program_binary = GL_FALSE;
GLboolean GLAD_DMP_shader_binary = GL_FALSE;
GLboolean GLAD_FJ_shader_binary_GCCSO = GL_FALSE;
GLboolean GLAD_GREMEDY_frame_terminator = GL_FALSE;
static void load_GL_GREMEDY_frame_terminator(LOADER load) {
	if(!GLAD_GREMEDY_frame_terminator) return;
	fp_glFrameTerminatorGREMEDY = (pfn_glFrameTerminatorGREMEDY)load("glFrameTerminatorGREMEDY");
}

GLboolean GLAD_GREMEDY_string_marker = GL_FALSE;
static void load_GL_GREMEDY_string_marker(LOADER load) {
	if(!GLAD_GREMEDY_string_marker) return;
	fp_glStringMarkerGREMEDY = (pfn_glStringMarkerGREMEDY)load("glStringMarkerGREMEDY");
}

GLboolean GLAD_IMG_multisampled_render_to_texture = GL_FALSE;
static void load_GL_IMG_multisampled_render_to_texture(LOADER load) {
	if(!GLAD_IMG_multisampled_render_to_texture) return;
	fp_glRenderbufferStorageMultisampleIMG = (pfn_glRenderbufferStorageMultisampleIMG)load("glRenderbufferStorageMultisampleIMG");
	fp_glFramebufferTexture2DMultisampleIMG = (pfn_glFramebufferTexture2DMultisampleIMG)load("glFramebufferTexture2DMultisampleIMG");
}

GLboolean GLAD_IMG_program_binary = GL_FALSE;
GLboolean GLAD_IMG_read_format = GL_FALSE;
GLboolean GLAD_IMG_shader_binary = GL_FALSE;
GLboolean GLAD_IMG_texture_compression_pvrtc = GL_FALSE;
GLboolean GLAD_IMG_texture_compression_pvrtc2 = GL_FALSE;
GLboolean GLAD_IMG_texture_filter_cubic = GL_FALSE;
GLboolean GLAD_INGR_blend_func_separate = GL_FALSE;
static void load_GL_INGR_blend_func_separate(LOADER load) {
	if(!GLAD_INGR_blend_func_separate) return;
	fp_glBlendFuncSeparateINGR = (pfn_glBlendFuncSeparateINGR)load("glBlendFuncSeparateINGR");
}

GLboolean GLAD_INTEL_fragment_shader_ordering = GL_FALSE;
GLboolean GLAD_INTEL_framebuffer_CMAA = GL_FALSE;
static void load_GL_INTEL_framebuffer_CMAA(LOADER load) {
	if(!GLAD_INTEL_framebuffer_CMAA) return;
	fp_glApplyFramebufferAttachmentCMAAINTEL = (pfn_glApplyFramebufferAttachmentCMAAINTEL)load("glApplyFramebufferAttachmentCMAAINTEL");
}

GLboolean GLAD_INTEL_map_texture = GL_FALSE;
static void load_GL_INTEL_map_texture(LOADER load) {
	if(!GLAD_INTEL_map_texture) return;
	fp_glSyncTextureINTEL = (pfn_glSyncTextureINTEL)load("glSyncTextureINTEL");
	fp_glUnmapTexture2DINTEL = (pfn_glUnmapTexture2DINTEL)load("glUnmapTexture2DINTEL");
	fp_glMapTexture2DINTEL = (pfn_glMapTexture2DINTEL)load("glMapTexture2DINTEL");
}

GLboolean GLAD_INTEL_performance_query = GL_FALSE;
static void load_GL_INTEL_performance_query(LOADER load) {
	if(!GLAD_INTEL_performance_query) return;
	fp_glBeginPerfQueryINTEL = (pfn_glBeginPerfQueryINTEL)load("glBeginPerfQueryINTEL");
	fp_glCreatePerfQueryINTEL = (pfn_glCreatePerfQueryINTEL)load("glCreatePerfQueryINTEL");
	fp_glDeletePerfQueryINTEL = (pfn_glDeletePerfQueryINTEL)load("glDeletePerfQueryINTEL");
	fp_glEndPerfQueryINTEL = (pfn_glEndPerfQueryINTEL)load("glEndPerfQueryINTEL");
	fp_glGetFirstPerfQueryIdINTEL = (pfn_glGetFirstPerfQueryIdINTEL)load("glGetFirstPerfQueryIdINTEL");
	fp_glGetNextPerfQueryIdINTEL = (pfn_glGetNextPerfQueryIdINTEL)load("glGetNextPerfQueryIdINTEL");
	fp_glGetPerfCounterInfoINTEL = (pfn_glGetPerfCounterInfoINTEL)load("glGetPerfCounterInfoINTEL");
	fp_glGetPerfQueryDataINTEL = (pfn_glGetPerfQueryDataINTEL)load("glGetPerfQueryDataINTEL");
	fp_glGetPerfQueryIdByNameINTEL = (pfn_glGetPerfQueryIdByNameINTEL)load("glGetPerfQueryIdByNameINTEL");
	fp_glGetPerfQueryInfoINTEL = (pfn_glGetPerfQueryInfoINTEL)load("glGetPerfQueryInfoINTEL");
}

GLboolean GLAD_MESA_pack_invert = GL_FALSE;
GLboolean GLAD_MESA_ycbcr_texture = GL_FALSE;
GLboolean GLAD_MESAX_texture_stack = GL_FALSE;
GLboolean GLAD_NV_bindless_multi_draw_indirect = GL_FALSE;
static void load_GL_NV_bindless_multi_draw_indirect(LOADER load) {
	if(!GLAD_NV_bindless_multi_draw_indirect) return;
	fp_glMultiDrawArraysIndirectBindlessNV = (pfn_glMultiDrawArraysIndirectBindlessNV)load("glMultiDrawArraysIndirectBindlessNV");
	fp_glMultiDrawElementsIndirectBindlessNV = (pfn_glMultiDrawElementsIndirectBindlessNV)load("glMultiDrawElementsIndirectBindlessNV");
}

GLboolean GLAD_NV_bindless_multi_draw_indirect_count = GL_FALSE;
static void load_GL_NV_bindless_multi_draw_indirect_count(LOADER load) {
	if(!GLAD_NV_bindless_multi_draw_indirect_count) return;
	fp_glMultiDrawArraysIndirectBindlessCountNV = (pfn_glMultiDrawArraysIndirectBindlessCountNV)load("glMultiDrawArraysIndirectBindlessCountNV");
	fp_glMultiDrawElementsIndirectBindlessCountNV = (pfn_glMultiDrawElementsIndirectBindlessCountNV)load("glMultiDrawElementsIndirectBindlessCountNV");
}

GLboolean GLAD_NV_bindless_texture = GL_FALSE;
static void load_GL_NV_bindless_texture(LOADER load) {
	if(!GLAD_NV_bindless_texture) return;
	fp_glGetTextureHandleNV = (pfn_glGetTextureHandleNV)load("glGetTextureHandleNV");
	fp_glGetTextureSamplerHandleNV = (pfn_glGetTextureSamplerHandleNV)load("glGetTextureSamplerHandleNV");
	fp_glMakeTextureHandleResidentNV = (pfn_glMakeTextureHandleResidentNV)load("glMakeTextureHandleResidentNV");
	fp_glMakeTextureHandleNonResidentNV = (pfn_glMakeTextureHandleNonResidentNV)load("glMakeTextureHandleNonResidentNV");
	fp_glGetImageHandleNV = (pfn_glGetImageHandleNV)load("glGetImageHandleNV");
	fp_glMakeImageHandleResidentNV = (pfn_glMakeImageHandleResidentNV)load("glMakeImageHandleResidentNV");
	fp_glMakeImageHandleNonResidentNV = (pfn_glMakeImageHandleNonResidentNV)load("glMakeImageHandleNonResidentNV");
	fp_glUniformHandleui64NV = (pfn_glUniformHandleui64NV)load("glUniformHandleui64NV");
	fp_glUniformHandleui64vNV = (pfn_glUniformHandleui64vNV)load("glUniformHandleui64vNV");
	fp_glProgramUniformHandleui64NV = (pfn_glProgramUniformHandleui64NV)load("glProgramUniformHandleui64NV");
	fp_glProgramUniformHandleui64vNV = (pfn_glProgramUniformHandleui64vNV)load("glProgramUniformHandleui64vNV");
	fp_glIsTextureHandleResidentNV = (pfn_glIsTextureHandleResidentNV)load("glIsTextureHandleResidentNV");
	fp_glIsImageHandleResidentNV = (pfn_glIsImageHandleResidentNV)load("glIsImageHandleResidentNV");
}

GLboolean GLAD_NV_blend_equation_advanced = GL_FALSE;
static void load_GL_NV_blend_equation_advanced(LOADER load) {
	if(!GLAD_NV_blend_equation_advanced) return;
	fp_glBlendParameteriNV = (pfn_glBlendParameteriNV)load("glBlendParameteriNV");
	fp_glBlendBarrierNV = (pfn_glBlendBarrierNV)load("glBlendBarrierNV");
}

GLboolean GLAD_NV_blend_equation_advanced_coherent = GL_FALSE;
GLboolean GLAD_NV_command_list = GL_FALSE;
static void load_GL_NV_command_list(LOADER load) {
	if(!GLAD_NV_command_list) return;
	fp_glCreateStatesNV = (pfn_glCreateStatesNV)load("glCreateStatesNV");
	fp_glDeleteStatesNV = (pfn_glDeleteStatesNV)load("glDeleteStatesNV");
	fp_glIsStateNV = (pfn_glIsStateNV)load("glIsStateNV");
	fp_glStateCaptureNV = (pfn_glStateCaptureNV)load("glStateCaptureNV");
	fp_glGetCommandHeaderNV = (pfn_glGetCommandHeaderNV)load("glGetCommandHeaderNV");
	fp_glGetStageIndexNV = (pfn_glGetStageIndexNV)load("glGetStageIndexNV");
	fp_glDrawCommandsNV = (pfn_glDrawCommandsNV)load("glDrawCommandsNV");
	fp_glDrawCommandsAddressNV = (pfn_glDrawCommandsAddressNV)load("glDrawCommandsAddressNV");
	fp_glDrawCommandsStatesNV = (pfn_glDrawCommandsStatesNV)load("glDrawCommandsStatesNV");
	fp_glDrawCommandsStatesAddressNV = (pfn_glDrawCommandsStatesAddressNV)load("glDrawCommandsStatesAddressNV");
	fp_glCreateCommandListsNV = (pfn_glCreateCommandListsNV)load("glCreateCommandListsNV");
	fp_glDeleteCommandListsNV = (pfn_glDeleteCommandListsNV)load("glDeleteCommandListsNV");
	fp_glIsCommandListNV = (pfn_glIsCommandListNV)load("glIsCommandListNV");
	fp_glListDrawCommandsStatesClientNV = (pfn_glListDrawCommandsStatesClientNV)load("glListDrawCommandsStatesClientNV");
	fp_glCommandListSegmentsNV = (pfn_glCommandListSegmentsNV)load("glCommandListSegmentsNV");
	fp_glCompileCommandListNV = (pfn_glCompileCommandListNV)load("glCompileCommandListNV");
	fp_glCallCommandListNV = (pfn_glCallCommandListNV)load("glCallCommandListNV");
}

GLboolean GLAD_NV_compute_program5 = GL_FALSE;
GLboolean GLAD_NV_conditional_render = GL_FALSE;
static void load_GL_NV_conditional_render(LOADER load) {
	if(!GLAD_NV_conditional_render) return;
	fp_glBeginConditionalRenderNV = (pfn_glBeginConditionalRenderNV)load("glBeginConditionalRenderNV");
	fp_glEndConditionalRenderNV = (pfn_glEndConditionalRenderNV)load("glEndConditionalRenderNV");
}

GLboolean GLAD_NV_conservative_raster = GL_FALSE;
static void load_GL_NV_conservative_raster(LOADER load) {
	if(!GLAD_NV_conservative_raster) return;
	fp_glSubpixelPrecisionBiasNV = (pfn_glSubpixelPrecisionBiasNV)load("glSubpixelPrecisionBiasNV");
}

GLboolean GLAD_NV_conservative_raster_dilate = GL_FALSE;
static void load_GL_NV_conservative_raster_dilate(LOADER load) {
	if(!GLAD_NV_conservative_raster_dilate) return;
	fp_glConservativeRasterParameterfNV = (pfn_glConservativeRasterParameterfNV)load("glConservativeRasterParameterfNV");
}

GLboolean GLAD_NV_copy_buffer = GL_FALSE;
static void load_GL_NV_copy_buffer(LOADER load) {
	if(!GLAD_NV_copy_buffer) return;
	fp_glCopyBufferSubDataNV = (pfn_glCopyBufferSubDataNV)load("glCopyBufferSubDataNV");
}

GLboolean GLAD_NV_copy_image = GL_FALSE;
static void load_GL_NV_copy_image(LOADER load) {
	if(!GLAD_NV_copy_image) return;
	fp_glCopyImageSubDataNV = (pfn_glCopyImageSubDataNV)load("glCopyImageSubDataNV");
}

GLboolean GLAD_NV_coverage_sample = GL_FALSE;
static void load_GL_NV_coverage_sample(LOADER load) {
	if(!GLAD_NV_coverage_sample) return;
	fp_glCoverageMaskNV = (pfn_glCoverageMaskNV)load("glCoverageMaskNV");
	fp_glCoverageOperationNV = (pfn_glCoverageOperationNV)load("glCoverageOperationNV");
}

GLboolean GLAD_NV_deep_texture3D = GL_FALSE;
GLboolean GLAD_NV_depth_buffer_float = GL_FALSE;
static void load_GL_NV_depth_buffer_float(LOADER load) {
	if(!GLAD_NV_depth_buffer_float) return;
	fp_glDepthRangedNV = (pfn_glDepthRangedNV)load("glDepthRangedNV");
	fp_glClearDepthdNV = (pfn_glClearDepthdNV)load("glClearDepthdNV");
	fp_glDepthBoundsdNV = (pfn_glDepthBoundsdNV)load("glDepthBoundsdNV");
}

GLboolean GLAD_NV_depth_clamp = GL_FALSE;
GLboolean GLAD_NV_depth_nonlinear = GL_FALSE;
GLboolean GLAD_NV_draw_buffers = GL_FALSE;
static void load_GL_NV_draw_buffers(LOADER load) {
	if(!GLAD_NV_draw_buffers) return;
	fp_glDrawBuffersNV = (pfn_glDrawBuffersNV)load("glDrawBuffersNV");
}

GLboolean GLAD_NV_draw_instanced = GL_FALSE;
static void load_GL_NV_draw_instanced(LOADER load) {
	if(!GLAD_NV_draw_instanced) return;
	fp_glDrawArraysInstancedNV = (pfn_glDrawArraysInstancedNV)load("glDrawArraysInstancedNV");
	fp_glDrawElementsInstancedNV = (pfn_glDrawElementsInstancedNV)load("glDrawElementsInstancedNV");
}

GLboolean GLAD_NV_draw_texture = GL_FALSE;
static void load_GL_NV_draw_texture(LOADER load) {
	if(!GLAD_NV_draw_texture) return;
	fp_glDrawTextureNV = (pfn_glDrawTextureNV)load("glDrawTextureNV");
}

GLboolean GLAD_NV_explicit_attrib_location = GL_FALSE;
GLboolean GLAD_NV_explicit_multisample = GL_FALSE;
static void load_GL_NV_explicit_multisample(LOADER load) {
	if(!GLAD_NV_explicit_multisample) return;
	fp_glGetMultisamplefvNV = (pfn_glGetMultisamplefvNV)load("glGetMultisamplefvNV");
	fp_glSampleMaskIndexedNV = (pfn_glSampleMaskIndexedNV)load("glSampleMaskIndexedNV");
	fp_glTexRenderbufferNV = (pfn_glTexRenderbufferNV)load("glTexRenderbufferNV");
}

GLboolean GLAD_NV_fbo_color_attachments = GL_FALSE;
GLboolean GLAD_NV_fence = GL_FALSE;
static void load_GL_NV_fence(LOADER load) {
	if(!GLAD_NV_fence) return;
	fp_glDeleteFencesNV = (pfn_glDeleteFencesNV)load("glDeleteFencesNV");
	fp_glGenFencesNV = (pfn_glGenFencesNV)load("glGenFencesNV");
	fp_glIsFenceNV = (pfn_glIsFenceNV)load("glIsFenceNV");
	fp_glTestFenceNV = (pfn_glTestFenceNV)load("glTestFenceNV");
	fp_glGetFenceivNV = (pfn_glGetFenceivNV)load("glGetFenceivNV");
	fp_glFinishFenceNV = (pfn_glFinishFenceNV)load("glFinishFenceNV");
	fp_glSetFenceNV = (pfn_glSetFenceNV)load("glSetFenceNV");
}

GLboolean GLAD_NV_fill_rectangle = GL_FALSE;
GLboolean GLAD_NV_float_buffer = GL_FALSE;
GLboolean GLAD_NV_fragment_coverage_to_color = GL_FALSE;
static void load_GL_NV_fragment_coverage_to_color(LOADER load) {
	if(!GLAD_NV_fragment_coverage_to_color) return;
	fp_glFragmentCoverageColorNV = (pfn_glFragmentCoverageColorNV)load("glFragmentCoverageColorNV");
}

GLboolean GLAD_NV_fragment_program4 = GL_FALSE;
GLboolean GLAD_NV_fragment_shader_interlock = GL_FALSE;
GLboolean GLAD_NV_framebuffer_blit = GL_FALSE;
static void load_GL_NV_framebuffer_blit(LOADER load) {
	if(!GLAD_NV_framebuffer_blit) return;
	fp_glBlitFramebufferNV = (pfn_glBlitFramebufferNV)load("glBlitFramebufferNV");
}

GLboolean GLAD_NV_framebuffer_mixed_samples = GL_FALSE;
static void load_GL_NV_framebuffer_mixed_samples(LOADER load) {
	if(!GLAD_NV_framebuffer_mixed_samples) return;
	fp_glRasterSamplesEXT = (pfn_glRasterSamplesEXT)load("glRasterSamplesEXT");
	fp_glCoverageModulationTableNV = (pfn_glCoverageModulationTableNV)load("glCoverageModulationTableNV");
	fp_glGetCoverageModulationTableNV = (pfn_glGetCoverageModulationTableNV)load("glGetCoverageModulationTableNV");
	fp_glCoverageModulationNV = (pfn_glCoverageModulationNV)load("glCoverageModulationNV");
}

GLboolean GLAD_NV_framebuffer_multisample = GL_FALSE;
static void load_GL_NV_framebuffer_multisample(LOADER load) {
	if(!GLAD_NV_framebuffer_multisample) return;
	fp_glRenderbufferStorageMultisampleNV = (pfn_glRenderbufferStorageMultisampleNV)load("glRenderbufferStorageMultisampleNV");
}

GLboolean GLAD_NV_framebuffer_multisample_coverage = GL_FALSE;
static void load_GL_NV_framebuffer_multisample_coverage(LOADER load) {
	if(!GLAD_NV_framebuffer_multisample_coverage) return;
	fp_glRenderbufferStorageMultisampleCoverageNV = (pfn_glRenderbufferStorageMultisampleCoverageNV)load("glRenderbufferStorageMultisampleCoverageNV");
}

GLboolean GLAD_NV_generate_mipmap_sRGB = GL_FALSE;
GLboolean GLAD_NV_geometry_program4 = GL_FALSE;
static void load_GL_NV_geometry_program4(LOADER load) {
	if(!GLAD_NV_geometry_program4) return;
	fp_glProgramVertexLimitNV = (pfn_glProgramVertexLimitNV)load("glProgramVertexLimitNV");
	fp_glFramebufferTextureEXT = (pfn_glFramebufferTextureEXT)load("glFramebufferTextureEXT");
	fp_glFramebufferTextureLayerEXT = (pfn_glFramebufferTextureLayerEXT)load("glFramebufferTextureLayerEXT");
	fp_glFramebufferTextureFaceEXT = (pfn_glFramebufferTextureFaceEXT)load("glFramebufferTextureFaceEXT");
}

GLboolean GLAD_NV_geometry_shader4 = GL_FALSE;
GLboolean GLAD_NV_geometry_shader_passthrough = GL_FALSE;
GLboolean GLAD_NV_gpu_program4 = GL_FALSE;
static void load_GL_NV_gpu_program4(LOADER load) {
	if(!GLAD_NV_gpu_program4) return;
	fp_glProgramLocalParameterI4iNV = (pfn_glProgramLocalParameterI4iNV)load("glProgramLocalParameterI4iNV");
	fp_glProgramLocalParameterI4ivNV = (pfn_glProgramLocalParameterI4ivNV)load("glProgramLocalParameterI4ivNV");
	fp_glProgramLocalParametersI4ivNV = (pfn_glProgramLocalParametersI4ivNV)load("glProgramLocalParametersI4ivNV");
	fp_glProgramLocalParameterI4uiNV = (pfn_glProgramLocalParameterI4uiNV)load("glProgramLocalParameterI4uiNV");
	fp_glProgramLocalParameterI4uivNV = (pfn_glProgramLocalParameterI4uivNV)load("glProgramLocalParameterI4uivNV");
	fp_glProgramLocalParametersI4uivNV = (pfn_glProgramLocalParametersI4uivNV)load("glProgramLocalParametersI4uivNV");
	fp_glProgramEnvParameterI4iNV = (pfn_glProgramEnvParameterI4iNV)load("glProgramEnvParameterI4iNV");
	fp_glProgramEnvParameterI4ivNV = (pfn_glProgramEnvParameterI4ivNV)load("glProgramEnvParameterI4ivNV");
	fp_glProgramEnvParametersI4ivNV = (pfn_glProgramEnvParametersI4ivNV)load("glProgramEnvParametersI4ivNV");
	fp_glProgramEnvParameterI4uiNV = (pfn_glProgramEnvParameterI4uiNV)load("glProgramEnvParameterI4uiNV");
	fp_glProgramEnvParameterI4uivNV = (pfn_glProgramEnvParameterI4uivNV)load("glProgramEnvParameterI4uivNV");
	fp_glProgramEnvParametersI4uivNV = (pfn_glProgramEnvParametersI4uivNV)load("glProgramEnvParametersI4uivNV");
	fp_glGetProgramLocalParameterIivNV = (pfn_glGetProgramLocalParameterIivNV)load("glGetProgramLocalParameterIivNV");
	fp_glGetProgramLocalParameterIuivNV = (pfn_glGetProgramLocalParameterIuivNV)load("glGetProgramLocalParameterIuivNV");
	fp_glGetProgramEnvParameterIivNV = (pfn_glGetProgramEnvParameterIivNV)load("glGetProgramEnvParameterIivNV");
	fp_glGetProgramEnvParameterIuivNV = (pfn_glGetProgramEnvParameterIuivNV)load("glGetProgramEnvParameterIuivNV");
}

GLboolean GLAD_NV_gpu_program5 = GL_FALSE;
static void load_GL_NV_gpu_program5(LOADER load) {
	if(!GLAD_NV_gpu_program5) return;
	fp_glProgramSubroutineParametersuivNV = (pfn_glProgramSubroutineParametersuivNV)load("glProgramSubroutineParametersuivNV");
	fp_glGetProgramSubroutineParameteruivNV = (pfn_glGetProgramSubroutineParameteruivNV)load("glGetProgramSubroutineParameteruivNV");
}

GLboolean GLAD_NV_gpu_program5_mem_extended = GL_FALSE;
GLboolean GLAD_NV_gpu_shader5 = GL_FALSE;
static void load_GL_NV_gpu_shader5(LOADER load) {
	if(!GLAD_NV_gpu_shader5) return;
	fp_glUniform1i64NV = (pfn_glUniform1i64NV)load("glUniform1i64NV");
	fp_glUniform2i64NV = (pfn_glUniform2i64NV)load("glUniform2i64NV");
	fp_glUniform3i64NV = (pfn_glUniform3i64NV)load("glUniform3i64NV");
	fp_glUniform4i64NV = (pfn_glUniform4i64NV)load("glUniform4i64NV");
	fp_glUniform1i64vNV = (pfn_glUniform1i64vNV)load("glUniform1i64vNV");
	fp_glUniform2i64vNV = (pfn_glUniform2i64vNV)load("glUniform2i64vNV");
	fp_glUniform3i64vNV = (pfn_glUniform3i64vNV)load("glUniform3i64vNV");
	fp_glUniform4i64vNV = (pfn_glUniform4i64vNV)load("glUniform4i64vNV");
	fp_glUniform1ui64NV = (pfn_glUniform1ui64NV)load("glUniform1ui64NV");
	fp_glUniform2ui64NV = (pfn_glUniform2ui64NV)load("glUniform2ui64NV");
	fp_glUniform3ui64NV = (pfn_glUniform3ui64NV)load("glUniform3ui64NV");
	fp_glUniform4ui64NV = (pfn_glUniform4ui64NV)load("glUniform4ui64NV");
	fp_glUniform1ui64vNV = (pfn_glUniform1ui64vNV)load("glUniform1ui64vNV");
	fp_glUniform2ui64vNV = (pfn_glUniform2ui64vNV)load("glUniform2ui64vNV");
	fp_glUniform3ui64vNV = (pfn_glUniform3ui64vNV)load("glUniform3ui64vNV");
	fp_glUniform4ui64vNV = (pfn_glUniform4ui64vNV)load("glUniform4ui64vNV");
	fp_glGetUniformi64vNV = (pfn_glGetUniformi64vNV)load("glGetUniformi64vNV");
	fp_glProgramUniform1i64NV = (pfn_glProgramUniform1i64NV)load("glProgramUniform1i64NV");
	fp_glProgramUniform2i64NV = (pfn_glProgramUniform2i64NV)load("glProgramUniform2i64NV");
	fp_glProgramUniform3i64NV = (pfn_glProgramUniform3i64NV)load("glProgramUniform3i64NV");
	fp_glProgramUniform4i64NV = (pfn_glProgramUniform4i64NV)load("glProgramUniform4i64NV");
	fp_glProgramUniform1i64vNV = (pfn_glProgramUniform1i64vNV)load("glProgramUniform1i64vNV");
	fp_glProgramUniform2i64vNV = (pfn_glProgramUniform2i64vNV)load("glProgramUniform2i64vNV");
	fp_glProgramUniform3i64vNV = (pfn_glProgramUniform3i64vNV)load("glProgramUniform3i64vNV");
	fp_glProgramUniform4i64vNV = (pfn_glProgramUniform4i64vNV)load("glProgramUniform4i64vNV");
	fp_glProgramUniform1ui64NV = (pfn_glProgramUniform1ui64NV)load("glProgramUniform1ui64NV");
	fp_glProgramUniform2ui64NV = (pfn_glProgramUniform2ui64NV)load("glProgramUniform2ui64NV");
	fp_glProgramUniform3ui64NV = (pfn_glProgramUniform3ui64NV)load("glProgramUniform3ui64NV");
	fp_glProgramUniform4ui64NV = (pfn_glProgramUniform4ui64NV)load("glProgramUniform4ui64NV");
	fp_glProgramUniform1ui64vNV = (pfn_glProgramUniform1ui64vNV)load("glProgramUniform1ui64vNV");
	fp_glProgramUniform2ui64vNV = (pfn_glProgramUniform2ui64vNV)load("glProgramUniform2ui64vNV");
	fp_glProgramUniform3ui64vNV = (pfn_glProgramUniform3ui64vNV)load("glProgramUniform3ui64vNV");
	fp_glProgramUniform4ui64vNV = (pfn_glProgramUniform4ui64vNV)load("glProgramUniform4ui64vNV");
}

GLboolean GLAD_NV_half_float = GL_FALSE;
static void load_GL_NV_half_float(LOADER load) {
	if(!GLAD_NV_half_float) return;
	fp_glVertex2hNV = (pfn_glVertex2hNV)load("glVertex2hNV");
	fp_glVertex2hvNV = (pfn_glVertex2hvNV)load("glVertex2hvNV");
	fp_glVertex3hNV = (pfn_glVertex3hNV)load("glVertex3hNV");
	fp_glVertex3hvNV = (pfn_glVertex3hvNV)load("glVertex3hvNV");
	fp_glVertex4hNV = (pfn_glVertex4hNV)load("glVertex4hNV");
	fp_glVertex4hvNV = (pfn_glVertex4hvNV)load("glVertex4hvNV");
	fp_glNormal3hNV = (pfn_glNormal3hNV)load("glNormal3hNV");
	fp_glNormal3hvNV = (pfn_glNormal3hvNV)load("glNormal3hvNV");
	fp_glColor3hNV = (pfn_glColor3hNV)load("glColor3hNV");
	fp_glColor3hvNV = (pfn_glColor3hvNV)load("glColor3hvNV");
	fp_glColor4hNV = (pfn_glColor4hNV)load("glColor4hNV");
	fp_glColor4hvNV = (pfn_glColor4hvNV)load("glColor4hvNV");
	fp_glTexCoord1hNV = (pfn_glTexCoord1hNV)load("glTexCoord1hNV");
	fp_glTexCoord1hvNV = (pfn_glTexCoord1hvNV)load("glTexCoord1hvNV");
	fp_glTexCoord2hNV = (pfn_glTexCoord2hNV)load("glTexCoord2hNV");
	fp_glTexCoord2hvNV = (pfn_glTexCoord2hvNV)load("glTexCoord2hvNV");
	fp_glTexCoord3hNV = (pfn_glTexCoord3hNV)load("glTexCoord3hNV");
	fp_glTexCoord3hvNV = (pfn_glTexCoord3hvNV)load("glTexCoord3hvNV");
	fp_glTexCoord4hNV = (pfn_glTexCoord4hNV)load("glTexCoord4hNV");
	fp_glTexCoord4hvNV = (pfn_glTexCoord4hvNV)load("glTexCoord4hvNV");
	fp_glMultiTexCoord1hNV = (pfn_glMultiTexCoord1hNV)load("glMultiTexCoord1hNV");
	fp_glMultiTexCoord1hvNV = (pfn_glMultiTexCoord1hvNV)load("glMultiTexCoord1hvNV");
	fp_glMultiTexCoord2hNV = (pfn_glMultiTexCoord2hNV)load("glMultiTexCoord2hNV");
	fp_glMultiTexCoord2hvNV = (pfn_glMultiTexCoord2hvNV)load("glMultiTexCoord2hvNV");
	fp_glMultiTexCoord3hNV = (pfn_glMultiTexCoord3hNV)load("glMultiTexCoord3hNV");
	fp_glMultiTexCoord3hvNV = (pfn_glMultiTexCoord3hvNV)load("glMultiTexCoord3hvNV");
	fp_glMultiTexCoord4hNV = (pfn_glMultiTexCoord4hNV)load("glMultiTexCoord4hNV");
	fp_glMultiTexCoord4hvNV = (pfn_glMultiTexCoord4hvNV)load("glMultiTexCoord4hvNV");
	fp_glFogCoordhNV = (pfn_glFogCoordhNV)load("glFogCoordhNV");
	fp_glFogCoordhvNV = (pfn_glFogCoordhvNV)load("glFogCoordhvNV");
	fp_glSecondaryColor3hNV = (pfn_glSecondaryColor3hNV)load("glSecondaryColor3hNV");
	fp_glSecondaryColor3hvNV = (pfn_glSecondaryColor3hvNV)load("glSecondaryColor3hvNV");
	fp_glVertexWeighthNV = (pfn_glVertexWeighthNV)load("glVertexWeighthNV");
	fp_glVertexWeighthvNV = (pfn_glVertexWeighthvNV)load("glVertexWeighthvNV");
	fp_glVertexAttrib1hNV = (pfn_glVertexAttrib1hNV)load("glVertexAttrib1hNV");
	fp_glVertexAttrib1hvNV = (pfn_glVertexAttrib1hvNV)load("glVertexAttrib1hvNV");
	fp_glVertexAttrib2hNV = (pfn_glVertexAttrib2hNV)load("glVertexAttrib2hNV");
	fp_glVertexAttrib2hvNV = (pfn_glVertexAttrib2hvNV)load("glVertexAttrib2hvNV");
	fp_glVertexAttrib3hNV = (pfn_glVertexAttrib3hNV)load("glVertexAttrib3hNV");
	fp_glVertexAttrib3hvNV = (pfn_glVertexAttrib3hvNV)load("glVertexAttrib3hvNV");
	fp_glVertexAttrib4hNV = (pfn_glVertexAttrib4hNV)load("glVertexAttrib4hNV");
	fp_glVertexAttrib4hvNV = (pfn_glVertexAttrib4hvNV)load("glVertexAttrib4hvNV");
	fp_glVertexAttribs1hvNV = (pfn_glVertexAttribs1hvNV)load("glVertexAttribs1hvNV");
	fp_glVertexAttribs2hvNV = (pfn_glVertexAttribs2hvNV)load("glVertexAttribs2hvNV");
	fp_glVertexAttribs3hvNV = (pfn_glVertexAttribs3hvNV)load("glVertexAttribs3hvNV");
	fp_glVertexAttribs4hvNV = (pfn_glVertexAttribs4hvNV)load("glVertexAttribs4hvNV");
}

GLboolean GLAD_NV_image_formats = GL_FALSE;
GLboolean GLAD_NV_instanced_arrays = GL_FALSE;
static void load_GL_NV_instanced_arrays(LOADER load) {
	if(!GLAD_NV_instanced_arrays) return;
	fp_glVertexAttribDivisorNV = (pfn_glVertexAttribDivisorNV)load("glVertexAttribDivisorNV");
}

GLboolean GLAD_NV_internalformat_sample_query = GL_FALSE;
static void load_GL_NV_internalformat_sample_query(LOADER load) {
	if(!GLAD_NV_internalformat_sample_query) return;
	fp_glGetInternalformatSampleivNV = (pfn_glGetInternalformatSampleivNV)load("glGetInternalformatSampleivNV");
}

GLboolean GLAD_NV_multisample_coverage = GL_FALSE;
GLboolean GLAD_NV_non_square_matrices = GL_FALSE;
static void load_GL_NV_non_square_matrices(LOADER load) {
	if(!GLAD_NV_non_square_matrices) return;
	fp_glUniformMatrix2x3fvNV = (pfn_glUniformMatrix2x3fvNV)load("glUniformMatrix2x3fvNV");
	fp_glUniformMatrix3x2fvNV = (pfn_glUniformMatrix3x2fvNV)load("glUniformMatrix3x2fvNV");
	fp_glUniformMatrix2x4fvNV = (pfn_glUniformMatrix2x4fvNV)load("glUniformMatrix2x4fvNV");
	fp_glUniformMatrix4x2fvNV = (pfn_glUniformMatrix4x2fvNV)load("glUniformMatrix4x2fvNV");
	fp_glUniformMatrix3x4fvNV = (pfn_glUniformMatrix3x4fvNV)load("glUniformMatrix3x4fvNV");
	fp_glUniformMatrix4x3fvNV = (pfn_glUniformMatrix4x3fvNV)load("glUniformMatrix4x3fvNV");
}

GLboolean GLAD_NV_occlusion_query = GL_FALSE;
static void load_GL_NV_occlusion_query(LOADER load) {
	if(!GLAD_NV_occlusion_query) return;
	fp_glGenOcclusionQueriesNV = (pfn_glGenOcclusionQueriesNV)load("glGenOcclusionQueriesNV");
	fp_glDeleteOcclusionQueriesNV = (pfn_glDeleteOcclusionQueriesNV)load("glDeleteOcclusionQueriesNV");
	fp_glIsOcclusionQueryNV = (pfn_glIsOcclusionQueryNV)load("glIsOcclusionQueryNV");
	fp_glBeginOcclusionQueryNV = (pfn_glBeginOcclusionQueryNV)load("glBeginOcclusionQueryNV");
	fp_glEndOcclusionQueryNV = (pfn_glEndOcclusionQueryNV)load("glEndOcclusionQueryNV");
	fp_glGetOcclusionQueryivNV = (pfn_glGetOcclusionQueryivNV)load("glGetOcclusionQueryivNV");
	fp_glGetOcclusionQueryuivNV = (pfn_glGetOcclusionQueryuivNV)load("glGetOcclusionQueryuivNV");
}

GLboolean GLAD_NV_parameter_buffer_object = GL_FALSE;
static void load_GL_NV_parameter_buffer_object(LOADER load) {
	if(!GLAD_NV_parameter_buffer_object) return;
	fp_glProgramBufferParametersfvNV = (pfn_glProgramBufferParametersfvNV)load("glProgramBufferParametersfvNV");
	fp_glProgramBufferParametersIivNV = (pfn_glProgramBufferParametersIivNV)load("glProgramBufferParametersIivNV");
	fp_glProgramBufferParametersIuivNV = (pfn_glProgramBufferParametersIuivNV)load("glProgramBufferParametersIuivNV");
}

GLboolean GLAD_NV_parameter_buffer_object2 = GL_FALSE;
GLboolean GLAD_NV_path_rendering = GL_FALSE;
static void load_GL_NV_path_rendering(LOADER load) {
	if(!GLAD_NV_path_rendering) return;
	fp_glGenPathsNV = (pfn_glGenPathsNV)load("glGenPathsNV");
	fp_glDeletePathsNV = (pfn_glDeletePathsNV)load("glDeletePathsNV");
	fp_glIsPathNV = (pfn_glIsPathNV)load("glIsPathNV");
	fp_glPathCommandsNV = (pfn_glPathCommandsNV)load("glPathCommandsNV");
	fp_glPathCoordsNV = (pfn_glPathCoordsNV)load("glPathCoordsNV");
	fp_glPathSubCommandsNV = (pfn_glPathSubCommandsNV)load("glPathSubCommandsNV");
	fp_glPathSubCoordsNV = (pfn_glPathSubCoordsNV)load("glPathSubCoordsNV");
	fp_glPathStringNV = (pfn_glPathStringNV)load("glPathStringNV");
	fp_glPathGlyphsNV = (pfn_glPathGlyphsNV)load("glPathGlyphsNV");
	fp_glPathGlyphRangeNV = (pfn_glPathGlyphRangeNV)load("glPathGlyphRangeNV");
	fp_glWeightPathsNV = (pfn_glWeightPathsNV)load("glWeightPathsNV");
	fp_glCopyPathNV = (pfn_glCopyPathNV)load("glCopyPathNV");
	fp_glInterpolatePathsNV = (pfn_glInterpolatePathsNV)load("glInterpolatePathsNV");
	fp_glTransformPathNV = (pfn_glTransformPathNV)load("glTransformPathNV");
	fp_glPathParameterivNV = (pfn_glPathParameterivNV)load("glPathParameterivNV");
	fp_glPathParameteriNV = (pfn_glPathParameteriNV)load("glPathParameteriNV");
	fp_glPathParameterfvNV = (pfn_glPathParameterfvNV)load("glPathParameterfvNV");
	fp_glPathParameterfNV = (pfn_glPathParameterfNV)load("glPathParameterfNV");
	fp_glPathDashArrayNV = (pfn_glPathDashArrayNV)load("glPathDashArrayNV");
	fp_glPathStencilFuncNV = (pfn_glPathStencilFuncNV)load("glPathStencilFuncNV");
	fp_glPathStencilDepthOffsetNV = (pfn_glPathStencilDepthOffsetNV)load("glPathStencilDepthOffsetNV");
	fp_glStencilFillPathNV = (pfn_glStencilFillPathNV)load("glStencilFillPathNV");
	fp_glStencilStrokePathNV = (pfn_glStencilStrokePathNV)load("glStencilStrokePathNV");
	fp_glStencilFillPathInstancedNV = (pfn_glStencilFillPathInstancedNV)load("glStencilFillPathInstancedNV");
	fp_glStencilStrokePathInstancedNV = (pfn_glStencilStrokePathInstancedNV)load("glStencilStrokePathInstancedNV");
	fp_glPathCoverDepthFuncNV = (pfn_glPathCoverDepthFuncNV)load("glPathCoverDepthFuncNV");
	fp_glCoverFillPathNV = (pfn_glCoverFillPathNV)load("glCoverFillPathNV");
	fp_glCoverStrokePathNV = (pfn_glCoverStrokePathNV)load("glCoverStrokePathNV");
	fp_glCoverFillPathInstancedNV = (pfn_glCoverFillPathInstancedNV)load("glCoverFillPathInstancedNV");
	fp_glCoverStrokePathInstancedNV = (pfn_glCoverStrokePathInstancedNV)load("glCoverStrokePathInstancedNV");
	fp_glGetPathParameterivNV = (pfn_glGetPathParameterivNV)load("glGetPathParameterivNV");
	fp_glGetPathParameterfvNV = (pfn_glGetPathParameterfvNV)load("glGetPathParameterfvNV");
	fp_glGetPathCommandsNV = (pfn_glGetPathCommandsNV)load("glGetPathCommandsNV");
	fp_glGetPathCoordsNV = (pfn_glGetPathCoordsNV)load("glGetPathCoordsNV");
	fp_glGetPathDashArrayNV = (pfn_glGetPathDashArrayNV)load("glGetPathDashArrayNV");
	fp_glGetPathMetricsNV = (pfn_glGetPathMetricsNV)load("glGetPathMetricsNV");
	fp_glGetPathMetricRangeNV = (pfn_glGetPathMetricRangeNV)load("glGetPathMetricRangeNV");
	fp_glGetPathSpacingNV = (pfn_glGetPathSpacingNV)load("glGetPathSpacingNV");
	fp_glIsPointInFillPathNV = (pfn_glIsPointInFillPathNV)load("glIsPointInFillPathNV");
	fp_glIsPointInStrokePathNV = (pfn_glIsPointInStrokePathNV)load("glIsPointInStrokePathNV");
	fp_glGetPathLengthNV = (pfn_glGetPathLengthNV)load("glGetPathLengthNV");
	fp_glPointAlongPathNV = (pfn_glPointAlongPathNV)load("glPointAlongPathNV");
	fp_glMatrixLoad3x2fNV = (pfn_glMatrixLoad3x2fNV)load("glMatrixLoad3x2fNV");
	fp_glMatrixLoad3x3fNV = (pfn_glMatrixLoad3x3fNV)load("glMatrixLoad3x3fNV");
	fp_glMatrixLoadTranspose3x3fNV = (pfn_glMatrixLoadTranspose3x3fNV)load("glMatrixLoadTranspose3x3fNV");
	fp_glMatrixMult3x2fNV = (pfn_glMatrixMult3x2fNV)load("glMatrixMult3x2fNV");
	fp_glMatrixMult3x3fNV = (pfn_glMatrixMult3x3fNV)load("glMatrixMult3x3fNV");
	fp_glMatrixMultTranspose3x3fNV = (pfn_glMatrixMultTranspose3x3fNV)load("glMatrixMultTranspose3x3fNV");
	fp_glStencilThenCoverFillPathNV = (pfn_glStencilThenCoverFillPathNV)load("glStencilThenCoverFillPathNV");
	fp_glStencilThenCoverStrokePathNV = (pfn_glStencilThenCoverStrokePathNV)load("glStencilThenCoverStrokePathNV");
	fp_glStencilThenCoverFillPathInstancedNV = (pfn_glStencilThenCoverFillPathInstancedNV)load("glStencilThenCoverFillPathInstancedNV");
	fp_glStencilThenCoverStrokePathInstancedNV = (pfn_glStencilThenCoverStrokePathInstancedNV)load("glStencilThenCoverStrokePathInstancedNV");
	fp_glPathGlyphIndexRangeNV = (pfn_glPathGlyphIndexRangeNV)load("glPathGlyphIndexRangeNV");
	fp_glPathGlyphIndexArrayNV = (pfn_glPathGlyphIndexArrayNV)load("glPathGlyphIndexArrayNV");
	fp_glPathMemoryGlyphIndexArrayNV = (pfn_glPathMemoryGlyphIndexArrayNV)load("glPathMemoryGlyphIndexArrayNV");
	fp_glProgramPathFragmentInputGenNV = (pfn_glProgramPathFragmentInputGenNV)load("glProgramPathFragmentInputGenNV");
	fp_glGetProgramResourcefvNV = (pfn_glGetProgramResourcefvNV)load("glGetProgramResourcefvNV");
	fp_glPathColorGenNV = (pfn_glPathColorGenNV)load("glPathColorGenNV");
	fp_glPathTexGenNV = (pfn_glPathTexGenNV)load("glPathTexGenNV");
	fp_glPathFogGenNV = (pfn_glPathFogGenNV)load("glPathFogGenNV");
	fp_glGetPathColorGenivNV = (pfn_glGetPathColorGenivNV)load("glGetPathColorGenivNV");
	fp_glGetPathColorGenfvNV = (pfn_glGetPathColorGenfvNV)load("glGetPathColorGenfvNV");
	fp_glGetPathTexGenivNV = (pfn_glGetPathTexGenivNV)load("glGetPathTexGenivNV");
	fp_glGetPathTexGenfvNV = (pfn_glGetPathTexGenfvNV)load("glGetPathTexGenfvNV");
}

GLboolean GLAD_NV_path_rendering_shared_edge = GL_FALSE;
GLboolean GLAD_NV_polygon_mode = GL_FALSE;
static void load_GL_NV_polygon_mode(LOADER load) {
	if(!GLAD_NV_polygon_mode) return;
	fp_glPolygonModeNV = (pfn_glPolygonModeNV)load("glPolygonModeNV");
}

GLboolean GLAD_NV_present_video = GL_FALSE;
static void load_GL_NV_present_video(LOADER load) {
	if(!GLAD_NV_present_video) return;
	fp_glPresentFrameKeyedNV = (pfn_glPresentFrameKeyedNV)load("glPresentFrameKeyedNV");
	fp_glPresentFrameDualFillNV = (pfn_glPresentFrameDualFillNV)load("glPresentFrameDualFillNV");
	fp_glGetVideoivNV = (pfn_glGetVideoivNV)load("glGetVideoivNV");
	fp_glGetVideouivNV = (pfn_glGetVideouivNV)load("glGetVideouivNV");
	fp_glGetVideoi64vNV = (pfn_glGetVideoi64vNV)load("glGetVideoi64vNV");
	fp_glGetVideoui64vNV = (pfn_glGetVideoui64vNV)load("glGetVideoui64vNV");
}

GLboolean GLAD_NV_primitive_restart = GL_FALSE;
static void load_GL_NV_primitive_restart(LOADER load) {
	if(!GLAD_NV_primitive_restart) return;
	fp_glPrimitiveRestartNV = (pfn_glPrimitiveRestartNV)load("glPrimitiveRestartNV");
	fp_glPrimitiveRestartIndexNV = (pfn_glPrimitiveRestartIndexNV)load("glPrimitiveRestartIndexNV");
}

GLboolean GLAD_NV_read_buffer = GL_FALSE;
static void load_GL_NV_read_buffer(LOADER load) {
	if(!GLAD_NV_read_buffer) return;
	fp_glReadBufferNV = (pfn_glReadBufferNV)load("glReadBufferNV");
}

GLboolean GLAD_NV_read_buffer_front = GL_FALSE;
GLboolean GLAD_NV_read_depth = GL_FALSE;
GLboolean GLAD_NV_read_depth_stencil = GL_FALSE;
GLboolean GLAD_NV_read_stencil = GL_FALSE;
GLboolean GLAD_NV_sample_locations = GL_FALSE;
static void load_GL_NV_sample_locations(LOADER load) {
	if(!GLAD_NV_sample_locations) return;
	fp_glFramebufferSampleLocationsfvNV = (pfn_glFramebufferSampleLocationsfvNV)load("glFramebufferSampleLocationsfvNV");
	fp_glNamedFramebufferSampleLocationsfvNV = (pfn_glNamedFramebufferSampleLocationsfvNV)load("glNamedFramebufferSampleLocationsfvNV");
	fp_glResolveDepthValuesNV = (pfn_glResolveDepthValuesNV)load("glResolveDepthValuesNV");
}

GLboolean GLAD_NV_sample_mask_override_coverage = GL_FALSE;
GLboolean GLAD_NV_shader_atomic_counters = GL_FALSE;
GLboolean GLAD_NV_shader_atomic_float = GL_FALSE;
GLboolean GLAD_NV_shader_atomic_fp16_vector = GL_FALSE;
GLboolean GLAD_NV_shader_atomic_int64 = GL_FALSE;
GLboolean GLAD_NV_shader_buffer_load = GL_FALSE;
static void load_GL_NV_shader_buffer_load(LOADER load) {
	if(!GLAD_NV_shader_buffer_load) return;
	fp_glMakeBufferResidentNV = (pfn_glMakeBufferResidentNV)load("glMakeBufferResidentNV");
	fp_glMakeBufferNonResidentNV = (pfn_glMakeBufferNonResidentNV)load("glMakeBufferNonResidentNV");
	fp_glIsBufferResidentNV = (pfn_glIsBufferResidentNV)load("glIsBufferResidentNV");
	fp_glMakeNamedBufferResidentNV = (pfn_glMakeNamedBufferResidentNV)load("glMakeNamedBufferResidentNV");
	fp_glMakeNamedBufferNonResidentNV = (pfn_glMakeNamedBufferNonResidentNV)load("glMakeNamedBufferNonResidentNV");
	fp_glIsNamedBufferResidentNV = (pfn_glIsNamedBufferResidentNV)load("glIsNamedBufferResidentNV");
	fp_glGetBufferParameterui64vNV = (pfn_glGetBufferParameterui64vNV)load("glGetBufferParameterui64vNV");
	fp_glGetNamedBufferParameterui64vNV = (pfn_glGetNamedBufferParameterui64vNV)load("glGetNamedBufferParameterui64vNV");
	fp_glGetIntegerui64vNV = (pfn_glGetIntegerui64vNV)load("glGetIntegerui64vNV");
	fp_glUniformui64NV = (pfn_glUniformui64NV)load("glUniformui64NV");
	fp_glUniformui64vNV = (pfn_glUniformui64vNV)load("glUniformui64vNV");
	fp_glGetUniformui64vNV = (pfn_glGetUniformui64vNV)load("glGetUniformui64vNV");
	fp_glProgramUniformui64NV = (pfn_glProgramUniformui64NV)load("glProgramUniformui64NV");
	fp_glProgramUniformui64vNV = (pfn_glProgramUniformui64vNV)load("glProgramUniformui64vNV");
}

GLboolean GLAD_NV_shader_buffer_store = GL_FALSE;
GLboolean GLAD_NV_shader_noperspective_interpolation = GL_FALSE;
GLboolean GLAD_NV_shader_storage_buffer_object = GL_FALSE;
GLboolean GLAD_NV_shader_thread_group = GL_FALSE;
GLboolean GLAD_NV_shader_thread_shuffle = GL_FALSE;
GLboolean GLAD_NV_shadow_samplers_array = GL_FALSE;
GLboolean GLAD_NV_shadow_samplers_cube = GL_FALSE;
GLboolean GLAD_NV_sRGB_formats = GL_FALSE;
GLboolean GLAD_NV_tessellation_program5 = GL_FALSE;
GLboolean GLAD_NV_texture_barrier = GL_FALSE;
static void load_GL_NV_texture_barrier(LOADER load) {
	if(!GLAD_NV_texture_barrier) return;
	fp_glTextureBarrierNV = (pfn_glTextureBarrierNV)load("glTextureBarrierNV");
}

GLboolean GLAD_NV_texture_border_clamp = GL_FALSE;
GLboolean GLAD_NV_texture_compression_s3tc_update = GL_FALSE;
GLboolean GLAD_NV_texture_multisample = GL_FALSE;
static void load_GL_NV_texture_multisample(LOADER load) {
	if(!GLAD_NV_texture_multisample) return;
	fp_glTexImage2DMultisampleCoverageNV = (pfn_glTexImage2DMultisampleCoverageNV)load("glTexImage2DMultisampleCoverageNV");
	fp_glTexImage3DMultisampleCoverageNV = (pfn_glTexImage3DMultisampleCoverageNV)load("glTexImage3DMultisampleCoverageNV");
	fp_glTextureImage2DMultisampleNV = (pfn_glTextureImage2DMultisampleNV)load("glTextureImage2DMultisampleNV");
	fp_glTextureImage3DMultisampleNV = (pfn_glTextureImage3DMultisampleNV)load("glTextureImage3DMultisampleNV");
	fp_glTextureImage2DMultisampleCoverageNV = (pfn_glTextureImage2DMultisampleCoverageNV)load("glTextureImage2DMultisampleCoverageNV");
	fp_glTextureImage3DMultisampleCoverageNV = (pfn_glTextureImage3DMultisampleCoverageNV)load("glTextureImage3DMultisampleCoverageNV");
}

GLboolean GLAD_NV_texture_npot_2D_mipmap = GL_FALSE;
GLboolean GLAD_NV_transform_feedback = GL_FALSE;
static void load_GL_NV_transform_feedback(LOADER load) {
	if(!GLAD_NV_transform_feedback) return;
	fp_glBeginTransformFeedbackNV = (pfn_glBeginTransformFeedbackNV)load("glBeginTransformFeedbackNV");
	fp_glEndTransformFeedbackNV = (pfn_glEndTransformFeedbackNV)load("glEndTransformFeedbackNV");
	fp_glTransformFeedbackAttribsNV = (pfn_glTransformFeedbackAttribsNV)load("glTransformFeedbackAttribsNV");
	fp_glBindBufferRangeNV = (pfn_glBindBufferRangeNV)load("glBindBufferRangeNV");
	fp_glBindBufferOffsetNV = (pfn_glBindBufferOffsetNV)load("glBindBufferOffsetNV");
	fp_glBindBufferBaseNV = (pfn_glBindBufferBaseNV)load("glBindBufferBaseNV");
	fp_glTransformFeedbackVaryingsNV = (pfn_glTransformFeedbackVaryingsNV)load("glTransformFeedbackVaryingsNV");
	fp_glActiveVaryingNV = (pfn_glActiveVaryingNV)load("glActiveVaryingNV");
	fp_glGetVaryingLocationNV = (pfn_glGetVaryingLocationNV)load("glGetVaryingLocationNV");
	fp_glGetActiveVaryingNV = (pfn_glGetActiveVaryingNV)load("glGetActiveVaryingNV");
	fp_glGetTransformFeedbackVaryingNV = (pfn_glGetTransformFeedbackVaryingNV)load("glGetTransformFeedbackVaryingNV");
	fp_glTransformFeedbackStreamAttribsNV = (pfn_glTransformFeedbackStreamAttribsNV)load("glTransformFeedbackStreamAttribsNV");
}

GLboolean GLAD_NV_transform_feedback2 = GL_FALSE;
static void load_GL_NV_transform_feedback2(LOADER load) {
	if(!GLAD_NV_transform_feedback2) return;
	fp_glBindTransformFeedbackNV = (pfn_glBindTransformFeedbackNV)load("glBindTransformFeedbackNV");
	fp_glDeleteTransformFeedbacksNV = (pfn_glDeleteTransformFeedbacksNV)load("glDeleteTransformFeedbacksNV");
	fp_glGenTransformFeedbacksNV = (pfn_glGenTransformFeedbacksNV)load("glGenTransformFeedbacksNV");
	fp_glIsTransformFeedbackNV = (pfn_glIsTransformFeedbackNV)load("glIsTransformFeedbackNV");
	fp_glPauseTransformFeedbackNV = (pfn_glPauseTransformFeedbackNV)load("glPauseTransformFeedbackNV");
	fp_glResumeTransformFeedbackNV = (pfn_glResumeTransformFeedbackNV)load("glResumeTransformFeedbackNV");
	fp_glDrawTransformFeedbackNV = (pfn_glDrawTransformFeedbackNV)load("glDrawTransformFeedbackNV");
}

GLboolean GLAD_NV_uniform_buffer_unified_memory = GL_FALSE;
GLboolean GLAD_NV_vdpau_interop = GL_FALSE;
static void load_GL_NV_vdpau_interop(LOADER load) {
	if(!GLAD_NV_vdpau_interop) return;
	fp_glVDPAUInitNV = (pfn_glVDPAUInitNV)load("glVDPAUInitNV");
	fp_glVDPAUFiniNV = (pfn_glVDPAUFiniNV)load("glVDPAUFiniNV");
	fp_glVDPAURegisterVideoSurfaceNV = (pfn_glVDPAURegisterVideoSurfaceNV)load("glVDPAURegisterVideoSurfaceNV");
	fp_glVDPAURegisterOutputSurfaceNV = (pfn_glVDPAURegisterOutputSurfaceNV)load("glVDPAURegisterOutputSurfaceNV");
	fp_glVDPAUIsSurfaceNV = (pfn_glVDPAUIsSurfaceNV)load("glVDPAUIsSurfaceNV");
	fp_glVDPAUUnregisterSurfaceNV = (pfn_glVDPAUUnregisterSurfaceNV)load("glVDPAUUnregisterSurfaceNV");
	fp_glVDPAUGetSurfaceivNV = (pfn_glVDPAUGetSurfaceivNV)load("glVDPAUGetSurfaceivNV");
	fp_glVDPAUSurfaceAccessNV = (pfn_glVDPAUSurfaceAccessNV)load("glVDPAUSurfaceAccessNV");
	fp_glVDPAUMapSurfacesNV = (pfn_glVDPAUMapSurfacesNV)load("glVDPAUMapSurfacesNV");
	fp_glVDPAUUnmapSurfacesNV = (pfn_glVDPAUUnmapSurfacesNV)load("glVDPAUUnmapSurfacesNV");
}

GLboolean GLAD_NV_vertex_attrib_integer_64bit = GL_FALSE;
static void load_GL_NV_vertex_attrib_integer_64bit(LOADER load) {
	if(!GLAD_NV_vertex_attrib_integer_64bit) return;
	fp_glVertexAttribL1i64NV = (pfn_glVertexAttribL1i64NV)load("glVertexAttribL1i64NV");
	fp_glVertexAttribL2i64NV = (pfn_glVertexAttribL2i64NV)load("glVertexAttribL2i64NV");
	fp_glVertexAttribL3i64NV = (pfn_glVertexAttribL3i64NV)load("glVertexAttribL3i64NV");
	fp_glVertexAttribL4i64NV = (pfn_glVertexAttribL4i64NV)load("glVertexAttribL4i64NV");
	fp_glVertexAttribL1i64vNV = (pfn_glVertexAttribL1i64vNV)load("glVertexAttribL1i64vNV");
	fp_glVertexAttribL2i64vNV = (pfn_glVertexAttribL2i64vNV)load("glVertexAttribL2i64vNV");
	fp_glVertexAttribL3i64vNV = (pfn_glVertexAttribL3i64vNV)load("glVertexAttribL3i64vNV");
	fp_glVertexAttribL4i64vNV = (pfn_glVertexAttribL4i64vNV)load("glVertexAttribL4i64vNV");
	fp_glVertexAttribL1ui64NV = (pfn_glVertexAttribL1ui64NV)load("glVertexAttribL1ui64NV");
	fp_glVertexAttribL2ui64NV = (pfn_glVertexAttribL2ui64NV)load("glVertexAttribL2ui64NV");
	fp_glVertexAttribL3ui64NV = (pfn_glVertexAttribL3ui64NV)load("glVertexAttribL3ui64NV");
	fp_glVertexAttribL4ui64NV = (pfn_glVertexAttribL4ui64NV)load("glVertexAttribL4ui64NV");
	fp_glVertexAttribL1ui64vNV = (pfn_glVertexAttribL1ui64vNV)load("glVertexAttribL1ui64vNV");
	fp_glVertexAttribL2ui64vNV = (pfn_glVertexAttribL2ui64vNV)load("glVertexAttribL2ui64vNV");
	fp_glVertexAttribL3ui64vNV = (pfn_glVertexAttribL3ui64vNV)load("glVertexAttribL3ui64vNV");
	fp_glVertexAttribL4ui64vNV = (pfn_glVertexAttribL4ui64vNV)load("glVertexAttribL4ui64vNV");
	fp_glGetVertexAttribLi64vNV = (pfn_glGetVertexAttribLi64vNV)load("glGetVertexAttribLi64vNV");
	fp_glGetVertexAttribLui64vNV = (pfn_glGetVertexAttribLui64vNV)load("glGetVertexAttribLui64vNV");
	fp_glVertexAttribLFormatNV = (pfn_glVertexAttribLFormatNV)load("glVertexAttribLFormatNV");
}

GLboolean GLAD_NV_vertex_buffer_unified_memory = GL_FALSE;
static void load_GL_NV_vertex_buffer_unified_memory(LOADER load) {
	if(!GLAD_NV_vertex_buffer_unified_memory) return;
	fp_glBufferAddressRangeNV = (pfn_glBufferAddressRangeNV)load("glBufferAddressRangeNV");
	fp_glVertexFormatNV = (pfn_glVertexFormatNV)load("glVertexFormatNV");
	fp_glNormalFormatNV = (pfn_glNormalFormatNV)load("glNormalFormatNV");
	fp_glColorFormatNV = (pfn_glColorFormatNV)load("glColorFormatNV");
	fp_glIndexFormatNV = (pfn_glIndexFormatNV)load("glIndexFormatNV");
	fp_glTexCoordFormatNV = (pfn_glTexCoordFormatNV)load("glTexCoordFormatNV");
	fp_glEdgeFlagFormatNV = (pfn_glEdgeFlagFormatNV)load("glEdgeFlagFormatNV");
	fp_glSecondaryColorFormatNV = (pfn_glSecondaryColorFormatNV)load("glSecondaryColorFormatNV");
	fp_glFogCoordFormatNV = (pfn_glFogCoordFormatNV)load("glFogCoordFormatNV");
	fp_glVertexAttribFormatNV = (pfn_glVertexAttribFormatNV)load("glVertexAttribFormatNV");
	fp_glVertexAttribIFormatNV = (pfn_glVertexAttribIFormatNV)load("glVertexAttribIFormatNV");
	fp_glGetIntegerui64i_vNV = (pfn_glGetIntegerui64i_vNV)load("glGetIntegerui64i_vNV");
}

GLboolean GLAD_NV_vertex_program4 = GL_FALSE;
static void load_GL_NV_vertex_program4(LOADER load) {
	if(!GLAD_NV_vertex_program4) return;
	fp_glVertexAttribI1iEXT = (pfn_glVertexAttribI1iEXT)load("glVertexAttribI1iEXT");
	fp_glVertexAttribI2iEXT = (pfn_glVertexAttribI2iEXT)load("glVertexAttribI2iEXT");
	fp_glVertexAttribI3iEXT = (pfn_glVertexAttribI3iEXT)load("glVertexAttribI3iEXT");
	fp_glVertexAttribI4iEXT = (pfn_glVertexAttribI4iEXT)load("glVertexAttribI4iEXT");
	fp_glVertexAttribI1uiEXT = (pfn_glVertexAttribI1uiEXT)load("glVertexAttribI1uiEXT");
	fp_glVertexAttribI2uiEXT = (pfn_glVertexAttribI2uiEXT)load("glVertexAttribI2uiEXT");
	fp_glVertexAttribI3uiEXT = (pfn_glVertexAttribI3uiEXT)load("glVertexAttribI3uiEXT");
	fp_glVertexAttribI4uiEXT = (pfn_glVertexAttribI4uiEXT)load("glVertexAttribI4uiEXT");
	fp_glVertexAttribI1ivEXT = (pfn_glVertexAttribI1ivEXT)load("glVertexAttribI1ivEXT");
	fp_glVertexAttribI2ivEXT = (pfn_glVertexAttribI2ivEXT)load("glVertexAttribI2ivEXT");
	fp_glVertexAttribI3ivEXT = (pfn_glVertexAttribI3ivEXT)load("glVertexAttribI3ivEXT");
	fp_glVertexAttribI4ivEXT = (pfn_glVertexAttribI4ivEXT)load("glVertexAttribI4ivEXT");
	fp_glVertexAttribI1uivEXT = (pfn_glVertexAttribI1uivEXT)load("glVertexAttribI1uivEXT");
	fp_glVertexAttribI2uivEXT = (pfn_glVertexAttribI2uivEXT)load("glVertexAttribI2uivEXT");
	fp_glVertexAttribI3uivEXT = (pfn_glVertexAttribI3uivEXT)load("glVertexAttribI3uivEXT");
	fp_glVertexAttribI4uivEXT = (pfn_glVertexAttribI4uivEXT)load("glVertexAttribI4uivEXT");
	fp_glVertexAttribI4bvEXT = (pfn_glVertexAttribI4bvEXT)load("glVertexAttribI4bvEXT");
	fp_glVertexAttribI4svEXT = (pfn_glVertexAttribI4svEXT)load("glVertexAttribI4svEXT");
	fp_glVertexAttribI4ubvEXT = (pfn_glVertexAttribI4ubvEXT)load("glVertexAttribI4ubvEXT");
	fp_glVertexAttribI4usvEXT = (pfn_glVertexAttribI4usvEXT)load("glVertexAttribI4usvEXT");
	fp_glVertexAttribIPointerEXT = (pfn_glVertexAttribIPointerEXT)load("glVertexAttribIPointerEXT");
	fp_glGetVertexAttribIivEXT = (pfn_glGetVertexAttribIivEXT)load("glGetVertexAttribIivEXT");
	fp_glGetVertexAttribIuivEXT = (pfn_glGetVertexAttribIuivEXT)load("glGetVertexAttribIuivEXT");
}

GLboolean GLAD_NV_video_capture = GL_FALSE;
static void load_GL_NV_video_capture(LOADER load) {
	if(!GLAD_NV_video_capture) return;
	fp_glBeginVideoCaptureNV = (pfn_glBeginVideoCaptureNV)load("glBeginVideoCaptureNV");
	fp_glBindVideoCaptureStreamBufferNV = (pfn_glBindVideoCaptureStreamBufferNV)load("glBindVideoCaptureStreamBufferNV");
	fp_glBindVideoCaptureStreamTextureNV = (pfn_glBindVideoCaptureStreamTextureNV)load("glBindVideoCaptureStreamTextureNV");
	fp_glEndVideoCaptureNV = (pfn_glEndVideoCaptureNV)load("glEndVideoCaptureNV");
	fp_glGetVideoCaptureivNV = (pfn_glGetVideoCaptureivNV)load("glGetVideoCaptureivNV");
	fp_glGetVideoCaptureStreamivNV = (pfn_glGetVideoCaptureStreamivNV)load("glGetVideoCaptureStreamivNV");
	fp_glGetVideoCaptureStreamfvNV = (pfn_glGetVideoCaptureStreamfvNV)load("glGetVideoCaptureStreamfvNV");
	fp_glGetVideoCaptureStreamdvNV = (pfn_glGetVideoCaptureStreamdvNV)load("glGetVideoCaptureStreamdvNV");
	fp_glVideoCaptureNV = (pfn_glVideoCaptureNV)load("glVideoCaptureNV");
	fp_glVideoCaptureStreamParameterivNV = (pfn_glVideoCaptureStreamParameterivNV)load("glVideoCaptureStreamParameterivNV");
	fp_glVideoCaptureStreamParameterfvNV = (pfn_glVideoCaptureStreamParameterfvNV)load("glVideoCaptureStreamParameterfvNV");
	fp_glVideoCaptureStreamParameterdvNV = (pfn_glVideoCaptureStreamParameterdvNV)load("glVideoCaptureStreamParameterdvNV");
}

GLboolean GLAD_NV_viewport_array = GL_FALSE;
static void load_GL_NV_viewport_array(LOADER load) {
	if(!GLAD_NV_viewport_array) return;
	fp_glViewportArrayvNV = (pfn_glViewportArrayvNV)load("glViewportArrayvNV");
	fp_glViewportIndexedfNV = (pfn_glViewportIndexedfNV)load("glViewportIndexedfNV");
	fp_glViewportIndexedfvNV = (pfn_glViewportIndexedfvNV)load("glViewportIndexedfvNV");
	fp_glScissorArrayvNV = (pfn_glScissorArrayvNV)load("glScissorArrayvNV");
	fp_glScissorIndexedNV = (pfn_glScissorIndexedNV)load("glScissorIndexedNV");
	fp_glScissorIndexedvNV = (pfn_glScissorIndexedvNV)load("glScissorIndexedvNV");
	fp_glDepthRangeArrayfvNV = (pfn_glDepthRangeArrayfvNV)load("glDepthRangeArrayfvNV");
	fp_glDepthRangeIndexedfNV = (pfn_glDepthRangeIndexedfNV)load("glDepthRangeIndexedfNV");
	fp_glGetFloati_vNV = (pfn_glGetFloati_vNV)load("glGetFloati_vNV");
	fp_glEnableiNV = (pfn_glEnableiNV)load("glEnableiNV");
	fp_glDisableiNV = (pfn_glDisableiNV)load("glDisableiNV");
	fp_glIsEnablediNV = (pfn_glIsEnablediNV)load("glIsEnablediNV");
}

GLboolean GLAD_NV_viewport_array2 = GL_FALSE;
GLboolean GLAD_NVX_conditional_render = GL_FALSE;
static void load_GL_NVX_conditional_render(LOADER load) {
	if(!GLAD_NVX_conditional_render) return;
	fp_glBeginConditionalRenderNVX = (pfn_glBeginConditionalRenderNVX)load("glBeginConditionalRenderNVX");
	fp_glEndConditionalRenderNVX = (pfn_glEndConditionalRenderNVX)load("glEndConditionalRenderNVX");
}

GLboolean GLAD_NVX_gpu_memory_info = GL_FALSE;
GLboolean GLAD_OVR_multiview = GL_FALSE;
static void load_GL_OVR_multiview(LOADER load) {
	if(!GLAD_OVR_multiview) return;
	fp_glFramebufferTextureMultiviewOVR = (pfn_glFramebufferTextureMultiviewOVR)load("glFramebufferTextureMultiviewOVR");
}

GLboolean GLAD_OVR_multiview2 = GL_FALSE;
GLboolean GLAD_OVR_multiview_multisampled_render_to_texture = GL_FALSE;
static void load_GL_OVR_multiview_multisampled_render_to_texture(LOADER load) {
	if(!GLAD_OVR_multiview_multisampled_render_to_texture) return;
	fp_glFramebufferTextureMultisampleMultiviewOVR = (pfn_glFramebufferTextureMultisampleMultiviewOVR)load("glFramebufferTextureMultisampleMultiviewOVR");
}

GLboolean GLAD_QCOM_alpha_test = GL_FALSE;
static void load_GL_QCOM_alpha_test(LOADER load) {
	if(!GLAD_QCOM_alpha_test) return;
	fp_glAlphaFuncQCOM = (pfn_glAlphaFuncQCOM)load("glAlphaFuncQCOM");
}

GLboolean GLAD_QCOM_binning_control = GL_FALSE;
GLboolean GLAD_QCOM_driver_control = GL_FALSE;
static void load_GL_QCOM_driver_control(LOADER load) {
	if(!GLAD_QCOM_driver_control) return;
	fp_glGetDriverControlsQCOM = (pfn_glGetDriverControlsQCOM)load("glGetDriverControlsQCOM");
	fp_glGetDriverControlStringQCOM = (pfn_glGetDriverControlStringQCOM)load("glGetDriverControlStringQCOM");
	fp_glEnableDriverControlQCOM = (pfn_glEnableDriverControlQCOM)load("glEnableDriverControlQCOM");
	fp_glDisableDriverControlQCOM = (pfn_glDisableDriverControlQCOM)load("glDisableDriverControlQCOM");
}

GLboolean GLAD_QCOM_extended_get = GL_FALSE;
static void load_GL_QCOM_extended_get(LOADER load) {
	if(!GLAD_QCOM_extended_get) return;
	fp_glExtGetTexturesQCOM = (pfn_glExtGetTexturesQCOM)load("glExtGetTexturesQCOM");
	fp_glExtGetBuffersQCOM = (pfn_glExtGetBuffersQCOM)load("glExtGetBuffersQCOM");
	fp_glExtGetRenderbuffersQCOM = (pfn_glExtGetRenderbuffersQCOM)load("glExtGetRenderbuffersQCOM");
	fp_glExtGetFramebuffersQCOM = (pfn_glExtGetFramebuffersQCOM)load("glExtGetFramebuffersQCOM");
	fp_glExtGetTexLevelParameterivQCOM = (pfn_glExtGetTexLevelParameterivQCOM)load("glExtGetTexLevelParameterivQCOM");
	fp_glExtTexObjectStateOverrideiQCOM = (pfn_glExtTexObjectStateOverrideiQCOM)load("glExtTexObjectStateOverrideiQCOM");
	fp_glExtGetTexSubImageQCOM = (pfn_glExtGetTexSubImageQCOM)load("glExtGetTexSubImageQCOM");
	fp_glExtGetBufferPointervQCOM = (pfn_glExtGetBufferPointervQCOM)load("glExtGetBufferPointervQCOM");
}

GLboolean GLAD_QCOM_extended_get2 = GL_FALSE;
static void load_GL_QCOM_extended_get2(LOADER load) {
	if(!GLAD_QCOM_extended_get2) return;
	fp_glExtGetShadersQCOM = (pfn_glExtGetShadersQCOM)load("glExtGetShadersQCOM");
	fp_glExtGetProgramsQCOM = (pfn_glExtGetProgramsQCOM)load("glExtGetProgramsQCOM");
	fp_glExtIsProgramBinaryQCOM = (pfn_glExtIsProgramBinaryQCOM)load("glExtIsProgramBinaryQCOM");
	fp_glExtGetProgramBinarySourceQCOM = (pfn_glExtGetProgramBinarySourceQCOM)load("glExtGetProgramBinarySourceQCOM");
}

GLboolean GLAD_QCOM_perfmon_global_mode = GL_FALSE;
GLboolean GLAD_QCOM_tiled_rendering = GL_FALSE;
static void load_GL_QCOM_tiled_rendering(LOADER load) {
	if(!GLAD_QCOM_tiled_rendering) return;
	fp_glStartTilingQCOM = (pfn_glStartTilingQCOM)load("glStartTilingQCOM");
	fp_glEndTilingQCOM = (pfn_glEndTilingQCOM)load("glEndTilingQCOM");
}

GLboolean GLAD_QCOM_writeonly_rendering = GL_FALSE;
GLboolean GLAD_VIV_shader_binary = GL_FALSE;
static void find_extensions(void) {
	GLAD_KHR_blend_equation_advanced = has_ext("GL_KHR_blend_equation_advanced");
	GLAD_KHR_blend_equation_advanced_coherent = has_ext("GL_KHR_blend_equation_advanced_coherent");
	GLAD_KHR_context_flush_control = has_ext("GL_KHR_context_flush_control");
	GLAD_KHR_debug = has_ext("GL_KHR_debug");
	GLAD_KHR_no_error = has_ext("GL_KHR_no_error");
	GLAD_KHR_robust_buffer_access_behavior = has_ext("GL_KHR_robust_buffer_access_behavior");
	GLAD_KHR_robustness = has_ext("GL_KHR_robustness");
	GLAD_KHR_texture_compression_astc_hdr = has_ext("GL_KHR_texture_compression_astc_hdr");
	GLAD_KHR_texture_compression_astc_ldr = has_ext("GL_KHR_texture_compression_astc_ldr");
	GLAD_KHR_texture_compression_astc_sliced_3d = has_ext("GL_KHR_texture_compression_astc_sliced_3d");
	GLAD_ARB_arrays_of_arrays = has_ext("GL_ARB_arrays_of_arrays");
	GLAD_ARB_base_instance = has_ext("GL_ARB_base_instance");
	GLAD_ARB_bindless_texture = has_ext("GL_ARB_bindless_texture");
	GLAD_ARB_blend_func_extended = has_ext("GL_ARB_blend_func_extended");
	GLAD_ARB_buffer_storage = has_ext("GL_ARB_buffer_storage");
	GLAD_ARB_cl_event = has_ext("GL_ARB_cl_event");
	GLAD_ARB_clear_buffer_object = has_ext("GL_ARB_clear_buffer_object");
	GLAD_ARB_clear_texture = has_ext("GL_ARB_clear_texture");
	GLAD_ARB_clip_control = has_ext("GL_ARB_clip_control");
	GLAD_ARB_color_buffer_float = has_ext("GL_ARB_color_buffer_float");
	GLAD_ARB_compatibility = has_ext("GL_ARB_compatibility");
	GLAD_ARB_compressed_texture_pixel_storage = has_ext("GL_ARB_compressed_texture_pixel_storage");
	GLAD_ARB_compute_shader = has_ext("GL_ARB_compute_shader");
	GLAD_ARB_compute_variable_group_size = has_ext("GL_ARB_compute_variable_group_size");
	GLAD_ARB_conditional_render_inverted = has_ext("GL_ARB_conditional_render_inverted");
	GLAD_ARB_conservative_depth = has_ext("GL_ARB_conservative_depth");
	GLAD_ARB_copy_buffer = has_ext("GL_ARB_copy_buffer");
	GLAD_ARB_copy_image = has_ext("GL_ARB_copy_image");
	GLAD_ARB_cull_distance = has_ext("GL_ARB_cull_distance");
	GLAD_ARB_debug_output = has_ext("GL_ARB_debug_output");
	GLAD_ARB_depth_buffer_float = has_ext("GL_ARB_depth_buffer_float");
	GLAD_ARB_depth_clamp = has_ext("GL_ARB_depth_clamp");
	GLAD_ARB_derivative_control = has_ext("GL_ARB_derivative_control");
	GLAD_ARB_direct_state_access = has_ext("GL_ARB_direct_state_access");
	GLAD_ARB_draw_buffers_blend = has_ext("GL_ARB_draw_buffers_blend");
	GLAD_ARB_draw_elements_base_vertex = has_ext("GL_ARB_draw_elements_base_vertex");
	GLAD_ARB_draw_indirect = has_ext("GL_ARB_draw_indirect");
	GLAD_ARB_draw_instanced = has_ext("GL_ARB_draw_instanced");
	GLAD_ARB_enhanced_layouts = has_ext("GL_ARB_enhanced_layouts");
	GLAD_ARB_ES2_compatibility = has_ext("GL_ARB_ES2_compatibility");
	GLAD_ARB_ES3_1_compatibility = has_ext("GL_ARB_ES3_1_compatibility");
	GLAD_ARB_ES3_2_compatibility = has_ext("GL_ARB_ES3_2_compatibility");
	GLAD_ARB_ES3_compatibility = has_ext("GL_ARB_ES3_compatibility");
	GLAD_ARB_explicit_attrib_location = has_ext("GL_ARB_explicit_attrib_location");
	GLAD_ARB_explicit_uniform_location = has_ext("GL_ARB_explicit_uniform_location");
	GLAD_ARB_fragment_coord_conventions = has_ext("GL_ARB_fragment_coord_conventions");
	GLAD_ARB_fragment_layer_viewport = has_ext("GL_ARB_fragment_layer_viewport");
	GLAD_ARB_fragment_shader_interlock = has_ext("GL_ARB_fragment_shader_interlock");
	GLAD_ARB_framebuffer_no_attachments = has_ext("GL_ARB_framebuffer_no_attachments");
	GLAD_ARB_framebuffer_object = has_ext("GL_ARB_framebuffer_object");
	GLAD_ARB_framebuffer_sRGB = has_ext("GL_ARB_framebuffer_sRGB");
	GLAD_ARB_geometry_shader4 = has_ext("GL_ARB_geometry_shader4");
	GLAD_ARB_get_program_binary = has_ext("GL_ARB_get_program_binary");
	GLAD_ARB_get_texture_sub_image = has_ext("GL_ARB_get_texture_sub_image");
	GLAD_ARB_gpu_shader5 = has_ext("GL_ARB_gpu_shader5");
	GLAD_ARB_gpu_shader_fp64 = has_ext("GL_ARB_gpu_shader_fp64");
	GLAD_ARB_gpu_shader_int64 = has_ext("GL_ARB_gpu_shader_int64");
	GLAD_ARB_half_float_pixel = has_ext("GL_ARB_half_float_pixel");
	GLAD_ARB_half_float_vertex = has_ext("GL_ARB_half_float_vertex");
	GLAD_ARB_indirect_parameters = has_ext("GL_ARB_indirect_parameters");
	GLAD_ARB_instanced_arrays = has_ext("GL_ARB_instanced_arrays");
	GLAD_ARB_internalformat_query = has_ext("GL_ARB_internalformat_query");
	GLAD_ARB_internalformat_query2 = has_ext("GL_ARB_internalformat_query2");
	GLAD_ARB_invalidate_subdata = has_ext("GL_ARB_invalidate_subdata");
	GLAD_ARB_map_buffer_alignment = has_ext("GL_ARB_map_buffer_alignment");
	GLAD_ARB_map_buffer_range = has_ext("GL_ARB_map_buffer_range");
	GLAD_ARB_multi_bind = has_ext("GL_ARB_multi_bind");
	GLAD_ARB_multi_draw_indirect = has_ext("GL_ARB_multi_draw_indirect");
	GLAD_ARB_occlusion_query2 = has_ext("GL_ARB_occlusion_query2");
	GLAD_ARB_parallel_shader_compile = has_ext("GL_ARB_parallel_shader_compile");
	GLAD_ARB_pipeline_statistics_query = has_ext("GL_ARB_pipeline_statistics_query");
	GLAD_ARB_pixel_buffer_object = has_ext("GL_ARB_pixel_buffer_object");
	GLAD_ARB_post_depth_coverage = has_ext("GL_ARB_post_depth_coverage");
	GLAD_ARB_program_interface_query = has_ext("GL_ARB_program_interface_query");
	GLAD_ARB_provoking_vertex = has_ext("GL_ARB_provoking_vertex");
	GLAD_ARB_query_buffer_object = has_ext("GL_ARB_query_buffer_object");
	GLAD_ARB_robust_buffer_access_behavior = has_ext("GL_ARB_robust_buffer_access_behavior");
	GLAD_ARB_robustness = has_ext("GL_ARB_robustness");
	GLAD_ARB_robustness_isolation = has_ext("GL_ARB_robustness_isolation");
	GLAD_ARB_sample_locations = has_ext("GL_ARB_sample_locations");
	GLAD_ARB_sample_shading = has_ext("GL_ARB_sample_shading");
	GLAD_ARB_sampler_objects = has_ext("GL_ARB_sampler_objects");
	GLAD_ARB_seamless_cube_map = has_ext("GL_ARB_seamless_cube_map");
	GLAD_ARB_seamless_cubemap_per_texture = has_ext("GL_ARB_seamless_cubemap_per_texture");
	GLAD_ARB_separate_shader_objects = has_ext("GL_ARB_separate_shader_objects");
	GLAD_ARB_shader_atomic_counter_ops = has_ext("GL_ARB_shader_atomic_counter_ops");
	GLAD_ARB_shader_atomic_counters = has_ext("GL_ARB_shader_atomic_counters");
	GLAD_ARB_shader_ballot = has_ext("GL_ARB_shader_ballot");
	GLAD_ARB_shader_bit_encoding = has_ext("GL_ARB_shader_bit_encoding");
	GLAD_ARB_shader_clock = has_ext("GL_ARB_shader_clock");
	GLAD_ARB_shader_draw_parameters = has_ext("GL_ARB_shader_draw_parameters");
	GLAD_ARB_shader_group_vote = has_ext("GL_ARB_shader_group_vote");
	GLAD_ARB_shader_image_load_store = has_ext("GL_ARB_shader_image_load_store");
	GLAD_ARB_shader_image_size = has_ext("GL_ARB_shader_image_size");
	GLAD_ARB_shader_precision = has_ext("GL_ARB_shader_precision");
	GLAD_ARB_shader_stencil_export = has_ext("GL_ARB_shader_stencil_export");
	GLAD_ARB_shader_storage_buffer_object = has_ext("GL_ARB_shader_storage_buffer_object");
	GLAD_ARB_shader_subroutine = has_ext("GL_ARB_shader_subroutine");
	GLAD_ARB_shader_texture_image_samples = has_ext("GL_ARB_shader_texture_image_samples");
	GLAD_ARB_shader_texture_lod = has_ext("GL_ARB_shader_texture_lod");
	GLAD_ARB_shader_viewport_layer_array = has_ext("GL_ARB_shader_viewport_layer_array");
	GLAD_ARB_shading_language_420pack = has_ext("GL_ARB_shading_language_420pack");
	GLAD_ARB_shading_language_include = has_ext("GL_ARB_shading_language_include");
	GLAD_ARB_shading_language_packing = has_ext("GL_ARB_shading_language_packing");
	GLAD_ARB_sparse_buffer = has_ext("GL_ARB_sparse_buffer");
	GLAD_ARB_sparse_texture = has_ext("GL_ARB_sparse_texture");
	GLAD_ARB_sparse_texture2 = has_ext("GL_ARB_sparse_texture2");
	GLAD_ARB_sparse_texture_clamp = has_ext("GL_ARB_sparse_texture_clamp");
	GLAD_ARB_stencil_texturing = has_ext("GL_ARB_stencil_texturing");
	GLAD_ARB_sync = has_ext("GL_ARB_sync");
	GLAD_ARB_tessellation_shader = has_ext("GL_ARB_tessellation_shader");
	GLAD_ARB_texture_barrier = has_ext("GL_ARB_texture_barrier");
	GLAD_ARB_texture_buffer_object = has_ext("GL_ARB_texture_buffer_object");
	GLAD_ARB_texture_buffer_object_rgb32 = has_ext("GL_ARB_texture_buffer_object_rgb32");
	GLAD_ARB_texture_buffer_range = has_ext("GL_ARB_texture_buffer_range");
	GLAD_ARB_texture_compression_bptc = has_ext("GL_ARB_texture_compression_bptc");
	GLAD_ARB_texture_compression_rgtc = has_ext("GL_ARB_texture_compression_rgtc");
	GLAD_ARB_texture_cube_map_array = has_ext("GL_ARB_texture_cube_map_array");
	GLAD_ARB_texture_filter_minmax = has_ext("GL_ARB_texture_filter_minmax");
	GLAD_ARB_texture_float = has_ext("GL_ARB_texture_float");
	GLAD_ARB_texture_gather = has_ext("GL_ARB_texture_gather");
	GLAD_ARB_texture_mirror_clamp_to_edge = has_ext("GL_ARB_texture_mirror_clamp_to_edge");
	GLAD_ARB_texture_multisample = has_ext("GL_ARB_texture_multisample");
	GLAD_ARB_texture_query_levels = has_ext("GL_ARB_texture_query_levels");
	GLAD_ARB_texture_query_lod = has_ext("GL_ARB_texture_query_lod");
	GLAD_ARB_texture_rectangle = has_ext("GL_ARB_texture_rectangle");
	GLAD_ARB_texture_rg = has_ext("GL_ARB_texture_rg");
	GLAD_ARB_texture_rgb10_a2ui = has_ext("GL_ARB_texture_rgb10_a2ui");
	GLAD_ARB_texture_stencil8 = has_ext("GL_ARB_texture_stencil8");
	GLAD_ARB_texture_storage = has_ext("GL_ARB_texture_storage");
	GLAD_ARB_texture_storage_multisample = has_ext("GL_ARB_texture_storage_multisample");
	GLAD_ARB_texture_swizzle = has_ext("GL_ARB_texture_swizzle");
	GLAD_ARB_texture_view = has_ext("GL_ARB_texture_view");
	GLAD_ARB_timer_query = has_ext("GL_ARB_timer_query");
	GLAD_ARB_transform_feedback2 = has_ext("GL_ARB_transform_feedback2");
	GLAD_ARB_transform_feedback3 = has_ext("GL_ARB_transform_feedback3");
	GLAD_ARB_transform_feedback_instanced = has_ext("GL_ARB_transform_feedback_instanced");
	GLAD_ARB_transform_feedback_overflow_query = has_ext("GL_ARB_transform_feedback_overflow_query");
	GLAD_ARB_uniform_buffer_object = has_ext("GL_ARB_uniform_buffer_object");
	GLAD_ARB_vertex_array_bgra = has_ext("GL_ARB_vertex_array_bgra");
	GLAD_ARB_vertex_array_object = has_ext("GL_ARB_vertex_array_object");
	GLAD_ARB_vertex_attrib_64bit = has_ext("GL_ARB_vertex_attrib_64bit");
	GLAD_ARB_vertex_attrib_binding = has_ext("GL_ARB_vertex_attrib_binding");
	GLAD_ARB_vertex_type_10f_11f_11f_rev = has_ext("GL_ARB_vertex_type_10f_11f_11f_rev");
	GLAD_ARB_vertex_type_2_10_10_10_rev = has_ext("GL_ARB_vertex_type_2_10_10_10_rev");
	GLAD_ARB_viewport_array = has_ext("GL_ARB_viewport_array");
	GLAD_EXT_base_instance = has_ext("GL_EXT_base_instance");
	GLAD_EXT_bgra = has_ext("GL_EXT_bgra");
	GLAD_EXT_bindable_uniform = has_ext("GL_EXT_bindable_uniform");
	GLAD_EXT_blend_func_extended = has_ext("GL_EXT_blend_func_extended");
	GLAD_EXT_blend_minmax = has_ext("GL_EXT_blend_minmax");
	GLAD_EXT_buffer_storage = has_ext("GL_EXT_buffer_storage");
	GLAD_EXT_color_buffer_float = has_ext("GL_EXT_color_buffer_float");
	GLAD_EXT_color_buffer_half_float = has_ext("GL_EXT_color_buffer_half_float");
	GLAD_EXT_copy_image = has_ext("GL_EXT_copy_image");
	GLAD_EXT_debug_label = has_ext("GL_EXT_debug_label");
	GLAD_EXT_debug_marker = has_ext("GL_EXT_debug_marker");
	GLAD_EXT_direct_state_access = has_ext("GL_EXT_direct_state_access");
	GLAD_EXT_discard_framebuffer = has_ext("GL_EXT_discard_framebuffer");
	GLAD_EXT_disjoint_timer_query = has_ext("GL_EXT_disjoint_timer_query");
	GLAD_EXT_draw_buffers = has_ext("GL_EXT_draw_buffers");
	GLAD_EXT_draw_buffers2 = has_ext("GL_EXT_draw_buffers2");
	GLAD_EXT_draw_buffers_indexed = has_ext("GL_EXT_draw_buffers_indexed");
	GLAD_EXT_draw_elements_base_vertex = has_ext("GL_EXT_draw_elements_base_vertex");
	GLAD_EXT_draw_instanced = has_ext("GL_EXT_draw_instanced");
	GLAD_EXT_float_blend = has_ext("GL_EXT_float_blend");
	GLAD_EXT_framebuffer_blit = has_ext("GL_EXT_framebuffer_blit");
	GLAD_EXT_framebuffer_multisample = has_ext("GL_EXT_framebuffer_multisample");
	GLAD_EXT_framebuffer_multisample_blit_scaled = has_ext("GL_EXT_framebuffer_multisample_blit_scaled");
	GLAD_EXT_framebuffer_object = has_ext("GL_EXT_framebuffer_object");
	GLAD_EXT_framebuffer_sRGB = has_ext("GL_EXT_framebuffer_sRGB");
	GLAD_EXT_geometry_point_size = has_ext("GL_EXT_geometry_point_size");
	GLAD_EXT_geometry_shader = has_ext("GL_EXT_geometry_shader");
	GLAD_EXT_geometry_shader4 = has_ext("GL_EXT_geometry_shader4");
	GLAD_EXT_gpu_program_parameters = has_ext("GL_EXT_gpu_program_parameters");
	GLAD_EXT_gpu_shader4 = has_ext("GL_EXT_gpu_shader4");
	GLAD_EXT_gpu_shader5 = has_ext("GL_EXT_gpu_shader5");
	GLAD_EXT_instanced_arrays = has_ext("GL_EXT_instanced_arrays");
	GLAD_EXT_map_buffer_range = has_ext("GL_EXT_map_buffer_range");
	GLAD_EXT_multi_draw_indirect = has_ext("GL_EXT_multi_draw_indirect");
	GLAD_EXT_multisampled_compatibility = has_ext("GL_EXT_multisampled_compatibility");
	GLAD_EXT_multisampled_render_to_texture = has_ext("GL_EXT_multisampled_render_to_texture");
	GLAD_EXT_multiview_draw_buffers = has_ext("GL_EXT_multiview_draw_buffers");
	GLAD_EXT_occlusion_query_boolean = has_ext("GL_EXT_occlusion_query_boolean");
	GLAD_EXT_packed_depth_stencil = has_ext("GL_EXT_packed_depth_stencil");
	GLAD_EXT_packed_float = has_ext("GL_EXT_packed_float");
	GLAD_EXT_pixel_buffer_object = has_ext("GL_EXT_pixel_buffer_object");
	GLAD_EXT_polygon_offset_clamp = has_ext("GL_EXT_polygon_offset_clamp");
	GLAD_EXT_post_depth_coverage = has_ext("GL_EXT_post_depth_coverage");
	GLAD_EXT_primitive_bounding_box = has_ext("GL_EXT_primitive_bounding_box");
	GLAD_EXT_provoking_vertex = has_ext("GL_EXT_provoking_vertex");
	GLAD_EXT_pvrtc_sRGB = has_ext("GL_EXT_pvrtc_sRGB");
	GLAD_EXT_raster_multisample = has_ext("GL_EXT_raster_multisample");
	GLAD_EXT_read_format_bgra = has_ext("GL_EXT_read_format_bgra");
	GLAD_EXT_render_snorm = has_ext("GL_EXT_render_snorm");
	GLAD_EXT_robustness = has_ext("GL_EXT_robustness");
	GLAD_EXT_separate_shader_objects = has_ext("GL_EXT_separate_shader_objects");
	GLAD_EXT_shader_framebuffer_fetch = has_ext("GL_EXT_shader_framebuffer_fetch");
	GLAD_EXT_shader_image_load_formatted = has_ext("GL_EXT_shader_image_load_formatted");
	GLAD_EXT_shader_image_load_store = has_ext("GL_EXT_shader_image_load_store");
	GLAD_EXT_shader_implicit_conversions = has_ext("GL_EXT_shader_implicit_conversions");
	GLAD_EXT_shader_integer_mix = has_ext("GL_EXT_shader_integer_mix");
	GLAD_EXT_shader_io_blocks = has_ext("GL_EXT_shader_io_blocks");
	GLAD_EXT_shader_pixel_local_storage = has_ext("GL_EXT_shader_pixel_local_storage");
	GLAD_EXT_shader_texture_lod = has_ext("GL_EXT_shader_texture_lod");
	GLAD_EXT_shadow_samplers = has_ext("GL_EXT_shadow_samplers");
	GLAD_EXT_sparse_texture = has_ext("GL_EXT_sparse_texture");
	GLAD_EXT_sparse_texture2 = has_ext("GL_EXT_sparse_texture2");
	GLAD_EXT_sRGB = has_ext("GL_EXT_sRGB");
	GLAD_EXT_sRGB_write_control = has_ext("GL_EXT_sRGB_write_control");
	GLAD_EXT_stencil_clear_tag = has_ext("GL_EXT_stencil_clear_tag");
	GLAD_EXT_tessellation_point_size = has_ext("GL_EXT_tessellation_point_size");
	GLAD_EXT_tessellation_shader = has_ext("GL_EXT_tessellation_shader");
	GLAD_EXT_texture_array = has_ext("GL_EXT_texture_array");
	GLAD_EXT_texture_border_clamp = has_ext("GL_EXT_texture_border_clamp");
	GLAD_EXT_texture_buffer = has_ext("GL_EXT_texture_buffer");
	GLAD_EXT_texture_buffer_object = has_ext("GL_EXT_texture_buffer_object");
	GLAD_EXT_texture_compression_dxt1 = has_ext("GL_EXT_texture_compression_dxt1");
	GLAD_EXT_texture_compression_latc = has_ext("GL_EXT_texture_compression_latc");
	GLAD_EXT_texture_compression_rgtc = has_ext("GL_EXT_texture_compression_rgtc");
	GLAD_EXT_texture_compression_s3tc = has_ext("GL_EXT_texture_compression_s3tc");
	GLAD_EXT_texture_cube_map = has_ext("GL_EXT_texture_cube_map");
	GLAD_EXT_texture_cube_map_array = has_ext("GL_EXT_texture_cube_map_array");
	GLAD_EXT_texture_filter_anisotropic = has_ext("GL_EXT_texture_filter_anisotropic");
	GLAD_EXT_texture_filter_minmax = has_ext("GL_EXT_texture_filter_minmax");
	GLAD_EXT_texture_format_BGRA8888 = has_ext("GL_EXT_texture_format_BGRA8888");
	GLAD_EXT_texture_integer = has_ext("GL_EXT_texture_integer");
	GLAD_EXT_texture_norm16 = has_ext("GL_EXT_texture_norm16");
	GLAD_EXT_texture_rg = has_ext("GL_EXT_texture_rg");
	GLAD_EXT_texture_shared_exponent = has_ext("GL_EXT_texture_shared_exponent");
	GLAD_EXT_texture_snorm = has_ext("GL_EXT_texture_snorm");
	GLAD_EXT_texture_sRGB = has_ext("GL_EXT_texture_sRGB");
	GLAD_EXT_texture_sRGB_decode = has_ext("GL_EXT_texture_sRGB_decode");
	GLAD_EXT_texture_sRGB_R8 = has_ext("GL_EXT_texture_sRGB_R8");
	GLAD_EXT_texture_sRGB_RG8 = has_ext("GL_EXT_texture_sRGB_RG8");
	GLAD_EXT_texture_storage = has_ext("GL_EXT_texture_storage");
	GLAD_EXT_texture_swizzle = has_ext("GL_EXT_texture_swizzle");
	GLAD_EXT_texture_type_2_10_10_10_REV = has_ext("GL_EXT_texture_type_2_10_10_10_REV");
	GLAD_EXT_texture_view = has_ext("GL_EXT_texture_view");
	GLAD_EXT_timer_query = has_ext("GL_EXT_timer_query");
	GLAD_EXT_transform_feedback = has_ext("GL_EXT_transform_feedback");
	GLAD_EXT_unpack_subimage = has_ext("GL_EXT_unpack_subimage");
	GLAD_EXT_vertex_array_bgra = has_ext("GL_EXT_vertex_array_bgra");
	GLAD_EXT_vertex_attrib_64bit = has_ext("GL_EXT_vertex_attrib_64bit");
	GLAD_EXT_x11_sync_object = has_ext("GL_EXT_x11_sync_object");
	GLAD_EXT_YUV_target = has_ext("GL_EXT_YUV_target");
	GLAD_OES_compressed_ETC1_RGB8_sub_texture = has_ext("GL_OES_compressed_ETC1_RGB8_sub_texture");
	GLAD_OES_compressed_ETC1_RGB8_texture = has_ext("GL_OES_compressed_ETC1_RGB8_texture");
	GLAD_OES_copy_image = has_ext("GL_OES_copy_image");
	GLAD_OES_depth24 = has_ext("GL_OES_depth24");
	GLAD_OES_depth32 = has_ext("GL_OES_depth32");
	GLAD_OES_depth_texture = has_ext("GL_OES_depth_texture");
	GLAD_OES_draw_buffers_indexed = has_ext("GL_OES_draw_buffers_indexed");
	GLAD_OES_draw_elements_base_vertex = has_ext("GL_OES_draw_elements_base_vertex");
	GLAD_OES_EGL_image = has_ext("GL_OES_EGL_image");
	GLAD_OES_EGL_image_external = has_ext("GL_OES_EGL_image_external");
	GLAD_OES_EGL_image_external_essl3 = has_ext("GL_OES_EGL_image_external_essl3");
	GLAD_OES_element_index_uint = has_ext("GL_OES_element_index_uint");
	GLAD_OES_fbo_render_mipmap = has_ext("GL_OES_fbo_render_mipmap");
	GLAD_OES_fragment_precision_high = has_ext("GL_OES_fragment_precision_high");
	GLAD_OES_geometry_point_size = has_ext("GL_OES_geometry_point_size");
	GLAD_OES_geometry_shader = has_ext("GL_OES_geometry_shader");
	GLAD_OES_get_program_binary = has_ext("GL_OES_get_program_binary");
	GLAD_OES_gpu_shader5 = has_ext("GL_OES_gpu_shader5");
	GLAD_OES_mapbuffer = has_ext("GL_OES_mapbuffer");
	GLAD_OES_packed_depth_stencil = has_ext("GL_OES_packed_depth_stencil");
	GLAD_OES_primitive_bounding_box = has_ext("GL_OES_primitive_bounding_box");
	GLAD_OES_required_internalformat = has_ext("GL_OES_required_internalformat");
	GLAD_OES_rgb8_rgba8 = has_ext("GL_OES_rgb8_rgba8");
	GLAD_OES_sample_shading = has_ext("GL_OES_sample_shading");
	GLAD_OES_sample_variables = has_ext("GL_OES_sample_variables");
	GLAD_OES_shader_image_atomic = has_ext("GL_OES_shader_image_atomic");
	GLAD_OES_shader_io_blocks = has_ext("GL_OES_shader_io_blocks");
	GLAD_OES_shader_multisample_interpolation = has_ext("GL_OES_shader_multisample_interpolation");
	GLAD_OES_standard_derivatives = has_ext("GL_OES_standard_derivatives");
	GLAD_OES_stencil1 = has_ext("GL_OES_stencil1");
	GLAD_OES_stencil4 = has_ext("GL_OES_stencil4");
	GLAD_OES_surfaceless_context = has_ext("GL_OES_surfaceless_context");
	GLAD_OES_tessellation_point_size = has_ext("GL_OES_tessellation_point_size");
	GLAD_OES_tessellation_shader = has_ext("GL_OES_tessellation_shader");
	GLAD_OES_texture_3D = has_ext("GL_OES_texture_3D");
	GLAD_OES_texture_border_clamp = has_ext("GL_OES_texture_border_clamp");
	GLAD_OES_texture_buffer = has_ext("GL_OES_texture_buffer");
	GLAD_OES_texture_compression_astc = has_ext("GL_OES_texture_compression_astc");
	GLAD_OES_texture_cube_map_array = has_ext("GL_OES_texture_cube_map_array");
	GLAD_OES_texture_float = has_ext("GL_OES_texture_float");
	GLAD_OES_texture_float_linear = has_ext("GL_OES_texture_float_linear");
	GLAD_OES_texture_half_float = has_ext("GL_OES_texture_half_float");
	GLAD_OES_texture_half_float_linear = has_ext("GL_OES_texture_half_float_linear");
	GLAD_OES_texture_npot = has_ext("GL_OES_texture_npot");
	GLAD_OES_texture_stencil8 = has_ext("GL_OES_texture_stencil8");
	GLAD_OES_texture_storage_multisample_2d_array = has_ext("GL_OES_texture_storage_multisample_2d_array");
	GLAD_OES_texture_view = has_ext("GL_OES_texture_view");
	GLAD_OES_vertex_array_object = has_ext("GL_OES_vertex_array_object");
	GLAD_OES_vertex_half_float = has_ext("GL_OES_vertex_half_float");
	GLAD_OES_vertex_type_10_10_10_2 = has_ext("GL_OES_vertex_type_10_10_10_2");
	GLAD_AMD_blend_minmax_factor = has_ext("GL_AMD_blend_minmax_factor");
	GLAD_AMD_compressed_3DC_texture = has_ext("GL_AMD_compressed_3DC_texture");
	GLAD_AMD_compressed_ATC_texture = has_ext("GL_AMD_compressed_ATC_texture");
	GLAD_AMD_conservative_depth = has_ext("GL_AMD_conservative_depth");
	GLAD_AMD_debug_output = has_ext("GL_AMD_debug_output");
	GLAD_AMD_depth_clamp_separate = has_ext("GL_AMD_depth_clamp_separate");
	GLAD_AMD_draw_buffers_blend = has_ext("GL_AMD_draw_buffers_blend");
	GLAD_AMD_gcn_shader = has_ext("GL_AMD_gcn_shader");
	GLAD_AMD_gpu_shader_int64 = has_ext("GL_AMD_gpu_shader_int64");
	GLAD_AMD_interleaved_elements = has_ext("GL_AMD_interleaved_elements");
	GLAD_AMD_multi_draw_indirect = has_ext("GL_AMD_multi_draw_indirect");
	GLAD_AMD_name_gen_delete = has_ext("GL_AMD_name_gen_delete");
	GLAD_AMD_occlusion_query_event = has_ext("GL_AMD_occlusion_query_event");
	GLAD_AMD_performance_monitor = has_ext("GL_AMD_performance_monitor");
	GLAD_AMD_pinned_memory = has_ext("GL_AMD_pinned_memory");
	GLAD_AMD_program_binary_Z400 = has_ext("GL_AMD_program_binary_Z400");
	GLAD_AMD_query_buffer_object = has_ext("GL_AMD_query_buffer_object");
	GLAD_AMD_sample_positions = has_ext("GL_AMD_sample_positions");
	GLAD_AMD_seamless_cubemap_per_texture = has_ext("GL_AMD_seamless_cubemap_per_texture");
	GLAD_AMD_shader_atomic_counter_ops = has_ext("GL_AMD_shader_atomic_counter_ops");
	GLAD_AMD_shader_stencil_export = has_ext("GL_AMD_shader_stencil_export");
	GLAD_AMD_shader_trinary_minmax = has_ext("GL_AMD_shader_trinary_minmax");
	GLAD_AMD_sparse_texture = has_ext("GL_AMD_sparse_texture");
	GLAD_AMD_stencil_operation_extended = has_ext("GL_AMD_stencil_operation_extended");
	GLAD_AMD_texture_texture4 = has_ext("GL_AMD_texture_texture4");
	GLAD_AMD_transform_feedback3_lines_triangles = has_ext("GL_AMD_transform_feedback3_lines_triangles");
	GLAD_AMD_transform_feedback4 = has_ext("GL_AMD_transform_feedback4");
	GLAD_AMD_vertex_shader_layer = has_ext("GL_AMD_vertex_shader_layer");
	GLAD_AMD_vertex_shader_tessellator = has_ext("GL_AMD_vertex_shader_tessellator");
	GLAD_AMD_vertex_shader_viewport_index = has_ext("GL_AMD_vertex_shader_viewport_index");
	GLAD_ANDROID_extension_pack_es31a = has_ext("GL_ANDROID_extension_pack_es31a");
	GLAD_ANGLE_depth_texture = has_ext("GL_ANGLE_depth_texture");
	GLAD_ANGLE_framebuffer_blit = has_ext("GL_ANGLE_framebuffer_blit");
	GLAD_ANGLE_framebuffer_multisample = has_ext("GL_ANGLE_framebuffer_multisample");
	GLAD_ANGLE_instanced_arrays = has_ext("GL_ANGLE_instanced_arrays");
	GLAD_ANGLE_pack_reverse_row_order = has_ext("GL_ANGLE_pack_reverse_row_order");
	GLAD_ANGLE_program_binary = has_ext("GL_ANGLE_program_binary");
	GLAD_ANGLE_texture_compression_dxt3 = has_ext("GL_ANGLE_texture_compression_dxt3");
	GLAD_ANGLE_texture_compression_dxt5 = has_ext("GL_ANGLE_texture_compression_dxt5");
	GLAD_ANGLE_texture_usage = has_ext("GL_ANGLE_texture_usage");
	GLAD_ANGLE_translated_shader_source = has_ext("GL_ANGLE_translated_shader_source");
	GLAD_APPLE_aux_depth_stencil = has_ext("GL_APPLE_aux_depth_stencil");
	GLAD_APPLE_client_storage = has_ext("GL_APPLE_client_storage");
	GLAD_APPLE_clip_distance = has_ext("GL_APPLE_clip_distance");
	GLAD_APPLE_color_buffer_packed_float = has_ext("GL_APPLE_color_buffer_packed_float");
	GLAD_APPLE_copy_texture_levels = has_ext("GL_APPLE_copy_texture_levels");
	GLAD_APPLE_element_array = has_ext("GL_APPLE_element_array");
	GLAD_APPLE_fence = has_ext("GL_APPLE_fence");
	GLAD_APPLE_float_pixels = has_ext("GL_APPLE_float_pixels");
	GLAD_APPLE_flush_buffer_range = has_ext("GL_APPLE_flush_buffer_range");
	GLAD_APPLE_framebuffer_multisample = has_ext("GL_APPLE_framebuffer_multisample");
	GLAD_APPLE_object_purgeable = has_ext("GL_APPLE_object_purgeable");
	GLAD_APPLE_rgb_422 = has_ext("GL_APPLE_rgb_422");
	GLAD_APPLE_row_bytes = has_ext("GL_APPLE_row_bytes");
	GLAD_APPLE_sync = has_ext("GL_APPLE_sync");
	GLAD_APPLE_texture_format_BGRA8888 = has_ext("GL_APPLE_texture_format_BGRA8888");
	GLAD_APPLE_texture_max_level = has_ext("GL_APPLE_texture_max_level");
	GLAD_APPLE_texture_packed_float = has_ext("GL_APPLE_texture_packed_float");
	GLAD_APPLE_texture_range = has_ext("GL_APPLE_texture_range");
	GLAD_APPLE_vertex_array_object = has_ext("GL_APPLE_vertex_array_object");
	GLAD_APPLE_vertex_array_range = has_ext("GL_APPLE_vertex_array_range");
	GLAD_APPLE_vertex_program_evaluators = has_ext("GL_APPLE_vertex_program_evaluators");
	GLAD_APPLE_ycbcr_422 = has_ext("GL_APPLE_ycbcr_422");
	GLAD_ARM_mali_program_binary = has_ext("GL_ARM_mali_program_binary");
	GLAD_ARM_mali_shader_binary = has_ext("GL_ARM_mali_shader_binary");
	GLAD_ARM_rgba8 = has_ext("GL_ARM_rgba8");
	GLAD_ARM_shader_framebuffer_fetch = has_ext("GL_ARM_shader_framebuffer_fetch");
	GLAD_ARM_shader_framebuffer_fetch_depth_stencil = has_ext("GL_ARM_shader_framebuffer_fetch_depth_stencil");
	GLAD_ATI_meminfo = has_ext("GL_ATI_meminfo");
	GLAD_ATI_pixel_format_float = has_ext("GL_ATI_pixel_format_float");
	GLAD_DMP_program_binary = has_ext("GL_DMP_program_binary");
	GLAD_DMP_shader_binary = has_ext("GL_DMP_shader_binary");
	GLAD_FJ_shader_binary_GCCSO = has_ext("GL_FJ_shader_binary_GCCSO");
	GLAD_GREMEDY_frame_terminator = has_ext("GL_GREMEDY_frame_terminator");
	GLAD_GREMEDY_string_marker = has_ext("GL_GREMEDY_string_marker");
	GLAD_IMG_multisampled_render_to_texture = has_ext("GL_IMG_multisampled_render_to_texture");
	GLAD_IMG_program_binary = has_ext("GL_IMG_program_binary");
	GLAD_IMG_read_format = has_ext("GL_IMG_read_format");
	GLAD_IMG_shader_binary = has_ext("GL_IMG_shader_binary");
	GLAD_IMG_texture_compression_pvrtc = has_ext("GL_IMG_texture_compression_pvrtc");
	GLAD_IMG_texture_compression_pvrtc2 = has_ext("GL_IMG_texture_compression_pvrtc2");
	GLAD_IMG_texture_filter_cubic = has_ext("GL_IMG_texture_filter_cubic");
	GLAD_INGR_blend_func_separate = has_ext("GL_INGR_blend_func_separate");
	GLAD_INTEL_fragment_shader_ordering = has_ext("GL_INTEL_fragment_shader_ordering");
	GLAD_INTEL_framebuffer_CMAA = has_ext("GL_INTEL_framebuffer_CMAA");
	GLAD_INTEL_map_texture = has_ext("GL_INTEL_map_texture");
	GLAD_INTEL_performance_query = has_ext("GL_INTEL_performance_query");
	GLAD_MESA_pack_invert = has_ext("GL_MESA_pack_invert");
	GLAD_MESA_ycbcr_texture = has_ext("GL_MESA_ycbcr_texture");
	GLAD_MESAX_texture_stack = has_ext("GL_MESAX_texture_stack");
	GLAD_NV_bindless_multi_draw_indirect = has_ext("GL_NV_bindless_multi_draw_indirect");
	GLAD_NV_bindless_multi_draw_indirect_count = has_ext("GL_NV_bindless_multi_draw_indirect_count");
	GLAD_NV_bindless_texture = has_ext("GL_NV_bindless_texture");
	GLAD_NV_blend_equation_advanced = has_ext("GL_NV_blend_equation_advanced");
	GLAD_NV_blend_equation_advanced_coherent = has_ext("GL_NV_blend_equation_advanced_coherent");
	GLAD_NV_command_list = has_ext("GL_NV_command_list");
	GLAD_NV_compute_program5 = has_ext("GL_NV_compute_program5");
	GLAD_NV_conditional_render = has_ext("GL_NV_conditional_render");
	GLAD_NV_conservative_raster = has_ext("GL_NV_conservative_raster");
	GLAD_NV_conservative_raster_dilate = has_ext("GL_NV_conservative_raster_dilate");
	GLAD_NV_copy_buffer = has_ext("GL_NV_copy_buffer");
	GLAD_NV_copy_image = has_ext("GL_NV_copy_image");
	GLAD_NV_coverage_sample = has_ext("GL_NV_coverage_sample");
	GLAD_NV_deep_texture3D = has_ext("GL_NV_deep_texture3D");
	GLAD_NV_depth_buffer_float = has_ext("GL_NV_depth_buffer_float");
	GLAD_NV_depth_clamp = has_ext("GL_NV_depth_clamp");
	GLAD_NV_depth_nonlinear = has_ext("GL_NV_depth_nonlinear");
	GLAD_NV_draw_buffers = has_ext("GL_NV_draw_buffers");
	GLAD_NV_draw_instanced = has_ext("GL_NV_draw_instanced");
	GLAD_NV_draw_texture = has_ext("GL_NV_draw_texture");
	GLAD_NV_explicit_attrib_location = has_ext("GL_NV_explicit_attrib_location");
	GLAD_NV_explicit_multisample = has_ext("GL_NV_explicit_multisample");
	GLAD_NV_fbo_color_attachments = has_ext("GL_NV_fbo_color_attachments");
	GLAD_NV_fence = has_ext("GL_NV_fence");
	GLAD_NV_fill_rectangle = has_ext("GL_NV_fill_rectangle");
	GLAD_NV_float_buffer = has_ext("GL_NV_float_buffer");
	GLAD_NV_fragment_coverage_to_color = has_ext("GL_NV_fragment_coverage_to_color");
	GLAD_NV_fragment_program4 = has_ext("GL_NV_fragment_program4");
	GLAD_NV_fragment_shader_interlock = has_ext("GL_NV_fragment_shader_interlock");
	GLAD_NV_framebuffer_blit = has_ext("GL_NV_framebuffer_blit");
	GLAD_NV_framebuffer_mixed_samples = has_ext("GL_NV_framebuffer_mixed_samples");
	GLAD_NV_framebuffer_multisample = has_ext("GL_NV_framebuffer_multisample");
	GLAD_NV_framebuffer_multisample_coverage = has_ext("GL_NV_framebuffer_multisample_coverage");
	GLAD_NV_generate_mipmap_sRGB = has_ext("GL_NV_generate_mipmap_sRGB");
	GLAD_NV_geometry_program4 = has_ext("GL_NV_geometry_program4");
	GLAD_NV_geometry_shader4 = has_ext("GL_NV_geometry_shader4");
	GLAD_NV_geometry_shader_passthrough = has_ext("GL_NV_geometry_shader_passthrough");
	GLAD_NV_gpu_program4 = has_ext("GL_NV_gpu_program4");
	GLAD_NV_gpu_program5 = has_ext("GL_NV_gpu_program5");
	GLAD_NV_gpu_program5_mem_extended = has_ext("GL_NV_gpu_program5_mem_extended");
	GLAD_NV_gpu_shader5 = has_ext("GL_NV_gpu_shader5");
	GLAD_NV_half_float = has_ext("GL_NV_half_float");
	GLAD_NV_image_formats = has_ext("GL_NV_image_formats");
	GLAD_NV_instanced_arrays = has_ext("GL_NV_instanced_arrays");
	GLAD_NV_internalformat_sample_query = has_ext("GL_NV_internalformat_sample_query");
	GLAD_NV_multisample_coverage = has_ext("GL_NV_multisample_coverage");
	GLAD_NV_non_square_matrices = has_ext("GL_NV_non_square_matrices");
	GLAD_NV_occlusion_query = has_ext("GL_NV_occlusion_query");
	GLAD_NV_parameter_buffer_object = has_ext("GL_NV_parameter_buffer_object");
	GLAD_NV_parameter_buffer_object2 = has_ext("GL_NV_parameter_buffer_object2");
	GLAD_NV_path_rendering = has_ext("GL_NV_path_rendering");
	GLAD_NV_path_rendering_shared_edge = has_ext("GL_NV_path_rendering_shared_edge");
	GLAD_NV_polygon_mode = has_ext("GL_NV_polygon_mode");
	GLAD_NV_present_video = has_ext("GL_NV_present_video");
	GLAD_NV_primitive_restart = has_ext("GL_NV_primitive_restart");
	GLAD_NV_read_buffer = has_ext("GL_NV_read_buffer");
	GLAD_NV_read_buffer_front = has_ext("GL_NV_read_buffer_front");
	GLAD_NV_read_depth = has_ext("GL_NV_read_depth");
	GLAD_NV_read_depth_stencil = has_ext("GL_NV_read_depth_stencil");
	GLAD_NV_read_stencil = has_ext("GL_NV_read_stencil");
	GLAD_NV_sample_locations = has_ext("GL_NV_sample_locations");
	GLAD_NV_sample_mask_override_coverage = has_ext("GL_NV_sample_mask_override_coverage");
	GLAD_NV_shader_atomic_counters = has_ext("GL_NV_shader_atomic_counters");
	GLAD_NV_shader_atomic_float = has_ext("GL_NV_shader_atomic_float");
	GLAD_NV_shader_atomic_fp16_vector = has_ext("GL_NV_shader_atomic_fp16_vector");
	GLAD_NV_shader_atomic_int64 = has_ext("GL_NV_shader_atomic_int64");
	GLAD_NV_shader_buffer_load = has_ext("GL_NV_shader_buffer_load");
	GLAD_NV_shader_buffer_store = has_ext("GL_NV_shader_buffer_store");
	GLAD_NV_shader_noperspective_interpolation = has_ext("GL_NV_shader_noperspective_interpolation");
	GLAD_NV_shader_storage_buffer_object = has_ext("GL_NV_shader_storage_buffer_object");
	GLAD_NV_shader_thread_group = has_ext("GL_NV_shader_thread_group");
	GLAD_NV_shader_thread_shuffle = has_ext("GL_NV_shader_thread_shuffle");
	GLAD_NV_shadow_samplers_array = has_ext("GL_NV_shadow_samplers_array");
	GLAD_NV_shadow_samplers_cube = has_ext("GL_NV_shadow_samplers_cube");
	GLAD_NV_sRGB_formats = has_ext("GL_NV_sRGB_formats");
	GLAD_NV_tessellation_program5 = has_ext("GL_NV_tessellation_program5");
	GLAD_NV_texture_barrier = has_ext("GL_NV_texture_barrier");
	GLAD_NV_texture_border_clamp = has_ext("GL_NV_texture_border_clamp");
	GLAD_NV_texture_compression_s3tc_update = has_ext("GL_NV_texture_compression_s3tc_update");
	GLAD_NV_texture_multisample = has_ext("GL_NV_texture_multisample");
	GLAD_NV_texture_npot_2D_mipmap = has_ext("GL_NV_texture_npot_2D_mipmap");
	GLAD_NV_transform_feedback = has_ext("GL_NV_transform_feedback");
	GLAD_NV_transform_feedback2 = has_ext("GL_NV_transform_feedback2");
	GLAD_NV_uniform_buffer_unified_memory = has_ext("GL_NV_uniform_buffer_unified_memory");
	GLAD_NV_vdpau_interop = has_ext("GL_NV_vdpau_interop");
	GLAD_NV_vertex_attrib_integer_64bit = has_ext("GL_NV_vertex_attrib_integer_64bit");
	GLAD_NV_vertex_buffer_unified_memory = has_ext("GL_NV_vertex_buffer_unified_memory");
	GLAD_NV_vertex_program4 = has_ext("GL_NV_vertex_program4");
	GLAD_NV_video_capture = has_ext("GL_NV_video_capture");
	GLAD_NV_viewport_array = has_ext("GL_NV_viewport_array");
	GLAD_NV_viewport_array2 = has_ext("GL_NV_viewport_array2");
	GLAD_NVX_conditional_render = has_ext("GL_NVX_conditional_render");
	GLAD_NVX_gpu_memory_info = has_ext("GL_NVX_gpu_memory_info");
	GLAD_OVR_multiview = has_ext("GL_OVR_multiview");
	GLAD_OVR_multiview2 = has_ext("GL_OVR_multiview2");
	GLAD_OVR_multiview_multisampled_render_to_texture = has_ext("GL_OVR_multiview_multisampled_render_to_texture");
	GLAD_QCOM_alpha_test = has_ext("GL_QCOM_alpha_test");
	GLAD_QCOM_binning_control = has_ext("GL_QCOM_binning_control");
	GLAD_QCOM_driver_control = has_ext("GL_QCOM_driver_control");
	GLAD_QCOM_extended_get = has_ext("GL_QCOM_extended_get");
	GLAD_QCOM_extended_get2 = has_ext("GL_QCOM_extended_get2");
	GLAD_QCOM_perfmon_global_mode = has_ext("GL_QCOM_perfmon_global_mode");
	GLAD_QCOM_tiled_rendering = has_ext("GL_QCOM_tiled_rendering");
	GLAD_QCOM_writeonly_rendering = has_ext("GL_QCOM_writeonly_rendering");
	GLAD_VIV_shader_binary = has_ext("GL_VIV_shader_binary");
}

static void find_core(void) {
	const char *v = (const char *)fp_glGetString(GL_VERSION);
	int major = v[0] - '0', minor = v[2] - '0', gles = false;
	GLVersion.gles = false;
	if (strstr(v, "OpenGL ES ") == v) {
		major = v[10] - '0'; minor = v[12] - '0'; gles = true;
	}
	GLVersion.major = major; GLVersion.minor = minor; GLVersion.gles = gles;
	GLAD_VERSION_1_0 = gles == 0 && ((major == 1 && minor >= 0) || major > 1);
	GLAD_VERSION_1_1 = gles == 0 && ((major == 1 && minor >= 1) || major > 1);
	GLAD_VERSION_1_2 = gles == 0 && ((major == 1 && minor >= 2) || major > 1);
	GLAD_VERSION_1_3 = gles == 0 && ((major == 1 && minor >= 3) || major > 1);
	GLAD_VERSION_1_4 = gles == 0 && ((major == 1 && minor >= 4) || major > 1);
	GLAD_VERSION_1_5 = gles == 0 && ((major == 1 && minor >= 5) || major > 1);
	GLAD_VERSION_2_0 = gles == 0 && ((major == 2 && minor >= 0) || major > 2);
	GLAD_VERSION_2_1 = gles == 0 && ((major == 2 && minor >= 1) || major > 2);
	GLAD_VERSION_3_0 = gles == 0 && ((major == 3 && minor >= 0) || major > 3);
	GLAD_VERSION_3_1 = gles == 0 && ((major == 3 && minor >= 1) || major > 3);
	GLAD_VERSION_3_2 = gles == 0 && ((major == 3 && minor >= 2) || major > 3);
	GLAD_VERSION_3_3 = gles == 0 && ((major == 3 && minor >= 3) || major > 3);
	GLAD_VERSION_4_0 = gles == 0 && ((major == 4 && minor >= 0) || major > 4);
	GLAD_VERSION_4_1 = gles == 0 && ((major == 4 && minor >= 1) || major > 4);
	GLAD_VERSION_4_2 = gles == 0 && ((major == 4 && minor >= 2) || major > 4);
	GLAD_VERSION_4_3 = gles == 0 && ((major == 4 && minor >= 3) || major > 4);
	GLAD_VERSION_4_4 = gles == 0 && ((major == 4 && minor >= 4) || major > 4);
	GLAD_VERSION_4_5 = gles == 0 && ((major == 4 && minor >= 5) || major > 4);
	GLAD_ES_VERSION_2_0 = gles == 1 && ((major == 2 && minor >= 0) || major > 2);
	GLAD_ES_VERSION_3_0 = gles == 1 && ((major == 3 && minor >= 0) || major > 3);
	GLAD_ES_VERSION_3_1 = gles == 1 && ((major == 3 && minor >= 1) || major > 3);
	GLAD_ES_VERSION_3_2 = gles == 1 && ((major == 3 && minor >= 2) || major > 3);
}

bool gladLoadGLLoader(LOADER load) {
	GLVersion.major = 0; GLVersion.minor = 0; GLVersion.gles = 0;
	fp_glGetString = (pfn_glGetString)load("glGetString");
	if(fp_glGetString == NULL) return false;
	find_core();
	load_GL_VERSION_1_0(load);
	load_GL_VERSION_1_1(load);
	load_GL_VERSION_1_2(load);
	load_GL_VERSION_1_3(load);
	load_GL_VERSION_1_4(load);
	load_GL_VERSION_1_5(load);
	load_GL_VERSION_2_0(load);
	load_GL_VERSION_2_1(load);
	load_GL_VERSION_3_0(load);
	load_GL_VERSION_3_1(load);
	load_GL_VERSION_3_2(load);
	load_GL_VERSION_3_3(load);
	load_GL_VERSION_4_0(load);
	load_GL_VERSION_4_1(load);
	load_GL_VERSION_4_2(load);
	load_GL_VERSION_4_3(load);
	load_GL_VERSION_4_4(load);
	load_GL_VERSION_4_5(load);
	load_GL_ES_VERSION_2_0(load);
	load_GL_ES_VERSION_3_0(load);
	load_GL_ES_VERSION_3_1(load);
	load_GL_ES_VERSION_3_2(load);

	find_extensions();
	load_GL_KHR_blend_equation_advanced(load);
	load_GL_KHR_debug(load);
	load_GL_KHR_robustness(load);
	load_GL_ARB_base_instance(load);
	load_GL_ARB_bindless_texture(load);
	load_GL_ARB_blend_func_extended(load);
	load_GL_ARB_buffer_storage(load);
	load_GL_ARB_cl_event(load);
	load_GL_ARB_clear_buffer_object(load);
	load_GL_ARB_clear_texture(load);
	load_GL_ARB_clip_control(load);
	load_GL_ARB_color_buffer_float(load);
	load_GL_ARB_compute_shader(load);
	load_GL_ARB_compute_variable_group_size(load);
	load_GL_ARB_copy_buffer(load);
	load_GL_ARB_copy_image(load);
	load_GL_ARB_debug_output(load);
	load_GL_ARB_direct_state_access(load);
	load_GL_ARB_draw_buffers_blend(load);
	load_GL_ARB_draw_elements_base_vertex(load);
	load_GL_ARB_draw_indirect(load);
	load_GL_ARB_draw_instanced(load);
	load_GL_ARB_ES2_compatibility(load);
	load_GL_ARB_ES3_1_compatibility(load);
	load_GL_ARB_ES3_2_compatibility(load);
	load_GL_ARB_framebuffer_no_attachments(load);
	load_GL_ARB_framebuffer_object(load);
	load_GL_ARB_geometry_shader4(load);
	load_GL_ARB_get_program_binary(load);
	load_GL_ARB_get_texture_sub_image(load);
	load_GL_ARB_gpu_shader_fp64(load);
	load_GL_ARB_gpu_shader_int64(load);
	load_GL_ARB_indirect_parameters(load);
	load_GL_ARB_instanced_arrays(load);
	load_GL_ARB_internalformat_query(load);
	load_GL_ARB_internalformat_query2(load);
	load_GL_ARB_invalidate_subdata(load);
	load_GL_ARB_map_buffer_range(load);
	load_GL_ARB_multi_bind(load);
	load_GL_ARB_multi_draw_indirect(load);
	load_GL_ARB_parallel_shader_compile(load);
	load_GL_ARB_program_interface_query(load);
	load_GL_ARB_provoking_vertex(load);
	load_GL_ARB_robustness(load);
	load_GL_ARB_sample_locations(load);
	load_GL_ARB_sample_shading(load);
	load_GL_ARB_sampler_objects(load);
	load_GL_ARB_separate_shader_objects(load);
	load_GL_ARB_shader_atomic_counters(load);
	load_GL_ARB_shader_image_load_store(load);
	load_GL_ARB_shader_storage_buffer_object(load);
	load_GL_ARB_shader_subroutine(load);
	load_GL_ARB_shading_language_include(load);
	load_GL_ARB_sparse_buffer(load);
	load_GL_ARB_sparse_texture(load);
	load_GL_ARB_sync(load);
	load_GL_ARB_tessellation_shader(load);
	load_GL_ARB_texture_barrier(load);
	load_GL_ARB_texture_buffer_object(load);
	load_GL_ARB_texture_buffer_range(load);
	load_GL_ARB_texture_multisample(load);
	load_GL_ARB_texture_storage(load);
	load_GL_ARB_texture_storage_multisample(load);
	load_GL_ARB_texture_view(load);
	load_GL_ARB_timer_query(load);
	load_GL_ARB_transform_feedback2(load);
	load_GL_ARB_transform_feedback3(load);
	load_GL_ARB_transform_feedback_instanced(load);
	load_GL_ARB_uniform_buffer_object(load);
	load_GL_ARB_vertex_array_object(load);
	load_GL_ARB_vertex_attrib_64bit(load);
	load_GL_ARB_vertex_attrib_binding(load);
	load_GL_ARB_vertex_type_2_10_10_10_rev(load);
	load_GL_ARB_viewport_array(load);
	load_GL_EXT_base_instance(load);
	load_GL_EXT_bindable_uniform(load);
	load_GL_EXT_blend_func_extended(load);
	load_GL_EXT_blend_minmax(load);
	load_GL_EXT_buffer_storage(load);
	load_GL_EXT_copy_image(load);
	load_GL_EXT_debug_label(load);
	load_GL_EXT_debug_marker(load);
	load_GL_EXT_direct_state_access(load);
	load_GL_EXT_discard_framebuffer(load);
	load_GL_EXT_disjoint_timer_query(load);
	load_GL_EXT_draw_buffers(load);
	load_GL_EXT_draw_buffers2(load);
	load_GL_EXT_draw_buffers_indexed(load);
	load_GL_EXT_draw_elements_base_vertex(load);
	load_GL_EXT_draw_instanced(load);
	load_GL_EXT_framebuffer_blit(load);
	load_GL_EXT_framebuffer_multisample(load);
	load_GL_EXT_framebuffer_object(load);
	load_GL_EXT_geometry_shader(load);
	load_GL_EXT_geometry_shader4(load);
	load_GL_EXT_gpu_program_parameters(load);
	load_GL_EXT_gpu_shader4(load);
	load_GL_EXT_instanced_arrays(load);
	load_GL_EXT_map_buffer_range(load);
	load_GL_EXT_multi_draw_indirect(load);
	load_GL_EXT_multisampled_render_to_texture(load);
	load_GL_EXT_multiview_draw_buffers(load);
	load_GL_EXT_occlusion_query_boolean(load);
	load_GL_EXT_polygon_offset_clamp(load);
	load_GL_EXT_primitive_bounding_box(load);
	load_GL_EXT_provoking_vertex(load);
	load_GL_EXT_raster_multisample(load);
	load_GL_EXT_robustness(load);
	load_GL_EXT_separate_shader_objects(load);
	load_GL_EXT_shader_image_load_store(load);
	load_GL_EXT_sparse_texture(load);
	load_GL_EXT_stencil_clear_tag(load);
	load_GL_EXT_tessellation_shader(load);
	load_GL_EXT_texture_array(load);
	load_GL_EXT_texture_border_clamp(load);
	load_GL_EXT_texture_buffer(load);
	load_GL_EXT_texture_buffer_object(load);
	load_GL_EXT_texture_filter_minmax(load);
	load_GL_EXT_texture_integer(load);
	load_GL_EXT_texture_storage(load);
	load_GL_EXT_texture_view(load);
	load_GL_EXT_timer_query(load);
	load_GL_EXT_transform_feedback(load);
	load_GL_EXT_vertex_attrib_64bit(load);
	load_GL_EXT_x11_sync_object(load);
	load_GL_OES_copy_image(load);
	load_GL_OES_draw_buffers_indexed(load);
	load_GL_OES_draw_elements_base_vertex(load);
	load_GL_OES_EGL_image(load);
	load_GL_OES_geometry_shader(load);
	load_GL_OES_get_program_binary(load);
	load_GL_OES_mapbuffer(load);
	load_GL_OES_primitive_bounding_box(load);
	load_GL_OES_sample_shading(load);
	load_GL_OES_tessellation_shader(load);
	load_GL_OES_texture_3D(load);
	load_GL_OES_texture_border_clamp(load);
	load_GL_OES_texture_buffer(load);
	load_GL_OES_texture_storage_multisample_2d_array(load);
	load_GL_OES_texture_view(load);
	load_GL_OES_vertex_array_object(load);
	load_GL_AMD_debug_output(load);
	load_GL_AMD_draw_buffers_blend(load);
	load_GL_AMD_gpu_shader_int64(load);
	load_GL_AMD_interleaved_elements(load);
	load_GL_AMD_multi_draw_indirect(load);
	load_GL_AMD_name_gen_delete(load);
	load_GL_AMD_occlusion_query_event(load);
	load_GL_AMD_performance_monitor(load);
	load_GL_AMD_sample_positions(load);
	load_GL_AMD_sparse_texture(load);
	load_GL_AMD_stencil_operation_extended(load);
	load_GL_AMD_vertex_shader_tessellator(load);
	load_GL_ANGLE_framebuffer_blit(load);
	load_GL_ANGLE_framebuffer_multisample(load);
	load_GL_ANGLE_instanced_arrays(load);
	load_GL_ANGLE_translated_shader_source(load);
	load_GL_APPLE_copy_texture_levels(load);
	load_GL_APPLE_element_array(load);
	load_GL_APPLE_fence(load);
	load_GL_APPLE_flush_buffer_range(load);
	load_GL_APPLE_framebuffer_multisample(load);
	load_GL_APPLE_object_purgeable(load);
	load_GL_APPLE_sync(load);
	load_GL_APPLE_texture_range(load);
	load_GL_APPLE_vertex_array_object(load);
	load_GL_APPLE_vertex_array_range(load);
	load_GL_APPLE_vertex_program_evaluators(load);
	load_GL_GREMEDY_frame_terminator(load);
	load_GL_GREMEDY_string_marker(load);
	load_GL_IMG_multisampled_render_to_texture(load);
	load_GL_INGR_blend_func_separate(load);
	load_GL_INTEL_framebuffer_CMAA(load);
	load_GL_INTEL_map_texture(load);
	load_GL_INTEL_performance_query(load);
	load_GL_NV_bindless_multi_draw_indirect(load);
	load_GL_NV_bindless_multi_draw_indirect_count(load);
	load_GL_NV_bindless_texture(load);
	load_GL_NV_blend_equation_advanced(load);
	load_GL_NV_command_list(load);
	load_GL_NV_conditional_render(load);
	load_GL_NV_conservative_raster(load);
	load_GL_NV_conservative_raster_dilate(load);
	load_GL_NV_copy_buffer(load);
	load_GL_NV_copy_image(load);
	load_GL_NV_coverage_sample(load);
	load_GL_NV_depth_buffer_float(load);
	load_GL_NV_draw_buffers(load);
	load_GL_NV_draw_instanced(load);
	load_GL_NV_draw_texture(load);
	load_GL_NV_explicit_multisample(load);
	load_GL_NV_fence(load);
	load_GL_NV_fragment_coverage_to_color(load);
	load_GL_NV_framebuffer_blit(load);
	load_GL_NV_framebuffer_mixed_samples(load);
	load_GL_NV_framebuffer_multisample(load);
	load_GL_NV_framebuffer_multisample_coverage(load);
	load_GL_NV_geometry_program4(load);
	load_GL_NV_gpu_program4(load);
	load_GL_NV_gpu_program5(load);
	load_GL_NV_gpu_shader5(load);
	load_GL_NV_half_float(load);
	load_GL_NV_instanced_arrays(load);
	load_GL_NV_internalformat_sample_query(load);
	load_GL_NV_non_square_matrices(load);
	load_GL_NV_occlusion_query(load);
	load_GL_NV_parameter_buffer_object(load);
	load_GL_NV_path_rendering(load);
	load_GL_NV_polygon_mode(load);
	load_GL_NV_present_video(load);
	load_GL_NV_primitive_restart(load);
	load_GL_NV_read_buffer(load);
	load_GL_NV_sample_locations(load);
	load_GL_NV_shader_buffer_load(load);
	load_GL_NV_texture_barrier(load);
	load_GL_NV_texture_multisample(load);
	load_GL_NV_transform_feedback(load);
	load_GL_NV_transform_feedback2(load);
	load_GL_NV_vdpau_interop(load);
	load_GL_NV_vertex_attrib_integer_64bit(load);
	load_GL_NV_vertex_buffer_unified_memory(load);
	load_GL_NV_vertex_program4(load);
	load_GL_NV_video_capture(load);
	load_GL_NV_viewport_array(load);
	load_GL_NVX_conditional_render(load);
	load_GL_OVR_multiview(load);
	load_GL_OVR_multiview_multisampled_render_to_texture(load);
	load_GL_QCOM_alpha_test(load);
	load_GL_QCOM_driver_control(load);
	load_GL_QCOM_extended_get(load);
	load_GL_QCOM_extended_get2(load);
	load_GL_QCOM_tiled_rendering(load);
	return true;
}

} /* namespace glad */
