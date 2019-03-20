#!/bin/sh

#  api-reference.sh
#  adventure2019
#
#  Created by admin on 2019-03-20.
#  Copyright © 2019 Maxim Puchkov. All rights reserved.


# Creates API table of contents in 'doc/' folder
HTML_OUTPUT_PATH=doc/.HeaderDoc/
headerdoc2html -o ${HTML_OUTPUT_PATH} $(find -E . -regex '.*(lib|data)\/.*\.h')
gatherheaderdoc ./doc
