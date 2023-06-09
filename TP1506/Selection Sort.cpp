#include <iostream>
using namespace std;

 
void
troca (int &a, int &b)
{
  
int temp = a;
  
a = b;
  
b = temp;

} 
 
void

selectionSort (int *v, int n)
{
  
for (int i = 0; i < n - 1; i++)
    {
      
int minIndex = i;
      
 
for (int j = i + 1; j < n; j++)
	{
	  
if (v[j] < v[minIndex])
	    {
	      
minIndex = j;
	    
}
	
}
      
 
troca (v[i], v[minIndex]);
    
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
  
 
selectionSort (v, n);
  
 
cout << "Vetor depois da ordenacao: ";
  
for (int i = 0; i < n; i++)
    {
      
cout << v[i] << " ";
    
} 
cout << endl;
  
 
return 0;

}


