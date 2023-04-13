cmake_minimum_required(VERSION 3.25)
project(new_biblio)

set(CMAKE_CXX_STANDARD 17)

add_executable(new_biblio main.cpp CD.cpp DVD.cpp Livre.cpp Media.cpp Mediatheque.cpp RessourceNumerique.cpp Revue.cpp VHS.cpp)
