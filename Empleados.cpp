#include <iostream>
#include<algorithm>
#include <string>

using namespace std;


int mostrarMenu()
{
    int opcion;

    cout << endl
         << "                   MENÚ       " << endl;
    cout << "      1. Opcion 1: Buscar el nombre de un empleado por su número de empleado." << endl;
    cout << "      2. Opcion 2: Buscar el número de empleado por su nombre." << endl;
    cout << "      3. Opcion 3: Saber si hay nombres similares entre sus empleados." << endl;
    cout << "      4. Opcion 4: Mostrar empleados de forma ascendente/descendente por número de empleado" << endl;
    cout << "      5. Salir" << endl;
    cout << "         Ingrese su opción: ";
    cin >> opcion;
    return opcion;
}

int main()
{
    string medio;
    string aux, value, aux2, value2, matriz[20][2];
    int aux3, aux4, numeros[20];
    char contador = 0, name[20];
    int opcion, primari = 0, center = 0, finally = 2;
    char bandera = 'F';



    for (int i = 0; i < 20; i++)
    {
        cout << "   Ingrese el numero del empleado ";
        cin >> matriz[i][1];
         cout << "   Ingrese el nombre del empleado ";
         cin >> matriz[i][0];
    }



   for (int i = 0; i < 20; i++) {
        cout << matriz[i][1] << " ";
    }



    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            aux3 = stoi(matriz[j][1]);
            aux4 = stoi(matriz[i][1]);
            if (aux3 > aux4)
            {
                aux = matriz[i][0];
                aux2 = matriz[i][1];
                matriz[i][0] = matriz[j][0];
                matriz[i][1] = matriz[j][1];
                matriz[j][0] = aux;
                matriz[j][1] = aux2;
            }
        }
    }

    cout << endl
         << "Lista de empleados" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << endl
             << matriz[i][0] << " ";
        cout << matriz[i][1] << " ";
    }

    int opcionSeleccionada;
    do
    {
        opcionSeleccionada = mostrarMenu();

        switch (opcionSeleccionada)
        {
        case 1:
            cout << "      Buscar el nombre de un empleado por su número de empleado." << endl;
            cout << "Ingrese el numero del empleado" << endl;
            cin >> value;
            primari = 0;
            center = 0;
            finally = 2;
            while (primari <= finally)
            {
                center = (primari + finally) / 2; // 1
                medio = center;
                value2 = matriz[center][1]; // 2 >1 c=0 & 1
                if (value2 == value)
                {
                    cout << "      empleado " << matriz[center][0] << endl;
                    cout << "      Number " << matriz[center][1] << endl;
                    bandera = 'v';

                    break;
                }
                else if (value2 > value)
                {
                    finally = center - 1;
                }
                else
                {
                    primari = center + 1;
                }
                /* code */
            }

            if (bandera == 'F')
            {
                cout << "      Not found" << endl;
            }
            bandera = 'F';

            break;

        case 2:
            cout << "      Buscar el número de empleado por su nombre." << endl;

            cout << "   Ingrese el nombre del empleado" << endl;
            cin >> value;
            for (int i = 0; i < 20; i++)
            {
                if (matriz[i][0] == value)
                {
                    cout << " Number " << matriz[i][1];
                }
            }

            break;

        case 3:
            cout << "       Saber si hay nombres similares entre sus empleados." << endl;
            contador = 0;

            for (int i = 0; i < 2; i++)
            {
                if (matriz[i][0] == matriz[i + 1][0])
                {
                    cout << "   Empleados encontrados";
                    contador++;
                };
            }
            if (contador > 0)
            {
                cout << "   Empleados encontrados: " << contador << endl;
                ;
            }
            else
            {
                cout << "   Not found" << endl;
            }

            break;

        case 4:
            cout << "       Mostrar empleados de forma ascendente/descendente por número de empleado" << endl;
            cout << "         ingrese 1 para ver empleados de forma ascendente o 2 para ver de forma descendente " << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                for (int i = 0; i < 20; i++)
                {
                    cout << endl
                         << matriz[i][0] << " ";
                    cout << matriz[i][1] << " ";
                }
            }
            else if (opcion == 2)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                           aux3 = stoi(matriz[j][1]);
            aux4 = stoi(matriz[i][1]);
                        if (aux3 < aux4)
                        {

                            aux = matriz[i][0];
                            aux2 = matriz[i][1];
                            matriz[i][0] = matriz[j][0];
                            matriz[i][1] = matriz[j][1];
                            matriz[j][0] = aux;
                            matriz[j][1] = aux2;
                        }
                    }
                }
                for (int i = 0; i < 20; i++)
                {
                    cout << endl
                         << matriz[i][0] << " ";
                    cout << matriz[i][1] << " ";
                }
            }
            else
            {
                cout << "   opcion no valida";
            }

            break;

        case 5:
            cout << "   ...Saliendo del programa..." << endl;
            break;

        default:
            cout << "      Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }

    } while (opcionSeleccionada != 5);
    return 0;
}