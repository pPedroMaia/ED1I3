#include <iostream>
using namespace std;

 
void
merge (int *v, int esq, int meio, int dir)
{
  
int n1 = meio - esq + 1;
  
int n2 = dir - meio;
  
 
int *esqV = new int[n1];
  
int *dirV = new int[n2];
  
 
for (int i = 0; i < n1; i++)
    {
      
esqV[i] = v[esq + i];
  
} 
 
for (int j = 0; j < n2; j++)
    {
      
dirV[j] = v[meio + 1 + j];
    
} 
 
int i = 0;
  
int j = 0;
  
int k = esq;
  
 
while (i < n1 && j < n2)
    {
      
if (esqV[i] <= dirV[j])
	{
	  
v[k] = esqV[i];
	  
i++;
	
}
      else
	{
	  
v[k] = dirV[j];
	  
j++;
	
}
      
k++;
    
}
  
 
while (i < n1)
    {
      
v[k] = esqV[i];
      
i++;
      
k++;
    
}
  
 
while (j < n2)
    {
      
v[k] = dirV[j];
      
j++;
      
k++;
    
}
  
 
delete[]esqV;
  
delete[]dirV;

}


 
void
mergeSort (int *v, int esq, int dir)
{
  
if (esq < dir)
    {
      
int meio = esq + (dir - esq) / 2;
      
 
mergeSort (v, esq, meio);
      
mergeSort (v, meio + 1, dir);
      
 
merge (v, esq, meio, dir);
    
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
  
 
mergeSort (v, 0, n - 1);
  
 
cout << "Vetor depois da ordenacao: ";
  
for (int i = 0; i < n; i++)
    {
      
cout << v[i] << " ";
    
} 
cout << endl;
  
 
return 0;

}
