#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Robo
{
    int identificador;
    char nome[50];
    int energia;
    int nivel;
    int l, c;
};

void cadastrar(Robo &robo, int id);
void listar(Robo robos[], int totalDeRobos);
void simularMissao(Robo robos[], int totalDeRobos);
void recuperarRobo(Robo robos[], int totalDeRobos);
void mostrarCampo(Robo robos[], int totalDeRobos);

int main()
{
    srand(time(NULL));

    Robo robos[4];
    int totalDeRobos = 0;
    int op;

    do
    {
        cout << "\n--- Sistema de Gerenciamento de Robos ---\n";
        cout << "1 - Cadastrar robo\n";
        cout << "2 - Listar robos\n";
        cout << "3 - Simular missao\n";
        cout << "4 - Mostrar campo de missao\n";
        cout << "5 - Recuperar robo\n";
        cout << "6 - Sair\n";
        cout << "Escolha uma Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            if (totalDeRobos < 4)
            {
                cadastrar(robos[totalDeRobos], totalDeRobos);
                totalDeRobos++;
            }
            else
            {
                cout << "Limite maximo de 4 robos atingido!\n";
            }
            break;
        case 2:
            listar(robos, totalDeRobos);
            break;
        case 3:
            simularMissao(robos, totalDeRobos);
            break;
        case 4:
            mostrarCampo(robos, totalDeRobos);
            break;
        case 5:
            recuperarRobo(robos, totalDeRobos);
            break;
        case 6:
            cout << "Saindo do programa.\n";
            break;
        default:
            cout << "Opcao invalida!\n";
            break;
        }

        if (op != 6)
        {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        system("cls");

    } while (op != 6);

    return 0;
}

void cadastrar(Robo &robo, int id)
{
    system("cls");
    cout << "--- Cadastro do Robo ID: " << id << " ---\n";

    robo.identificador = id;
    robo.l = -1;
    robo.c = -1;

    cout << "Qual o Nome do Robo: ";
    cin.ignore();
    cin.getline(robo.nome, 50);

    cout << "Quantidade de energia: ";
    cin >> robo.energia;

    cout << "Qual o Nivel do Robo: ";
    cin >> robo.nivel;

    cout << "\nRobo '" << robo.nome << "' cadastrado com sucesso!\n";
}

void listar(Robo robos[], int totalDeRobos)
{
    system("cls");
    cout << "--- Lista de Robos Cadastrados ---\n";

    if (totalDeRobos == 0)
    {
        cout << "Nenhum Robo Cadastrado Ainda.\n";
        return;
    }

    for (int i = 0; i < totalDeRobos; i++)
    {
        cout << "\n----------------------------\n";
        cout << " Robo: " << robos[i].nome << "\n";
        cout << "----------------------------\n";
        cout << "  ID: " << robos[i].identificador << endl;
        cout << "  Energia: " << robos[i].energia << endl;
        cout << "  Nivel: " << robos[i].nivel << endl;
        if (robos[i].l == -1)
        {
            cout << "  Status: Na base\n";
        }
        else
        {
            cout << "  Status: Em missao no campo [" << robos[i].l << "][" << robos[i].c << "]\n";
        }
    }
}

void simularMissao(Robo robos[], int totalDeRobos)
{
    system("cls");
    cout << "--- Simular Missao ---\n";
    if (totalDeRobos == 0)
    {
        cout << "Cadastre Um Robo Primeiro!\n";
        return;
    }

    int id;
    cout << "Digite o ID do Robo para a Missao: ";
    cin >> id;

    if (id < 0 || id >= totalDeRobos)
    {
        cout << "ID invalido!\n";
        return;
    }

    if (robos[id].l != -1)
    {
        cout << "FALHA: Este Robo ja Esta em uma Missao!\n";
        return;
    }

    if (robos[id].energia > 20)
    {
        int l, c;
        bool achouLugar = false;

        for (int tentativa = 0; tentativa < 10; tentativa++)
        {
            l = rand() % 2;
            c = rand() % 2;

            bool lugarOcupado = false;
            for (int i = 0; i < totalDeRobos; i++)
            {
                if (robos[i].l == l && robos[i].c == c)
                {
                    lugarOcupado = true;
                    break;
                }
            }

            if (!lugarOcupado)
            {
                achouLugar = true;
                break;
            }
        }

        if (achouLugar)
        {
            robos[id].energia -= 20;
            robos[id].l = l;
            robos[id].c = c;
            cout << "SUCESSO! Robo movido para o campo na posicao [" << l << "][" << c << "].\n";
            cout << "Energia restante: " << robos[id].energia << endl;
        }
        else
        {
            cout << "FALHA: Nao foi Possivel Encontrar uma Posicao Livre No Campo.\n";
        }
    }
    else
    {
        cout << "FALHA: Energia Insuficiente (Necessario > 20).\n";
    }
}

void recuperarRobo(Robo robos[], int totalDeRobos)
{
    system("cls");
    cout << "--- Recuperar Robo da Missao ---\n";
    if (totalDeRobos == 0)
    {
        cout << "Nenhum Robo Cadastrado.\n";
        return;
    }

    int id;
    cout << "Digite o ID do Robo a ser Recuperado: ";
    cin >> id;

    if (id < 0 || id >= totalDeRobos)
    {
        cout << "ID invalido!\n";
        return;
    }

    if (robos[id].l != -1)
    {
        robos[id].l = -1;
        robos[id].c = -1;
        cout << "Robo " << robos[id].nome << " (ID: " << id << ") recuperado para a base com sucesso!\n";
    }
    else
    {
        cout << "Este Robo ja Esta na Base.\n";
    }
}

void mostrarCampo(Robo robos[], int totalDeRobos)
{
    system("cls");
    cout << "--- Campo de Missao (2x2) ---\n";
    cout << "IDs dos robos em missao. '[ ]' = Vazio\n\n";

    int campo[2][2];

    for (int l = 0; l < 2; l++)
    {
        for (int c = 0; c < 2; c++)
        {
            campo[l][c] = -1;
        }
    }

    for (int i = 0; i < totalDeRobos; i++)
    {
        if (robos[i].l != -1)
        {
            campo[robos[i].l][robos[i].c] = robos[i].identificador;
        }
    }

    for (int l = 0; l < 2; l++)
    {
        for (int c = 0; c < 2; c++)
        {
            if (campo[l][c] == -1)
            {
                cout << "[ ] ";
            }
            else
            {
                cout << "[" << campo[l][c] << "] ";
            }
        }
        cout << endl;
    }
}