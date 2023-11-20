#include <jni.h>
#include <stdio.h>
#include “TestJNI.h"

JNIEXPORT jint JNICALL Java_TestJNI_add(JNIEnv *env , jobject
thisObj , jint n1 , jint n2)
 {
jint res;
res=n1+n2;
return res;
}



Compile c-program:
$gcc -fPIC -I /usr/local/jdk1.8.0_91/include -I/usr/ 
local/jdk1.8.0_91/include/linux -o libcal.so –shared 
TestJNI.c
6. Run java program
$java -Djava.library.path=. TestJNI