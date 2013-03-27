<?php

/**
 * simple_content.admin.inc
 * Outputs the admin forms
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */


/**
 * Implements hook_form().
 * 
 * Main settings form
 *
 */
function simple_content_settings_form($form, &$form_state) {
  $form = array();

  // Vertical tabs
  $form['simple_content_settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => '-10',
  );

  // Fieldsets
  $form['simple_content_settings_introduction'] = array(
    '#type' => 'fieldset',
    '#weight' => '1',
    '#title' => t('Introduction section'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_settings',
  );
  $form['simple_content_settings_solutions'] = array(
    '#type' => 'fieldset',
    '#weight' => '2',
    '#title' => t('Solutions section'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_settings',
  );
  $form['simple_content_settings_banners'] = array(
    '#type' => 'fieldset',
    '#weight' => '3',
    '#title' => t('Banners section'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_settings',
  );
  $form['simple_content_settings_conclusion'] = array(
    '#type' => 'fieldset',
    '#weight' => '4',
    '#title' => t('Conclusion section'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_settings',
  );
  $form['simple_content_settings_contact'] = array(
    '#type' => 'fieldset',
    '#weight' => '5',
    '#title' => t('Contact section'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_settings',
  );

  // Home Enabled?
  $form['simple_content_settings_introduction']['simple_content_introduction_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Enable the introduction section?'),
    '#default_value' => variable_get('simple_content_introduction_enabled', 0),
    '#required' => FALSE,
  );

  // Solutions Enabled?
  $form['simple_content_settings_solutions']['simple_content_solutions_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Enable the solutions section?'),
    '#default_value' => variable_get('simple_content_solutions_enabled', 0),
    '#required' => FALSE,
  );

  // Number of solutions
  $form['simple_content_settings_solutions']['simple_content_solutions_number'] = array(
    '#title' => t('Number of solutions'),
    '#type' => 'textfield',
    '#default_value' => variable_get('simple_content_solutions_number', 3),
    '#description' => t('Number of solutions for solutions section. Note: inputing a smaller number will delete the upper values.')
  );

  // Banners Enabled?
  $form['simple_content_settings_banners']['simple_content_banners_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Enable the banners section?'),
    '#default_value' => variable_get('simple_content_banners_enabled', 0),
    '#required' => FALSE,
  );

  // Number of banners
  $form['simple_content_settings_banners']['simple_content_banners_number'] = array(
    '#title' => t('Number of banners'),
    '#type' => 'textfield',
    '#default_value' => variable_get('simple_content_banners_number', 3),
    '#description' => t('Number of banners for banners section. Note: inputing a smaller number will delete the upper values.')
  );

  // Conclusion Enabled?
  $form['simple_content_settings_conclusion']['simple_content_conclusion_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Enable the conclusion section?'),
    '#default_value' => variable_get('simple_content_conclusion_enabled', 0),
    '#required' => FALSE,
  );

  // Contact Enabled?
  $form['simple_content_settings_contact']['simple_content_contact_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Enable the contact section?'),
    '#default_value' => variable_get('simple_content_contact_enabled', 0),
    '#required' => FALSE,
  );

  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save configuration'),
  );

  return $form;
}


/**
 * Submit handler for form().
 * 
 * Main settings form
 *
 */
function simple_content_settings_form_submit($form, &$form_state) {

  // Home Enabled?
  variable_set('simple_content_introduction_enabled', 
    $form_state['values']['simple_content_introduction_enabled']);

  // Solutions Enabled?
  variable_set('simple_content_solutions_enabled',
    $form_state['values']['simple_content_solutions_enabled']);

  // Number of solutions
  $solutions_number_new = $form_state['values']['simple_content_solutions_number'];
  if (!empty($solutions_number_new)) {
    $solutions_number_old = variable_get('simple_content_solutions_number', 3);
    // Save new maximum solutions
    variable_set('simple_content_solutions_number', $solutions_number_new);
    // Delete solutions outside bounds
    if ($solutions_number_old > $solutions_number_new) {
      // Loop through number of solutions
      for ($i = $solutions_number_new + 1; $i <= $solutions_number_old; $i++) {
        // Make pid two digit algarism
        $pid = str_pad($i, 2, '0', STR_PAD_LEFT);

        // Solution Enabled?
        $tmp = variable_get('simple_content_solutions_' . $pid . '_enabled', NULL);
        (isset($tmp)) ? variable_del('simple_content_solutions_' . $pid . '_enabled') : '';

        // Solution Title
        $tmp = variable_get('simple_content_solutions_' . $pid . '_title', NULL);
        (isset($tmp)) ? variable_del('simple_content_solutions_' . $pid . '_title') : '';

        // Solution Menu Title
        $tmp = variable_get('simple_content_solutions_' . $pid . '_menu', NULL);
        (isset($tmp)) ? variable_del('simple_content_solutions_' . $pid . '_menu') : '';

        // Solution Body
        $tmp = variable_get('simple_content_solutions_' . $pid . '_body', NULL);
        (isset($tmp)) ? variable_del('simple_content_solutions_' . $pid . '_body') : '';

        // Solution Thumbnail
        $tmp = variable_get('simple_content_solutions_' . $pid . '_thumbnail', NULL);
        (isset($tmp)) ? variable_del('simple_content_solutions_' . $pid . '_thumbnail') : '';

      }
    }
  }

  // Banners Enabled?
  variable_set('simple_content_banners_enabled',
    $form_state['values']['simple_content_banners_enabled']);

  // Number of banners
  $banners_number_new = $form_state['values']['simple_content_banners_number'];
  if (!empty($banners_number_new)) {
    $banners_number_old = variable_get('simple_content_banners_number', 3);
    // Save new maximum banners
    variable_set('simple_content_banners_number', $banners_number_new);
    // Delete banners outside bounds
    if ($banners_number_old > $banners_number_new) {
      // Loop through number of banners
      for ($i = $banners_number_new + 1; $i <= $banners_number_old; $i++) {
        // Make pid two digit algarism
        $pid = str_pad($i, 2, '0', STR_PAD_LEFT);

        // Banner Enabled?
        $tmp = variable_get('simple_content_banners_' . $pid . '_enabled', NULL);
        (isset($tmp)) ? variable_del('simple_content_banners_' . $pid . '_enabled') : '';

        // Banner Title
        $tmp = variable_get('simple_content_banners_' . $pid . '_title', NULL);
        (isset($tmp)) ? variable_del('simple_content_banners_' . $pid . '_title') : '';

        // Banner Thumbnail
        $tmp = variable_get('simple_content_banners_' . $pid . '_thumbnail', NULL);
        (isset($tmp)) ? variable_del('simple_content_banners_' . $pid . '_thumbnail') : '';

      }
    }
  }

  // Contact Enabled?
  variable_set('simple_content_contact_enabled',
    $form_state['values']['simple_content_contact_enabled']);

}
