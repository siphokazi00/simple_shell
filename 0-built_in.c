#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on invalid argument, 2 on error
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_error_puts(info->argv[1]);
			_error_putchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir;
	int chdir_ret;
	char buffer[1024];

	if (!info->argv[1])
		dir = _getenv(info, "HOME=");
	else if (_strcmp(info->argv[1], "-") == 0)
		dir = _getenv(info, "OLDPWD=");
	else
		dir = info->argv[1];

	chdir_ret = chdir(dir);

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_error_puts(info->argv[1]);
		_error_putchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, sizeof(buffer)));
	}

	if (_strcmp(info->argv[1], "-") == 0 && !_getenv(info, "OLDPWD="))
	{
		_puts("OLDPWD not set");
		_putchar('\n');
	}

	return (0);
}

/**
 * _myhelp - displays help information (not yet implemented)
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented\n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
