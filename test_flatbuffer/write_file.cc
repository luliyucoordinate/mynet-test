#include "flatbuffers/flatbuffers.h"
#include "monster_generated.h"
#include <iostream>
#include <fstream>

using namespace MyGame::Sample; // Specified in the schema.

int main(int argc, char* argv[]) {
    // Create a `FlatBufferBuilder`, which will be used to create our
    // monsters' FlatBuffers.
    flatbuffers::FlatBufferBuilder builder(1024);
    auto weapon_one_name = builder.CreateString("Sword");
    short weapon_one_damage = 3;
    
    auto weapon_two_name = builder.CreateString("Axe");
    short weapon_two_damage = 5;
    
    // Use the `CreateWeapon` shortcut to create Weapons with all the fields set.
    auto sword = CreateWeapon(builder, weapon_one_name, weapon_one_damage);
    auto axe = CreateWeapon(builder, weapon_two_name, weapon_two_damage);
        // Serialize a name for our monster, called "Orc".
    auto name = builder.CreateString("Orc");
    
    // Create a `vector` representing the inventory of the Orc. Each number
    // could correspond to an item that can be claimed after he is slain.
    unsigned char treasure[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto inventory = builder.CreateVector(treasure, 10);
    // Place the weapons into a `std::vector`, then convert that into a FlatBuffer `vector`.
    std::vector<flatbuffers::Offset<Weapon>> weapons_vector;
    weapons_vector.push_back(sword);
    weapons_vector.push_back(axe);
    auto weapons = builder.CreateVector(weapons_vector);
    Vec3 points[] = { Vec3(1.0f, 2.0f, 3.0f), Vec3(4.0f, 5.0f, 6.0f) };
    auto path = builder.CreateVectorOfStructs(points, 2);
    // Create the position struct
    auto position = Vec3(1.0f, 2.0f, 3.0f);
    
    // Set his hit points to 300 and his mana to 150.
    int hp = 300;
    int mana = 150;
    
    flatbuffers::Offset<Monster> mlocs[3];
    auto fred = builder.CreateString("Fred");
    auto barney = builder.CreateString("Barney");
    auto wilma = builder.CreateString("Wilma");
    MonsterBuilder mb1(builder);
    mb1.add_name(fred);
    mlocs[0] = mb1.Finish();
    MonsterBuilder mb2(builder);
    mb2.add_name(barney);
    mb2.add_hp(1000);
    mlocs[1] = mb2.Finish();
    MonsterBuilder mb3(builder);
    mb3.add_name(wilma);
    mlocs[2] = mb3.Finish();
    auto vecoftables = builder.CreateVectorOfSortedTables(mlocs, 3);
    
    // Finally, create the monster using the `CreateMonster` helper function
    // to set all fields.
    auto orc = CreateMonster(builder, &position, mana, hp, name, inventory,
                            Color_Red, weapons, Equipment_Weapon, axe.Union(),
                            path, vecoftables);
    // Call `Finish()` to instruct the builder that this monster is complete.
    // Note: Regardless of how you created the `orc`, you still need to call
    // `Finish()` on the `FlatBufferBuilder`.
    builder.Finish(orc); // You could also call `FinishMonsterBuffer(builder, orc);`.
    uint8_t *buf = builder.GetBufferPointer();
    int size = builder.GetSize(); // Returns the size of the buffer that
                                // `GetBufferPointer()` points to.

    {
        // Write the new address book back to disk.
        std::fstream output(argv[1], std::ios::out | std::ios::trunc | std::ios::binary);
        output.write((char*)buf, size);
    }
}