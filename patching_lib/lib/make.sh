read -p "static/shared/clean? st/sh/c: " inp

if [ "$inp" = "st" ]; then
   gcc -c operation.c
   gcc -c multiply.c
   gcc -c subs.c
   gcc -c divide.c
   ar rcs libmath.a operation.o multiply.o subs.o divide.o
   echo
   echo "~~~~ libmath.a ~~~~~"
   ar t libmath.a
elif [ "$inp" = "sh" ]; then
   gcc -fPIC -shared operation.c multiply.c subs.c divide.c -o libmath.so
else
   rm *.o
fi
