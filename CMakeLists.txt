cmake_minimum_required(VERSION 3.23)
project(mimuw-algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(bazarek labs/lab01/bazarek.cpp)
add_executable(matryca labs/lab01/matryca.cpp)
add_executable(sortowanie labs/lab02/sortowanie.cpp)
add_executable(mecze labs/lab03/mecze.cpp)
add_executable(kin_dp labs/lab04/kin_dp.cpp)
add_executable(kin_segtree labs/lab04/kin_segtree.cpp)
add_executable(malowanie labs/lab05/malowanie.cpp)
add_executable(dyn_vector labs/lab06/dyn_vector.cpp)
add_executable(dyn_splay labs/lab06/dyn_splay.cpp)
add_executable(projekty labs/lab07/projekty.cpp)
add_executable(kapitan labs/lab08/kapitan.cpp)
add_executable(park labs/lab09/park.cpp)
add_executable(lex labs/lab10/lex.cpp)

add_executable(komitet graded/graded1/komitet.cpp)
add_executable(choinka graded/graded2/choinka.cpp)

add_executable(przedzialy exams/2021/przedzialy.cpp)
add_executable(estetyczne exams/2016p/estetyczne.cpp)
add_executable(urozmaicone exams/2021p/urozmaicone.cpp)
add_executable(ciag exams/2020p/ciag.cpp)
add_executable(trojki exams/2020/trojki.cpp)
add_executable(podzielnosc exams/2019p/podzielnosc.cpp)
add_executable(jedynki exams/2009/jedynki.cpp)
add_executable(roznica exams/2010/roznica.cpp)
add_executable(podciagi_rosnace exams/2017/podciagi_rosnace.cpp)
add_executable(suma_kwadratow exams/2017p/suma_kwadratow.cpp)
add_executable(perly exams/2018/perly.cpp)
add_executable(parking exams/2015/parking.cpp)
add_executable(odwracanie exams/2022/odwracanie.cpp)
add_executable(projekty_egz exams/2019/projekty.cpp)
add_executable(gielda exams/2023/gielda.cpp)
add_executable(marszruta exams/2023/marszruta.cpp)
