/*
 * Generated by ./misc/optlib2c from optlib/RSpec.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "subparser.h"


static void initializeRSpecParser (const langType language CTAGS_ATTR_UNUSED)
{
}

extern parserDefinition* RSpecParser (void)
{
	static const char *const extensions [] = {
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static kindDefinition RSpecKindTable [] = {
		{ true, 'd', "describe", "describes" },
		{ true, 'c', "context", "contexts" },
	};
	static tagRegexTable RSpecTagRegexTable [] = {
		{"^[ \t]*RSpec\\.describe[ \t]+([^\"']+)[ \t]+do", "\\1",
		"d", NULL, NULL, false},
		{"^[ \t]*describe[ \t]+\"([^\"]+)\"[ \t]+do", "\\1",
		"d", NULL, NULL, false},
		{"^[ \t]*describe[ \t]+'([^']+)'[ \t]+do", "\\1",
		"d", "	", NULL, false},
		{"^[ \t]*describe[ \t]+([^\"']+)[ \t]+do", "\\1",
		"d", NULL, NULL, false},
		{"^[ \t]*context[ \t]+\"([^\"]+)\"[ \t]+do", "\\1",
		"c", NULL, NULL, false},
		{"^[ \t]*context[ \t]+'([^']+)'[ \t]+do", "\\1",
		"c", "	", NULL, false},
		{"^[ \t]*context[ \t]+([^\"']+)[ \t]+do", "\\1",
		"c", NULL, NULL, false},
	};

	static subparser RSpecSubparser = {
		.direction = SUBPARSER_BASE_RUNS_SUB,
	};
	static parserDependency RSpecDependencies [] = {
		[0] = { DEPTYPE_SUBPARSER, "Ruby", &RSpecSubparser },
	};

	parserDefinition* const def = parserNew ("RSpec");

	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->kindTable = RSpecKindTable;
	def->kindCount = ARRAY_SIZE(RSpecKindTable);
	def->tagRegexTable = RSpecTagRegexTable;
	def->tagRegexCount = ARRAY_SIZE(RSpecTagRegexTable);
	def->dependencies = RSpecDependencies;
	def->dependencyCount = ARRAY_SIZE(RSpecDependencies);
	def->initialize    = initializeRSpecParser;

	return def;
}
