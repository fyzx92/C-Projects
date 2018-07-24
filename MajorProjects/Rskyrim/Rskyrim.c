/*
* Authored by Bryce Burgess
* pseudo, text-based skyrim
*/

typedef struct character {
	char name;
	int maxHealth;
	int health;
	int money;
	char race;
	journal;
	weapon equippedWeapon;
	armor equippedArmor;
	consumable consumable;
	weapons storedWeapons;
	armor storedArmor;
} character;

typedef struct weapon {
	char name;
	int damage;
	double strikeSpeed;
	char enchantment;
} weapon;

typedef struct armor {
	
} armor;

typedef struct consumable {
	char type;
	char effect;
	int strength;
	double weight;
} consumable;

typedef struct map {
	
} map;

map mapGenerator () {
	/*
	* shallow water
	* deep water
	* swamp
	* forest
	* rocky
	* grass
	* stone
	* empty
	*
	*
	*/


};
