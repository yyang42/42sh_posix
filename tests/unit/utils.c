#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <project.h>

#define MAX_CMD_SIZE 10000
#define SANDBOX_PATH "/tmp/sandbox"

int		debug = 0;

char	*get_cmd_out(const char *cmd)
{
	FILE *fp;
	char buf[1035];
	char *out;

	out = malloc(1);
	*out = '\0';

	fp = popen(cmd, "r");

	/* Read the output a line at a time - output it. */
	while (fgets(buf, sizeof(buf)-1, fp) != NULL) {
		out = realloc(out, strlen(out) + strlen(buf) + 1);
		strcat(out, buf);
	}
	pclose(fp);
	return (out);
}

char	*sandbox_cmd(const char *cmd)
{
	char full_cmd[MAX_CMD_SIZE];

	bzero(full_cmd, MAX_CMD_SIZE);
	strcat(full_cmd, "cd "SANDBOX_PATH);
	strcat(full_cmd, " && ");
	strcat(full_cmd, cmd);
	if(debug)
		strcat(full_cmd, " 1>&2");
	return get_cmd_out(full_cmd);
}

void	reset_sandbox()
{
	get_cmd_out("chmod -R 777 /tmp/sandbox");
	get_cmd_out("rm -rf /tmp/sandbox");
	get_cmd_out("mkdir /tmp/sandbox ");
}
