/*
Atsa y la serie recursiva

Descripción
A Atsa le gusta mucho jugar con arreglos. Esta vez decidió trabajar con en siguiente.

Comenzó con H0:=[1]
Luego para obtener H1 concatenó H0 + [2] + H0. Así H1:=[1,2,1]
Y así sucesivamente. De manera que Hi:=Hi−1 + [2^i] + Hi−1.
Ese proceso lo continuó infinitamente hasta obtener el arreglo H=[1,2,1,4,1,2,1,8,...].

Después se le ocurrió que sería interesante calcular la suma de los elementos en un subarreglo.

Entrada
La primera línea contiene el número Q de sumas que debes calcular.

Cada una de las siguientes Q líneas contiene dos enteros ai y bi.

Salida
Imprime Q números separados uno en cada línea.

El i-ésimo número deberá ser igual a suma de los elementos en el intervalo [ai,bi].

Ejemplo 1
Entrada	
1
3 6
Salida		
8

Explicación
1,2,[1,4,1,2],1,8,...
1 + 4 + 1 + 2 = 8

Ejemplo 2
Entrada: 
3
176 177
5 9
12 40
	
Salida: 
17
13
108

Límites
1≤Q≤10^4
1≤ai≤bi≤10^15
*/
//SOL:
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull get(ull x){return x?get(x/2)+1:0;}
ull po(ull a,ull p){
    ull res=1;
    while(p){
      if(p&1)res*=a;
      a*=a;
      p>>=1;
   }
   return res;
}
ull s(ull x){
	ull n=get(x),s=0,t=1,m=po(2,n);
	vector<ull>c(n+1);
	for(ull i=n;i>0;i--){
		c[i]=x/m;
		c[i]-=s;
		s+=c[i];
		m/=2;
	}
	c[0]=x-s;
	s=0;
	for(ull i=0;i<=n;i++,t*=2)
		s+=c[i]*t;
	return s;
}
int main(){
	ull n,a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		cout<<s(b)-s(a-1)<<endl;
	}
	return 0;
}
