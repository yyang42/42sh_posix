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

void	exec_cmd(const char *cmd)
{
	free(get_cmd_out(cmd));
}

void	sandbox_cmd(const char *cmd)
{
	char full_cmd[MAX_CMD_SIZE];

	bzero(full_cmd, MAX_CMD_SIZE);
	strcat(full_cmd, "cd "SANDBOX_PATH);
	strcat(full_cmd, " && ");
	strcat(full_cmd, cmd);
	if(debug)
		strcat(full_cmd, " 1>&2");
	exec_cmd(full_cmd);
}

void	reset_sandbox()
{
	exec_cmd("chmod -Rf 777 /tmp/sandbox 2> /dev/null");
	exec_cmd("rm -rf /tmp/sandbox");
	exec_cmd("mkdir /tmp/sandbox ");
}
