#include <iostream>
using namespace std;

 
void
insertionSort (int *v, int n)
{
  
for (int i = 1; i < n; i++)
    {
      
int chave = v[i];
      
int j = i - 1;
      
 
while (j >= 0 && v[j] > chave)
	{
	  
v[j + 1] = v[j];
	  
j--;
	
}
      
 
v[j + 1] = chave;
    
}

}


 
int
main ()
{
  
int v[8] = { 49, 38, 58, 87, 34, 93, 26, 13 };
  
int n = sizeof (v) / sizeof (v[0]);
  
 
cout << "Vetor antes da ordenacao: ";
  
for (int i = 0; i < n; i++)
    {
      
cout << v[i] << " ";
    
} 
cout << endl;
  
 
insertionSort (v, n);
  
 
cout << "Vetor depois da ordenacao: ";
  
for (int i = 0; i < n; i++)
    {
      
cout << v[i] << " ";
    
} 
cout << endl;
  
 
return 0;

}


