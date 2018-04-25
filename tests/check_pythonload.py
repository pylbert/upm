#!/usr/bin/python
import glob
import imp
import os
import sys

# Skip individual modules based on module name.  For example,
# pyupm_ozw will skip pyupm_ozw.py.
blacklist = [
             # OpenZwave-dependent modules
             'pyupm_ozw', 'aeotecdw2e', 'tzemt400', 'aeotecdsb09104',
             'aeotecss6', 'aeotecsdg2', 'ozwdump',
             # Requires mraa python module
             'curieimu',
             # Requires modbus
             'h803x', 'hwxpxx', 't3311',
             # Requires bacnet
             'e50hx', 'tb7300', 't8100',
             # Requires PIL
             'make_oled_pic'
             ]


#class loadModule(unittest.TestCase):
class loadModule(object):
    ''' The loadModule class loads all module which match a search string
    provided via argv.  If any of the target modules fails loading, this
    class will assert and provide a list of failing modules.'''
    def test_load_modules(self, test_module_regex, support_module_regex = None):
        # Make sure the search string has a full path
        full_py_search_str = os.path.realpath(test_module_regex)

        # Get all python modules matching full_py_search_str
        pyfiles = glob.glob(full_py_search_str)

        # Fail if no modules to test
        if len(pyfiles) == 0:
            sys.exit('Failed to find any %s modules in %s' %
                    (test_module_regex, full_py_search_str))

        # If any support modules were provided, create a fake module
        # called 'upm', and place them under it
        if (support_module_regex != None):
            import upm
            x = upm.loader()
            x.addModules(support_module_regex)

        # Test load each module
        failures = {}
        for pyfile in pyfiles:
            module = os.path.splitext(os.path.basename(pyfile))[0]

            # Don't load blacklisted modules
            if module in blacklist:
                print('Skipping blacklisted %s ...' % pyfile)
                continue

            # Append the path of this python module
            sys.path.append(os.path.dirname(pyfile))

            try:
                pyfile = imp.load_source(module, pyfile)
            except Exception as x:
                failures[pyfile] = x

        skeys = list(failures.keys())
        skeys.sort()
        if len(failures) != 0:
            sys.exit(
                '\n\n%s' % '\n'.join((['%s=%s' % (k, os.environ[k]) for k in list(os.environ.keys())])) +
                '\npython %s\n' % ' '.join(sys.version.strip().split()) +
                '\nFailed to load %d modules:\n' % len(failures) +
                '\n'.join(['%s: %s' % (k, failures[k]) for k in skeys]))


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(description='Python module loader')
    parser.add_argument('-l', '--load-module-regex',
            metavar='/regex/path/to/*/module.py', required=True,
            help='Regex of modules to test')
    parser.add_argument('-s', '--support-module-regex',
            metavar='/regex/path/to/*/module.py',
            help="Regex of python modules to add to module 'upm'")

    args = parser.parse_args()
    x = loadModule()

    x.test_load_modules(args.load_module_regex, args.support_module_regex)
