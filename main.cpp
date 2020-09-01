#include <iostream>
#include <fstream>

void Ingresa(int Elementos[],int Tam,int Copia[]);

void Dividir(int Elementos[],int inicial,int final);
void Fucionar(int Elementos[],int pinicial,int pfinal, int medio);
using namespace std;

int main() {
   ofstream ArchivoOrde;
  int Tam;
  int Elemento[Tam];
  int Copia[Tam];
  
  cout << "Ingrese el tamaño del Arreglo: ";
  cin >> Tam;

  Ingresa(Elemento,Tam,Copia);

  Dividir (Elemento,0,Tam-1);
  ArchivoOrde.open("mergesort", ios::app);
  ArchivoOrde << "Arreglo Ordenado {";

  for(int i=0;i<Tam;i++)
  {
    cout << Elemento[i] << " ";
    ArchivoOrde << Elemento[i] << " ";
  }
  ArchivoOrde << "}\n";
  ArchivoOrde.close();
}
void Ingresa(int Elementos[],int Tam,int Copia[])
{
  ofstream ArchivoOrde;
  ArchivoOrde.open("mergesort", ios::app);
  ArchivoOrde << "Arreglo Original: {";

  for(int i=0;i<Tam;i++)
  {
    cout << "Ingrese el elemento " << i+1 << ": ";
    cin >> Elementos[i];
    Copia[i]=Elementos[i];

    ArchivoOrde << Elementos[i] << " ";
  }
  ArchivoOrde << "}\n";
  ArchivoOrde.close();
}

void Dividir(int Elementos[],int inicial,int final)
{
  int Mitad;
  if(inicial<final)
  {
    Mitad =(final+inicial)/2;
    Dividir(Elementos, inicial,Mitad);
    Dividir(Elementos, Mitad+1,final);
    Fucionar(Elementos,inicial,final,Mitad);
  }
}
void Fucionar(int Elementos[],int pinicial,int pfinal, int medio)
{
  int i,j,k,temp[pfinal-pinicial+1];
  i=pinicial;
  k=0;
  j=medio+1;

  while(i<=medio && j<=pfinal)
  {
    if(Elementos[i]<Elementos[j])
    {
      temp[k]=Elementos[i];
      k++;
      i++;
    }else
    {
      temp[k]=Elementos[j];
      k++;
      j++;
    }
  }
  while(i<=medio)
  {
    temp[k]=Elementos[i];
    k++;
    i++;
  }
  while(j<=pfinal)
  {
    temp[k]=Elementos[j];
    j++;
    k++;
  }
  for(i=pinicial;i<=pfinal;i++)
  {
    Elementos[i]=temp[i-pinicial];
  }

}
