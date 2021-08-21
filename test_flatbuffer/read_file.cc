#include "flatbuffers/flatbuffers.h"
#include "monster_generated.h"
#include <iostream>
#include <fstream>

using namespace MyGame::Sample; // Specified in the schema.

int main(int argc, char* argv[]) {

    std::ifstream input;
    input.open(argv[1], std::ios::binary | std::ios::in);
    if (!input) {
        std::cout << argv[1] << ": File not found.  Creating a new file." << std::endl;
        return 0;
    } 
    input.seekg(0,std::ios::end);
    int length = input.tellg();
    input.seekg(0,std::ios::beg);
    char *data = new char[length];
    input.read(data, length);
    input.close();

    
    auto monster = GetMonster(data);
    auto hp = monster->hp();
    auto mana = monster->mana();
    auto name = monster->name()->c_str();
    auto pos = monster->pos();
    auto x = pos->x();
    auto y = pos->y();
    auto z = pos->z();
    auto inv = monster->inventory(); // A pointer to a `flatbuffers::Vector<>`.
    auto inv_len = inv->size();
    auto third_item = inv->Get(2);
    auto weapons = monster->weapons(); // A pointer to a `flatbuffers::Vector<>`.
    auto weapon_len = weapons->size();
    auto second_weapon_name = weapons->Get(1)->name()->str();
    auto second_weapon_damage = weapons->Get(1)->damage();
    auto union_type = monster->equipped_type();
 
    if (union_type == Equipment_Weapon) {
        auto weapon = static_cast<const Weapon*>(monster->equipped()); // Requires `static_cast`
                                                                        // to type `const Weapon*`.
        
        auto weapon_name = weapon->name()->str(); // "Axe"
        auto weapon_damage = weapon->damage();    // 5
    }
    std::cout << hp << " " << mana << " " << name << std::endl;
}