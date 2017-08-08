// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <magenta/syscalls/hypervisor.h>

/* Stores the IO port state. */
typedef struct io_port {
    // Index of the RTC register to use.
    uint8_t rtc_index;
    // Command being issued to the i8042 controller.
    uint8_t i8042_command;
    // State of power management enable register.
    uint16_t pm1_enable;
    // Selected address in PCI config space.
    uint32_t pci_config_address;
} io_port_t;

void io_port_init(io_port_t* io_port);
mx_status_t io_port_read(const io_port_t* io_port, uint16_t port, mx_vcpu_io_t* vcpu_io);
mx_status_t io_port_write(io_port_t* io_port, uint16_t port, const mx_guest_io_t* io);
