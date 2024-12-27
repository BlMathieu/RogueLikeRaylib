# Spécifier la version minimale de CMake
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(rlib)

# Spécifier le standard C++ à utiliser
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver tous les fichiers .cpp dans le répertoire courant et sous-répertoires
file(GLOB_RECURSE SOURCES "*.cpp")

# Ajouter l'exécutable, en utilisant tous les fichiers source détectés
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier les bibliothèques nécessaires (ici, raylib et d'autres)
target_link_libraries(${PROJECT_NAME} raylib GL pthread dl X11)