#include <iostream>
#include <memory>  //libraria in care se afla smart pointers
#include <vector>

//std::unique_ptr -> smart pointer ce asigura o singura referinta spre obiect si sterge obiectul cand este out of scope

//std::shared_ptr -> smart pointer ce pate avea mai multi pointeri spre acelasi obiect, dar cand nu mai este nici unul cheama delete


class Entity
{
    public:
        Entity()
        {
            std::cout << "Entity was created \n";
        }
        ~Entity()
        {
            std::cout << "Entity was destroyed \n";
        }
};

void CreateEntity()
{
    Entity* e = new Entity();
    delete e;
}

void CreateEntityUniquePtr()
{
    //std::unique_ptr<Entity> e(Entity);
    //std::unique_ptr<Entity> e (new Entity());

    std::unique_ptr<Entity> e = std::make_unique<Entity>(); //preferabil (varianta preferabila)
    std::cout << "Se termina CreatyEntityUniquePtr \n";
}

std::shared_ptr<Entity> CreateEntitySharedPtr()
{
    std::shared_ptr<Entity> e = std::make_shared<Entity>(); 
    std::cout << "Ref count: " << e.use_count() << std::endl;
    std::cout << "Se termina CreatyEntitySharedPtr \n";
    return e;
}
void print(std::shared_ptr<Entity> e)
{
    std::cout << "Ref count: " << e.use_count() << std::endl;
    std::cout << "Se termina CreatyEntitySharedPtr \n";
}

struct Player 
{
    Player()
    {
        std::cout << "Player was created \n";
    }
    //std::shared_ptr<Player> companion;
    std::weak_ptr<Player> companion;

    ~Player()
    {
        std::cout << "Player was destroyed \n";
    }
};

int main(int argc, char const *argv[])
{
    std::shared_ptr<Player> Sergiu = std::make_shared<Player>();
    std::shared_ptr<Player> Stefan = std::make_shared<Player>();

    std::weak_ptr<Player> p = std::make_shared<Player>();
    //std::weak_ptr<Player> p = p_weak(p_shared);

    std::weak_ptr<Player> p2 = p.lock(); 


    Sergiu->companion = Stefan;
    Stefan->companion = Sergiu;

    //CreateEntity();
    CreateEntityUniquePtr();
    std::shared_ptr<Entity> e = CreateEntitySharedPtr();

    std::cout << "Se termina stiva main \n";

    //std::unique_ptr<Entity> e = std::make_unique<Entity>();
    //std::unique_ptr<Entity> e2 = e;
    //std::unique_ptr<Entity> e2 = std::move(e);

    //std::vector<std::unique_ptr<Entity>> lista ;
    //std::unique_ptr<Entity[]> data(new Entity[50]);


    
    
    return 0;
}
