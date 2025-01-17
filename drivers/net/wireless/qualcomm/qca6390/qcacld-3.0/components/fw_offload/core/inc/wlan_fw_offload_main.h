/*
 * Copyright (c) 2012 - 2019 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/**
 * DOC: declare utility API related to the fw_offload component
 * called by other components
 */

#ifndef _WLAN_FW_OFFLOAD_MAIN_H_
#define _WLAN_FW_OFFLOAD_MAIN_H_

#include <wlan_objmgr_psoc_obj.h>
#include <wlan_objmgr_global_obj.h>
#include <wlan_cmn.h>

#include "cfg_ucfg_api.h"

#define fwol_alert(params...) QDF_TRACE_FATAL(QDF_MODULE_ID_FWOL, params)
#define fwol_err(params...) QDF_TRACE_ERROR(QDF_MODULE_ID_FWOL, params)
#define fwol_warn(params...) QDF_TRACE_WARN(QDF_MODULE_ID_FWOL, params)
#define fwol_info(params...) QDF_TRACE_INFO(QDF_MODULE_ID_FWOL, params)
#define fwol_debug(params...) QDF_TRACE_DEBUG(QDF_MODULE_ID_FWOL, params)

/**
 * struct wlan_fwol_three_antenna_btc - Three antenna BTC config items
 * @btc_mode: Config BTC mode
 * @antenna_isolation: Antenna isolation
 * @max_tx_power_for_btc: Max wlan tx power in co-ex scenario
 * @wlan_low_rssi_threshold: Wlan low rssi threshold for BTC mode switching
 * @bt_low_rssi_threshold: BT low rssi threshold for BTC mode switching
 * @bt_interference_low_ll: Lower limit of low level BT interference
 * @bt_interference_low_ul: Upper limit of low level BT interference
 * @bt_interference_medium_ll: Lower limit of medium level BT interference
 * @bt_interference_medium_ul: Upper limit of medium level BT interference
 * @bt_interference_high_ll: Lower limit of high level BT interference
 * @bt_interference_high_ul: Upper limit of high level BT interference
 * @btc_mpta_helper_enable: Enable/Disable tri-radio MPTA helper
 */
struct wlan_fwol_coex_config {
	uint8_t btc_mode;
	uint8_t antenna_isolation;
	uint8_t max_tx_power_for_btc;
	int16_t wlan_low_rssi_threshold;
	int16_t bt_low_rssi_threshold;
	int16_t bt_interference_low_ll;
	int16_t bt_interference_low_ul;
	int16_t bt_interference_medium_ll;
	int16_t bt_interference_medium_ul;
	int16_t bt_interference_high_ll;
	int16_t bt_interference_high_ul;
#ifdef FEATURE_MPTA_HELPER
	bool    btc_mpta_helper_enable;
#endif
};

#define FWOL_THERMAL_LEVEL_MAX 4
#define FWOL_THERMAL_THROTTLE_LEVEL_MAX 4
/*
 * struct wlan_fwol_thermal_temp - Thermal temperature config items
 * @thermal_temp_min_level: Array of temperature minimum levels
 * @thermal_temp_max_level: Array of temperature maximum levels
 * @thermal_mitigation_enable: Control for Thermal mitigation feature
 * @throttle_period: Thermal throttle period value
 * @throttle_dutycycle_level: Array of throttle duty cycle levels
 */
struct wlan_fwol_thermal_temp {
	bool     thermal_mitigation_enable;
	uint32_t throttle_period;
	uint16_t thermal_temp_min_level[FWOL_THERMAL_LEVEL_MAX];
	uint16_t thermal_temp_max_level[FWOL_THERMAL_LEVEL_MAX];
	uint32_t throttle_dutycycle_level[FWOL_THERMAL_THROTTLE_LEVEL_MAX];
};

/**
 * struct wlan_fwol_ie_whitelist - Probe request IE whitelist config items
 * @ie_whitelist: IE whitelist flag
 * @ie_bitmap_0: IE bitmap 0
 * @ie_bitmap_1: IE bitmap 1
 * @ie_bitmap_2: IE bitmap 2
 * @ie_bitmap_3: IE bitmap 3
 * @ie_bitmap_4: IE bitmap 4
 * @ie_bitmap_5: IE bitmap 5
 * @ie_bitmap_6: IE bitmap 6
 * @ie_bitmap_7: IE bitmap 7
 * @no_of_probe_req_ouis: Total number of ouis present in probe req
 * @probe_req_voui: Stores oui values after parsing probe req ouis
 */
struct wlan_fwol_ie_whitelist {
	bool ie_whitelist;
	uint32_t ie_bitmap_0;
	uint32_t ie_bitmap_1;
	uint32_t ie_bitmap_2;
	uint32_t ie_bitmap_3;
	uint32_t ie_bitmap_4;
	uint32_t ie_bitmap_5;
	uint32_t ie_bitmap_6;
	uint32_t ie_bitmap_7;
	uint32_t no_of_probe_req_ouis;
	uint32_t probe_req_voui[MAX_PROBE_REQ_OUIS];
};

/**
 * struct wlan_fwol_neighbor_report_cfg - Neighbor report config params
 * @enable_bitmask: Neighbor report offload bitmask control
 * @params_bitmask: Param validity bitmask
 * @time_offset: Neighbor report frame time offset
 * @low_rssi_offset: Low RSSI offset
 * @bmiss_count_trigger: Beacon miss trigger count
 * @per_threshold_offset: PER Threshold offset
 * @cache_timeout: Cache timeout
 * @max_req_cap: Max request per peer
 */
struct wlan_fwol_neighbor_report_cfg {
	uint32_t enable_bitmask;
	uint32_t params_bitmask;
	uint32_t time_offset;
	uint32_t low_rssi_offset;
	uint32_t bmiss_count_trigger;
	uint32_t per_threshold_offset;
	uint32_t cache_timeout;
	uint32_t max_req_cap;
};

/**
 * struct wlan_fwol_cfg - fwol config items
 * @coex_config: coex config items
 * @thermal_temp_cfg: Thermal temperature related config items
 * @ie_whitelist_cfg: IE Whitelist related config items
 * @neighbor_report_cfg: 11K neighbor report config
 * @ani_enabled: ANI enable/disable
 * @enable_rts_sifsbursting: Enable RTS SIFS Bursting
 * @max_mpdus_inampdu: Max number of MPDUS
 * @arp_ac_category: ARP AC category
 * @enable_phy_reg_retention: Enable PHY reg retention
 * @upper_brssi_thresh: Upper BRSSI threshold
 * @lower_brssi_thresh: Lower BRSSI threshold
 * @enable_dtim_1chrx: Enable/disable DTIM 1 CHRX
 * @alternative_chainmask_enabled: Alternate chainmask
 * @smart_chainmask_enabled: Enable/disable chainmask
 * @get_rts_profile: Set the RTS profile
 * @enable_fw_log_level: Set the FW log level
 * @enable_fw_log_type: Set the FW log type
 * @enable_fw_module_log_level: enable fw module log level
 * @enable_fw_module_log_level_num: enablefw module log level num
 * @is_rate_limit_enabled: Enable/disable RA rate limited
 * @tsf_gpio_pin: TSF GPIO Pin config
 * @tsf_irq_host_gpio_pin: TSF GPIO Pin config
 * @tsf_ptp_options: TSF Plus feature options config
 * @lprx_enable: LPRx feature enable config
 * @sae_enable: SAE feature enable config
 * @gcmp_enable: GCMP feature enable config
 * @enable_tx_sch_delay: Enable TX SCH delay value config
 * @enable_secondary_rate: Enable secondary retry rate config
 * @enable_dhcp_server_offload: DHCP Offload is enabled or not
 * @dhcp_max_num_clients: Max number of DHCP client supported
 * @dwelltime_params: adaptive dwell time parameters
 */
struct wlan_fwol_cfg {
	/* Add CFG and INI items here */
	struct wlan_fwol_coex_config coex_config;
	struct wlan_fwol_thermal_temp thermal_temp_cfg;
	struct wlan_fwol_ie_whitelist ie_whitelist_cfg;
	struct wlan_fwol_neighbor_report_cfg neighbor_report_cfg;
	bool ani_enabled;
	bool enable_rts_sifsbursting;
	uint8_t max_mpdus_inampdu;
	uint32_t arp_ac_category;
	uint8_t enable_phy_reg_retention;
	uint16_t upper_brssi_thresh;
	uint16_t lower_brssi_thresh;
	bool enable_dtim_1chrx;
	bool alternative_chainmask_enabled;
	bool smart_chainmask_enabled;
	uint16_t get_rts_profile;
	uint16_t enable_fw_log_level;
	uint16_t enable_fw_log_type;
	uint8_t enable_fw_module_log_level[FW_MODULE_LOG_LEVEL_STRING_LENGTH];
	uint8_t enable_fw_module_log_level_num;
#ifdef FEATURE_WLAN_RA_FILTERING
	bool is_rate_limit_enabled;
#endif
#ifdef WLAN_FEATURE_TSF
	uint32_t tsf_gpio_pin;
#ifdef WLAN_FEATURE_TSF_PLUS
	uint32_t tsf_ptp_options;
#ifdef WLAN_FEATURE_TSF_PLUS_EXT_GPIO_IRQ
	uint32_t tsf_irq_host_gpio_pin;
#endif
#endif
#endif
	bool lprx_enable;
#ifdef WLAN_FEATURE_SAE
	bool sae_enable;
#endif
	bool gcmp_enable;
	uint8_t enable_tx_sch_delay;
	uint32_t enable_secondary_rate;
#ifdef DHCP_SERVER_OFFLOAD
	bool enable_dhcp_server_offload;
	uint32_t dhcp_max_num_clients;
#endif
	struct adaptive_dwelltime_params dwelltime_params;
};

/**
 * struct wlan_fwol_psoc_obj - FW offload psoc priv object
 * @cfg:     cfg items
 */
struct wlan_fwol_psoc_obj {
	struct wlan_fwol_cfg cfg;
};

/**
 * wlan_psoc_get_fwol_obj() - private API to get fwol object from psoc
 * @psoc: psoc object
 *
 * Return: fwol object
 */
struct wlan_fwol_psoc_obj *fwol_get_psoc_obj(struct wlan_objmgr_psoc *psoc);

/*
 * fwol_cfg_on_psoc_enable() - Populate FWOL structure from CFG and INI
 * @psoc: pointer to the psoc object
 *
 * Populate the FWOL CFG structure from CFG and INI values using CFG APIs
 *
 * Return: QDF_STATUS
 */
QDF_STATUS fwol_cfg_on_psoc_enable(struct wlan_objmgr_psoc *psoc);

/*
 * fwol_cfg_on_psoc_disable() - Clear the CFG structure on psoc disable
 * @psoc: pointer to the psoc object
 *
 * Clear the FWOL CFG structure on psoc disable
 *
 * Return: QDF_STATUS
 */
QDF_STATUS fwol_cfg_on_psoc_disable(struct wlan_objmgr_psoc *psoc);

/*
 * fwol_init_neighbor_report_cfg() - Populate default neighbor report CFG values
 * @psoc: pointer to the psoc object
 * @fwol_neighbor_report_cfg: Pointer to Neighbor report config data structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS fwol_init_neighbor_report_cfg(struct wlan_objmgr_psoc *psoc,
					 struct wlan_fwol_neighbor_report_cfg
					 *fwol_neighbor_report_cfg);

/**
 * wlan_fwol_init_adapt_dwelltime_in_cfg - initialize adaptive dwell time params
 * @psoc: Pointer to struct wlan_objmgr_psoc context
 * @dwelltime_params: Pointer to dwell time params
 *
 * This function parses initialize the adaptive dwell params from ini.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
fwol_init_adapt_dwelltime_in_cfg(
			struct wlan_objmgr_psoc *psoc,
			struct adaptive_dwelltime_params *dwelltime_params);

/**
 * fwol_set_adaptive_dwelltime_config - API to set adaptive dwell params config
 *
 * @adaptive_dwelltime_params: adaptive_dwelltime_params structure
 *
 * Return: QDF Status
 */
QDF_STATUS
fwol_set_adaptive_dwelltime_config(
			struct adaptive_dwelltime_params *dwelltime_params);
#endif
