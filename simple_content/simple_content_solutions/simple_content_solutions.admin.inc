<?php

/**
 * simple_content_solutions.admin.inc
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
 * Solutions section form
 *
 */
function simple_content_solutions_form($form, &$form_state) {
  $form = array();

  // Solutions Header
  $form['simple_content_solutions_header'] = array(
    '#type' => 'textfield',
    '#weight' => '-20',
    '#title' => t('Header'),
    '#description' => t('Insert the solutions section header.'),
    '#default_value' => variable_get('simple_content_solutions_header', NULL),
    '#required' => FALSE,
    '#maxlength' => 40,
  );

  // Vertical tabs
  $form['simple_content_solutions_group_main'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => '-10',
  );

  $solutions_number = variable_get('simple_content_solutions_number', 3);
  // Loop through number of solutions
  for ($i = 1; $i <= $solutions_number; $i++) {
    // Make pid two digit algarism
    $pid = str_pad($i, 2, '0', STR_PAD_LEFT);

    // Fieldsets
    $form['simple_content_solutions_group_' . $pid] = array(
      '#type' => 'fieldset',
      '#weight' => $i,
      '#title' => $pid . ': ' . variable_get('simple_content_solutions_' . $pid . '_menu', NULL),
      '#collapsible' => TRUE,
      '#group' => 'simple_content_solutions_group_main',
    );

    // Solution Enabled?
    $form['simple_content_solutions_group_' . $pid]['simple_content_solutions_' . $pid . '_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#description' => t('Enable the solution?'),
      '#default_value' => variable_get('simple_content_solutions_' . $pid . '_enabled', 0),
      '#required' => FALSE,
    );

    // Solution Title
    $form['simple_content_solutions_group_' . $pid]['simple_content_solutions_' . $pid . '_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('Insert the solution title.'),
      '#default_value' => variable_get('simple_content_solutions_' . $pid . '_title', NULL),
      '#required' => TRUE,
      '#maxlength' => 60,
    );

    // Solution Menu Title
    $form['simple_content_solutions_group_' . $pid]['simple_content_solutions_' . $pid . '_menu'] = array(
      '#type' => 'textfield',
      '#title' => t('Menu Title'),
      '#description' => t('Insert the solution menu title.'),
      '#default_value' => variable_get('simple_content_solutions_' . $pid . '_menu', NULL),
      '#required' => TRUE,
      '#maxlength' => 20,
    );

    // Solution Body
    $form['simple_content_solutions_group_' . $pid]['simple_content_solutions_' . $pid . '_body'] = array(
      '#type' => 'textarea',
      '#title' => t('Body'),
      '#description' => t('Insert the solution body.'),
      '#default_value' => variable_get('simple_content_solutions_' . $pid . '_body', NULL),
      '#required' => FALSE,
      '#resizable' => TRUE,
      '#rows' => 5,
    );

    // Solution Thumbnail
    $form['simple_content_solutions_group_' . $pid]['simple_content_solutions_' . $pid . '_thumbnail'] = array(
      '#type' => 'managed_file',
      '#title' => t('Thumbnail'),
      '#description' => t('Insert the solution thumbnail.'),
      '#default_value' => variable_get('simple_content_solutions_' . $pid . '_thumbnail', NULL),
      '#required' => FALSE,
      '#upload_location' => 'public://images/solutions',
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
 * Solutions section form
 *
 */
function simple_content_solutions_form_submit($form, &$form_state) {

  // Solutions Header
  variable_set('simple_content_solutions_header', $form_state['values']['simple_content_solutions_header']);

  $solutions_number = variable_get('simple_content_solutions_number', 3);
  // Loop through number of solutions
  for ($i = 1; $i <= $solutions_number; $i++) {
    // Make pid two digit algarism
    $pid = str_pad($i, 2, '0', STR_PAD_LEFT);

    // Solution Enabled?
    variable_set('simple_content_solutions_' . $pid . '_enabled',
      $form_state['values']['simple_content_solutions_' . $pid . '_enabled']);

    // Solution Title
    variable_set('simple_content_solutions_' . $pid . '_title',
      $form_state['values']['simple_content_solutions_' . $pid . '_title']);

    // Solution Menu Title
    variable_set('simple_content_solutions_' . $pid . '_menu',
      $form_state['values']['simple_content_solutions_' . $pid . '_menu']);

    // Solution Body
    variable_set('simple_content_solutions_' . $pid . '_body', 
      $form_state['values']['simple_content_solutions_' . $pid . '_body']);

    // Solution Thumbnail
    variable_set('simple_content_solutions_' . $pid . '_thumbnail', 
      $form_state['values']['simple_content_solutions_' . $pid . '_thumbnail']);

  }

}
