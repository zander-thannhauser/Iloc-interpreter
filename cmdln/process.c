
#include <getopt.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include <memory/tmalloc.h>

#include "flags.h"
#include "usage.h"
#include "free.h"
#include "process.h"

int process_cmdln(
	struct cmdln_flags** out_flags,
	int argc, char** argv)
{
	int error = 0;
	ENTER;
	
	const char* input_path = NULL;
	bool verbose = false;
	bool print_stats = false;
	
	// for getopt:
	int opt, option_index;
	const struct option long_options[] = {
		{"input",  required_argument, 0, 'i'},
		{"verbose",      no_argument, 0, 'v'},
		{"print-stats",  no_argument, 0, 's'},
		{0, 0, 0, 0}
	};
	
	while (!error && (opt = getopt_long(argc, argv,
		"i:" "v" "d" "s" "h",
		long_options, &option_index)) >= 0)
	{
		switch (opt)
		{
			case 'i':
				input_path = optarg;
				break;
			
			case 'v':
				verbose = false;
				break;
			
			case 's':
				print_stats = true;
				break;
			
			case 'h':
				error = e_show_usage;
				break;
			
			default:
				error = e_bad_cmdline_args;
				break;
		}
	}
	
	if (!error && (!input_path))
		error = e_bad_cmdline_args;
	
	#ifdef DEBUGGING
	if (!error)
	{
		dpvs(input_path);
		dpvb(verbose);
	}
	#endif
	
	FILE* in = NULL;
	
	struct cmdln_flags* flags = NULL;
	
	if (error)
		usage();
	else if (!(in  = fopen(input_path, "r")))
		fprintf(stderr, "%s: fopen(\"%s\"): %m\n", argv0, input_path),
		error = e_syscall_failed;
	else
		error = tmalloc((void**) &flags, sizeof(*flags), free_cmdln_flags);
	
	if (!error)
	{
		flags->in  = in, in = NULL;
		flags->verbose = verbose;
		flags->print_stats = print_stats;
		
		*out_flags = flags;
	}
	
	if (in)
		fclose(in);
	
	EXIT;
	return error;
}









