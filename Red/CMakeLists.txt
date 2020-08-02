cmake_minimum_required(VERSION 2.6)
project(RED)

include_directories(
  src
  contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-x86/openal-soft/include
    contrib/msvc-windows-x86/ogg/include
    contrib/msvc-windows-x86/vorbis/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/vorbis/lib
  )

else()
  include_directories(
    /usr/X11R6/include
    /usr/local/include
  )

  link_directories(
    /usr/X11R6/lib
    /usr/local/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(red
  src/red/entity.cpp
  src/red/core.cpp
  src/red/Component.cpp
  src/red/MeshRenderer.cpp
  src/red/ShaderProgram.cpp
  src/red/VertexArray.cpp
  src/red/VertexBuffer.cpp
  src/red/Sound.cpp
  src/red/Texture.cpp
  src/red/KeyboardInput.cpp
  src/red/Transform.cpp
  src/red/Environment.cpp
  src/red/Screen.cpp
  src/red/Camera.cpp
  src/red/BoxCollision.cpp

  src/red/Red.h
  src/red/entity.h
  src/red/core.h
  src/red/Component.h
  src/red/MeshRenderer.h
  src/red/ShaderProgram.h
  src/red/VertexArray.h
  src/red/VertexBuffer.h
  src/red/Sound.h
  src/red/Texture.h
  src/red/KeyboardInput.h
  src/red/Transform.h
  src/red/Environment.h
  src/red/Screen.h
  src/red/Camera.h
  src/red/BoxCollision.h

  contrib/stb_image/stb_image.cpp
  contrib/stb_image/stb_image.h
)

if(MSVC)
  target_link_libraries(red
    SDL2 glew32 opengl32 OpenAL32 ogg vorbis vorbisfile
  )
else()
  target_link_libraries(red
    SDL2 GLU GLEW GL AL ogg vorbis vorbisfile
  )
endif()

add_executable(game
  src/game/main.cpp
)

target_link_libraries(game red)

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()