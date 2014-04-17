if [ $1 == 'clean' ]; then
	gmake clean
fi;
exe='./ej3.debug -i input/2.txt -o stdout -d stderr'
valgrind_param='--leak-check=yes --show-reachable=yes --error-exitcode=1 -q'
clear && gmake debug && valgrind $valgrind_param $exe && $exe
