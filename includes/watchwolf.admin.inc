<?php
/**
 * @file
 * Admin pages.
 */


/**
 * Administration form.
 */
function watchwolf_admin_settings_form($form, &$form_state) {

  $form = array();

  $form['watchdog_services_url'] = array(
    '#title' => t('URL'),
    '#description' => t('The URL to post logmessages to.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('watchdog_services_url', 'http://localhost:3000/log'),
  );

  $form['watchdog_lightweight_http'] = array(
    '#title' => t('Use lightweight http requests?'),
    '#description' => t('Lightweight http requests are more performant but there is a higher probability some log messages will not be registered by the external api.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('watchdog_lightweight_http', 0),
  );

  $form['watchdog_log_every_page_request'] = array(
    '#title' => t('Test logging every page request?'),
    '#description' => t('Sends a log message at least once every page request (non cached pages). Useful for testing the api. Do not use in production.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('watchdog_log_every_page_request', 0),
  );

  return system_settings_form($form);
}