#! /usr/bin/env python

class loader(object):
    def __init__(self):
        self.modules = {}

    def addModules(self, module_regex):
        import imp
        import os
        import sys
        import glob

        for file_match in glob.glob(module_regex):
            file_match = os.path.realpath(file_match)
            f_dir = os.path.dirname(file_match)
            f_module = os.path.basename(os.path.splitext(file_match)[0])
            sys.path.append(f_dir)
            try:
                module = imp.load_source(f_module, file_match)
                sys.modules[f_module] = module
                self.modules[f_module] = module

                # Add to the globals
                setattr(sys.modules[__name__], f_module, module)
            except:
                pass


if __name__ == '__main__':
    import sys
    x = loader()
    x.addModules(sys.argv[1])
