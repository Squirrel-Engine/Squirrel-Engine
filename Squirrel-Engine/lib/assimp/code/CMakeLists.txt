# Open Asset Import Library (assimp)
# ----------------------------------------------------------------------
#
# Copyright (c) 2006-2019, assimp team
#
# All rights reserved.
#
# Redistribution and use of this software in source and binary forms,
# with or without modification, are permitted provided that the
# following conditions are met:
#
# * Redistributions of source code must retain the above
#   copyright notice, this list of conditions and the
#   following disclaimer.
#
# * Redistributions in binary form must reproduce the above
#   copyright notice, this list of conditions and the
#   following disclaimer in the documentation and/or other
#   materials provided with the distribution.
#
# * Neither the name of the assimp team, nor the names of its
#   contributors may be used to endorse or promote products
#   derived from this software without specific prior
#   written permission of the assimp team.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#----------------------------------------------------------------------

# Listing and grouping of all the source files.
# 1) Set the file lists for each component
# 2) Create a Source Group for each component, for IDE project orginization
# 3) Add libassimp using the file lists (eliminates duplication of file names between
#    source groups and library command)
#
cmake_minimum_required( VERSION 3.0 )
SET( HEADER_PATH ../include/assimp )

if(NOT ANDROID AND ASSIMP_ANDROID_JNIIOSYSTEM)
    message(WARNING "Requesting Android JNI I/O-System in non-Android toolchain. Resetting ASSIMP_ANDROID_JNIIOSYSTEM to OFF.")
    set(ASSIMP_ANDROID_JNIIOSYSTEM OFF)
endif(NOT ANDROID AND ASSIMP_ANDROID_JNIIOSYSTEM)

SET( COMPILER_HEADERS
  ${HEADER_PATH}/Compiler/pushpack1.h
  ${HEADER_PATH}/Compiler/poppack1.h
  ${HEADER_PATH}/Compiler/pstdint.h
)
SOURCE_GROUP( Compiler FILES ${COMPILER_HEADERS})

SET( PUBLIC_HEADERS
  ${HEADER_PATH}/anim.h
  ${HEADER_PATH}/aabb.h
  ${HEADER_PATH}/ai_assert.h
  ${HEADER_PATH}/camera.h
  ${HEADER_PATH}/color4.h
  ${HEADER_PATH}/color4.inl
  ${CMAKE_CURRENT_BINARY_DIR}/../include/assimp/config.h
  ${HEADER_PATH}/defs.h
  ${HEADER_PATH}/Defines.h
  ${HEADER_PATH}/cfileio.h
  ${HEADER_PATH}/light.h
  ${HEADER_PATH}/material.h
  ${HEADER_PATH}/material.inl
  ${HEADER_PATH}/matrix3x3.h
  ${HEADER_PATH}/matrix3x3.inl
  ${HEADER_PATH}/matrix4x4.h
  ${HEADER_PATH}/matrix4x4.inl
  ${HEADER_PATH}/mesh.h
  ${HEADER_PATH}/pbrmaterial.h
  ${HEADER_PATH}/postprocess.h
  ${HEADER_PATH}/quaternion.h
  ${HEADER_PATH}/quaternion.inl
  ${HEADER_PATH}/scene.h
  ${HEADER_PATH}/metadata.h
  ${HEADER_PATH}/texture.h
  ${HEADER_PATH}/types.h
  ${HEADER_PATH}/vector2.h
  ${HEADER_PATH}/vector2.inl
  ${HEADER_PATH}/vector3.h
  ${HEADER_PATH}/vector3.inl
  ${HEADER_PATH}/version.h
  ${HEADER_PATH}/cimport.h
  ${HEADER_PATH}/importerdesc.h
  ${HEADER_PATH}/Importer.hpp
  ${HEADER_PATH}/DefaultLogger.hpp
  ${HEADER_PATH}/ProgressHandler.hpp
  ${HEADER_PATH}/IOStream.hpp
  ${HEADER_PATH}/IOSystem.hpp
  ${HEADER_PATH}/Logger.hpp
  ${HEADER_PATH}/LogStream.hpp
  ${HEADER_PATH}/NullLogger.hpp
  ${HEADER_PATH}/cexport.h
  ${HEADER_PATH}/Exporter.hpp
  ${HEADER_PATH}/DefaultIOStream.h
  ${HEADER_PATH}/DefaultIOSystem.h
  ${HEADER_PATH}/ZipArchiveIOSystem.h
  ${HEADER_PATH}/SceneCombiner.h
  ${HEADER_PATH}/fast_atof.h
  ${HEADER_PATH}/qnan.h
  ${HEADER_PATH}/BaseImporter.h
  ${HEADER_PATH}/Hash.h
  ${HEADER_PATH}/MemoryIOWrapper.h
  ${HEADER_PATH}/ParsingUtils.h
  ${HEADER_PATH}/StreamReader.h
  ${HEADER_PATH}/StreamWriter.h
  ${HEADER_PATH}/StringComparison.h
  ${HEADER_PATH}/StringUtils.h
  ${HEADER_PATH}/SGSpatialSort.h
  ${HEADER_PATH}/GenericProperty.h
  ${HEADER_PATH}/SpatialSort.h
  ${HEADER_PATH}/SkeletonMeshBuilder.h
  ${HEADER_PATH}/SmoothingGroups.h
  ${HEADER_PATH}/SmoothingGroups.inl
  ${HEADER_PATH}/StandardShapes.h
  ${HEADER_PATH}/RemoveComments.h
  ${HEADER_PATH}/Subdivision.h
  ${HEADER_PATH}/Vertex.h
  ${HEADER_PATH}/LineSplitter.h
  ${HEADER_PATH}/TinyFormatter.h
  ${HEADER_PATH}/Profiler.h
  ${HEADER_PATH}/LogAux.h
  ${HEADER_PATH}/Bitmap.h
  ${HEADER_PATH}/XMLTools.h
  ${HEADER_PATH}/IOStreamBuffer.h
  ${HEADER_PATH}/CreateAnimMesh.h
  ${HEADER_PATH}/irrXMLWrapper.h
  ${HEADER_PATH}/BlobIOSystem.h
  ${HEADER_PATH}/MathFunctions.h
  ${HEADER_PATH}/Macros.h
  ${HEADER_PATH}/Exceptional.h
  ${HEADER_PATH}/ByteSwapper.h
)

SET( Core_SRCS
  Common/Assimp.cpp
)

IF(MSVC)
  list(APPEND Core_SRCS "res/assimp.rc")
ENDIF(MSVC)

SET( Logging_SRCS
  ${HEADER_PATH}/DefaultLogger.hpp
  ${HEADER_PATH}/LogStream.hpp
  ${HEADER_PATH}/Logger.hpp
  ${HEADER_PATH}/NullLogger.hpp
  Common/Win32DebugLogStream.h
  Common/DefaultLogger.cpp
  Common/FileLogStream.h
  Common/StdOStreamLogStream.h
)
SOURCE_GROUP(Logging FILES ${Logging_SRCS})

SET( Common_SRCS
  Common/BaseImporter.cpp
  Common/BaseProcess.cpp
  Common/BaseProcess.h
  Common/Importer.h
  Common/ScenePrivate.h
  Common/PostStepRegistry.cpp
  Common/ImporterRegistry.cpp
  Common/DefaultProgressHandler.h
  Common/DefaultIOStream.cpp
  Common/DefaultIOSystem.cpp
  Common/ZipArchiveIOSystem.cpp
  Common/PolyTools.h
  Common/Importer.cpp
  Common/IFF.h
  Common/SGSpatialSort.cpp
  Common/VertexTriangleAdjacency.cpp
  Common/VertexTriangleAdjacency.h
  Common/SpatialSort.cpp
  Common/SceneCombiner.cpp
  Common/ScenePreprocessor.cpp
  Common/ScenePreprocessor.h
  Common/SkeletonMeshBuilder.cpp
  Common/SplitByBoneCountProcess.cpp
  Common/SplitByBoneCountProcess.h
  Common/StandardShapes.cpp
  Common/TargetAnimation.cpp
  Common/TargetAnimation.h
  Common/RemoveComments.cpp
  Common/Subdivision.cpp
  Common/scene.cpp
  Common/Bitmap.cpp
  Common/Version.cpp
  Common/CreateAnimMesh.cpp
  Common/simd.h
  Common/simd.cpp
)
SOURCE_GROUP(Common FILES ${Common_SRCS})

SET( CApi_SRCS
  CApi/CInterfaceIOWrapper.cpp
  CApi/CInterfaceIOWrapper.h
)
SOURCE_GROUP(CApi FILES ${CApi_SRCS})

SET( STEPParser_SRCS
  Importer/STEPParser/STEPFileReader.h
  Importer/STEPParser/STEPFileReader.cpp
  Importer/STEPParser/STEPFileEncoding.cpp
  Importer/STEPParser/STEPFileEncoding.h
)
SOURCE_GROUP(STEPParser FILES ${STEPParser_SRCS})

IF ( ASSIMP_BUILD_NONFREE_C4D_IMPORTER )
  SET( C4D_SRCS
    C4D/C4DImporter.cpp
    C4D/C4DImporter.h
  )
  SOURCE_GROUP( C4D FILES ${C4D_SRCS})
ENDIF ( ASSIMP_BUILD_NONFREE_C4D_IMPORTER )

# if this variable is set to TRUE, the user can manually disable importers by setting
# ASSIMP_BUILD_XXX_IMPORTER to FALSE for each importer
# if this variable is set to FALSE, the user can manually enable importers by setting
# ASSIMP_BUILD_XXX_IMPORTER to TRUE for each importer
OPTION(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT "default value of all ASSIMP_BUILD_XXX_IMPORTER values" TRUE)

# macro to add the CMake Option ADD_ASSIMP_IMPORTER_<name> which enables compile of loader
# this way selective loaders can be compiled (reduces filesize + compile time)
MACRO(ADD_ASSIMP_IMPORTER name)
  IF (ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT)
    set(ASSIMP_IMPORTER_ENABLED TRUE)
    IF (DEFINED ASSIMP_BUILD_${name}_IMPORTER AND NOT ASSIMP_BUILD_${name}_IMPORTER)
      set(ASSIMP_IMPORTER_ENABLED FALSE)
    ENDIF ()
  ELSE ()
    set(ASSIMP_IMPORTER_ENABLED ${ASSIMP_BUILD_${name}_IMPORTER})
  ENDIF ()
  IF (ASSIMP_IMPORTER_ENABLED)
    LIST(APPEND ASSIMP_LOADER_SRCS ${ARGN})
    SET(ASSIMP_IMPORTERS_ENABLED "${ASSIMP_IMPORTERS_ENABLED} ${name}")
    SOURCE_GROUP(${name} FILES ${ARGN})
  ELSE()
    SET(${name}_SRC "")
    SET(ASSIMP_IMPORTERS_DISABLED "${ASSIMP_IMPORTERS_DISABLED} ${name}")
    add_definitions(-DASSIMP_BUILD_NO_${name}_IMPORTER)
  ENDIF()
ENDMACRO()

# if this variable is set to TRUE, the user can manually disable exporters by setting
# ASSIMP_BUILD_XXX_EXPORTER to FALSE for each exporter
# if this variable is set to FALSE, the user can manually enable exporters by setting
# ASSIMP_BUILD_XXX_EXPORTER to TRUE for each exporter
OPTION(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT "default value of all ASSIMP_BUILD_XXX_EXPORTER values" TRUE)

# macro to add the CMake Option ADD_ASSIMP_IMPORTER_<name> which enables compile of loader
# this way selective loaders can be compiled (reduces filesize + compile time)
MACRO(ADD_ASSIMP_EXPORTER name)
  IF (ASSIMP_NO_EXPORT)
	set(ASSIMP_EXPORTER_ENABLED FALSE)
  ELSEIF (ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT)
    set(ASSIMP_EXPORTER_ENABLED TRUE)
    IF (DEFINED ASSIMP_BUILD_${name}_EXPORTER AND NOT ASSIMP_BUILD_${name}_EXPORTER)
      set(ASSIMP_EXPORTER_ENABLED FALSE)
    ENDIF ()
  ELSE ()
    set(ASSIMP_EXPORTER_ENABLED ${ASSIMP_BUILD_${name}_EXPORTER})
  ENDIF ()

  IF (ASSIMP_EXPORTER_ENABLED)
    SET(ASSIMP_EXPORTERS_ENABLED "${ASSIMP_EXPORTERS_ENABLED} ${name}")
	LIST(APPEND ASSIMP_EXPORTER_SRCS ${ARGN})
    SOURCE_GROUP(${name}_EXPORTER FILES ${ARGN})
  ELSE()
    SET(ASSIMP_EXPORTERS_DISABLED "${ASSIMP_EXPORTERS_DISABLED} ${name}")
    add_definitions(-DASSIMP_BUILD_NO_${name}_EXPORTER)
  ENDIF()
ENDMACRO()

SET(ASSIMP_LOADER_SRCS "")
SET(ASSIMP_IMPORTERS_ENABLED "") # list of enabled importers
SET(ASSIMP_IMPORTERS_DISABLED "") # disabled importers list (used to print)

SET(ASSIMP_EXPORTER_SRCS "")
SET(ASSIMP_EXPORTERS_ENABLED "") # list of enabled exporters
SET(ASSIMP_EXPORTERS_DISABLED "") # disabled exporters list (used to print)

ADD_ASSIMP_IMPORTER( OBJ
  Obj/ObjFileData.h
  Obj/ObjFileImporter.cpp
  Obj/ObjFileImporter.h
  Obj/ObjFileMtlImporter.cpp
  Obj/ObjFileMtlImporter.h
  Obj/ObjFileParser.cpp
  Obj/ObjFileParser.h
  Obj/ObjTools.h
)

ADD_ASSIMP_EXPORTER( OBJ
  Obj/ObjExporter.h
  Obj/ObjExporter.cpp
)

if ((NOT ASSIMP_NO_EXPORT) OR (NOT ASSIMP_EXPORTERS_ENABLED STREQUAL ""))
	SET( Exporter_SRCS
	  Common/Exporter.cpp
	  CApi/AssimpCExport.cpp
	  ${HEADER_PATH}/BlobIOSystem.h
	)
	SOURCE_GROUP( Exporter FILES ${Exporter_SRCS})
endif()

SET( Extra_SRCS
  MD4FileData.h
)
SOURCE_GROUP( Extra FILES ${Extra_SRCS})

# irrXML
IF(HUNTER_ENABLED)
  hunter_add_package(irrXML)
  find_package(irrXML CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  # irrXML already included in contrib directory by parent CMakeLists.txt.
ENDIF(HUNTER_ENABLED)

# utf8
IF(HUNTER_ENABLED)
  hunter_add_package(utf8)
  find_package(utf8 CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  # utf8 is header-only, so Assimp doesn't need to do anything.
ENDIF(HUNTER_ENABLED)

# polyclipping
IF(HUNTER_ENABLED)
  hunter_add_package(polyclipping)
  find_package(polyclipping CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  SET( Clipper_SRCS
    ../contrib/clipper/clipper.hpp
    ../contrib/clipper/clipper.cpp
  )
  SOURCE_GROUP( Contrib\\Clipper FILES ${Clipper_SRCS})
ENDIF(HUNTER_ENABLED)

# poly2tri
IF(HUNTER_ENABLED)
  hunter_add_package(poly2tri)
  find_package(poly2tri CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  SET( Poly2Tri_SRCS
    ../contrib/poly2tri/poly2tri/common/shapes.cc
    ../contrib/poly2tri/poly2tri/common/shapes.h
    ../contrib/poly2tri/poly2tri/common/utils.h
    ../contrib/poly2tri/poly2tri/sweep/advancing_front.h
    ../contrib/poly2tri/poly2tri/sweep/advancing_front.cc
    ../contrib/poly2tri/poly2tri/sweep/cdt.cc
    ../contrib/poly2tri/poly2tri/sweep/cdt.h
    ../contrib/poly2tri/poly2tri/sweep/sweep.cc
    ../contrib/poly2tri/poly2tri/sweep/sweep.h
    ../contrib/poly2tri/poly2tri/sweep/sweep_context.cc
    ../contrib/poly2tri/poly2tri/sweep/sweep_context.h
  )
  SOURCE_GROUP( Contrib\\Poly2Tri FILES ${Poly2Tri_SRCS})
ENDIF(HUNTER_ENABLED)

# minizip/unzip
IF(HUNTER_ENABLED)
  hunter_add_package(minizip)
  find_package(minizip CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  SET( unzip_SRCS
    ../contrib/unzip/crypt.h
    ../contrib/unzip/ioapi.c
    ../contrib/unzip/ioapi.h
    ../contrib/unzip/unzip.c
    ../contrib/unzip/unzip.h
  )
  SOURCE_GROUP(Contrib\\unzip FILES ${unzip_SRCS})
ENDIF(HUNTER_ENABLED)

# zip (https://github.com/kuba--/zip)
IF(HUNTER_ENABLED)
  hunter_add_package(zip)
  find_package(zip CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  SET( ziplib_SRCS
    ../contrib/zip/src/miniz.h
    ../contrib/zip/src/zip.c
    ../contrib/zip/src/zip.h
  )

  # TODO if cmake required version has been updated to >3.12.0, collapse this to the second case only
  if(${CMAKE_VERSION} VERSION_LESS "3.12.0")
  	add_definitions(-DMINIZ_USE_UNALIGNED_LOADS_AND_STORES=0)
  else()
  	add_compile_definitions(MINIZ_USE_UNALIGNED_LOADS_AND_STORES=0)
  endif()

  SOURCE_GROUP( ziplib FILES ${ziplib_SRCS} )
ENDIF(HUNTER_ENABLED)

# openddlparser
IF(HUNTER_ENABLED)
  hunter_add_package(openddlparser)
  find_package(openddlparser CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  SET ( openddl_parser_SRCS
    ../contrib/openddlparser/code/OpenDDLParser.cpp
    ../contrib/openddlparser/code/DDLNode.cpp
    ../contrib/openddlparser/code/OpenDDLCommon.cpp
    ../contrib/openddlparser/code/OpenDDLExport.cpp
    ../contrib/openddlparser/code/Value.cpp
    ../contrib/openddlparser/code/OpenDDLStream.cpp
    ../contrib/openddlparser/include/openddlparser/OpenDDLParser.h
    ../contrib/openddlparser/include/openddlparser/OpenDDLParserUtils.h
    ../contrib/openddlparser/include/openddlparser/OpenDDLCommon.h
    ../contrib/openddlparser/include/openddlparser/OpenDDLExport.h
    ../contrib/openddlparser/include/openddlparser/OpenDDLStream.h
    ../contrib/openddlparser/include/openddlparser/DDLNode.h
    ../contrib/openddlparser/include/openddlparser/Value.h
  )
  SOURCE_GROUP( Contrib\\openddl_parser FILES ${openddl_parser_SRCS})
ENDIF(HUNTER_ENABLED)

# Open3DGC
IF(HUNTER_ENABLED)
  # Nothing to do, not available in Hunter yet.
ELSE(HUNTER_ENABLED)
  SET ( open3dgc_SRCS
    ../contrib/Open3DGC/o3dgcAdjacencyInfo.h
    ../contrib/Open3DGC/o3dgcArithmeticCodec.cpp
    ../contrib/Open3DGC/o3dgcArithmeticCodec.h
    ../contrib/Open3DGC/o3dgcBinaryStream.h
    ../contrib/Open3DGC/o3dgcCommon.h
    ../contrib/Open3DGC/o3dgcDVEncodeParams.h
    ../contrib/Open3DGC/o3dgcDynamicVectorDecoder.cpp
    ../contrib/Open3DGC/o3dgcDynamicVectorDecoder.h
    ../contrib/Open3DGC/o3dgcDynamicVectorEncoder.cpp
    ../contrib/Open3DGC/o3dgcDynamicVectorEncoder.h
    ../contrib/Open3DGC/o3dgcDynamicVector.h
    ../contrib/Open3DGC/o3dgcFIFO.h
    ../contrib/Open3DGC/o3dgcIndexedFaceSet.h
    ../contrib/Open3DGC/o3dgcIndexedFaceSet.inl
    ../contrib/Open3DGC/o3dgcSC3DMCDecoder.h
    ../contrib/Open3DGC/o3dgcSC3DMCDecoder.inl
    ../contrib/Open3DGC/o3dgcSC3DMCEncodeParams.h
    ../contrib/Open3DGC/o3dgcSC3DMCEncoder.h
    ../contrib/Open3DGC/o3dgcSC3DMCEncoder.inl
    ../contrib/Open3DGC/o3dgcTimer.h
    ../contrib/Open3DGC/o3dgcTools.cpp
    ../contrib/Open3DGC/o3dgcTriangleFans.cpp
    ../contrib/Open3DGC/o3dgcTriangleFans.h
    ../contrib/Open3DGC/o3dgcTriangleListDecoder.h
    ../contrib/Open3DGC/o3dgcTriangleListDecoder.inl
    ../contrib/Open3DGC/o3dgcTriangleListEncoder.h
    ../contrib/Open3DGC/o3dgcTriangleListEncoder.inl
    ../contrib/Open3DGC/o3dgcVector.h
    ../contrib/Open3DGC/o3dgcVector.inl
  )
  SOURCE_GROUP( Contrib\\open3dgc FILES ${open3dgc_SRCS})
ENDIF(HUNTER_ENABLED)

# Check dependencies for glTF importer with Open3DGC-compression.
# RT-extensions is used in "contrib/Open3DGC/o3dgcTimer.h" for collecting statistics. Pointed file
# has implementation for different platforms: WIN32, __MACH__ and other ("else" block).
FIND_PACKAGE(RT QUIET)
IF (NOT HUNTER_ENABLED AND (RT_FOUND OR MSVC))
  SET( ASSIMP_IMPORTER_GLTF_USE_OPEN3DGC 1 )
  ADD_DEFINITIONS( -DASSIMP_IMPORTER_GLTF_USE_OPEN3DGC=1 )
ELSE ()
  SET (open3dgc_SRCS "")
  MESSAGE (INFO " Hunter enabled or RT-extension not found. glTF import/export will be built without Open3DGC-compression.")
  #!TODO: off course is better to remove statistics timers from o3dgc codec. Or propose to choose what to use.
ENDIF ()

# RapidJSON
IF(HUNTER_ENABLED)
  hunter_add_package(RapidJSON)
  find_package(RapidJSON CONFIG REQUIRED)
ELSE(HUNTER_ENABLED)
  INCLUDE_DIRECTORIES( "../contrib/rapidjson/include" )
  INCLUDE_DIRECTORIES( "../contrib" )
ENDIF(HUNTER_ENABLED)

# VC2010 fixes
if(MSVC10)
  option( VC10_STDINT_FIX "Fix for VC10 Compiler regarding pstdint.h redefinition errors" OFF )
  if( VC10_STDINT_FIX )
    ADD_DEFINITIONS( -D_STDINT )
  endif( VC10_STDINT_FIX )
endif(MSVC10)

ADD_DEFINITIONS( -DASSIMP_BUILD_DLL_EXPORT )

if ( MSVC )
  ADD_DEFINITIONS( -D_SCL_SECURE_NO_WARNINGS )
  ADD_DEFINITIONS( -D_CRT_SECURE_NO_WARNINGS )
endif ( MSVC )

IF(NOT HUNTER_ENABLED)
  if (UNZIP_FOUND)
    SET (unzip_compile_SRCS "")
  else (UNZIP_FOUND)
    SET (unzip_compile_SRCS ${unzip_SRCS})
    INCLUDE_DIRECTORIES( "../contrib/unzip/" )
  endif (UNZIP_FOUND)
ENDIF(NOT HUNTER_ENABLED)

MESSAGE(STATUS "Enabled importer formats:${ASSIMP_IMPORTERS_ENABLED}")
MESSAGE(STATUS "Disabled importer formats:${ASSIMP_IMPORTERS_DISABLED}")

MESSAGE(STATUS "Enabled exporter formats:${ASSIMP_EXPORTERS_ENABLED}")
MESSAGE(STATUS "Disabled exporter formats:${ASSIMP_EXPORTERS_DISABLED}")

SET( assimp_src
  # Assimp Files
  ${Core_SRCS}
  ${CApi_SRCS}
  ${Common_SRCS}
  ${Logging_SRCS}
  ${Exporter_SRCS}
  ${PostProcessing_SRCS}
  ${MaterialSystem_SRCS}
  ${STEPParser_SRCS}
#  ${Step_SRCS} check if we need a different approach

  # Model Support
  ${ASSIMP_LOADER_SRCS}
  ${ASSIMP_EXPORTER_SRCS}

  # Third-party libraries
  ${IrrXML_SRCS}
  ${unzip_compile_SRCS}
  ${Poly2Tri_SRCS}
  ${Clipper_SRCS}
  ${openddl_parser_SRCS}
  ${open3dgc_SRCS}
  ${ziplib_SRCS}
  # Necessary to show the headers in the project when using the VC++ generator:

  ${PUBLIC_HEADERS}
  ${COMPILER_HEADERS}
)
ADD_DEFINITIONS( -DOPENDDLPARSER_BUILD )

IF(NOT HUNTER_ENABLED)
  INCLUDE_DIRECTORIES(
      ${IRRXML_INCLUDE_DIR}
      ../contrib/openddlparser/include
  )
ENDIF(NOT HUNTER_ENABLED)

IF (ASSIMP_BUILD_NONFREE_C4D_IMPORTER)
  SET( assimp_src ${assimp_src} ${C4D_SRCS})
  INCLUDE_DIRECTORIES(${C4D_INCLUDES})
ENDIF (ASSIMP_BUILD_NONFREE_C4D_IMPORTER)

ADD_LIBRARY( assimp ${assimp_src} )
ADD_LIBRARY(assimp::assimp ALIAS assimp)

TARGET_INCLUDE_DIRECTORIES ( assimp PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/../include>
  $<INSTALL_INTERFACE:include>
)

IF(HUNTER_ENABLED)
  TARGET_LINK_LIBRARIES(assimp
      PUBLIC
      polyclipping::polyclipping
      irrXML::irrXML
      openddlparser::openddl_parser
      poly2tri::poly2tri
      minizip::minizip
      ZLIB::zlib
      RapidJSON::rapidjson
      utf8::utf8
      zip::zip
  )
ELSE(HUNTER_ENABLED)
  TARGET_LINK_LIBRARIES(assimp ${ZLIB_LIBRARIES} ${OPENDDL_PARSER_LIBRARIES} ${IRRXML_LIBRARY} )
ENDIF(HUNTER_ENABLED)

if(ASSIMP_ANDROID_JNIIOSYSTEM)
  set(ASSIMP_ANDROID_JNIIOSYSTEM_PATH port/AndroidJNI)
  add_subdirectory(../${ASSIMP_ANDROID_JNIIOSYSTEM_PATH}/ ../${ASSIMP_ANDROID_JNIIOSYSTEM_PATH}/)
  target_link_libraries(assimp android_jniiosystem)
endif(ASSIMP_ANDROID_JNIIOSYSTEM)

IF (ASSIMP_BUILD_NONFREE_C4D_IMPORTER)
  TARGET_LINK_LIBRARIES(assimp optimized ${C4D_RELEASE_LIBRARIES})
  TARGET_LINK_LIBRARIES(assimp debug ${C4D_DEBUG_LIBRARIES})
  TARGET_LINK_LIBRARIES(assimp ${C4D_EXTRA_LIBRARIES})
ENDIF (ASSIMP_BUILD_NONFREE_C4D_IMPORTER)

if( MSVC )
  # in order to prevent DLL hell, each of the DLLs have to be suffixed with the major version and msvc prefix
  # CMake 3.12 added a variable for this
  if(MSVC_TOOLSET_VERSION)
    set(MSVC_PREFIX "vc${MSVC_TOOLSET_VERSION}")
  else()
    if( MSVC70 OR MSVC71 )
      set(MSVC_PREFIX "vc70")
    elseif( MSVC80 )
      set(MSVC_PREFIX "vc80")
    elseif( MSVC90 )
      set(MSVC_PREFIX "vc90")
    elseif( MSVC10 )
      set(MSVC_PREFIX "vc100")
    elseif( MSVC11 )
      set(MSVC_PREFIX "vc110")
    elseif( MSVC12 )
      set(MSVC_PREFIX "vc120")
    elseif( MSVC_VERSION LESS 1910)
      set(MSVC_PREFIX "vc140")
    elseif( MSVC_VERSION LESS 1920)
      set(MSVC_PREFIX "vc141")
    elseif( MSVC_VERSION LESS 1930)
      set(MSVC_PREFIX "vc142")
    else()
      MESSAGE(WARNING "unknown msvc version ${MSVC_VERSION}")
      set(MSVC_PREFIX "vc150")
    endif()
  endif()
  set(LIBRARY_SUFFIX "${ASSIMP_LIBRARY_SUFFIX}-${MSVC_PREFIX}-mt" CACHE STRING "the suffix for the assimp windows library")
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "WindowsStore")
    target_compile_definitions(assimp PUBLIC WindowsStore)
    TARGET_LINK_LIBRARIES(assimp advapi32)
    #set(WindowsStore TRUE)
endif()
SET_TARGET_PROPERTIES( assimp PROPERTIES
  VERSION ${ASSIMP_VERSION}
  SOVERSION ${ASSIMP_SOVERSION} # use full version
  OUTPUT_NAME assimp${LIBRARY_SUFFIX}
)

if (APPLE)
  SET_TARGET_PROPERTIES( assimp PROPERTIES
    INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${ASSIMP_LIB_INSTALL_DIR}"
  )

  if (BUILD_FRAMEWORK)
    SET_TARGET_PROPERTIES( assimp PROPERTIES
      FRAMEWORK TRUE
      FRAMEWORK_VERSION C
      MACOSX_FRAMEWORK_IDENTIFIER net.sf.assimp
      PUBLIC_HEADER "${PUBLIC_HEADERS}"
    )

    # PUBLIC_HEADER option does not support directory structure creation
    # add ./Compiler/*.h to assimp.framework via copy command
    ADD_CUSTOM_COMMAND(TARGET assimp POST_BUILD
      COMMAND "${CMAKE_COMMAND}" -E copy_directory
         "../${HEADER_PATH}/Compiler"
         assimp.framework/Headers/Compiler
      COMMENT "Copying public ./Compiler/ header files to framework bundle's Headers/Compiler/")
  ENDIF(BUILD_FRAMEWORK)
ENDIF(APPLE)

# Build against external unzip, or add ../contrib/unzip so
# assimp can #include "unzip.h"
IF(NOT HUNTER_ENABLED)
  if (UNZIP_FOUND)
    INCLUDE_DIRECTORIES(${UNZIP_INCLUDE_DIRS})
    TARGET_LINK_LIBRARIES(assimp ${UNZIP_LIBRARIES})
  else (UNZIP_FOUND)
    INCLUDE_DIRECTORIES("../")
  endif (UNZIP_FOUND)
ENDIF(NOT HUNTER_ENABLED)

# Add RT-extension library for glTF importer with Open3DGC-compression.
IF (RT_FOUND AND ASSIMP_IMPORTER_GLTF_USE_OPEN3DGC)
  TARGET_LINK_LIBRARIES(assimp ${RT_LIBRARY})
ENDIF (RT_FOUND AND ASSIMP_IMPORTER_GLTF_USE_OPEN3DGC)

IF(HUNTER_ENABLED)
  INSTALL( TARGETS assimp
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
    ARCHIVE DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
    RUNTIME DESTINATION ${ASSIMP_BIN_INSTALL_DIR}
    FRAMEWORK DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
    COMPONENT ${LIBASSIMP_COMPONENT}
    INCLUDES DESTINATION "include")
ELSE(HUNTER_ENABLED)
INSTALL( TARGETS assimp
    LIBRARY DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
    ARCHIVE DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
    RUNTIME DESTINATION ${ASSIMP_BIN_INSTALL_DIR}
    FRAMEWORK DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
    COMPONENT ${LIBASSIMP_COMPONENT})
ENDIF(HUNTER_ENABLED)
INSTALL( FILES ${PUBLIC_HEADERS} DESTINATION ${ASSIMP_INCLUDE_INSTALL_DIR}/assimp COMPONENT assimp-dev)
INSTALL( FILES ${COMPILER_HEADERS} DESTINATION ${ASSIMP_INCLUDE_INSTALL_DIR}/assimp/Compiler COMPONENT assimp-dev)

if (ASSIMP_ANDROID_JNIIOSYSTEM)
  INSTALL(FILES ${HEADER_PATH}/${ASSIMP_ANDROID_JNIIOSYSTEM_PATH}/AndroidJNIIOSystem.h
    DESTINATION ${ASSIMP_INCLUDE_INSTALL_DIR}
    COMPONENT assimp-dev)
ENDIF(ASSIMP_ANDROID_JNIIOSYSTEM)

if(MSVC AND ASSIMP_INSTALL_PDB)
  # When only the static library is built, these properties must
  # be set to ensure the static lib .pdb is staged for installation.
  IF(NOT BUILD_SHARED_LIBS)
    SET_TARGET_PROPERTIES( assimp PROPERTIES
      COMPILE_PDB_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMPILE_PDB_NAME assimp${LIBRARY_SUFFIX}
      COMPILE_PDB_NAME_DEBUG assimp${LIBRARY_SUFFIX}${CMAKE_DEBUG_POSTFIX}
    )
  ENDIF()

  IF(CMAKE_GENERATOR MATCHES "^Visual Studio")
    install(FILES ${Assimp_BINARY_DIR}/code/Debug/assimp${LIBRARY_SUFFIX}${CMAKE_DEBUG_POSTFIX}.pdb
      DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
      CONFIGURATIONS Debug
    )
    install(FILES ${Assimp_BINARY_DIR}/code/RelWithDebInfo/assimp${LIBRARY_SUFFIX}.pdb
      DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
      CONFIGURATIONS RelWithDebInfo
    )
  ELSE()
    install(FILES ${Assimp_BINARY_DIR}/code/assimp${LIBRARY_SUFFIX}${CMAKE_DEBUG_POSTFIX}.pdb
      DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
      CONFIGURATIONS Debug
    )
    install(FILES ${Assimp_BINARY_DIR}/code/assimp${LIBRARY_SUFFIX}.pdb
      DESTINATION ${ASSIMP_LIB_INSTALL_DIR}
      CONFIGURATIONS RelWithDebInfo
    )
  ENDIF()
ENDIF ()

if (ASSIMP_COVERALLS)
    include(Coveralls)

    set(COVERAGE_SRCS ${assimp_src} ${TEST_SRCS} )

    # Create the coveralls target.
    coveralls_setup(
        "${COVERAGE_SRCS}" # The source files.
        ON                 # If we should upload.
        "${PROJECT_SOURCE_DIR}/cmake-modules/") # (Optional) Alternate project cmake module path.
ENDIF()
