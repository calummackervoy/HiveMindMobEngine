#pragma once
#include "Typedef.h"
#include <string>
#include "Drug.h"

using std::string;

enum ItemType : uint8_t {
	ITEM_NULL,
	ITEM_WEAPON,
	ITEM_CONSUMABLE,
	ITEM_EQUIPMENT,
	ITEM_VULNERABILITY
};

struct Item {
	string name = "DEFAULT_ITEM_NAME";
	string desc = "DEFAULT_ITEM_DESC";
	int val = 1;
	sint id = -1;
	ItemType type = ITEM_NULL;
};

struct Weapon : Item {
	
};

struct Consumable : Item {
	DrugType type = DEF_DRUGTYPE;
	bool legal = true;
};

//an item which allows a certain task to be completed
//can be hardware or software or a combination
struct Equipment : Item {

};

//for hacking
struct Information : Item {

};

//vulnerability has type & method
enum VulnerabilityType : uint8_t {
	VULN_OTHER,
	VULN_BUFFER_OVERFLOW,
	VULN_UNVALIDATED_INPUT,
	VULN_RACE_CONDITION,
	VULN_MITM,
	VULN_REPLAY,
	VULN_CRYPTO,
	VULN_VIRUS
};

enum VulnerabilityMethod : uint8_t {
	METHOD_PHYSICAL_FORCE,
	METHOD_BRUTE_FORCE,
	METHOD_SQL_INJECTION,
	METHOD_XSS,
	METHOD_SNIFF_PACKETS,
	METHOD_SOCIAL_ENGINEERING,
	METHOD_PHISHING,
	METHOD_PHISHING_SPEAR,
	METHOD_KEY_LOGGER,
	METHOD_BIOS_ATTACK,
	METHOD_MANUAL_INSTALL
};

struct Vulnerability {
	VulnerabilityType type = VULN_OTHER;
	VulnerabilityMethod method = METHOD_PHYSICAL_FORCE;
};
//TODO: give items vulnerabilities or method to find out if they cover it? - how to check?

//access attempts will use a privilege type (can be user or access to specific element)
enum Privilege : uint8_t {
	PRIVILEGE_ROOT,
	PRIVILEGE_ADMIN,
	PRIVILEGE_HIGH,
	PRIVILEGE_MEDIUM,
	PRIVILEGE_LOW,
	PRIVILEGE_OUTSIDER
};

//access attempts will have a target action being attempted by the hacker
//TODO: changing & stealing specific data?
enum AccessAction : uint8_t {
	ACCESS_KILL,
	//ACCESS_CORRUPT_DATA, //i.e. make some errors?
	ACCESS_DOS,
	ACCESS_DDOS,
	ACCESS_RANSOMWARE,
	ACCESS_SPYWARE,
	ACCESS_STEAL_DATA,
	ACCESS_STEAL_PASS,
	ACCESS_TAKEOVER
};