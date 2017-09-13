#pragma once
#include "Item.h"

struct Information : Item {

};

//vulnerability has type & method
enum VulnerabilityType : uint8_t {
	VULN_OTHER,
	VULN_BUFFER_OVERFLOW,
	VULN_UNVALIDATED_INPUT,
	VULN_RACE_CONDITION,
	//VULN_MITM, //TODO: <--name for method?
	//VULN_REPLAY, //TODO: <--name for method?
	VULN_CRYPTO,
	VULN_VIRUS
};

enum VulnerabilityMethod : uint8_t {
	METHOD_PHYSICAL_FORCE,
	METHOD_BRUTE_FORCE,
	METHOD_SQL_INJECTION,
	METHOD_XSS,
	METHOD_SNIFF_PACKETS,
	//METHOD_SOCIAL_ENGINEERING, <--??
	//METHOD_SPOOFING, <--??
	METHOD_PHISHING,
	METHOD_PHISHING_SPEAR,
	METHOD_KEY_LOGGER,
	METHOD_BIOS_ATTACK,
	METHOD_MANUAL_INSTALL,
	//METHOD_ROUTING_ATTACK <--??
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

//for social engineering actions
enum SocialEngineeringAction : uint8_t {
	SOCIAL_ALLOW_ACCESS,
	SOCIAL_GAIN_INFO,
	SOCIAL_GIVE_PASS
};
enum SocialEngineeringMethod : uint8_t {
	//SOCIAL_METHOD_NULL,
	SOCIAL_METHOD_SPOOF,
	SOCIAL_METHOD_BRIBE,
	SOCIAL_METHOD_THREAT
};

//for functions relating to hacking
enum ExploitResponse : uint8_t {
	EXPLOIT_RES_SUCCESS,
	EXPLOIT_RES_FAILURE_DISCRETE,
	//EXPLOIT_RES_INVALID_NULL_SOCIAL_METHOD,
	EXPLOIT_RES_FAILURE_OVERT
};