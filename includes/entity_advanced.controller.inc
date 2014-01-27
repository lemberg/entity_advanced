<?php

/**
 * @file
 * Provides an advanced version of Entity API controller with some generic
 * properties support like created/changed timestamp.
 */

/**
 * An advanced version of Entity API controller implementing
 * EntityAPIControllerInterface for the database.
 */
class EntityAPIAdvancedController extends EntityAPIController {

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $entity->changed = REQUEST_TIME;
    if(empty($entity->{$this->idKey})) {
      $entity->created = REQUEST_TIME;
    }
    return parent::save($entity, $transaction);
  }
}
