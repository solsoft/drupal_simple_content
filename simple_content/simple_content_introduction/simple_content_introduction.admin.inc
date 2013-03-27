<?php

/**
 * simple_content_introduction.admin.inc
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
 * Introduction section form
 *
 */
function simple_content_introduction_form($form, &$form_state) {
  $form = array();

  // Introduction Header
  $form['simple_content_introduction_header'] = array(
    '#type' => 'textfield',
    '#weight' => '-20',
    '#title' => t('Header'),
    '#description' => t('Insert the introduction section header.'),
    '#default_value' => variable_get('simple_content_introduction_header', NULL),
    '#required' => TRUE,
    '#maxlength' => 40,
  );

  // Introduction Body
  $form['simple_content_introduction_body'] = array(
    '#type' => 'textarea',
    '#weight' => '-10',
    '#title' => t('Body'),
    '#description' => t('Insert the introduction section body.'),
    '#default_value' => variable_get('simple_content_introduction_body', NULL),
    '#required' => TRUE,
    '#resizable' => TRUE,
    '#rows' => 5,
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
 * Home section form
 *
 */
function simple_content_introduction_form_submit($form, &$form_state) {

  // Introduction Header
  variable_set('simple_content_introduction_header', $form_state['values']['simple_content_introduction_header']);

  // Introduction Body
  variable_set('simple_content_introduction_body', $form_state['values']['simple_content_introduction_body']);

}
