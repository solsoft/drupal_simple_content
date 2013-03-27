<?php

/**
 * simple_content_banners.admin.inc
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
 * Banners section form
 *
 */
function simple_content_banners_form($form, &$form_state) {
  $form = array();

  // Banners Header
  $form['simple_content_banners_header'] = array(
    '#type' => 'textfield',
    '#weight' => '-20',
    '#title' => t('Header'),
    '#description' => t('Insert the banners section header.'),
    '#default_value' => variable_get('simple_content_banners_header', NULL),
    '#required' => FALSE,
    '#maxlength' => 40,
  );

  // Vertical tabs
  $form['simple_content_banners_group_main'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => '-10',
  );

  $banners_number = variable_get('simple_content_banners_number', 3);
  // Loop through number of banners
  for ($i = 1; $i <= $banners_number; $i++) {
    // Make pid two digit algarism
    $pid = str_pad($i, 2, '0', STR_PAD_LEFT);

    // Fieldsets
    $form['simple_content_banners_group_' . $pid] = array(
      '#type' => 'fieldset',
      '#weight' => $i,
      '#title' => $pid . ': ' . variable_get('simple_content_banners_' . $pid . '_title', NULL),
      '#collapsible' => TRUE,
      '#group' => 'simple_content_banners_group_main',
    );

    // Banner Enabled?
    $form['simple_content_banners_group_' . $pid]['simple_content_banners_' . $pid . '_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#description' => t('Enable the banner?'),
      '#default_value' => variable_get('simple_content_banners_' . $pid . '_enabled', 0),
      '#required' => FALSE,
    );

    // Banner Title
    $form['simple_content_banners_group_' . $pid]['simple_content_banners_' . $pid . '_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('Insert the banner title.'),
      '#default_value' => variable_get('simple_content_banners_' . $pid . '_title', NULL),
      '#required' => TRUE,
      '#maxlength' => 60,
    );

    // Banner Thumbnail
    $form['simple_content_banners_group_' . $pid]['simple_content_banners_' . $pid . '_thumbnail'] = array(
      '#type' => 'managed_file',
      '#title' => t('Banner'),
      '#description' => t('Insert the banner thumbnail.'),
      '#default_value' => variable_get('simple_content_banners_' . $pid . '_thumbnail', NULL),
      '#required' => FALSE,
      '#upload_location' => 'public://images/banners',
      '#upload_validators' => array(
        'file_validate_extensions' => array('gif png jpg jpeg'),
      )
    );

  }

  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save configuration'),
  );

  return $form;
}


/**
 * Submit handler for form().
 * 
 * Banners section form
 *
 */
function simple_content_banners_form_submit($form, &$form_state) {

  // Banners Header
  variable_set('simple_content_banners_header', $form_state['values']['simple_content_banners_header']);

  $banners_number = variable_get('simple_content_banners_number', 3);
  // Loop through number of banners
  for ($i = 1; $i <= $banners_number; $i++) {
    // Make pid two digit algarism
    $pid = str_pad($i, 2, '0', STR_PAD_LEFT);

    // Banner Enabled?
    variable_set('simple_content_banners_' . $pid . '_enabled',
      $form_state['values']['simple_content_banners_' . $pid . '_enabled']);

    // Banner Title
    variable_set('simple_content_banners_' . $pid . '_title',
      $form_state['values']['simple_content_banners_' . $pid . '_title']);

    // Banner Thumbnail
    variable_set('simple_content_banners_' . $pid . '_thumbnail',
      $form_state['values']['simple_content_banners_' . $pid . '_thumbnail']);

  }

}
