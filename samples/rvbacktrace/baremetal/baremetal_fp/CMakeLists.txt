# Copyright (c) 2024 HPMicro
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

set(CONFIG_RV_BACKTRACE true)
set(RV_BACKTRACE_USE_FP true)
find_package(hpm-sdk REQUIRED HINTS $ENV{HPM_SDK_BASE})

project(backtrace_bm)

sdk_inc(src)
sdk_app_src(../baremetal.c)
generate_ide_projects()
