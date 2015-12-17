#include "simple_command.h"

void simple_command_entrance(t_simple_command *cmd, t_ast *this)
{
	travel_simple_command(this->root, cmd);
}
