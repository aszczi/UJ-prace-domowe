// Joanna Szewczyk
#include <iostream>

int MAX_SIZE = 128;
int MAX_PLACES = 65535;
unsigned long long suma = 0;

// pododawac do funkcji place num !!!
// jak zrobic z pola znikaja?
// dodac do reszty suma
// duze P <=
// male p <
struct Place
{
    unsigned short quantity = 0;
    char label[2] = {0, 0}; // 3 czy 2 (bo jeszce znak pusty)
};

struct Shelf
{
    long long int quantity = 0;
    Place miejsca[128];
    unsigned short Places_num = 0;
};

struct Rack
{
    long long int quantity = 0;
    Shelf polki[128];
    unsigned short Shelfs_num = 0;
};

struct Warehouse
{
    long long int quantity = 0;
    Rack regaly[128];
    Shelf handyShelf;
    unsigned short Racks_num = 0;
};

struct Storehouse
{
    long long int quantity = 0;
    Warehouse magazyny[128];
    Rack handyRack;
    Shelf handyShelf;
    unsigned short Warehouses_num = 0;
};

Storehouse sklad;

// int zmienilam na short

void SET_AP(int w, int r, int s, int p)
{
    for (int i = p; i < sklad.magazyny[w].regaly[r].polki[s].Places_num; i++)
    {
        sklad.quantity -= sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity;
        sklad.magazyny[w].quantity -= sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity;
        sklad.magazyny[w].regaly[r].quantity -= sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity;
        sklad.magazyny[w].regaly[r].polki[s].quantity -= sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity;
        sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity = 0;
        sklad.magazyny[w].regaly[r].polki[s].miejsca[i].label[0] = 0;
        sklad.magazyny[w].regaly[r].polki[s].miejsca[i].label[1] = 0;
    }
    for (int j = sklad.magazyny[w].regaly[r].polki[s].Places_num; j < p; j++)
    {
        sklad.magazyny[w].regaly[r].polki[s].miejsca[j].quantity = 0;
        sklad.magazyny[w].regaly[r].polki[s].miejsca[j].label[1] = 0;
        sklad.magazyny[w].regaly[r].polki[s].miejsca[j].label[0] = 0;
    }

    /*
    int temporary;
         for (int i = p; i >= ::MAX_SIZE; i--)
        {  temporary = sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity;

            sklad.quantity -= temporary;
            sklad.magazyny[w].quantity -= temporary;
            sklad.magazyny[w].regaly[r].quantity -= temporary;
            sklad.magazyny[w].regaly[r].polki[s].quantity -=temporary;
            sklad.magazyny[w].regaly[r].polki[s].miejsca[i].quantity -= temporary;
            sklad.magazyny[w].regaly[r].polki[s].miejsca[i].label[0] = 0;
            sklad.magazyny[w].regaly[r].polki[s].miejsca[i].label[1] = 0;
        }*/
    sklad.magazyny[w].regaly[r].polki[s].Places_num = p;
}
void SET_HW(int w, int p)
{
    int temp = sklad.magazyny[w].handyShelf.Places_num;

    for (int i = p; i < temp; i++)
    {
        sklad.quantity -= sklad.magazyny[w].handyShelf.miejsca[i].quantity;
        sklad.magazyny[w].quantity -= sklad.magazyny[w].handyShelf.miejsca[i].quantity;
        sklad.magazyny[w].handyShelf.quantity -= sklad.magazyny[w].handyShelf.miejsca[i].quantity;
        sklad.magazyny[w].handyShelf.miejsca[i].quantity = 0;
        sklad.magazyny[w].handyShelf.miejsca[i].label[0] = 0;
        sklad.magazyny[w].handyShelf.miejsca[i].label[1] = 0;
    }
    sklad.magazyny[w].handyShelf.Places_num = p;
}

void SET_HR(int s, int p)
{
    int temp = sklad.handyRack.Shelfs_num;
    int temp2 = 0;
    sklad.handyRack.Shelfs_num = s;
    for (int j = s; j < temp; j++)
    {
        temp2 = sklad.handyRack.polki[j].Places_num;
        sklad.handyRack.polki[j].Places_num = 0;
        for (int i = 0; i < temp2; i++)
        {
            sklad.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
            sklad.handyRack.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
            sklad.handyRack.polki[j].quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
            sklad.handyRack.polki[j].miejsca[i].quantity = 0;
            sklad.handyRack.polki[j].miejsca[i].label[0] = 0;
            sklad.handyRack.polki[j].miejsca[i].label[1] = 0;
        }
    }

    for (int j = 0; j < s; j++)
    {
        temp2 = sklad.handyRack.polki[j].Places_num;
        sklad.handyRack.polki[j].Places_num = p;
        for (int i = p; i < temp2; i++)
        {
            sklad.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
            sklad.handyRack.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
            sklad.handyRack.polki[j].quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
            sklad.handyRack.polki[j].miejsca[i].quantity = 0;
            sklad.handyRack.polki[j].miejsca[i].label[0] = 0;
            sklad.handyRack.polki[j].miejsca[i].label[1] = 0;
        }
    }
}
void SET_HS(int p)
{
    for (int i = p; i < sklad.handyShelf.Places_num; i++)
    {
        sklad.quantity -= sklad.handyShelf.miejsca[i].quantity;
        sklad.handyShelf.quantity -= sklad.handyShelf.miejsca[i].quantity;
        sklad.handyShelf.miejsca[i].quantity = 0;
        sklad.handyShelf.miejsca[i].label[0] = 0;
        sklad.handyShelf.miejsca[i].label[1] = 0;
    }
    sklad.handyShelf.Places_num = p;
}
void SET_AS(int w, int r, int s, int p)
{

    for (int i = 0; i < s; i++)
    {
        SET_AP(w, r, i, p);
    }
    for (int i = s; i < sklad.magazyny[w].regaly[r].Shelfs_num; i++)
    {
        SET_AP(w, r, i, 0);
    }

    sklad.magazyny[w].regaly[r].Shelfs_num = s;

    // int temp2 = 0;
    // int temp3 =0;
    /*
     for (int j = s; j < sklad.magazyny[w].regaly[r].Shelfs_num; j++)
     {


         for (int i = 0; i <sklad.magazyny[w].regaly[r].polki[j].Places_num ; i++)
         {
             sklad.quantity -= sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].quantity -=sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].regaly[r].quantity -= sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].regaly[r].polki[j].quantity -= sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity = 0;
             sklad.magazyny[w].regaly[r].polki[j].miejsca[i].label[0] = 0;
             sklad.magazyny[w].regaly[r].polki[j].miejsca[i].label[1] = 0;
         }
          sklad.magazyny[w].regaly[r].polki[j].Places_num = 0;
     }

     for (int j = 0; j < s; j++)
     {


         for (int i = p; i < sklad.magazyny[w].regaly[r].polki[j].Places_num; i++)
         {
              sklad.quantity -= sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].quantity -=sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].regaly[r].quantity -= sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].regaly[r].polki[j].quantity -= sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity;
             sklad.magazyny[w].regaly[r].polki[j].miejsca[i].quantity = 0;
             sklad.magazyny[w].regaly[r].polki[j].miejsca[i].label[0] = 0;
             sklad.magazyny[w].regaly[r].polki[j].miejsca[i].label[1] = 0;
         } sklad.magazyny[w].regaly[r].polki[j].Places_num = p;
     }
     sklad.magazyny[w].regaly[r].Shelfs_num = s;*/
}

void SET_AR(int w, int r, int s, int p)
{

    for (int j = 0; j < r; j++)
    {
        SET_AS(w, j, s, p);
    }
    for (int j = r; j < sklad.magazyny[w].Racks_num; j++)
    {
        SET_AS(w, j, 0, 0);
    }

    sklad.magazyny[w].Racks_num = r;
}

void SET_AW(int w, int r, int s, int p)
{
    for (int i = w; i < sklad.Warehouses_num; i++)
    {
        SET_AR(i, 0, 0, 0);
        SET_HW(i, 0);
    }

    for (int i = 0; i < w; i++)
    {
        SET_AR(i, r, s, p);
    }

    // handyShelfs zniknac
    sklad.Warehouses_num = w;
}

void fill(int w, int r, int s, int p, long long int a)
{

    if (a > ::MAX_PLACES)
    {
        a = ::MAX_PLACES;
    }

    sklad.Warehouses_num = w;
    for (int i = 0; i < w; i++)
    {
        sklad.magazyny[i].quantity = 0;

        sklad.magazyny[i].Racks_num = r;

        for (int j = 0; j < r; j++)
        {
            sklad.magazyny[i].regaly[j].Shelfs_num = s;

            for (int k = 0; k < s; k++)
            {
                sklad.magazyny[i].regaly[j].polki[k].Places_num = p;

                for (int l = 0; l < p; l++)
                {

                    sklad.magazyny[i].regaly[j].polki[k].miejsca[l].quantity = a;
                    sklad.magazyny[i].regaly[j].polki[k].miejsca[l].label[0] = 0;
                    sklad.magazyny[i].regaly[j].polki[k].miejsca[l].label[1] = 0;
                    sklad.magazyny[i].quantity += a;
                }
                sklad.magazyny[i].regaly[j].polki[k].quantity = a * p;
            }
            sklad.magazyny[i].regaly[j].quantity = a * p * s;
        }

        sklad.magazyny[i].handyShelf.Places_num = p; // podreczna polka skladu
        for (int l = 0; l < p; l++)
        {

            sklad.magazyny[i].handyShelf.miejsca[l].quantity = a;
            sklad.magazyny[i].handyShelf.miejsca[l].label[0] = 0;
            sklad.magazyny[i].handyShelf.miejsca[l].label[1] = 0;
            sklad.magazyny[i].quantity += a;
        }
        sklad.magazyny[i].handyShelf.quantity = p * a;
        // sklad.magazyny[i].quantity = r * a * p * s + p * a;
    }

    sklad.handyRack.Shelfs_num = s; // podreczny regal skladu
    for (int k = 0; k < s; k++)
    {
        sklad.handyRack.polki[k].Places_num = p;

        for (int l = 0; l < p; l++)
        {
            sklad.handyRack.polki[k].miejsca[l].quantity = a;
            sklad.handyRack.polki[k].miejsca[l].label[0] = 0;
            sklad.handyRack.polki[k].miejsca[l].label[1] = 0;
        }
        sklad.handyRack.polki[k].quantity = p * a;
    }
    sklad.handyRack.quantity = a * s * p;

    sklad.handyShelf.Places_num = p;
    for (int l = 0; l < p; l++)
    {
        sklad.handyShelf.miejsca[l].quantity = a;
        sklad.handyShelf.miejsca[l].label[0] = 0;
        sklad.handyShelf.miejsca[l].label[1] = 0;
    }
    sklad.handyShelf.quantity = p * a;

    sklad.quantity = (a * w * r * s * p) + (a * w * p) + (a * s * p) + (a * p);
}

int main()
{
    /*
    sklad.Warehouses_num = 0;
    sklad.handyRack.Shelfs_num = 0;
    sklad.handyShelf.Places_num = 0;
    sklad.quantity = 0;*/

    char nazwa[8];
    // std::cin >> nazwa;
    int w = 0; // nr magazynu
    int r = 0; // nr regalu
    int s = 0; // nr polki
    int p = 0; // ilosc miejsca na towary

    // Put
    int a = 0; // ilosc towaru do dodania

    // mov
    int w2 = 0;
    int r2 = 0;
    int s2 = 0;

    // labels
    unsigned char dd[3] = {0, 0, 0};

    // temporary
    // int temp = 0;
    // int temp2 = 0;

    do
    {
        std::cin >> nazwa;

        // SET-AP

        if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'A') && (nazwa[5] == 'P'))
        {

            std::cin >> w;
            std::cin >> r;
            std::cin >> s;
            std::cin >> p;
            if ((w < 0) || (w >= sklad.Warehouses_num) || (r < 0) || (r >= sklad.magazyny[w].Racks_num) || (s < 0) || (s >= sklad.magazyny[w].regaly[s].Shelfs_num) || (p < 0) || (p > 128))
            { // uzupelnic!!!
                // usunelam p >= MAXSIZE
                std::cout << "error" << std::endl;
            }
            else
            {
                SET_AP(w, r, s, p);
            }
        }
        // SET-as
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'A') && (nazwa[5] == 'S'))
        {
            std::cin >> w >> r >> s >> p;

            if ((w < 0) || (w >= sklad.Warehouses_num) || (r < 0) || (r >= sklad.magazyny[w].Racks_num) || (s < 0) || (s > 128) || (p < 0) || (p > 128))
            { // uzupelnioneee
                std::cout << "error" << std::endl;
            }
            else
            {
                SET_AS(w, r, s, p);
            }

            /*   if( (w >= 0) && (w < sklad.Warehouses_num) && (r >= 0)&& (r < sklad.magazyny[w].Racks_num ) &&(s >=0) && (s <= 128) &&(p>=0) &&(p <= 128)){

                 SET_AS(w, r, s, p);
               }else {
                std::cout<<"error"<<std::endl;

               }*/
        }

        // set-ar
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'A') && (nazwa[5] == 'R'))
        {
            std::cin >> w >> r >> s >> p;

            if ((w < 0) || (w >= sklad.Warehouses_num) || (r < 0) || (r > 128) || (s < 0) || (s > 128) || (p < 0) || (p > 128))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                SET_AR(w, r, s, p);
            }
        }
        // set aw
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'A') && (nazwa[5] == 'W'))
        {
            std::cin >> w;
            std::cin >> r;
            std::cin >> s;
            std::cin >> p;
            if ((w < 0) || (w > 128) || (r < 0) || (r > 128) || (s < 0) || (s > 128) || (p < 0) || (p > 128))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                SET_AW(w, r, s, p);
            }
        }

        // set hw

        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'H') && (nazwa[5] == 'W'))
        {
            std::cin >> w >> p;
            if ((w >= sklad.Warehouses_num) || (p > ::MAX_SIZE) || (w < 0) || (p < 0))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            { /*
                temp = sklad.magazyny[w].handyShelf.Places_num;
                sklad.magazyny[w].handyShelf.Places_num = p;
                for (int i = p; i < temp; i++)
                {

                    sklad.quantity -= sklad.magazyny[w].handyShelf.miejsca[i].quantity;
                    sklad.magazyny[w].quantity -= sklad.magazyny[w].handyShelf.miejsca[i].quantity;
                    sklad.magazyny[w].handyShelf.quantity -= sklad.magazyny[w].handyShelf.miejsca[i].quantity;
                    sklad.magazyny[w].handyShelf.miejsca[i].quantity = 0;
                    sklad.magazyny[w].handyShelf.miejsca[i].label[0] = 0;
                    sklad.magazyny[w].handyShelf.miejsca[i].label[1] = 0;
                }
                */
                SET_HW(w, p);
            }
        }
        // set hr

        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'H') && (nazwa[5] == 'R'))
        {
            std::cin >> s >> p;
            if ((s > ::MAX_SIZE) || (p > ::MAX_SIZE) || (s < 0) || (p < 0))
            {
                std::cout << "error" << std::endl;
            }
            else
            { /*
                 temp = sklad.handyRack.Shelfs_num;
                 sklad.handyRack.Shelfs_num = s;
                 for (int j = s; j < temp; j++)
                 {

                     temp2 = sklad.handyRack.polki[j].Places_num;
                     sklad.handyRack.polki[j].Places_num = 0;
                     for (int i = 0; i < temp2; i++)
                     {
                         sklad.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
                         sklad.handyRack.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
                         sklad.handyRack.polki[j].quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
                         sklad.handyRack.polki[j].miejsca[i].quantity = 0;
                         sklad.handyRack.polki[j].miejsca[i].label[0] = 0;
                         sklad.handyRack.polki[j].miejsca[i].label[1] = 0;
                     }
                 }

                 for (int j = 0; j < s; j++)
                 {

                     temp2 = sklad.handyRack.polki[j].Places_num;
                     sklad.handyRack.polki[j].Places_num = p;
                     for (int i = p; i < temp2; i++)
                     {
                         sklad.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
                         sklad.handyRack.quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
                         sklad.handyRack.polki[j].quantity -= sklad.handyRack.polki[j].miejsca[i].quantity;
                         sklad.handyRack.polki[j].miejsca[i].quantity = 0;
                         sklad.handyRack.polki[j].miejsca[i].label[0] = 0;
                         sklad.handyRack.polki[j].miejsca[i].label[1] = 0;
                     }
                 }
             }
             */
                SET_HR(s, p);
            }
        }
        // SET hs
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'H') && (nazwa[5] == 'S'))
        {
            std::cin >> p;
            if ((p > ::MAX_SIZE) || (p < 0))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                SET_HS(p);
                /*
                    temp = sklad.handyShelf.Places_num;
                    sklad.handyShelf.Places_num = p;
                    for (int i = p; i < temp; i++)
                    {
                        sklad.quantity -= sklad.handyShelf.miejsca[i].quantity;
                        sklad.handyShelf.quantity -= sklad.handyShelf.miejsca[i].quantity;
                        sklad.handyShelf.miejsca[i].quantity = 0;
                        sklad.handyShelf.miejsca[i].label[0] = 0;
                        sklad.handyShelf.miejsca[i].label[1] = 0;
                    }
                    */
            }
        }

        // put w

        else if ((nazwa[0] == 'P') && (nazwa[1] == 'U') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'W'))
        {
            std::cin >> w >> r >> s >> p >> a;
            if ((w < 0) || (r < 0) || (s < 0) || (p < 0) || (w >= sklad.Warehouses_num) || (r >= sklad.magazyny[w].Racks_num) ||
                (s >= sklad.magazyny[w].regaly[r].Shelfs_num) || (p >= sklad.magazyny[w].regaly[r].polki[s].Places_num))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = (::MAX_PLACES - sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity);
                }
                sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity += a;
                sklad.magazyny[w].regaly[r].polki[s].quantity += a;
                sklad.magazyny[w].regaly[r].quantity += a;
                sklad.magazyny[w].quantity += a;
                sklad.quantity += a;
            }

            // ograniczniki
        }
        // put-h
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'U') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'H'))
        {
            std::cin >> w >> p >> a;
            if ((w < 0) || (p < 0) || (w >= sklad.Warehouses_num) || (p >= sklad.magazyny[w].handyShelf.Places_num))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].handyShelf.miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = (::MAX_PLACES - sklad.magazyny[w].handyShelf.miejsca[p].quantity);
                    /*
                        temp = ::MAX_PLACES - sklad.magazyny[w].handyShelf.miejsca[p].quantity;
                        sklad.magazyny[w].handyShelf.miejsca[p].quantity += temp;
                        sklad.magazyny[w].handyShelf.quantity += temp;
                        sklad.magazyny[w].quantity += temp;
                        sklad.quantity += temp;
                        */
                }
                sklad.magazyny[w].handyShelf.miejsca[p].quantity += a;
                sklad.magazyny[w].handyShelf.quantity += a;
                sklad.magazyny[w].quantity += a;
                sklad.quantity += a;
            }
        }

        // put r
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'U') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'R'))
        {
            std::cin >> s >> p >> a;
            if ((p < 0) || (s < 0) || (s >= sklad.handyRack.Shelfs_num) || (p >= sklad.handyRack.polki[s].Places_num)) // czy ogranizcac a odnosnie max value?
            {                                                                                                          // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.handyRack.polki[s].miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = (::MAX_PLACES - sklad.handyRack.polki[s].miejsca[p].quantity);
                    /*  temp = ::MAX_PLACES - sklad.handyRack.polki[s].miejsca[p].quantity;
                      sklad.handyRack.polki[s].miejsca[p].quantity += temp;
                      sklad.handyRack.polki[s].quantity += temp;
                      sklad.handyRack.quantity += temp;
                      sklad.quantity += temp;
                      */
                }
                else
                {
                }
                sklad.handyRack.polki[s].miejsca[p].quantity += a;
                sklad.handyRack.polki[s].quantity += a;
                sklad.handyRack.quantity += a;
                sklad.quantity += a;
            }
        }

        // put s
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'U') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'S'))
        {
            std::cin >> p >> a;
            if (p < 0 || p >= sklad.handyShelf.Places_num)
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.handyShelf.miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = (::MAX_PLACES - sklad.handyShelf.miejsca[p].quantity);
                    /*  temp = ::MAX_PLACES - sklad.handyRack.polki[s].miejsca[p].quantity;
                      sklad.handyRack.polki[s].miejsca[p].quantity += temp;
                      sklad.handyRack.polki[s].quantity += temp;
                      sklad.handyRack.quantity += temp;
                      sklad.quantity += temp;
                      */
                }
                else
                {
                }
                sklad.handyShelf.miejsca[p].quantity += a;
                sklad.handyShelf.quantity += a;
                //  sklad.handyRack.quantity += a;
                sklad.quantity += a;
            }

            // sklad.handyShelf.miejsca[p].quantity += a;
        }
        // fill
        else if ((nazwa[0] == 'F') && (nazwa[1] == 'I') && (nazwa[2] == 'L') && (nazwa[3] == 'L'))
        {
            std::cin >> w >> r >> s >> p >> a;
            if (w > ::MAX_SIZE || r > ::MAX_SIZE || s > ::MAX_SIZE || p > ::MAX_SIZE || w < 0 || r < 0 || s < 0 || p < 0 // pousuwane >=
                                                                                                                         // tu moze byc 128                                                                                                      //|| w >= sklad.Warehouses_num || r >= sklad.magazyny[w].Racks_num || s >= sklad.magazyny[w].regaly[r].Shelfs_num || p >= sklad.magazyny[w].regaly[r].polki[s].Places_num
            )
            {
                std::cout << "error" << std::endl;
            }
            else
            {

                if (a > ::MAX_PLACES)
                {
                    a = ::MAX_PLACES;
                }

                fill(w, r, s, p, a);
            }
        }
        // pop-w
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'O') && (nazwa[2] == 'P') && (nazwa[3] == '-') && (nazwa[4] == 'W'))
        {
            std::cin >> w;
            std::cin >> r;
            std::cin >> s;
            std::cin >> p;
            std::cin >> a;
            if (w < 0 || r < 0 || s < 0 || p < 0 || w >= sklad.Warehouses_num || r >= sklad.magazyny[w].Racks_num ||
                s >= sklad.magazyny[w].regaly[r].Shelfs_num || p >= sklad.magazyny[w].regaly[r].polki[s].Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity < a)
                {

                    a = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity;
                    /*
                    temp = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity;

                    sklad.magazyny[w].quantity -= temp;
                    sklad.magazyny[w].regaly[r].quantity -= temp;
                    sklad.magazyny[w].regaly[r].polki[s].quantity -= temp;
                    sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity -= temp;
                    */
                }
                sklad.quantity -= a;
                sklad.magazyny[w].quantity -= a;
                sklad.magazyny[w].regaly[r].quantity -= a;
                sklad.magazyny[w].regaly[r].polki[s].quantity -= a;
                sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity -= a;
            }
        }
        // pop h
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'O') && (nazwa[2] == 'P') && (nazwa[3] == '-') && (nazwa[4] == 'H'))
        {
            std::cin >> w >> p >> a;
            if ((w < 0) || (p < 0) || (w >= sklad.Warehouses_num) || (p >= sklad.magazyny[w].handyShelf.Places_num))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].handyShelf.miejsca[p].quantity < a)
                {
                    a = (sklad.magazyny[w].handyShelf.miejsca[p].quantity);
                    /*
                        temp = ::MAX_PLACES - sklad.magazyny[w].handyShelf.miejsca[p].quantity;
                        sklad.magazyny[w].handyShelf.miejsca[p].quantity += temp;
                        sklad.magazyny[w].handyShelf.quantity += temp;
                        sklad.magazyny[w].quantity += temp;
                        sklad.quantity += temp;
                        */
                }
                sklad.magazyny[w].handyShelf.miejsca[p].quantity -= a;
                sklad.magazyny[w].handyShelf.quantity -= a;
                sklad.magazyny[w].quantity -= a;
                sklad.quantity -= a;
            }
        }

        // pop r
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'O') && (nazwa[2] == 'P') && (nazwa[3] == '-') && (nazwa[4] == 'R'))
        {
            std::cin >> s >> p >> a;
            if ((p < 0) || (s < 0) || (s >= sklad.handyRack.Shelfs_num) || (p >= sklad.handyRack.polki[s].Places_num)) // czy ogranizcac a odnosnie max value?
            {                                                                                                          // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.handyRack.polki[s].miejsca[p].quantity < a)
                {
                    a = (sklad.handyRack.polki[s].miejsca[p].quantity);
                    /*  temp = ::MAX_PLACES - sklad.handyRack.polki[s].miejsca[p].quantity;
                      sklad.handyRack.polki[s].miejsca[p].quantity += temp;
                      sklad.handyRack.polki[s].quantity += temp;
                      sklad.handyRack.quantity += temp;
                      sklad.quantity += temp;
                      */
                }
                else
                {
                }
                sklad.handyRack.polki[s].miejsca[p].quantity -= a;
                sklad.handyRack.polki[s].quantity -= a;
                sklad.handyRack.quantity -= a;
                sklad.quantity -= a;
            }
        }

        // pop s
        else if ((nazwa[0] == 'P') && (nazwa[1] == 'O') && (nazwa[2] == 'P') && (nazwa[3] == '-') && (nazwa[4] == 'S'))
        {
            std::cin >> p >> a;
            if ((p < 0) || (p >= sklad.handyShelf.Places_num))
            { // uzupelnic!!!
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.handyShelf.miejsca[p].quantity < a)
                {
                    a = (sklad.handyShelf.miejsca[p].quantity);
                    /*  temp = ::MAX_PLACES - sklad.handyRack.polki[s].miejsca[p].quantity;
                      sklad.handyRack.polki[s].miejsca[p].quantity += temp;
                      sklad.handyRack.polki[s].quantity += temp;
                      sklad.handyRack.quantity += temp;
                      sklad.quantity += temp;
                      */
                }
                else
                {
                }
                sklad.handyShelf.miejsca[p].quantity -= a;
                sklad.handyShelf.quantity -= a;
                //  sklad.handyRack.quantity += a;
                sklad.quantity -= a;
            }

            // sklad.handyShelf.miejsca[p].quantity += a;
        }

        // MV
        // dodac a musi byc wieksze od 0
        //

        // pozmireniac nazwy z uwzglednieniem numerow !!!!!!!!!!!

        //  mov-w
        else if ((nazwa[0] == 'M') && (nazwa[1] == 'O') && (nazwa[2] == 'V') && (nazwa[3] == '-') && (nazwa[4] == 'W'))
        {

            std::cin >> w >> r >> s >> w2 >> r2 >> s2 >> p >> a;
            if ((w < 0) || (r < 0) || (s < 0) || (w2 < 0) || (r2 < 0) || (s2 < 0) || (p < 0) || (w >= sklad.Warehouses_num) || (r >= sklad.magazyny[w].Racks_num) || (w2 >= sklad.Warehouses_num) || (r2 >= sklad.magazyny[w2].Racks_num) ||
                (s >= sklad.magazyny[w].regaly[r].Shelfs_num) || (s2 >= sklad.magazyny[w2].regaly[r2].Shelfs_num) || (p >= sklad.magazyny[w].regaly[r].polki[s].Places_num) || (p >= sklad.magazyny[w2].regaly[r2].polki[s2].Places_num))
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity < a)
                {
                    a = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity;

                    // przenosimy tylko quantity
                }
                if (sklad.magazyny[w2].regaly[r2].polki[s2].miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = ::MAX_PLACES - sklad.magazyny[w2].regaly[r2].polki[s2].miejsca[p].quantity;
                }

                sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity -= a;
                sklad.magazyny[w].regaly[r].polki[s].quantity -= a;
                sklad.magazyny[w].regaly[r].quantity -= a;
                sklad.magazyny[w].quantity -= a;
                sklad.quantity -= a;

                sklad.magazyny[w2].regaly[r2].polki[s2].miejsca[p].quantity += a;
                sklad.magazyny[w2].regaly[r2].polki[s2].quantity += a;
                sklad.magazyny[w2].regaly[r2].quantity += a;
                sklad.magazyny[w2].quantity += a;
                sklad.quantity += a;
            }
        }
        // mov-h
        else if ((nazwa[0] == 'M') && (nazwa[1] == 'O') && (nazwa[2] == 'V') && (nazwa[3] == '-') && (nazwa[4] == 'H'))
        {
            std::cin >> w >> r >> s >> p >> a; // czy ograniczac a
            if ((w < 0) || (r < 0) || (s < 0) || (p < 0) || (w >= sklad.Warehouses_num) || (r >= sklad.magazyny[w].Racks_num) ||
                (s >= sklad.magazyny[w].regaly[r].Shelfs_num) || (p >= sklad.magazyny[w].regaly[r].polki[s].Places_num) || (p >= sklad.magazyny[w].handyShelf.Places_num))
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity < a)
                {
                    a = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity;
                }
                if (sklad.magazyny[w].handyShelf.miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = ::MAX_PLACES - sklad.magazyny[w].handyShelf.miejsca[p].quantity;
                }
                sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity -= a;
                sklad.magazyny[w].regaly[r].polki[s].quantity -= a;
                sklad.magazyny[w].regaly[r].quantity -= a;
                sklad.magazyny[w].quantity -= a;
                sklad.quantity -= a;

                sklad.magazyny[w].handyShelf.miejsca[p].quantity += a;
                sklad.magazyny[w].handyShelf.quantity += a;
                sklad.magazyny[w].quantity += a;
                sklad.quantity += a;
            }

            // dodac ograniczinki
        }
        // mov-r
        else if ((nazwa[0] == 'M') && (nazwa[1] == 'O') && (nazwa[2] == 'V') && (nazwa[3] == '-') && (nazwa[4] == 'R'))
        {

            std::cin >> w >> r >> s >> s2 >> p >> a;
            if ((w >= 0) && (w < sklad.Warehouses_num) && (r >= 0) && (r < sklad.magazyny[w].Racks_num) && (s >= 0) && (s <= sklad.magazyny[w].regaly[r].Shelfs_num) && (s2 >= 0) && (s2 < sklad.handyRack.Shelfs_num) && (p >= 0) && (p < sklad.handyRack.polki[s2].Places_num) && (p < sklad.magazyny[w].regaly[r].polki[s].Places_num))
            {

                if (a > sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity)
                {
                    a = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity;
                }
                if (sklad.handyRack.polki[s2].miejsca[p].quantity + a > 65535)
                {
                    a = 65535 - sklad.handyRack.polki[s2].miejsca[p].quantity;
                }

                sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity -= a;
                sklad.magazyny[w].regaly[r].polki[s].quantity -= a;
                sklad.magazyny[w].regaly[r].quantity -= a;
                sklad.magazyny[w].quantity -= a;

                sklad.handyRack.polki[s2].miejsca[p].quantity += a;
                sklad.handyRack.polki[s2].quantity += a;
                sklad.handyRack.quantity += a;
            }
            else
            {
                std::cout << "error" << std::endl;
            }

            /*
            std::cin >> w >> r >> s >> s2 >> p >> a;
            if ( w < 0 || r < 0 || s < 0 || s2 < 0 || p < 0 || w >= sklad.Warehouses_num || r >= sklad.magazyny[w].Racks_num || s2 >=  sklad.handyRack.Shelfs_num ||
                s >= sklad.magazyny[w].regaly[r].Shelfs_num || p >= sklad.magazyny[w].regaly[r].polki[s].Places_num || p >= sklad.handyRack.polki[s2].Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity <= a)
                {
                    a = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity;
                }
                if (sklad.handyRack.polki[s2].miejsca[p].quantity + a > 65535)
                {
                    a = 65535 - sklad.handyRack.polki[s2].miejsca[p].quantity;
                }
                sklad.magazyny[w].regaly[r].polki[s].miejsca[p].quantity -= a;
                sklad.magazyny[w].regaly[r].polki[s].quantity -= a;
                sklad.magazyny[w].regaly[r].quantity -= a;
                sklad.magazyny[w].quantity -= a;


                sklad.handyRack.polki[s2].miejsca[p].quantity += a;
                sklad.handyRack.polki[s2].quantity += a;
                sklad.handyRack.quantity += a;

            }*/
        }

        // mov-s
        else if ((nazwa[0] == 'M') && (nazwa[1] == 'O') && (nazwa[2] == 'V') && (nazwa[3] == '-') && (nazwa[4] == 'S'))
        {
            std::cin >> s >> p >> a;

            if (s < 0 || p < 0 || s >= sklad.handyRack.Shelfs_num || p >= sklad.handyRack.polki[s].Places_num || p >= sklad.handyShelf.Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (sklad.handyRack.polki[s].miejsca[p].quantity < a)
                {
                    a = sklad.handyRack.polki[s].miejsca[p].quantity;
                }
                if (sklad.handyShelf.miejsca[p].quantity + a > ::MAX_PLACES)
                {
                    a = ::MAX_PLACES - sklad.handyShelf.miejsca[p].quantity;
                }

                sklad.handyRack.polki[s].miejsca[p].quantity -= a;
                sklad.handyRack.polki[s].quantity -= a;
                sklad.handyRack.quantity -= a;
                sklad.quantity -= a;

                sklad.handyShelf.miejsca[p].quantity += a;
                sklad.handyShelf.quantity += a;
                sklad.quantity += a;
            }
        }

        // get -e
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'E'))
        {
            std::cout << sklad.quantity << std::endl;
        }
        // get-w
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'W'))
        {

            std::cin >> w;

            if (w < 0 || w >= sklad.Warehouses_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                std::cout << sklad.magazyny[w].quantity << std::endl;
            }
        }
        // get-RW
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'R') && (nazwa[5] == 'W'))
        {
            std::cin >> w >> r;
            if ((w < 0) || (w >= sklad.Warehouses_num) || (r < 0) || (r >= sklad.magazyny[w].Racks_num))
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                long long int sum_rw = 0;
                for (int j = 0; j < sklad.magazyny[w].regaly[r].Shelfs_num; j++)
                {
                    for (int k = 0; k < sklad.magazyny[w].regaly[r].polki[j].Places_num; k++)
                    {
                        sum_rw += sklad.magazyny[w].regaly[r].polki[j].miejsca[k].quantity;
                    }
                }
                std::cout << sum_rw << std::endl;
                // std::cout << sklad.magazyny[w].regaly[r].quantity << std::endl;
            }
        }
        // get - rh
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'R') && (nazwa[5] == 'H'))
        {

            std::cout << sklad.handyRack.quantity << std::endl;
        }
        // get -sw
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'S') && (nazwa[5] == 'W'))
        {
            //   int sum_sw = 0;
            std::cin >> w >> r >> s;
            if ((w < 0) || (w >= sklad.Warehouses_num) || (r < 0) || (r >= sklad.magazyny[w].Racks_num) || (s < 0) || (s >= sklad.magazyny[w].regaly[r].Shelfs_num))
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                std::cout << sklad.magazyny[w].regaly[r].polki[s].quantity << std::endl;
            }
        }
        // get-sh
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'S') && (nazwa[5] == 'H'))
        {

            std::cin >> w;

            if ((w < 0) || (w >= sklad.Warehouses_num))
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                std::cout << sklad.magazyny[w].handyShelf.quantity << std::endl;
            }
        }
        // get-sr
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'S') && (nazwa[5] == 'R'))
        {
            std::cin >> s;

            if ((s < 0) || (s >= sklad.handyRack.Shelfs_num))
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                std::cout << sklad.handyRack.polki[s].quantity << std::endl;
            }
        }
        // get-s
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'S'))
        {
            std::cout << sklad.handyShelf.quantity << std::endl;
        }

        // get -lw
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'W'))
        {
            std::cin >> w >> r >> s >> p;
            if (w < 0 || r < 0 || s < 0 || p < 0 || w >= sklad.Warehouses_num || r >= sklad.magazyny[w].Racks_num ||
                s >= sklad.magazyny[w].regaly[r].Shelfs_num || p >= sklad.magazyny[w].regaly[r].polki[s].Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if ((sklad.magazyny[w].regaly[r].polki[s].miejsca[p].label[0] == 0) && (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].label[1] == 0))
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << sklad.magazyny[w].regaly[r].polki[s].miejsca[p].label[0];
                    std::cout << sklad.magazyny[w].regaly[r].polki[s].miejsca[p].label[1];
                    std::cout << std::endl;
                }
            }
        }
        // get- lh
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'H'))
        {
            std::cin >> w >> p;
            if (w < 0 || p < 0 || w >= sklad.Warehouses_num || p >= sklad.magazyny[w].handyShelf.Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if ((sklad.magazyny[w].handyShelf.miejsca[p].label[0] == 0) && (sklad.magazyny[w].handyShelf.miejsca[p].label[1] == 0))
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << sklad.magazyny[w].handyShelf.miejsca[p].label[0];
                    std::cout << sklad.magazyny[w].handyShelf.miejsca[p].label[1];
                    std::cout << std::endl;

                    // czy mam dawac entery?
                }
            }
        }
        // get-lr
        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'R'))
        {

            std::cin >> s >> p;
            if (s < 0 || p < 0 || s >= sklad.handyRack.Shelfs_num || p >= sklad.handyRack.polki[s].Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if ((sklad.handyRack.polki[s].miejsca[p].label[0] == '\0') && (sklad.handyRack.polki[s].miejsca[p].label[1] == '\0'))
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << sklad.handyRack.polki[s].miejsca[p].label[0];
                    std::cout << sklad.handyRack.polki[s].miejsca[p].label[1];
                    std::cout << std::endl;
                }
            }
        }
        // get-ls

        else if ((nazwa[0] == 'G') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'S'))
        {
            std::cin >> p;
            if (p < 0 || p >= sklad.handyShelf.Places_num)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if ((sklad.handyShelf.miejsca[p].label[0] == 0) && (sklad.handyShelf.miejsca[p].label[1] == 0))
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << sklad.handyShelf.miejsca[p].label[0];
                    std::cout << sklad.handyShelf.miejsca[p].label[1];
                    std::cout << std::endl;
                }
            }
        }

        // SETY

        // set-lw
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'W'))
        {
            std::cin >> w >> r >> s >> p >> dd;
            if (w >= sklad.Warehouses_num || r >= sklad.magazyny[w].Racks_num || s >= sklad.magazyny[w].regaly[r].Shelfs_num || p >= sklad.magazyny[w].regaly[r].polki[s].Places_num || w < 0 || r < 0 || s < 0 || p < 0)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (dd[0] == '0' || dd[0] == '1' || dd[0] == '2' || dd[0] == '3' || dd[0] == '4' || dd[0] == '5' || dd[0] == '6' || dd[0] == '7' || dd[0] == '8' || dd[0] == '9')
                {
                    if (dd[1] == '0' || dd[1] == '1' || dd[1] == '2' || dd[1] == '3' || dd[1] == '4' || dd[1] == '5' || dd[1] == '6' || dd[1] == '7' || dd[1] == '8' || dd[1] == '9')
                    {

                        sklad.magazyny[w].regaly[r].polki[s].miejsca[p].label[0] = dd[0];
                        sklad.magazyny[w].regaly[r].polki[s].miejsca[p].label[1] = dd[1];
                    }
                    else
                    {
                        std::cout << "error" << std::endl;
                    }
                }
                else
                {
                    std::cout << "error" << std::endl;
                }
            }
        }
        // set- lh
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'H'))
        {
            std::cin >> w >> p >> dd;
            if (w >= sklad.Warehouses_num || p >= sklad.magazyny[w].handyShelf.Places_num || w < 0 || p < 0)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (dd[0] == '0' || dd[0] == '1' || dd[0] == '2' || dd[0] == '3' || dd[0] == '4' || dd[0] == '5' || dd[0] == '6' || dd[0] == '7' || dd[0] == '8' || dd[0] == '9')
                {
                    if (dd[1] == '0' || dd[1] == '1' || dd[1] == '2' || dd[1] == '3' || dd[1] == '4' || dd[1] == '5' || dd[1] == '6' || dd[1] == '7' || dd[1] == '8' || dd[1] == '9')
                    {
                        sklad.magazyny[w].handyShelf.miejsca[p].label[0] = dd[0];
                        sklad.magazyny[w].handyShelf.miejsca[p].label[1] = dd[1];
                    }
                    else
                    {
                        std::cout << "error" << std::endl;
                    }
                }
                else
                {
                    std::cout << "error" << std::endl;
                }
            }
        }
        // set-lr
        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'R'))
        {
            std::cin >> s >> p >> dd;
            if (s >= sklad.handyRack.Shelfs_num || p >= sklad.handyRack.polki[s].Places_num || s < 0 || p < 0)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (dd[0] == '0' || dd[0] == '1' || dd[0] == '2' || dd[0] == '3' || dd[0] == '4' || dd[0] == '5' || dd[0] == '6' || dd[0] == '7' || dd[0] == '8' || dd[0] == '9')
                {
                    if (dd[1] == '0' || dd[1] == '1' || dd[1] == '2' || dd[1] == '3' || dd[1] == '4' || dd[1] == '5' || dd[1] == '6' || dd[1] == '7' || dd[1] == '8' || dd[1] == '9')
                    {
                        sklad.handyRack.polki[s].miejsca[p].label[0] = dd[0];
                        sklad.handyRack.polki[s].miejsca[p].label[1] = dd[1];
                    }
                    else
                    {
                        std::cout << "error" << std::endl;
                    }
                }
                else
                {
                    std::cout << "error" << std::endl;
                }
            }
        }
        // set-ls

        else if ((nazwa[0] == 'S') && (nazwa[1] == 'E') && (nazwa[2] == 'T') && (nazwa[3] == '-') && (nazwa[4] == 'L') && (nazwa[5] == 'S'))
        {
            std::cin >> p >> dd;
            if (p >= sklad.handyShelf.Places_num || p < 0)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                if (dd[0] == '0' || dd[0] == '1' || dd[0] == '2' || dd[0] == '3' || dd[0] == '4' || dd[0] == '5' || dd[0] == '6' || dd[0] == '7' || dd[0] == '8' || dd[0] == '9')
                {
                    if (dd[1] == '0' || dd[1] == '1' || dd[1] == '2' || dd[1] == '3' || dd[1] == '4' || dd[1] == '5' || dd[1] == '6' || dd[1] == '7' || dd[1] == '8' || dd[1] == '9')
                    {
                        sklad.handyShelf.miejsca[p].label[0] = dd[0];
                        sklad.handyShelf.miejsca[p].label[1] = dd[1];
                    }
                    else
                    {
                        std::cout << "error" << std::endl;
                    }
                }
                else
                {
                    std::cout << "error" << std::endl;
                }
            }
        }
    } while (nazwa[0] != 'E' && nazwa[1] != 'N' && nazwa[2] != 'D');
    return 0;
}