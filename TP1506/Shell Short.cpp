
#include <iostream>
  using namespace std;

 
void
shellSort (int *v, int n)
{
  
for (int esp = n / 2; esp > 0; esp /= 2)
    {
      
for (int i = esp; i < n; i++)
	{
	  
int temp = v[i];
	  
int j = i;
	  
 
while (j >= esp && v[j - esp] > temp)
	    {
	      
v[j] = v[j - esp];
	      
j -= esp;
	    
}
	  
 
v[j] = temp;
	
}
    
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
  
 
shellSort (v, n);
  
 
cout << "Vetor depois da ordenacao: ";
  
for (int i = 0; i < n; i++)
    {
      
cout << v[i] << " ";
    
} 
cout << endl;
  
 
return 0;

}
