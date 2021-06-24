#include "Servers.hpp"

Servers::~Servers()
{
    return ;
}

Servers::Servers()
{
    return ;
}

std::vector<Inside>    Servers::getServs() const
{
    return (this->servs);
}

int Servers::parsing(const char *filename)
{
    std::vector<std::string>    file;

    file = Parser::readConfig(filename);
    for (int i = 0; i < file.size(); i++)
    {
        if (file[i] != "server")
        {
            std::cerr << "Error: unknown [" << file[i] << "]" << std::endl;
            return (1);
        }
        else
        {
            Inside serv; //!!!
            i++;
            if (file[i] != "{")
            {
                std::cerr << "Error: no '{' after server directive" << std::endl;
                return (1);
            }
            i++;
            // if (!serv.writeInside(i, file)); //!!!
            // {
            //     //std::cout << file[i] << " !!! " << i << std::endl;
            //     std::cerr << "Error: invalid config file [" << filename << "]" << std::endl;
            //     return (1);
            // }
            serv.writeInside(i, file);
            this->servs.push_back(serv); //!!!!
        }
    }
    return (0);
}

int main(void)
{
    Servers raz;

    raz.parsing("./testconf/serv.conf");

    //print root
    std::cout << (raz.getServs())[0].getRoot() << std::endl;

    //print server_name
    std::cout << (raz.getServs())[0].getServerName()[0] << std::endl;

    //print listen
    std::cout << (raz.getServs())[0].getListen()[0].host << std::endl;
    std::cout << (raz.getServs())[0].getListen()[0].port << std::endl;

    //print location
    std::map<std::string, Inside>::iterator it;
    it = raz.getServs()[0].getLocation().begin();
    
    //std::cout << it << std::endl;
    std::cout <<it->first<<std::endl;
    std::cout <<it->second.getRoot()<<std::endl;
    it++;
    std::cout <<it->first<<std::endl;
    //std::map<std::string, Inside>::iterator it = (raz.getServs())[0].getLocation().begin();
    // while (it != raz.getServs()[0].getLocation().end())
    // {
    //     std::cout <<it->first<<std::endl;
    //     it++;
    // }
    return (0);
}