/*
 * Copyright (C) 2012 Thomas Petazzoni
 *
 * Thomas Petazzoni <thomas.petazzoni@free-electrons.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/acpi.h>
#include <linux/init.h>
#include <linux/of_irq.h>
#include <linux/irqchip.h>

/*
 * This special of_device_id is the sentinel at the end of the
 * of_device_id[] array of all irqchips. It is automatically placed at
 * the end of the array by the linker, thanks to being part of a
 * special section.
 */
static const struct of_device_id
irqchip_of_match_end __used __section(__irqchip_of_table_end);

// 
extern struct of_device_id __irqchip_of_table[];


// 在 start_kernel(void) -> init_IRQ(void) 中调用
void __init irqchip_init(void)
{
	// of_irq_init 函数执行之前，系统已经完成了device tree的初始化
	// __irqchip_of_table 在链接脚本 vmlinux.lds中定义段
	// of_irq_init 定义在 drivers/of/irq.c 
	of_irq_init(__irqchip_of_table);
	acpi_probe_device_table(irqchip);
}
